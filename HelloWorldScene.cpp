
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "PhysicsShapeCache.h"

USING_NS_CC;



Scene* HelloWorld::createScene()
{
	// create the scene with physics enabled
	auto scene = Scene::createWithPhysics();

	// set gravity
	//scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));

	// optional: set debug draw
	// scene->getPhysicsWorld()->setDebugDrawMask(0xffff);

	auto layer = HelloWorld::create();
	scene->addChild(layer);

	return scene;
}


bool HelloWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto pos = Vec2(Director::getInstance()->getVisibleSize()) / 2 +
		Director::getInstance()->getVisibleOrigin();

	int k = random() % 4;
	const std::string &name = m_sbackground[k];
	auto bgr = Sprite::create(name);
	bgr->setPosition(0, 0);
	bgr->setAnchorPoint(Vec2(0, 0));
	bgr->setZOrder(-1);
	auto moveByAction = MoveBy::create(1, Vec2(0, -200));
	auto rp = RepeatForever::create(moveByAction);
	this->addChild(bgr);

	k = random() % 4;
	const std::string &name2 = m_sbackground[k];
	auto bgr2 = Sprite::create(name2);
	bgr2->setPosition(0, 1200);
	bgr2->setAnchorPoint(Vec2(0, 0));
	bgr2->setZOrder(-1);
	auto moveByAction2 = MoveBy::create(1, Vec2(0, -200));
	auto rp2 = RepeatForever::create(moveByAction2);
	this->addChild(bgr2);


	bgr->runAction(rp);
	bgr2->runAction(rp2);

	// Load shapes
	if (load) {
		shapeCache = PhysicsShapeCache::getInstance();
		shapeCache->addShapesWithFile("shapes.plist");
		load = false;
	}


	// Load background image

	cocos2d::experimental::AudioEngine::play2d("background.mp3", true);

	// init main characters
	auto mc_physicsBody = shapeCache->createBodyWithName("spaceship");
	mc = Sprite::create("spaceship.png");
	mc_physicsBody->setDynamic(true);
	mc_physicsBody->setGravityEnable(false);
	mc_physicsBody->setMass(20000);
	mc->setPhysicsBody(mc_physicsBody);

	mc_physicsBody->setCollisionBitmask(0);
	mc_physicsBody->setContactTestBitmask(true);
	mc->setAnchorPoint(Vec2(0.5, 0.5));
	mc->setPosition(Vec2(visibleSize.width / 2, 100));
	auto rotate1 = RotateBy::create(0.5, 10);
	auto rotate2 = RotateBy::create(1, -20);
	auto action = Sequence::create(rotate1, rotate2, rotate1, nullptr);
	auto action_rp = RepeatForever::create(action);
	addChild(mc);
	mc->runAction(action_rp);

	
	mc2 = Sprite::create("ball1.png");
	mc2->setScale(0.5);
	auto mc2_physicsBody = PhysicsBody::createCircle(mc2->getContentSize().width/2*0.5);
	mc_physicsBody->setContactTestBitmask(true);
	mc2_physicsBody->setGravityEnable(false);
	mc2_physicsBody->setMass(200000);
	mc2->setPhysicsBody(mc2_physicsBody);
	addChild(mc2);
		 
	

	auto listener_mouse = EventListenerMouse::create();
	auto listener_contact = EventListenerPhysicsContact::create();


	listener_contact->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
	listener_mouse->onMouseMove = CC_CALLBACK_1(HelloWorld::onMouseMove, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_contact, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener_mouse, this);



	this->schedule(schedule_selector(HelloWorld::m_a), 0.1);
	this->schedule(schedule_selector(HelloWorld::setBackGround), 1200 / 200);

	this->schedule(schedule_selector(HelloWorld::LoadMap), 3);
	return true;
}





void HelloWorld::m_a(float dt) {
	
	mc2->getPhysicsBody()->setVelocity(Vec2(0,0));
}

