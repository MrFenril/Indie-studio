//
// GameManager.hpp for Managers in /home/rigola_s/rendu/C++/cpp_indie_studio/include/Common/Managers
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Sat Jun  4 19:55:58 2016 Rigolat Sébastien
// Last update Fri Jul 15 10:12:18 2016 Rigolat Sébastien
//

#ifndef GAMEMANAGER_HPP_
# define GAMEMANAGER_HPP_

#include "irrlicht.h"
#include "Map.hh"
#include "KeyReceiver.hpp"

using namespace irr;

namespace Manager
{
  class GameManager
  {
  private:
    GameManager(IrrlichtDevice *device, std::vector<core::stringw> const &players, std::string const &map)
      :	_device(device)
    {;
      initGame(players, map);
    }

  public:
    static void									generateGame(IrrlichtDevice *device,	std::vector<core::stringw> const &players, std::string const &map)
    {
      _instance = new GameManager(device, players, map);
    }

    static GameManager					*getInstance() { return _instance; }
    static void									killInstance();

    void												play();

  private:
    static GameManager		*_instance;
    IrrlichtDevice			*_device;
    Map							*_map;
    KeyReceiver			_receiver;

    void							initGame(const std::vector<core::stringw> &players, const std::string &map);
    void							resetReceiver();
  };
}

#endif // !GAMEMANAGER_HPP_
