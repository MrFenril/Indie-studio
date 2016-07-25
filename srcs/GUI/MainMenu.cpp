//
// MainMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Mon May  2 17:42:08 2016 Rigolat Sébastien
// Last update Sun Jun  5 23:34:28 2016 Nicolas Pujol
//

#include "MenuManager.hpp"

MainMenu::MainMenu(const SAppContext &context)
	: AGUIMenu(context)
{
	AGUIMenu::initGUIelements();
	initGUIelements();
	initKeyMap();
}

MainMenu::~MainMenu()
{

}

void MainMenu::initGUIelements()
{
	s32 X = 1024 / 2;
	s32 Y = 980 / 2;
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 50, Y + 50, X + 110, (Y + 50) + 30),
						   this,
						   PLAY));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 50, Y + 100, X + 110, (Y + 100) + 30),
						   this,
						   OPTION));
	_selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 50, Y + 150, X + 110, (Y + 150) + 30),
						   this,
						   EXIT));
	setButtonImage(PLAY, "imgs/PLAY.png");
	setButtonImage(OPTION, "imgs/OPTIONS.png");
	setButtonImage(EXIT, "imgs/EXIT.png");
	_currentButton = getElementFromId(PLAY);
	moveSelector();
}

void				MainMenu::initKeyMap()
{
	_mMap[KEY_UP] = &MainMenu::upKeyPressed;
	_mMap[KEY_DOWN] = &MainMenu::downKeyPressed;
	_mMap[KEY_RETURN] = &MainMenu::enterKeyPressed;

	_mMap[KEY_ESCAPE] = static_cast<mPtr>(&MainMenu::onExit);
	_mMap[EXIT] = static_cast<mPtr>(&MainMenu::onExit);
	_mMap[PLAY] = static_cast<mPtr>(&MainMenu::onPlay);
}

void			MainMenu::onLeaderBoard()
{

}

void			MainMenu::onOption()
{
	Manager::MenuManager::getInstance()->switchMenu(OPTION_MENU);
}

void			MainMenu::onPlay()
{
	Manager::MenuManager::getInstance()->switchMenu(PLAY_MENU);
}

void			MainMenu::onExit()
{
	_context.device->closeDevice();
}