bool HelloWorld::onContactBegin(PhysicsContact& contact) {
	
	auto A = contact.getShapeA();
	auto B = contact.getShapeB();
	if (A->getCollisionBitmask() == 2 && B->getCollisionBitmask() == 0) {
		
		if (over) {
			//over = false;
			cocos2d::experimental::AudioEngine::stopAll();
			int id = cocos2d::experimental::AudioEngine::play2d("gameover.mp3");
			cocos2d::experimental::AudioEngine::setVolume(id, 0.5);
			
		}
		auto gameover = Sprite::create("gameover.png");
		gameover->setScale(0.5);
		gameover->setPosition(Vec2(350, 600));
		gameover->setAnchorPoint(Vec2(0.5, 0.5));
		addChild(gameover);
		
		auto button = ui::Button::create("playagain.png");
		auto bd = PhysicsBody::createEdgeBox(button->getContentSize());
		//button->setPhysicsBody(bd);
		this->unschedule(schedule_selector(HelloWorld::random_Enemies));
		button->setPosition(Vec2(350, 50));
		button->setAnchorPoint(Vec2(0.5, 0));
		button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				//Director::getInstance()->stopAnimation();
				removeAllChildrenWithCleanup(true);
				init();
				break;
			default:
				break;
			}
		});
		addChild(button);
		
	}
	return true;
}

void HelloWorld::onMouseMove(cocos2d::Event * event)
{
	auto e = (EventMouse*)event;
	auto Pos = mc2->getPosition();
	auto Pos2 = e->getLocationInView();
	mc2->getPhysicsBody()->setVelocity((Pos2 - Pos)/0.05);
}

void HelloWorld::getScore(float dt)
{
	score += 1;
}

#define WIDTH 1200
void HelloWorld::LoadMap(float)
{
	/*for (int i = 0; i < arr.size(); i++)
	{
		removeChild(arr.at(i));
		delete arr.at(i);
	}*/
	//arr.clear();
	int width = WIDTH;
	for (int i = 0; i < 5; i++)
	{
		 
		Block ban1(shapeCache, "watermelon");
		Block ban2(shapeCache, "watermelon");
		ban1.getSprite()->setPosition(Vect(350, width));
		ban2.getSprite()->setPosition(Vect(400, width));
		addChild(ban1.getSprite());
		addChild(ban2.getSprite());
		width += 50;
	}

}
void HelloWorld::random_Enemies(float dt)
{
	/*Size visibleSize = Director::getInstance()->getVisibleSize();
	Block a(shapeCache);
	Block b(shapeCache);
	cocos2d::experimental::AudioEngine::play2d("sound.mp3");

	

	a.getSprite()->setPosition( visibleSize.width / 2 + i * 50,1000);
	b.getSprite()->setPosition(visibleSize.width / 2 - i * 50,1000);
	addChild(a.getSprite());
	addChild(b.getSprite());
	if (k == 0) {
		i++;
		if (i == 5) k = 1;
	}
	else {
		i--;
		if (i == 0) k = 0;
	}*/
}

void HelloWorld::spawnSprite(const std::string &name, Vec2 pos)
{
	// create a sprite with the given image name
	auto sprite = Sprite::create(name + ".png");
	sprite->setAnchorPoint(Vec2(0.5,0.5));
	PhysicsBody* body = shapeCache->createBodyWithName(name);
	sprite->setPhysicsBody(body);
	sprite->setPosition(pos);
	addChild(sprite);
}

void HelloWorld::setBackGround(float dt)
{
	Sprite::create();
	int k = random() % 4;
	const std::string &name= m_sbackground[k];
	auto bgr = Sprite::create(name);
	bgr->setPosition(0, 1200);
	bgr->setAnchorPoint(Vec2(0, 0));
	bgr->setZOrder(-1);
	auto moveByAction = MoveBy::create(1, Vec2(0, -200));
	auto rp = RepeatForever::create(moveByAction);
	this->addChild(bgr);
	bgr->runAction(rp);
}

