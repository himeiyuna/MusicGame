#include <boost/timer/timer.hpp>
#include <boost/lexical_cast.hpp>
#include "GameObject.h"

static boost::timer::cpu_timer timer;

void Ash::Transform::setChild(const boost::shared_ptr<Transform> & child)
{
	children.insert(std::pair<const std::string, boost::shared_ptr<Transform>>(child->getGameObject().getObjectId(), child));
}

void Ash::Transform::setParent(const boost::shared_ptr<Transform> & p)
{
	p->setChild(getGameObject().getTransform());
	parent = p;
}

boost::optional<const boost::shared_ptr<Ash::Transform> &> Ash::Transform::getParent()
{
	if (parent.lock() == nullptr) {
		return boost::none;
	}
	return parent.lock();
}

Math::Matrix Ash::Transform::getLocalTransform()
{
	Math::Matrix result;
	Math::GetMatrixFromQuaternion(result, localRotation);

	result.row[0].ToVector3() *= localScale.x;
	result.row[1].ToVector3() *= localScale.y;
	result.row[2].ToVector3() *= localScale.z;
	result.row[3] = localPosition;

	return result;
}

Math::Matrix Ash::Transform::getWorldTransform()
{
	if (auto parent = getParent()) {
		return getLocalTransform() * parent.get()->getWorldTransform();
	}
	else {
		return getLocalTransform();
	}
}

Ash::GameObject::GameObject() : active(true), transform(boost::make_shared<Transform>(*this)), objectId(boost::lexical_cast<std::string>(timer.elapsed().wall))
{
}

Ash::GameObject::GameObject(GameObject & parent) : active(true), transform(boost::make_shared<Transform>(*this)), objectId(boost::lexical_cast<std::string>(timer.elapsed().wall))
{
}

Ash::GameObject::~GameObject()
{
}

bool Ash::GameObject::isActiveInHierarchy()
{
	if (auto parent = getTransform()->getParent()) {
		auto & pt = parent.get();
		return !!pt->getGameObject().isActiveInHierarchy();
	} else {
		return !!isActive();
	}
}

void Ash::GameObject::update()
{
	for each (auto com in components) {
		if (!!com.second->isEnable()) {
			com.second->update();
		}
	}
}