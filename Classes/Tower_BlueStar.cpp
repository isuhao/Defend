#include "Tower_BlueStar.h"

#include "Scene_UI.h"
#include "Tower_BlueStar_Bullet.h"

void  Tower_BlueStar::sync_Attack(Vec2 pos, int width)
{
	/*������ת�˶�*/

	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{/*����Ƿ���ײ*/

		if ((*it)->isDone == true)
		{
	
			auto x = *it;
			bullet_queue.erase(it);
			it = bullet_queue.begin();
			target->beenAttacked(x->damage*0.5);

			/*��⸽������*/	
			Scene_UI*sce = (Scene_UI*)sprite->getParent();
			target->runBlueStarBoomAction();

			for (int i = 0;i<sce->monster_queue.size();i++)
			{
				if (160>PublicFunc::cacl_distance(target->sprite->getPosition(), sce->monster_queue[i]->sprite->getPosition()))
				{
					

					if (target->is_Bonus == true && sce->monster_queue[i]->is_Bonus == false)
					{
						continue;
					}
					if (target->is_Bonus == false && sce->monster_queue[i]->is_Bonus == true)
					{
						continue;
					}
					sce->monster_queue[i]->beenAttacked((x)->damage*0.5);
					sce->monster_queue[i]->set_effect_slow_Blue(level);
					
				}
			}

			

			(x)->Destory(target);


		}
		else
		{
			++it;
		}
	}

	float rot = PublicFunc::getRotation(pos, sprite->getPosition());




	++count;
	if (count > attackSpeed)
	{
		count = 0;
		/*�����ڵ�*/
		//	if (target->hp_now<=0)return;
		sprite->runAction(getAttackAction());
		bullet_queue.push_back(new  Tower_BlueStar_Bullet(this->level, sprite->getParent(), rot, sprite->getPosition(), pos));

		SimpleAudioEngine::getInstance()->playEffect("Music/Tower/PStar.mp3");


	}

}

void Tower_BlueStar::sync_None()
{
	for (vector<TowerBullet_UI*>::iterator it = bullet_queue.begin(); it != bullet_queue.end();)
	{
		if ((*it)->isDone == true)
		{
			auto x = *it;
			bullet_queue.erase(it);
			it = bullet_queue.begin();
			(x)->Destory(target);


		}
		else
		{
			++it;
		}

	}

	setTarget(0);

}





void  Tower_BlueStar::initTowerBase()
{
	switch (level)
	{
	case 1: attackRange = 240 / 2; break;
	case 2: attackRange = 260 / 2; break;
	case 3: attackRange = 300 / 2; break;


	default:
		break;
	}

	switch (level)
	{
	case 1: cos_upgrade = 260; break;
	case 2: cos_upgrade = 320; break;
	}


	attackSpeed = 50 - level * 5;

}


void  Tower_BlueStar::setLevel(int lev)
{

	sprite->stopAllActions();

	view_click = 0;


	switch (lev)
	{
	case 1:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("BStar11.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("BStar-11.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("BStar-11.png"));



	}break;
	case 2:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("BStar21.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("BStar-12.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("BStar-12.png"));

	}break;
	case 3:
	{
			  sprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("BStar31.png"));
			  sprite_base->setNormalImage(Sprite::createWithSpriteFrameName("BStar-13.png"));
			  sprite_base->setSelectedImage(Sprite::createWithSpriteFrameName("BStar-13.png"));

	}break;
	}


	if (lev == 1)
	{
		auto ani = Animation::create();
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air11.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air12.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air13.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air14.png"));
		ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air15.png"));


		ani->setDelayPerUnit(0.1);
		ani->setRestoreOriginalFrame(true);
		ani->setLoops(1);

		/* BUG  TMP FIX*/

		if (effect == 0)
		{

			effect = Sprite::create();
			effect->setPosition(sprite->getPosition());
			sprite->getParent()->addChild(effect);
			effect->runAction(Animate::create(ani));
		}
		else
		{
			effect->removeFromParentAndCleanup(true);

			effect = Sprite::create();
			effect->setPosition(sprite->getPosition());
			sprite->getParent()->addChild(effect);
			effect->runAction(Animate::create(ani));


		}

	}
	else
	{
		//if (this->level < lev)
		{

			auto ani = Animation::create();
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air11.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air12.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air13.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air14.png"));
			ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air15.png"));

			ani->setDelayPerUnit(0.03);
			ani->setRestoreOriginalFrame(true);
			ani->setLoops(1);


			/* BUG  TMP FIX*/

			if (effect == 0)
			{

				effect = Sprite::create();
				effect->setPosition(sprite->getPosition());
				sprite->getParent()->addChild(effect);
				effect->runAction(Animate::create(ani));
			}
			else
			{
				effect->removeFromParentAndCleanup(true);

				effect = Sprite::create();
				effect->setPosition(sprite->getPosition());
				sprite->getParent()->addChild(effect);
				effect->runAction(Animate::create(ani));


			}

		}
	}



	this->level = lev;
	initTowerBase();




}





