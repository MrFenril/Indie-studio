//
// PlaySubMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:40:34 2016 Rigolat Sébastien
// Last update Sun Jun  5 23:24:42 2016 Anaïs Foncel
//

#include "MenuManager.hpp"
#include "GameManager.hpp"

PlaySubMenu::PlaySubMenu(SAppContext const &context)
  : AGUIMenu(context)
{
  _nbPlayer = 1;
  AGUIMenu::initGUIelements();
  initGUIelements();
  initKeyMap();
}

PlaySubMenu::~PlaySubMenu() {}

void				PlaySubMenu::initGUIelements()
{
  s32 X = 1024 / 2;
  s32 Y = 980 / 2;

  _selectableButtons.push_back(Environment->addButton(core::rect<s32>(X - 160, Y + 220, X,  (Y + 250)),
						      this,
						      PLAY));
  _selectableButtons.push_back(Environment->addButton(core::rect<s32>(X + 20, Y + 220, X + 180,  (Y + 250)),
						      this,
						      BACK));
  Environment->addStaticText(L"Nombre de joueur : ",
			     core::rect<s32>(600, 540, 650, 650),
			     false,
			     true,
			     this)->setOverrideColor(video::SColor(255, 255, 255, 255));
  _names.push_back(Environment->addEditBox(L"Player 1", core::rect<s32>(400, 520, 550, 540), true, this));
  _names.push_back(Environment->addEditBox(L"Player 2", core::rect<s32>(400, 550, 550, 570), true, this));
  _names.at(1)->setVisible(false);
  Environment->addButton(core::rect<s32>(X + 150, 500, 700, 500 + 32),
			 this,
			 INC);
  Environment->addButton(core::rect<s32>(X + 150, 570, 700, 570 + 32),
			 this,
			 DEC);
  _nbTxt = Environment->addStaticText(core::stringw(_nbPlayer).c_str(),
				      core::rect<s32>(670, 545, 700, 660),
				      false,
				      true,
				      this);
  _nbTxt->setOverrideColor(video::SColor(255, 255, 255, 255));
  setButtonImage(PLAY, "imgs/START.png");
  setButtonImage(BACK, "imgs/RETURN.png");
  setButtonImage(INC, "imgs/PLUS.png");
  setButtonImage(DEC, "imgs/MINUS.png");
  _currentButton = getElementFromId(PLAY);
  moveSelector();
}

void				PlaySubMenu::initKeyMap()
{
  _mMap[KEY_UP] = &PlaySubMenu::upKeyPressed;
  _mMap[KEY_DOWN] = &PlaySubMenu::downKeyPressed;
  _mMap[KEY_RETURN] = &PlaySubMenu::enterKeyPressed;
  _mMap[KEY_ESCAPE] = static_cast<mPtr>(&PlaySubMenu::onReturn);

  _mMap[PLAY] = static_cast<mPtr>(&PlaySubMenu::onStart);
  _mMap[BACK] = static_cast<mPtr>(&PlaySubMenu::onReturn);
  _mMap[INC] = static_cast<mPtr>(&PlaySubMenu::incPlayerNb);
  _mMap[DEC] = static_cast<mPtr>(&PlaySubMenu::decPlayerNb);
}

void				PlaySubMenu::onStart()
{
  std::vector<core::stringw>		names;
  IrrlichtDevice			*device;

  device = Manager::MenuManager::getInstance()->getDevice();
  names.push_back(_names.at(0)->getText());
  names.push_back(_names.at(1)->getText());

  Manager::MenuManager::getInstance()->switchMenu(PAUSE_MENU);
  Manager::MenuManager::getInstance()->getCurrent()->setVisible(false);
  Manager::GameManager::generateGame(device, names, "map.txt");
  onPause = false;
}

void				PlaySubMenu::incPlayerNb()
{
  _nbPlayer + 1 > 2 ? (_nbPlayer = 1) : ++_nbPlayer;
  if (_nbPlayer == 2)
    _names.at(1)->setVisible(true);
  else
    _names.at(1)->setVisible(false);
  _nbTxt->setText(core::stringw(_nbPlayer).c_str());
}

void				PlaySubMenu::decPlayerNb()
{
  _nbPlayer - 1 < 1 ? _nbPlayer : --_nbPlayer;
  if (_nbPlayer == 2)
    _names.at(1)->setVisible(true);
  else
    _names.at(1)->setVisible(false);
  _nbTxt->setText(core::stringw(_nbPlayer).c_str());
}

void				PlaySubMenu::onReturn()
{
  Manager::MenuManager::getInstance()->switchMenu(PLAY_MENU);
}
