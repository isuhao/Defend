#include "Monster_fly_boss_yellow.h"

#include "Scene_UI.h"

void Monster_fly_boss_yellow::runMoveAction()
{
	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("fly_boss_yellow01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("fly_boss_yellow02.png"));
	ani->setDelayPerUnit(3.0 / 30.0);
	ani->setRestoreOriginalFrame(false);
	ani->setLoops(-1);

	auto an = Animate::create(ani);
	sprite->runAction(an);

}





Monster_fly_boss_yellow::Monster_fly_boss_yellow(int t_hp, Node*scene, Vec2 pos, queue<Vec2> que)
{

	string str = "fly_boss_yellow01.png";


	initBase();
	hp = t_hp;
	hp_now = hp;

	queue_way = que;
	sprite = Sprite::createWithSpriteFrameName(str);
	scene->addChild(sprite);
	sprite->setPosition(pos);

	sprite;;


	Scene_UI*sce = (Scene_UI*)scene;

	menu = MenuItemSprite::create(Sprite::create("1.png"), Sprite::create("1.png"), [=](Ref*)
	{
		is_selected = !is_selected;

		if (is_selected)
		{
			for (int i = 0; i < sce->monster_queue.size(); i++)
			{
				;
				{
					((Bonus_UI*)sce->monster_queue[i])->sprite_selected->setVisible(false);
					((Bonus_UI*)sce->monster_queue[i])->is_selected = false;

				}

			}

			is_selected = true;
			sprite_selected->setVisible(true);
			return;
		}
		sprite_selected->setVisible(false);

	});
	menu->setPosition(sprite->getContentSize().width/2,sprite->getContentSize().height/2);


	men = Menu::create(menu, nullptr);
	men->setPosition(0, 0);
	sprite->addChild(men);


	menu->setScale(sprite->getContentSize().height / 2.0 / 40.0);



	sprite_selected = Sprite::createWithSpriteFrameName("point01.png");

	{
		auto ani = Animation::create();
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("point01.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("point02.png"));
		ani->setDelayPerUnit(3.0 / 30.0);
		ani->setRestoreOriginalFrame(false);
		ani->setLoops(-1);

		sprite_selected->runAction(Animate::create(ani));
	}
	sprite_selected->setPosition(sprite->getContentSize().width / 2, sprite->getContentSize().height);
	sprite->addChild(sprite_selected);
	sprite_selected->setVisible(false);








	hp_sprite_2 = Sprite::createWithSpriteFrameName("MonsterHP02.png");
	hp_sprite_2->setPosition(Vec2(sprite->getContentSize().width / 2, sprite->getContentSize().height - 5));
	sprite->addChild(hp_sprite_2);



	hp_sprite_1 = Sprite::createWithSpriteFrameName("MonsterHP01.png");
	hp_sprite_1->setPosition(Vec2(sprite->getContentSize().width / 2, sprite->getContentSize().height - 5));
	sprite->addChild(hp_sprite_1);



	hp_sprite_1->setAnchorPoint(Vec2(0, 0.5));


	hp_sprite_2->setAnchorPoint(Vec2(0, 0.5));


	hp_sprite_1->setVisible(false);
	hp_sprite_2->setVisible(false);

	hp_sprite_1->setScaleY(0.7);

	resetWay();

	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("mcm01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("mcm02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("mcm02.png"));


	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);
	sprite->runAction(Animate::create(ani));


/*
	hp_sprite_1;;
	hp_sprite_2;;
*/

	



}




