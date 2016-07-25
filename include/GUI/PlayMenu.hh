//
// PlayMenu.hh for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/include/Menus
// 
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
// 
// Started on  Mon May  2 17:33:41 2016 Rigolat Sébastien
// Last update Mon May  2 17:33:41 2016 Rigolat Sébastien
//

#ifndef PLAYMENU_HH_
# define PLAYMENU_HH_

#include "AGUIMenu.hh"

class PlayMenu : public AGUIMenu
{
	public:
		explicit PlayMenu(SAppContext const &context);
		~PlayMenu();

	private:
		void							onContinue();
		void							onNewGame();
		void							onReturn();
		virtual void				initGUIelements();
		virtual void				initKeyMap();
};

#endif // !PLAYMENU_HH_
