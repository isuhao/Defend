#include "Scene_4_14.h"


#include "Bonus_4_1.h"
#include "Bonus_4_2.h"
#include "Bonus_4_3.h"
#include "Bonus_4_4.h"
#include "Bonus_4_5.h"
#include "Bonus_4_6.h"
#include "Bonus_4_7.h"




Scene* Scene_4_14::createScene()
{
	auto scene = Scene::create();
	auto layer = Scene_4_14::create();
	scene->addChild(layer);
	return scene;
}




void Scene_4_14::initQueue_way()
{

	queue_way.push(Vec2(10, 0));
	queue_way.push(Vec2(9, 0));
	queue_way.push(Vec2(8, 0));
	queue_way.push(Vec2(7, 0));
	queue_way.push(Vec2(6, 0));
	queue_way.push(Vec2(5, 0));
	queue_way.push(Vec2(4, 0));
	queue_way.push(Vec2(4, 1));

	queue_way.push(Vec2(5, 1));
	queue_way.push(Vec2(6, 1));
	queue_way.push(Vec2(7, 1));
	queue_way.push(Vec2(8, 1));
	queue_way.push(Vec2(9, 1));

	queue_way.push(Vec2(9, 2));
	queue_way.push(Vec2(8, 2));

	queue_way.push(Vec2(8, 3));
	queue_way.push(Vec2(8, 4));

	queue_way.push(Vec2(7, 4));
	queue_way.push(Vec2(6, 4));
	queue_way.push(Vec2(5, 4));
	queue_way.push(Vec2(4, 4));
	queue_way.push(Vec2(3, 4));
	queue_way.push(Vec2(2, 4));
	queue_way.push(Vec2(1, 4));

	queue_way.push(Vec2(1, 5));



	data->push_back(Vec2(0, 0));
	data->push_back(Vec2(1, 0));
	data->push_back(Vec2(2, 0));
	data->push_back(Vec2(3, 0));


	data->push_back(Vec2(11, 0));
	
}


void Scene_4_14::initAbleTower()
{
	view_click_gloal->tower_able.push_back(2);
	view_click_gloal->tower_able.push_back(7);
	view_click_gloal->tower_able.push_back(12);
	view_click_gloal->tower_able.push_back(15);
}


void Scene_4_14::initBonus()
{
	
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(0, 6)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(4, 6)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(5, 6)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(8, 6)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(9, 6)));

	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(0, 5)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(2, 5)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(4, 5)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(5, 5)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(6, 5)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(8, 5)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(9, 5)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(10, 5)));

	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(0, 4)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(11, 4)));

	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(2, 3)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(4, 3)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(11, 3)));

	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(9, 3)));



	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(0, 2)));
	monster_queue.push_back(new  Bonus_4_2(this, PublicFunc::convertToPoint(4, 2)));
	monster_queue.push_back(new  Bonus_4_1(this, PublicFunc::convertToPoint(5, 2)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(6, 2)));

	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(2, 1)));
	monster_queue.push_back(new  Bonus_4_6(this, PublicFunc::convertToPoint(10, 1)));




}