Tower_BlueStar::Tower_BlueStar(Node*scene, Vec2 pos, int lev)
{
	view_click = 0;
	count = 0;

	cos_upgrade = 260;

	this->level = lev;
	effect = 0;

	initTowerBase();

	sprite = Sprite::createWithSpriteFrameName("Shit11.png");

	sprite;;

	sprite_base = MenuItemSprite::create(Sprite::createWithSpriteFrameName("BShit-11.png"), Sprite::createWithSpriteFrameName("BShit-11.png")
		, [=](Ref*p)
	{
		if (view_click == 0)
		{
			((Scene_UI*)scene)->view_click_gloal->setAllVisFalse();

			view_click = new View_Click_Tower(7, this);
		}

	});

	sprite_base->setPosition(pos);
	sprite_base;;

	auto ss = Menu::create(sprite_base, nullptr);
	ss->setPosition(0, 0);
	scene->addChild(ss);


	//Sprite::createWithSpriteFrameName("Bottle-11.png");



	scene->addChild(sprite);
	sprite->setPosition(pos);

	sprite_upgrade = Sprite::createWithSpriteFrameName("showupgrade02.png");

	scene->addChild(sprite_upgrade);
	sprite_upgrade->setPosition(sprite->getPositionX(), sprite->getPositionY() + sprite->getContentSize().height);
	auto ani2 = Animation::create();
	ani2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("showupgrade02.png"));
	ani2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("showupgrade01.png"));
	ani2->setDelayPerUnit(0.1);
	ani2->setRestoreOriginalFrame(false);
	ani2->setLoops(-1);
	sprite_upgrade->runAction(Animate::create(ani2));
	sprite_upgrade->setVisible(false);
	setLevel(lev);


}





Animate*Tower_BlueStar::getAttackAction()
{

	string str = "";



	switch (level)
	{
	case 1:
	{
			  str = "BStar1";


	}break;
	case 2:
	{
			  str = "BStar2";
	}break;
	case 3:
	{
			  str = "BStar3";
	}break;
	}


	auto ani = Animation::create();
	//ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "1.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "2.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(str + "3.png"));


	ani->setDelayPerUnit(0.05);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);

	auto an = Animate::create(ani);
	return an;


}


void Tower_BlueStar::setClick(bool t)
{
	if (t)
	{
		view_click = new View_Click_Tower(1, this);
	}
	else
	{
		if (view_click != 0)
		{
			view_click->Destory();
		}
		view_click = 0;
	}

}

void Tower_BlueStar::clearBullet()
{

/*
	for (int i = 0; i < bullet_queue.size(); i++)
	{
	bullet_queue[i]->Destory(0);

	}
	bullet_queue.clear();
	*/

	/*

	tip:
	maybe BUG*/
}


void  Tower_BlueStar::Destory()
{

	Scene_UI*sc = (Scene_UI*)sprite->getParent();

	for (vector<Tower_UI*>::iterator it = sc->tower_queue.begin(); it != sc->tower_queue.end(); ++it)
	{

		if ((*it) == this)
		{
			sc->tower_queue.erase(it);
			break;
		}
	}


xx:
	setClick(false);

	setTarget(0);
	for (int i = 0; i < bullet_queue.size(); i++)
	{
		bullet_queue[i]->Destory(target);

	}


	bullet_queue.clear();

	auto x = (Scene_UI*)sprite->getParent();

	x->data->pop(PublicFunc::convertToX(sprite->getPosition().x),
		PublicFunc::convertToY(sprite->getPosition().y));


	auto ani = Animation::create();
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air01.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air02.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air03.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air04.png"));
	ani->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("air05.png"));

	ani->setDelayPerUnit(0.1);
	ani->setRestoreOriginalFrame(true);
	ani->setLoops(1);
	auto an = Animate::create(ani);

	sprite_base->removeFromParentAndCleanup(true);
	effect->removeFromParentAndCleanup(true);
	sprite_upgrade->removeFromParentAndCleanup(true);


	sprite->runAction(Sequence::create(an, CallFunc::create([=]
	{
		sprite->removeFromParentAndCleanup(true);

		delete this;

	}), nullptr));








}
