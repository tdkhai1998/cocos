#include "Boom.h"





void Boom::init(PhysicsShapeCache * shapeCache, string name)
{


	setPhysics(shapeCache, name);
	obj->getPhysicsBody()->setCollisionBitmask(4);

}
Boom::Boom(PhysicsShapeCache* shapeCache,string name)
{
	init(shapeCache, name);
}


Boom::~Boom()
{
}
