#include"Block.h"
#include"rotate.h"
#include"Boom.h"
#include"PhysicsShapeCache.h"
#include<cocos2d.h>
#include<vector>
using namespace cocos2d;

 

class Maps {

	typedef std::vector<Sprite*> (*map)();
	const map mapNomal[4];
	const map mapSpecial[4];
	static Maps* singleton;
	Maps();
	
public:
	void selectedMap(int type);
	Maps* getMap();
	~Maps();
};

Maps* Maps::singleton = NULL;