#include "rotate.h"


void rotate::init(PhysicsShapeCache* shapeCache, string name)
{
	setPhysics(shapeCache, name);
	auto rot = RotateBy::create(0.1, 15);
	auto repeat4 = RepeatForever::create(rot);
	obj->runAction(repeat4);
	obj->getPhysicsBody()->setCollisionBitmask(3);
}

rotate::rotate(PhysicsShapeCache* shapeCache,string name)
{
	
	init(shapeCache, name);

}


rotate::~rotate()
{
}
