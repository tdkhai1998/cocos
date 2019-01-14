#include "Boom.h"



Boom::Boom(PhysicsShapeCache* shapeCache,string name)
{
	setPhysics(shapeCache, name);
	obj->getPhysicsBody()->setCollisionBitmask(4);
}


Boom::~Boom()
{
}
