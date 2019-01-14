#pragma once
#include "Shape.h"
class Boom :
	public Shape
{
protected:
	virtual void init(PhysicsShapeCache* shapeCache, string name);

public:
	Boom(PhysicsShapeCache* shapeCache, string name);
	~Boom();
};

