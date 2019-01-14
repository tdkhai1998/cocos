#include "Block.h"





void Block::init(PhysicsShapeCache * shapeCache,string name)
{

	
	setPhysics(shapeCache,name);
	obj->getPhysicsBody()->setCollisionBitmask(2);
	
}

Block::Block(PhysicsShapeCache* shapeCache,string name)
{
	init(shapeCache,name);
}


Block::~Block()
{
}
