/*
** Plan.hpp for Plan in /home/drozdz_b/Documents/TestIrrlitch7
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Jun 01 16:08:51 2016 drozdz_b
// Last update Sun Jun  5 22:33:01 2016 Anaïs Foncel
*/

#ifndef PLAN_HPP_
#define PLAN_HPP_

#include <list>

#include "Object.hh"

class Plan : public Object
{
protected:
  scene::ISceneManager		*_smgr;
  std::list<Object*>		_objects;

public:
  Plan(scene::ISceneNode * const node, scene::ISceneManager * const smgr);
  Plan(scene::ISceneManager * const smgr, video::IVideoDriver * const driver);
  ~Plan();
};

#endif
