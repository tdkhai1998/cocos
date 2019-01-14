/*#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PhysicsShapeCache.h"


class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	//static Sprite a;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	
	
	virtual void update(float dt) override;
	void onMouseMove(cocos2d::Event *event);

	/*void onMouseUp(Event *event);

	void onMouseMove(Event *event);
	
	void setBackGround(float dt);
    // implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
	void spawnSprite(const std::string &name, Vec2 pos);
	PhysicsShapeCache *shapeCache;
private:
	cocos2d::PhysicsWorld* m_world;
	void setPhysicWorld(cocos2d::PhysicsWorld* wolrd);
		
		
		
		
		
		
};

#endif // __HELLOWORLD_SCENE_H__
*/
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"
#include "PhysicsShapeCache.h"
#include "Block.h"
#include "ui/UIButton.h"
#include "ui/UIWidget.h"
#include <string>

class HelloWorld : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);



private:
	bool over = true;
	void random_Enemies(float dt);
	void spawnSprite(const std::string &name, Vec2 pos);
	void move(float dt);
	bool onTouchesBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	void onMouseMove(cocos2d::Event *event);
	PhysicsShapeCache *shapeCache;
	Vec2 Pos;
	Vec2 Pos2;
	bool load = true;
	bool onContactBegin(PhysicsContact& contact);
	Sprite*mc;
	Sprite*mc2;
	void setBackGround(float dt);
	void m_a(float dt);
	int i = 0;
	std::string m_sbackground[4] = {/* "background1.png","background2.png" ,"background3.png" ,"background4.png" ,*/"background5.png" ,"background6.png" ,"background7.png" ,"background8.png" };
	int dem() {
		if (i == 2) {
			i = 0;
			return 2;
		}
		else {
			i++;
			return i - 1;
		}

	}
};

#endif // __HELLOWORLD_SCENE_H__
