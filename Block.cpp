#include "Block.h"



void Block::selectedImage(PhysicsShapeCache * shapeCache)
{
	string names[7] = { "banana","apple","cherries", "orange","watermelon","crate", "bird" };
//	int type = random() % 7;
	int type = 4;
	string k = names[type];
	obj = Sprite::create(k+".png");

	obj->setAnchorPoint(Vec2(0.5, 0.5));

	auto shape = shapeCache->createBodyWithName(k);
	
	obj->setPhysicsBody(shape);
}

void Block::init(PhysicsShapeCache * shapeCache)
{
	selectedImage(shapeCache);
	createPos();
	//setScale();
	obj->getPhysicsBody()->setCollisionBitmask(2);
	obj->getPhysicsBody()->setContactTestBitmask(true);
	obj->getPhysicsBody()->setDynamic(true);
	obj->getPhysicsBody()->setGravityEnable(true);
}

Block::Block(PhysicsShapeCache* shapeCache)
{
	init(shapeCache);
}


Block::~Block()
{
}
