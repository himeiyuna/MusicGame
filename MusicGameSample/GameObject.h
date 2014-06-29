#include <glew.h>
#include <string>
#include <boost/unordered_map.hpp>
#include <boost/noncopyable.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/optional.hpp>
#include "Math.h"

namespace Ash
{
	class GameComponent;
	class Transform;
	class GameObject;
}

class Ash::GameComponent : private boost::noncopyable
{
	friend class Ash::GameObject;

	///@brief 自身を組み込んでいるオブジェクト
	GameObject & gameObject;

protected:
	GameComponent(GameObject & obj) : gameObject(obj)
	{
	}
	virtual ~GameComponent()
	{}

	virtual void update() = 0;

public:
	///@brief 自身を組み込むオブジェクトを取得する
	///@return ゲームオブジェクト
	GameObject & getGameObject() { return gameObject; } 
};

///@brief 3D空間の情報を管理するクラス
class Ash::Transform : public Ash::GameComponent
{
	///@brief 座標値
	Math::Vector3 localPosition;

	///@brief スケール値
	Math::Vector3 localScale;

	///@brief 姿勢値
	Math::Quaternion localRotation;

	///@brief 親のポインタ
	boost::shared_ptr<Transform> parent;

public:
	Transform(GameObject & obj) : GameComponent(obj), localPosition(), localScale(1.0f, 1.0f, 1.0f), localRotation()
	{
	}
	~Transform()
	{
		int i = 0;
	}

	boost::optional<Transform &> getParent()
	{
		if (parent == nullptr) {
			return boost::none;
		}
		return *parent.get();
	}

	///@brief Local空間の情報を取得するアクセサ
	Math::Vector3 & getLocalPosition() { return localPosition; }
	Math::Vector3 & getLocalScale() { return localScale; }
	Math::Quaternion & getLocalRotation() { return localRotation; }

	Math::Matrix getLocalMatrix()
	{
		Math::Matrix result;
		Math::GetMatrixFromQuaternion(result, localRotation);

		result.row[0].ToVector3() *= localScale.x;
		result.row[1].ToVector3() *= localScale.y;
		result.row[2].ToVector3() *= localScale.z;
		result.row[3] = localPosition;

		return result;
	}

	Math::Matrix getWorldMatrix()
	{
		if (auto parent = getParent()) {
			return getLocalMatrix() * parent->getWorldMatrix();
		} else {
			return getLocalMatrix();
		}
	}

	virtual void update()
	{}
};

///@brief このクラスを用いてゲーム内のオブジェクトを配置する
class Ash::GameObject
{
	///@brief 3D空間の座標値等
	std::unique_ptr<Transform> transform;

	///@brief 組み込んでいるコンポーネント
	boost::unordered_multimap<std::string, boost::shared_ptr<GameComponent>> components;

public:
	GameObject();
	GameObject(GameObject & parent);
	virtual ~GameObject();

	///@brief 位置情報の取得
	///@return 位置情報
	inline Transform & getTransform() { return *transform; }

	///@brief コンポーネントの更新
	void update();

	///@brief コンポーネントを取得する
	///@param [in] T 取得したいコンポーネントの型
	///@return 指定したコンポーネント（同じコンポーネントがついていた場合はどれが取得できるかは未定義）
	template <class T> boost::optional<boost::shared_ptr<T>> getComponent()
	{
		auto i = components.find(typeid(T).name());
		if (i == components.end()) {
			return boost::none;
		}
		return boost::dynamic_pointer_cast<T>(i->second);
	}

	///@brief コンポーネントを追加する
	///@param [in] T 追加したいコンポーネントの型
	template <class T> void addComponent()
	{
		auto com = boost::make_shared<T>(*this);
		components.insert(std::pair<std::string, boost::shared_ptr<GameComponent>>(typeid(T).name(), com));
	}

	///@brief コンポーネントを削除する
	///@param [in] T 削除したいコンポーネントの型
	template <class T> void removeComponent()
	{
		components.erase(typeid(T).name());
	}
};

class Renderer : public Ash::GameComponent
{
public:
	Renderer(Ash::GameObject& obj) : GameComponent(obj)
	{

	}
	virtual ~Renderer()
	{

	}

	virtual void update()
	{
		glBegin(GL_TRIANGLE_STRIP);

		auto matrix = getGameObject().getTransform().getWorldMatrix();

		glVertex3d(-0.5 + matrix.row[3].x, -0.5 + matrix.row[3].y, 0.0);
		glVertex3d(0.5 + matrix.row[3].x, -0.5 + matrix.row[3].y, 0.0);
		glVertex3d(-0.5 + matrix.row[3].x, 0.5 + matrix.row[3].y, 0.0);
		glVertex3d(0.5 + matrix.row[3].x, 0.5 + matrix.row[3].y, 0.0);

		glEnd();
	}
};

class MyObj
{
	boost::shared_ptr<Ash::GameObject> obj;

public:
	MyObj() : obj(new Ash::GameObject())
	{
		obj->addComponent<Renderer>();
	}

	void update()
	{
		obj->update();
	}
};

