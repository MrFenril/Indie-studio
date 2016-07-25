//
// GameManager.cpp for Managers in /home/rigola_s/rendu/C++/cpp_indie_studio/srcs/Common/Managers
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Sat Jun  4 19:55:18 2016 Rigolat Sébastien
// Last update Sat Jun  4 19:55:18 2016 Rigolat Sébastien
//

#include "GameManager.hpp"

Manager::GameManager *Manager::GameManager::_instance = NULL;

void						Manager::GameManager::play()
{
	resetReceiver();
	_map->doAction();
}

void Manager::GameManager::resetReceiver()
{
	_device->setEventReceiver(&_receiver);
}

void						Manager::GameManager::initGame(std::vector<core::stringw> const &players, std::string const &map)
{
	_map = new Map(_device->getSceneManager(), _device->getVideoDriver(), _device, &_receiver);
	_map->load();
	_map->placeObjects();
	(void)players;
	(void)map;
}
