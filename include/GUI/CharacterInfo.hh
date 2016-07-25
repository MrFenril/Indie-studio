//
// CharacterInfo.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:27:00 2016 Anaïs Foncel
// Last update Thu May  5 15:57:01 2016 Anaïs Foncel
//

#ifndef CHARACTERINFO_HH__
# define CHARACTERINFO_HH__

# include <iostream>
# include <string>

class		CharacterInfo
{
private:
  int			_id;
  std::string		_name;
  int			_color;
  int			_score;
  bool			_shield;
  bool			_jump;
  bool			_movebomb;
  int			_deflagration;
  int			_countbomb;

public:
  CharacterInfo();
  ~CharacterInfo();

  void			setId(int const &id);
  void			setName(std::string const &name);
  void			setColor(int const &color);
  void			setScore(int const &score);

  void			setShield(bool const &available);
  void			setJump(bool const &available);
  void			setMoveBomb(bool const &available);
  void			setDeflagration(int const &number);
  void			setCountBomb(int const &number);

  int			getId() const;
  std::string		getName() const;
  int			getColor() const;
  int			getScore() const;

  bool			getShield() const;
  bool			getJump() const;
  bool			getMoveBomb() const;
  int			getDeflagration() const;
  int			getCountBomb() const;
};

#endif /* !CHARACTERINFO_HH__ */
