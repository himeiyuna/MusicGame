#include "Renderer.h"

Ash::Renderer::Renderer(Ash::GameObject & obj) : GameComponent(obj)
{
}

Ash::Renderer::~Renderer()
{

}

void Ash::Renderer::update()
{
	glLoadIdentity();

	auto matrix = getGameObject().getTransform()->getWorldTransform();
	glLoadMatrixf(reinterpret_cast<float *>(matrix.m));

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3d(-0.5 + matrix.row[3].x, -0.5 + matrix.row[3].y, 0.0);
	glVertex3d(0.5 + matrix.row[3].x, -0.5 + matrix.row[3].y, 0.0);
	glVertex3d(-0.5 + matrix.row[3].x, 0.5 + matrix.row[3].y, 0.0);
	glVertex3d(0.5 + matrix.row[3].x, 0.5 + matrix.row[3].y, 0.0);

	glEnd();
}

