#pragma once
#include "GameObject.h"

namespace Ash 
{
	class Renderer;
}

///@brief 描画コンポーネント
class Ash::Renderer : public Ash::GameComponent
{
public:
	Renderer(Ash::GameObject & obj);
	virtual ~Renderer();

	virtual void update();
};

class MyObj
{
	boost::shared_ptr<Ash::GameObject> obj;

public:
	MyObj() : obj(new Ash::GameObject())
	{
		obj->addComponent<Ash::Renderer>();
	}

	void update()
	{
		obj->update();
	}
};