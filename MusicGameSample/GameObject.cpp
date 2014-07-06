#include <boost/timer/timer.hpp>
#include <boost/lexical_cast.hpp>
#include "GameObject.h"

static boost::timer::cpu_timer timer;

///@copydoc Ash::Transform::setChild(boost::shared_ptr<Transform> &)
void Ash::Transform::setChild(boost::shared_ptr<Transform> & child)
{
	children.insert(std::pair<const std::string, boost::shared_ptr<Transform>>(child->getGameObject().getObjectId(), child));
}

///@copydoc Ash::Transform::setParent(boost::shared_ptr<Transform> &)
void Ash::Transform::setParent(boost::shared_ptr<Transform> & p)
{
	p->setChild(getGameObject().getTransform());
	parent = p;
}

///@copydoc Ash::Transform::getParent()
boost::optional<boost::shared_ptr<Ash::Transform>> Ash::Transform::getParent()
{
	if (parent.lock() == nullptr) {
		return boost::none;
	}
	return parent.lock();
}

///@copydoc Ash::GameObject::GameObject()
Ash::GameObject::GameObject() : transform(boost::make_shared<Transform>(*this)), objectId(boost::lexical_cast<std::string>(timer.elapsed().wall))
{
}

///@copydoc Ash::GameObject::GameObject(GameObject &)
Ash::GameObject::GameObject(GameObject & parent) : transform(boost::make_shared<Transform>(*this)), objectId(boost::lexical_cast<std::string>(timer.elapsed().wall))
{
}

///@copydoc Ash::GameObject::~GameObject()
Ash::GameObject::~GameObject()
{
}

///@copydoc Ash::GameObject::update()
void Ash::GameObject::update()
{
	for each (auto com in components) {
		com.second->update();
	}
}