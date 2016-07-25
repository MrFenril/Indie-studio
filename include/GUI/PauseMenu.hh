//
// PauseMenu.hh for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/include/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:34:10 2016 Rigolat Sébastien
// Last update Mon May  2 17:34:10 2016 Rigolat Sébastien
//

#ifndef PAUSEMENU_HH_
# define PAUSEMENU_HH_

#include "AGUIMenu.hh"

extern bool onPause;

class PauseMenu : public AGUIMenu
{
	public:
		explicit PauseMenu(SAppContext const &context);
		~PauseMenu();

	private:
		void							onContinue();
		void							onExit();
		virtual void				initGUIelements();
		virtual void				initKeyMap();
};

#endif // !PAUSEMENU_HH_
