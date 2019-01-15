#pragma once
#include "Shape.h"
class Rotate :
	public Shape
{
protected:
	virtual void init(PhysicsShapeCache* shapeCache,string namevoid );

public:

	Rotate(PhysicsShapeCache* shapeCache,string name);
	~Rotate();
};

