//
// IAController.hh for  in /home/mollon_m/rendu/test-lua
//
// Made by Maxime Mollonguet
// Login   <mollon_m@epitech.net>
//
// Started on  Fri Jun 03 18:59:36 2016 Maxime Mollonguet
// Last update Sun Jun  5 22:58:56 2016 Maxime Mollonguet
//

#ifndef IACONTROLLER_HH_
# define IACONTROLLER_HH_

# include <iostream>
# include "ICharacterController.hpp"
# include "LuaScript.hh"

class		IAController
{
private:
  Character*					_character;
  IrrlichtDevice*                               _device;
  u32                                           _now;
  u32                                           _last;
  f32                                           _frameDeltaTime;
  f32                                           _speed;

public:
  IAController();
  ~IAController();
  IAController();

public:
  IAController		&operator=(const IAController &) const;
  virtual void		doAction();

};

#endif /* !IACONTROLLER_HH_ */
