//
// LuaScript.hh for  in /home/mollon_m/rendu/test-lua
//
// Made by Maxime Mollonguet
// Login   <mollon_m@epitech.net>
//
// Started on  Thu Jun 02 16:27:18 2016 Maxime Mollonguet
// Last update Sun Jun  5 23:06:44 2016 Anaïs Foncel
//

#ifndef LUASCRIPT_HH_
# define LUASCRIPT_HH_

# include <iostream>
# include <string>

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <iostream>

class		LuaScript
{
private:
lua_State	*script_lua;

public:
  LuaScript(const char *);
  ~LuaScript();
  LuaScript(const LuaScript &);
  int		launch() const;

public:
  LuaScript		&operator=(const LuaScript &) const;
};

#endif /* !LUASCRIPT_HH_ */
