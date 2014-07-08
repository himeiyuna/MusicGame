#pragma once
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

	///@brief 有効状態か
	bool enable;

protected:
	GameComponent(GameObject & obj) : gameObject(obj), enable(true)
	{
	}
	virtual ~GameComponent()
	{}

	virtual void update() = 0;

public:
	///@brief 自身を組み込むオブジェクトを取得する
	///@return ゲームオブジェクト
	GameObject & getGameObject() { return gameObject; }

	///@brief 有効状態かどうか
	///@return 有効状態ならtrue
	bool isEnable() { return enable; }
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
	boost::weak_ptr<Transform> parent;

	///@brief 子のポインタ
	boost::unordered_map<const std::string, boost::shared_ptr<Transform>> children;

	///@brief 子を設定する
	void setChild(const boost::shared_ptr<Transform> & child);

public:
	Transform(GameObject & obj) : GameComponent(obj), localPosition(), localScale(1.0f, 1.0f, 1.0f), localRotation()
	{
	}
	virtual ~Transform()
	{
	}

	///@brief 親を設定する
	void setParent(const boost::shared_ptr<Transform> & p);

	///@brief 親を取得する
	///@return 親
	boost::optional<const boost::shared_ptr<Transform> &> getParent();

	///@brief Local空間の情報を取得するアクセサ
	Math::Vector3 & getLocalPosition() { return localPosition; }
	Math::Vector3 & getLocalScale() { return localScale; }
	Math::Quaternion & getLocalRotation() { return localRotation; }

	///@brief 親子関係を考慮しないワールド変換行列を取得
	///@return ワールド変換行列
	Math::Matrix getLocalTransform();

	///@brief 親子関係を考慮したワールド変換行列を取得
	///@return ワールド変換行列
	Math::Matrix getWorldTransform();

	virtual void update()
	{}
};

///@brief このクラスを用いてゲーム内のオブジェクトを配置する
class Ash::GameObject
{
	///@brief 活性状態か
	bool active;

	///@brief オブジェクト固有のID
	const std::string objectId;

	///@brief 3D空間の座標値等
	boost::shared_ptr<Transform> transform;

	///@brief 組み込んでいるコンポーネント
	boost::unordered_multimap<const std::string, boost::shared_ptr<GameComponent>> components;

public:
	GameObject();
	GameObject(GameObject & parent);
	virtual ~GameObject();

	///@brief 活性状態か取得する
	///@return 活性状態ならtrue
	bool isActive() { return active; }

	///@brief ヒエラルキー上で活性状態か取得する
	///@return 活性状態ならtrue
	bool isActiveInHierarchy();

	///@brief オブジェクトIDを取得する
	///@return ID
	const std::string & getObjectId() const { return objectId; }

	///@brief 位置情報の取得
	///@return 位置情報
	const boost::shared_ptr<Transform> & getTransform() { return transform; }

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
		components.insert(std::pair<const std::string, boost::shared_ptr<GameComponent>>(typeid(T).name(), com));
	}

	///@brief コンポーネントを削除する
	///@param [in] T 削除したいコンポーネントの型
	template <class T> void removeComponent()
	{
		components.erase(typeid(T).name());
	}
};

