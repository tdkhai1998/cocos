#pragma once
#include"cocos2d.h"
#include "PhysicsShapeCache.h"
using namespace std;
using namespace cocos2d;
class Shape:public Sprite
{
protected:
	Sprite* obj;
	void setPhysics(PhysicsShapeCache* shapeCache,string name);
	virtual void init(PhysicsShapeCache* shapeCache,string name) = 0;
public:
	Sprite* getSprite();
	Shape();
	~Shape();
};

