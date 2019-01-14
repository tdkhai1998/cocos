#include "Shape.h"

#define WIDTH 700
#define HEIGHT 1200

void Shape::createPos()
{
	Vec2 pos;

	
	pos.x = random() % (WIDTH + 400) - 200;
	pos.y = 1000;

	if (pos.x < 0) pos.x = -200;
	else if (pos.x > WIDTH) pos.x = WIDTH + 200;

	obj->setPosition(pos);
	setVecology(pos);
}

void Shape::setVecology(Vec2 pos)
{
	/*int signalX = (pos.x > WIDTH / 2) ? -1 : 1;
	int signalY = (pos.y > HEIGHT) ? 1 : 1;
	Vec2 vecology;
	vecology.x = random()%500*signalX;
	vecology.y = random()%500*signalY;
	obj->getPhysicsBody()->setVelocity(vecology);*/

	/*

	int signalX = (pos.x <= 0) ? 1 : (pos.x >WIDTH) ? -1 : 0;
	int signalY = (pos.y < HEIGHT) ? 1 : -1;
	Vec2 v;
	v.x = 100* signalX;
	v.y = 0;
	obj->getPhysicsBody()->setVelocity(v);*/
}

void Shape::setScale()
{
	float scale[5] = { 0.2, 0.5 , 1 , 1.5 ,2 };
	obj->setScale(0.5);
}

Sprite * Shape::getSprite()
{
	return obj;;
}

Shape::Shape()
{
	
}



Shape::~Shape()
{
}
