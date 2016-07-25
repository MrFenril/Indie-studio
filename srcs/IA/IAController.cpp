//
// IAController.cpp for  in /home/mollon_m/rendu/test-lua
//
// Made by Maxime Mollonguet
// Login   <mollon_m@epitech.net>
//
// Started on  Fri Jun 03 18:59:36 2016 Maxime Mollonguet
// Last update Sun Jun  5 23:32:01 2016 Maxime Mollonguet
//

#include "IAController.hh"

IAController::IAController()
{
  _character = NULL;
  _speed = 10.f;
}

IAController::IAController()
{
  this->_action_player = NONE;
  this->_character = character;
  this->_receiver = receiver;
  this->_device = device;
  this->_last = this->_device->getTimer()->getTime();
  _speed = 10.f;
}

IAController::~IAController()
{
}

IAController	&IAController::operator=(const IAController &other) const
{
  return (*new IAController(other));
}

void		IAController::doAction()
{
  LuaScript	script("IA.lua");
  int		sum;

  _now = _device->getTimer()->getTime();
  _frameDeltaTime = (f32)(_now - _last) / 1000.f;
  _last = _now;
  while (1)
    {
      sum = script.launch();
      if (sum = 1)
	_character->move(-(_speed * _frameDeltaTime), 0);
      else if (sum = 2)
	_character->move((_speed * _frameDeltaTime), 0);
      else if (sum = 3)
	_character->move(0, 0, -(_speed * _frameDeltaTime));
      else if (sum = 4)
	_character->move(0, 0, (_speed * _frameDeltaTime));
      else
	_character->stati();
      _character->updateAnim();
    }
}
