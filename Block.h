#pragma once
#include "Shape.h"
class Block :
	public Shape
{
protected:
	virtual void init(PhysicsShapeCache* shapeCache,string name);

public:
	Block(PhysicsShapeCache* shapeCache,string name);
	~Block();
};

