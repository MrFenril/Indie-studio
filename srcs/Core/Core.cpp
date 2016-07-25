//
// Core.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Thu Apr 28 12:53:24 2016 Anaïs Foncel
// Last update Thu Apr 28 12:55:15 2016 Anaïs Foncel
//

#include "Core.hh"

bool onPause;

Core::Core(IrrlichtDevice * const device)
	:	_device(device)
{
	initData();
	initScene();
}

Core::~Core()
{

}

void Core::run()
{
	while (_device->run())
	  {
		_driver->beginScene(true, true, 0);
		_smgr->drawAll();
		Manager::MenuManager::getInstance()->render();
		if (!onPause)
			Manager::GameManager::getInstance()->play();
		_driver->endScene();
	  }
	  _device->drop();
}

void Core::initData()
{
	_smgr = _device->getSceneManager();
	_env = _device->getGUIEnvironment();
	_driver = _device->getVideoDriver();
	_driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
	Manager::MenuManager::createManager(_device);
	onPause = true;
}

void	Core::initScene()
{
	_smgr->addSkyBoxSceneNode(
							   _driver->getTexture("imgs/irrlicht2_up.jpg"),
							   _driver->getTexture("imgs/irrlicht2_dn.jpg"),
							   _driver->getTexture("imgs/irrlicht2_lf.jpg"),
							   _driver->getTexture("imgs/irrlicht2_rt.jpg"),
							   _driver->getTexture("imgs/irrlicht2_ft.jpg"),
							   _driver->getTexture("imgs/irrlicht2_bk.jpg"));

	_smgr->addSkyDomeSceneNode(_driver->getTexture("imgs/skydome.jpg"),16,8,0.95f,2.0f);
}
