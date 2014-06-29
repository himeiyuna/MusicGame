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

	///@brief ���g��g�ݍ���ł���I�u�W�F�N�g
	GameObject & gameObject;

protected:
	GameComponent(GameObject & obj) : gameObject(obj)
	{
	}
	virtual ~GameComponent()
	{}

	virtual void update() = 0;

public:
	///@brief ���g��g�ݍ��ރI�u�W�F�N�g���擾����
	///@return �Q�[���I�u�W�F�N�g
	GameObject & getGameObject() { return gameObject; } 
};

///@brief 3D��Ԃ̏����Ǘ�����N���X
class Ash::Transform : public Ash::GameComponent
{
	///@brief ���W�l
	Math::Vector3 localPosition;

	///@brief �X�P�[���l
	Math::Vector3 localScale;

	///@brief �p���l
	Math::Quaternion localRotation;

	///@brief �e�̃|�C���^
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

	///@brief Local��Ԃ̏����擾����A�N�Z�T
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

///@brief ���̃N���X��p���ăQ�[�����̃I�u�W�F�N�g��z�u����
class Ash::GameObject
{
	///@brief 3D��Ԃ̍��W�l��
	std::unique_ptr<Transform> transform;

	///@brief �g�ݍ���ł���R���|�[�l���g
	boost::unordered_multimap<std::string, boost::shared_ptr<GameComponent>> components;

public:
	GameObject();
	GameObject(GameObject & parent);
	virtual ~GameObject();

	///@brief �ʒu���̎擾
	///@return �ʒu���
	inline Transform & getTransform() { return *transform; }

	///@brief �R���|�[�l���g�̍X�V
	void update();

	///@brief �R���|�[�l���g���擾����
	///@param [in] T �擾�������R���|�[�l���g�̌^
	///@return �w�肵���R���|�[�l���g�i�����R���|�[�l���g�����Ă����ꍇ�͂ǂꂪ�擾�ł��邩�͖���`�j
	template <class T> boost::optional<boost::shared_ptr<T>> getComponent()
	{
		auto i = components.find(typeid(T).name());
		if (i == components.end()) {
			return boost::none;
		}
		return boost::dynamic_pointer_cast<T>(i->second);
	}

	///@brief �R���|�[�l���g��ǉ�����
	///@param [in] T �ǉ��������R���|�[�l���g�̌^
	template <class T> void addComponent()
	{
		auto com = boost::make_shared<T>(*this);
		components.insert(std::pair<std::string, boost::shared_ptr<GameComponent>>(typeid(T).name(), com));
	}

	///@brief �R���|�[�l���g���폜����
	///@param [in] T �폜�������R���|�[�l���g�̌^
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

