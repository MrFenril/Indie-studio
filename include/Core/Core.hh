//
// Core.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Thu Apr 28 12:53:41 2016 Anaïs Foncel
// Last update Mon May  2 17:46:53 2016 Anaïs Foncel
//

#ifndef CORE_HH__
# define CORE_HH__

#include <iostream>
#include "GameManager.hpp"
#include "MenuManager.hpp"
#include "irrlicht.h"
#include "Character.hpp"
#include "KeyReceiver.hpp"
#include "PlayerController.hpp"
#include "Plan.hpp"
#include "Object.hh"
#include "Box.hh"
#include "Map.hh"
//#include "Bomb.hh"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

extern bool onPause;

class		Core
{
public:
  Core(IrrlichtDevice	 * const device);
  ~Core();

  void			run();

private:
	IrrlichtDevice						*_device;
	video::IVideoDriver			*_driver;
	scene::ISceneManager		*_smgr;
	gui::IGUIEnvironment		*_env;

	void			initData();
	void			initScene();
};

#endif /* !CORE_HH__ */
