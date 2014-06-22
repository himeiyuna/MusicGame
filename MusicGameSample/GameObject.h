#include <glew.h>
#include <string>
#include <boost/unordered_map.hpp>
#include <boost/noncopyable.hpp>
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

class Ash::GameComponent
{
	friend class Ash::GameObject;

	///@brief 自身を組み込んでいるオブジェクト
	GameObject& gameObject;

protected:
	GameComponent(GameObject& obj) : gameObject(obj)
	{
	}
	virtual ~GameComponent()
	{}

	virtual void update() = 0;

public:
	///@brief 自身を組み込むオブジェクトを取得する
	///@return ゲームオブジェクト
	GameObject& getGameObject() { return gameObject; }
};

///@brief 3D空間の情報を管理するクラス
class Ash::Transform : public Ash::GameComponent
{
	///@brief 座標値
	Math::Vector3 localPosition;
	Math::Vector3 localScale;
	Math::Quaternion localRotation;

	///@brief 親のポインタ
	boost::shared_ptr<Transform> parent;

public:
	Transform(GameObject& obj) : GameComponent(obj), localPosition(), localScale(1.0f, 1.0f, 1.0f), localRotation()
	{
	}
	~Transform()
	{
		int i = 0;
	}

	boost::optional<Transform&> getParent()
	{
		if (parent == nullptr) {
			return boost::none;
		}
		return *parent.get();
	}

	///@brief Local空間の情報を取得するアクセサ
	Math::Vector3& getLocalPosition() { return localPosition; }
	Math::Vector3& getLocalScale() { return localScale; }
	Math::Quaternion& getLocalRotation() { return localRotation; }

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
	GameObject() : transform(new Ash::Transform(*this))
	{
	}
	GameObject(GameObject& parent)
	{}
	~GameObject()
	{}

	Transform& getTransform() { return *transform; }

	void update()
	{
		for each (auto com in components) {
			com.second->update();
		}
	}

	template <class T>
	void addComponent(std::function<void(T&)> initializer)
	{
		boost::shared_ptr<T> com(new T(*this));
		initializer(*com);
		components.insert(std::pair<std::string, boost::shared_ptr<GameComponent>>(typeid(T).name(), com));
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
		obj->addComponent<Renderer>([](Renderer& r) -> void {
			auto go = r.getGameObject().getTransform();
			r.getGameObject().getTransform().getLocalPosition().x += -0.5f;
		});
	}

	void update()
	{
		obj->update();
	}
};

