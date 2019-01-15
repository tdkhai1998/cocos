#include "Rotate.h"


void Rotate::init(PhysicsShapeCache* shapeCache, string name)
{
	setPhysics(shapeCache, name);
	auto rot = RotateBy::create(0.1, 15);
	auto repeat4 = RepeatForever::create(rot);
	obj->runAction(repeat4);
	obj->getPhysicsBody()->setCollisionBitmask(3);
}

Rotate::Rotate(PhysicsShapeCache* shapeCache,string name)
{
	
	init(shapeCache, name);

}


Rotate::~Rotate()
{
}
