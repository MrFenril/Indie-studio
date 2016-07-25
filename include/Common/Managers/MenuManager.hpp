//
// Singleton.hh for Manager in /home/rigola_s/test_repo/test_irrlicht/test_indie/include/Manager
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Thu May  5 17:55:37 2016 Rigolat Sébastien
// Last update Fri Jul 15 10:12:51 2016 Rigolat Sébastien
//

#ifndef MANAGER_HH_
# define MANAGER_HH_

#include "AGUIMenu.hh"
#include "MainMenu.hh"
#include "PlayMenu.hh"
#include "PlaySubMenu.hh"
#include "PauseMenu.hh"


namespace Manager
{
  class MenuManager
  {
  private:
    MenuManager(IrrlichtDevice *device)
      : _device(device)
    {
      initMenus();
    }

    ~MenuManager() { }

  public:
    static void									createManager(IrrlichtDevice *device)
    {
      _instance = new MenuManager(device);
    }
    static MenuManager					*getInstance() { return _instance; }
    static void									killInstance();

    void												render() const;
    void												switchMenu(MenuType type);
    void												pause();
    void												unPause();

    AGUIMenu									*getCurrent() const;
    IrrlichtDevice								*getDevice() const;

  protected:
    static Manager::MenuManager				*_instance;
    AGUIMenu													*_previous;
    AGUIMenu													*_current;
    std::map<MenuType, AGUIMenu *>		_menuMap;
    IrrlichtDevice												*_device;

    void												initMenus();
  };
}

#endif // !MANAGER_HH_
