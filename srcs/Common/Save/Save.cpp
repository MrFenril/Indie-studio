//
// Save.cpp for IndieStudio in /home/pujol_n/rendu/cpp_indie_studio/srcs
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Thu May 26 21:30:58 2016 Nicolas Pujol
// Last update Thu May 26 23:20:09 2016 Nicolas Pujol
//

#include "Save.hh"

Save::Save(const std::string &name,
	   const std::string &date,
	   const std::string &map,
	   unsigned int score)
		 :  _name(name), _date(date), _map(map), _score(score)
{
}

std::string			Save::getName() const
{
  return (_name);
}

std::string			Save::getDate() const
{
  return (_date);
}

std::string			Save::getMap() const
{
  return (_map);
}

unsigned int			Save::getScore() const
{
  return (_score);
}

void				Save::setName(const std::string& name)
{
  if (name.empty())
    throw std::invalid_argument("Name is not valid\n");
  _name = name;
}

void				Save::setDate(const std::string& date)
{
  if (date.empty())
    throw std::invalid_argument("Date is not valid\n");
  _date = date;
}

void				Save::setMap(const std::string& map)
{
  if (map.empty())
    throw std::invalid_argument("Map is not valid\n");
  _map = map;
}

void				Save::setScore(unsigned int score)
{
  _score = score;
}
