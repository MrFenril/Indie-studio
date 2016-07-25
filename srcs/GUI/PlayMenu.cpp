//
// PlayMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:39:16 2016 Rigolat Sébastien
// Last update Mon May  2 17:39:16 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"

PlayMenu::PlayMenu(SAppContext const &context)
	: AGUIMenu(context)
{
	AGUIMenu::initGUIelements();
	initGUIelements();
	initKeyMap();
}

PlayMenu::~PlayMenu() {}

void PlayMenu::initGUIelements()
{
	s32 X = 1024 / 2;
	s32 Y = 980 / 2;
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 50, Y + 50, X + 110, (Y + 50) + 30),
						   this,
						   LOAD_SAVE));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 50, Y + 100, X + 110, (Y + 100) + 30),
						   this,
						   NEW_GAME));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 50, Y + 150, X + 110, (Y + 150) + 30),
						   this,
						   BACK));
	setButtonImage(LOAD_SAVE, "imgs/CONTINUE.png");
	setButtonImage(NEW_GAME, "imgs/NEW_GAME.png");
	setButtonImage(BACK, "imgs/RETURN.png");
	_currentButton = getElementFromId(NEW_GAME);
	moveSelector();
}

void				PlayMenu::initKeyMap()
{
	_mMap[KEY_UP] = &PlayMenu::upKeyPressed;
	_mMap[KEY_DOWN] = &PlayMenu::downKeyPressed;
	_mMap[KEY_RETURN] = &PlayMenu::enterKeyPressed;

	_mMap[KEY_ESCAPE] = static_cast<mPtr>(&PlayMenu::onReturn);
	_mMap[BACK] = static_cast<mPtr>(&PlayMenu::onReturn);
	_mMap[NEW_GAME] = static_cast<mPtr>(&PlayMenu::onNewGame);
	_mMap[LOAD_SAVE] = static_cast<mPtr>(&PlayMenu::onContinue);
}

void				PlayMenu::onNewGame()
{
	Manager::MenuManager::getInstance()->switchMenu(PLAY_SUB_MENU);
}

void				PlayMenu::onContinue()
{
		Manager::MenuManager::getInstance()->switchMenu(PLAY_SUB_MENU);
}

void				PlayMenu::onReturn()
{
	Manager::MenuManager::getInstance()->switchMenu(MAIN_MENU);
}
