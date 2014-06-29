#include "GameObject.h"

///@copydoc Ash::GameObject::GameObject()
Ash::GameObject::GameObject() : transform(new Ash::Transform(*this))
{
}

///@copydoc Ash::GameObject::GameObject(GameObject &)
Ash::GameObject::GameObject(GameObject & parent)	
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