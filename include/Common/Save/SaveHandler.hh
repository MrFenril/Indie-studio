//
// SaveHandler.hh for IndieStudio in /home/pujol_n/rendu/cpp_indie_studio/include
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Thu May 26 22:00:34 2016 Nicolas Pujol
// Last update Sun Jun  5 23:40:18 2016 Rigolat Sébastien
//

#pragma once

# include <map>
# include <chrono>
# include <ctime>
# include <sstream>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <streambuf>
# include "Save.hh"
# include "json.hpp"

class					SaveHandler {

public:

  SaveHandler();
  ~SaveHandler();

  static  std::string			getCurrentTime() const;
  void					          save(Save&);
  Save					          *operator[](const std::string &);
  void					          preload();

private:
  void writeSavefile();
  nlohmann::json saveToJson(Save*);

  std::map<std::string, Save*>		_saves;
};
