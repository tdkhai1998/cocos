#include "Shape.h"


void Shape::setPhysics(PhysicsShapeCache* shapeCache,string name)
{
	obj = Sprite::create(name + ".png");

	obj->setAnchorPoint(Vec2(0.5, 0.5));

	auto shape = shapeCache->createBodyWithName(name);

	obj->setPhysicsBody(shape);
	obj->getPhysicsBody()->setContactTestBitmask(true);
	obj->getPhysicsBody()->setDynamic(true);
	obj->getPhysicsBody()->setGravityEnable(true);
}

Sprite * Shape::getSprite()
{
	return obj;
}

Shape::Shape()
{
	
}



Shape::~Shape()
{
}
