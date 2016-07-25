//
// CharacterInfo.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include/Header
//
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
//
// Started on  Mon May  2 18:32:50 2016 Anaïs Foncel
// Last update Sun Jun  5 22:23:58 2016 Anaïs Foncel
//

#include "CharacterInfo.hh"

CharacterInfo::CharacterInfo()
{
  _id = 0;
  _name = "";
  _color = 0xFFFFFF;
  _score = 0;
  _shield = false;
  _jump = false;
  _movebomb = false;
  _deflagration = 1;
  _countbomb = 1;
}

CharacterInfo::~CharacterInfo()
{

}

void			CharacterInfo::setId(int const &id)
{
  _id = id;
}

void			CharacterInfo::setName(std::string const &name)
{
  _name = name;
}

void			CharacterInfo::setColor(int const &color)
{
  _color = color;
}

void			CharacterInfo::setScore(int const &score)
{
  _score = score;
}

void			CharacterInfo::setShield(bool const &available)
{
  _shield = available;
}

void			CharacterInfo::setJump(bool const &available)
{
  _jump = available;
}

void			CharacterInfo::setMoveBomb(bool const &available)
{
  _movebomb = available;
}

void			CharacterInfo::setDeflagration(int const &number)
{
  _deflagration = number;
}

void			CharacterInfo::setCountBomb(int const &number)
{
  _countbomb = number;
}

int			CharacterInfo::getId() const
{
return (_id);
}

std::string		CharacterInfo::getName() const
{
  return (_name);
}

int			CharacterInfo::getColor() const
{
  return (_color);
}

int			CharacterInfo::getScore() const
{
  return (_score);
}

bool			CharacterInfo::getShield() const
{
  return (_shield);
}

bool			CharacterInfo::getJump() const
{
  return (_jump);
}

bool			CharacterInfo::getMoveBomb() const
{
  return (_movebomb);
}

int			CharacterInfo::getDeflagration() const
{
  return (_deflagration);
}

int			CharacterInfo::getCountBomb() const
{
  return (_countbomb);
}
