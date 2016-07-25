//
// Map.hh for indie_studio in /home/monder_s/C++/cpp_indie_studio/include
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Fri Jun  3 16:42:32 2016 Sacha Sacha Monderer
// Last update Sun Jun  5 23:13:47 2016 Anaïs Foncel
//

#ifndef MAP_HH_
# define MAP_HH_

#include "Object.hh"
#include "PlayerController.hpp"

class	Map
{
  std::list<Object*>			_map;
  Object*				_plan;
  std::list<ICharacterController*>	_controllers;
  KeyReceiver				*_receiver;
  scene::ISceneManager			*_smgr;
  std::string				_path;
  video::IVideoDriver 			*_driver;
  IrrlichtDevice 			*_device;
  std::vector<int> 			_vect;
  std::list<Object*>			_charList;
  std::list<Object*>			_objList;

public:
  Map(scene::ISceneManager*, video::IVideoDriver*, IrrlichtDevice*, KeyReceiver*);
  ~Map();

  std::list<Object*> getMap() const;
  void	doAction();

  void	load(const std::string& path = "map/map.txt");
  void	placeObjects();
  Object*	createObject(char c, int& nbChar, int& i);
  Object*	createCharacter(int& nbChar);
  void		setCollisionList(Object* character, std::list<Object*>::iterator);
  void		setCharList();
  void		setObjList();
  void		checkObject();
};

#endif /* MAP_HH_ */
