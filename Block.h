#pragma once
#include "Shape.h"
class Block :
	public Shape
{
protected:
	virtual void selectedImage(PhysicsShapeCache* shapeCache);
	
public:
	virtual void init(PhysicsShapeCache* shapeCache);
	Block(PhysicsShapeCache* shapeCache);
	~Block();
};

