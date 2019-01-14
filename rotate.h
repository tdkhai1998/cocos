#pragma once
#include "Shape.h"
class rotate :
	public Shape
{
protected:
	virtual void init(PhysicsShapeCache* shapeCache,string namevoid );

public:

	rotate(PhysicsShapeCache* shapeCache,string name);
	~rotate();
};

