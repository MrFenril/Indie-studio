//
// LuaScript.cpp for  in /home/mollon_m/rendu/test-lua
//
// Made by Maxime Mollonguet
// Login   <mollon_m@epitech.net>
//
// Started on  Thu Jun 02 16:27:18 2016 Maxime Mollonguet
// Last update Sun Jun  5 23:06:36 2016 Anaïs Foncel
//

#include "LuaScript.hh"

LuaScript::LuaScript(const char *filename)
{
  script_lua = luaL_newstate();
  luaL_openlibs(script_lua);
  if (luaL_dofile(script_lua, filename))
    {
      std::cerr << lua_tostring(script_lua, -1) << std::endl;
    }
}

LuaScript::LuaScript(const LuaScript &other)
{
  (void)other;
}

LuaScript::~LuaScript()
{
  lua_close(script_lua);
}

int		LuaScript::launch() const
{
  int		sum;

  lua_getglobal(script_lua, "ranval");
  lua_call(script_lua, 0, 1);

  sum = (int)lua_tointeger(script_lua, -1);
  lua_pop(script_lua, 1);
  return (sum);
}

LuaScript	&LuaScript::operator=(const LuaScript &other) const
{
  return (*new LuaScript(other));
}
