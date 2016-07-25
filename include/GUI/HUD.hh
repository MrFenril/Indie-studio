//
// HUD.hh for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:28:07 2016 Anaïs Foncel
// Last update Sun Jun  5 22:15:00 2016 Anaïs Foncel
//

#ifndef HUD_HH__
# define HUD_HH__

# include <iostream>
# include <string>
# include <vector>
# include <irrlicht.h>
# include <rect.h>
# include "CharacterInfo.hh"
# include "GUIBonus.hh"

# define SIZE_IMAGE	(40)

using namespace irr;

class		HUD
{
private:
  IrrlichtDevice		*_device;
  video::IVideoDriver		*_driver;
  std::vector<CharacterInfo>	_characters;
  GUIBonus			*_bonus;
  int				_size_winX;
  int				_size_winY;
  int				_size_HUD_Y;
  int				_size_mHUD_X;

  void			displayScore(CharacterInfo const &character) const;
  void			displayName(CharacterInfo const &character) const;

  void			displayBonusBomb(CharacterInfo const &character) const;
  void			displayBonusDeflagration(CharacterInfo const &character) const;
  void			displayBonusThird(CharacterInfo const &character) const;

  void			displayBonus(CharacterInfo const &character) const;

public:
  HUD(video::IVideoDriver * const driver, IrrlichtDevice * const device, std::vector<int> const &size);
  ~HUD();

  void			display() const;
};

#endif /* !HUD_HH__ */
