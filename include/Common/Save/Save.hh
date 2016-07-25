//
// Save.hh for Save in /home/pujol_n/rendu/cpp_indie_studio/include
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Thu May 26 21:31:14 2016 Nicolas Pujol
// Last update Thu May 26 23:15:16 2016 Nicolas Pujol
//

#pragma once

# include <string>
# include <stdexcept>


class			Save {

public:

  Save(const std::string &, const std::string &, const std::string &, unsigned int);
  ~Save() {}

  std::string		       getName() const;
  std::string		       getDate() const;
  std::string		       getMap() const;
  unsigned int		     getScore() const;
  void			           setName(const std::string&);
  void			           setDate(const std::string&);
  void			           setMap(const std::string&);
  void			           setScore(unsigned int);

private:
  std::string		_name;
  std::string		_date;
  std::string		_map;
  unsigned int		_score;
};
