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

	///@brief ���g��g�ݍ���ł���I�u�W�F�N�g
	GameObject & gameObject;

	///@brief �L����Ԃ�
	bool enable;

protected:
	GameComponent(GameObject & obj) : gameObject(obj), enable(true)
	{
	}
	virtual ~GameComponent()
	{}

	virtual void update() = 0;

public:
	///@brief ���g��g�ݍ��ރI�u�W�F�N�g���擾����
	///@return �Q�[���I�u�W�F�N�g
	GameObject & getGameObject() { return gameObject; }

	///@brief �L����Ԃ��ǂ���
	///@return �L����ԂȂ�true
	bool isEnable() { return enable; }
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
	boost::weak_ptr<Transform> parent;

	///@brief �q�̃|�C���^
	boost::unordered_map<const std::string, boost::shared_ptr<Transform>> children;

	///@brief �q��ݒ肷��
	void setChild(const boost::shared_ptr<Transform> & child);

public:
	Transform(GameObject & obj) : GameComponent(obj), localPosition(), localScale(1.0f, 1.0f, 1.0f), localRotation()
	{
	}
	virtual ~Transform()
	{
	}

	///@brief �e��ݒ肷��
	void setParent(const boost::shared_ptr<Transform> & p);

	///@brief �e���擾����
	///@return �e
	boost::optional<const boost::shared_ptr<Transform> &> getParent();

	///@brief Local��Ԃ̏����擾����A�N�Z�T
	Math::Vector3 & getLocalPosition() { return localPosition; }
	Math::Vector3 & getLocalScale() { return localScale; }
	Math::Quaternion & getLocalRotation() { return localRotation; }

	///@brief �e�q�֌W���l�����Ȃ����[���h�ϊ��s����擾
	///@return ���[���h�ϊ��s��
	Math::Matrix getLocalTransform();

	///@brief �e�q�֌W���l���������[���h�ϊ��s����擾
	///@return ���[���h�ϊ��s��
	Math::Matrix getWorldTransform();

	virtual void update()
	{}
};

///@brief ���̃N���X��p���ăQ�[�����̃I�u�W�F�N�g��z�u����
class Ash::GameObject
{
	///@brief ������Ԃ�
	bool active;

	///@brief �I�u�W�F�N�g�ŗL��ID
	const std::string objectId;

	///@brief 3D��Ԃ̍��W�l��
	boost::shared_ptr<Transform> transform;

	///@brief �g�ݍ���ł���R���|�[�l���g
	boost::unordered_multimap<const std::string, boost::shared_ptr<GameComponent>> components;

public:
	GameObject();
	GameObject(GameObject & parent);
	virtual ~GameObject();

	///@brief ������Ԃ��擾����
	///@return ������ԂȂ�true
	bool isActive() { return active; }

	///@brief �q�G�����L�[��Ŋ�����Ԃ��擾����
	///@return ������ԂȂ�true
	bool isActiveInHierarchy();

	///@brief �I�u�W�F�N�gID���擾����
	///@return ID
	const std::string & getObjectId() const { return objectId; }

	///@brief �ʒu���̎擾
	///@return �ʒu���
	const boost::shared_ptr<Transform> & getTransform() { return transform; }

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
		components.insert(std::pair<const std::string, boost::shared_ptr<GameComponent>>(typeid(T).name(), com));
	}

	///@brief �R���|�[�l���g���폜����
	///@param [in] T �폜�������R���|�[�l���g�̌^
	template <class T> void removeComponent()
	{
		components.erase(typeid(T).name());
	}
};

