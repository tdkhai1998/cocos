#pragma once
#include"cocos2d.h"
#include "PhysicsShapeCache.h"
using namespace std;
using namespace cocos2d;
class Shape:public Sprite
{
protected:
	Sprite* obj;
	void createPos();
	void setVecology(Vec2 pos);
	virtual void selectedImage(PhysicsShapeCache* shapeCache) = 0;
	virtual void init(PhysicsShapeCache* shapeCache) = 0;
	void setScale();
public:
	Sprite* getSprite();
	Shape();
	~Shape();
};

