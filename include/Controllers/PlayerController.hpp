/*
** PlayerController.hpp for PlayerController in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed May 25 14:48:26 2016 drozdz_b
// Last update Sun Jun  5 23:37:07 2016 Nicolas Pujol
*/

#ifndef PLAYERCONTROLLER_HPP_
#define PLAYERCONTROLLER_HPP_

# include <vector>
# include <map>
# include "irrlicht.h"
# include "Character.hpp"
# include "ICharacterController.hpp"
# include "KeyReceiver.hpp"
# include "MenuManager.hpp"

using namespace irr;

enum e_action_player
{
    MOVE_XN,
    MOVE_XP,
    MOVE_YP,
    MOVE_YN,
    MOVE_ZP,
    MOVE_ZN,
    ACTION,
    MENU,
    NONE
};

class PlayerController : public ICharacterController
{
private:
  e_action_player									_action_player;
  Character*											_character;
  KeyReceiver*									_receiver;
  IrrlichtDevice*									_device;
	std::map<e_action_player, EKEY_CODE>	_map;
  u32															_now;
  u32															_last;
  f32															_frameDeltaTime;
  f32															_speed;

public:
  PlayerController();
  PlayerController(Character*, KeyReceiver*, IrrlichtDevice*);
  PlayerController(Character* character,
    KeyReceiver* receiver, IrrlichtDevice* device, int id);
  virtual ~PlayerController();

  void	setAxisControleX(EKEY_CODE, EKEY_CODE);
  void	setAxisControleY(EKEY_CODE, EKEY_CODE);
  void	setAxisControleZ(EKEY_CODE, EKEY_CODE);

  virtual void	doAction();
};

#endif
