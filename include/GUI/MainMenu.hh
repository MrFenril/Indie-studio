//
// MainMenu.hh for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/include/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:33:58 2016 Rigolat Sébastien
// Last update Mon May  2 17:33:58 2016 Rigolat Sébastien
//

#ifndef MAINMENU_HH_
# define MAINMENU_HH_

#include <map>
#include "AGUIMenu.hh"

class MainMenu : public AGUIMenu
{
	public:
		explicit MainMenu(SAppContext const &context);
		~MainMenu();

	protected:
		void						onLeaderBoard();
		void						onOption();
		void						onPlay();
		void						onExit();

		virtual void			initGUIelements();
		virtual void			initKeyMap();
};

#endif // !MAINMENU_HH_
