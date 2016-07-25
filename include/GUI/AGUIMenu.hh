//
// AMenu.hpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/include/Menus
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Mon May  2 17:43:17 2016 Rigolat Sébastien
// Last update Mon Jun 20 23:44:22 2016 Rigolat Sébastien
//

#ifndef AGUIMenu_HH_
# define AGUIMenu_HH_

#include <map>
#include <list>
#include <iostream>
#include "irrlicht.h"

using namespace irr;

enum MenuType
  {
    MAIN_MENU = -30,
    PLAY_MENU,
    OPTION_MENU,
    PLAY_SUB_MENU,
    LEADER_BOARD_MENU,
    PAUSE_MENU
  };

enum ButtonType
  {
    PLAY = -16,
    OPTION,
    LEADER_BOARD,
    EXIT,
    BACK,
    NEW_GAME,
    LOAD_SAVE,
    INC,
    DEC,
    SAVE,
    CONTINUE,
    BACKGROUND,
    GET_MAP
  };

typedef struct			SAppContext
{
public:
  SAppContext(IrrlichtDevice * const device,
	      gui::EGUI_ELEMENT_TYPE const &type,
	      MenuType const &id,
	      gui::IGUIElement * const parent,
	      core::rect< s32 > const &rect)
  {
    this->device = device;
    this->type = type;
    this->id = id;
    this->parent = parent;
    this->rect = rect;
  }

  IrrlichtDevice		*device;
  gui::EGUI_ELEMENT_TYPE	type;
  MenuType			id;
  gui::IGUIElement		*parent;
  core::rect<s32>		rect;
}								SAppContext;


class AGUIMenu : public gui::IGUIElement
{
public:
  typedef void (AGUIMenu::*mPtr)();

public:
  explicit AGUIMenu(SAppContext const &context);
  virtual ~AGUIMenu();

  virtual bool						OnEvent(const SEvent& event);
  virtual void						draw();

  gui::IGUIImage			*getSelectorImage() const;
  gui::IGUIImage			*getBackgroundImage() const;

  void								setSelectorImage(video::ITexture * const t);
  void								setBackgroundImage(video::ITexture * const t);

protected:
  video::IVideoDriver						*_driver;
  gui::IGUIImage								*_selector;
  gui::IGUIImage								*_background;
  gui::IGUIElement							*_currentButton;
  SAppContext									_context;
  core::list<IGUIElement *>			_selectableButtons;
  std::map<int, mPtr>						_mMap;

  virtual void				initKeyMap() = 0;
  virtual bool				onGUIEvent(const SEvent &e);
  virtual bool				onButtonClicked(s32 ID);

  virtual void				upKeyPressed();
  virtual void				downKeyPressed();
  virtual void				enterKeyPressed();

  virtual bool				onButtonHover(gui::IGUIElement *button);

  virtual void				moveSelector();
  virtual bool				keyInputTreatment(const SEvent &e);
  virtual void				initGUIelements();
  virtual void				setButtonImage(int ID, std::string const &path);
};

#endif // !AGUIMenu_HH_
