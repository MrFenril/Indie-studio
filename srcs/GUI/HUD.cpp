//
// HUD.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/include/Header
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:32:39 2016 Anaïs Foncel
// Last update Sun Jun  5 22:16:02 2016 Anaïs Foncel
//

#include "HUD.hh"

HUD::HUD(video::IVideoDriver * const driver, IrrlichtDevice * const device, std::vector<int> const &size)
{
  _driver = driver;
  _device = device;
  _bonus = new GUIBonus(_driver);
  _size_winX = size[0];
  _size_winY = size[1];
  _size_HUD_Y = _size_winY / 4;
  _size_mHUD_X = _size_winX / 4;
}

HUD::~HUD()
{

}

void		HUD::displayScore(CharacterInfo const &character) const
{
  gui::IGUIFont	*font;
  std::string	inter;
  core::stringw	res;
  int		score;
  int		posX;
  int		posY;


  score = character.getScore();
  inter = std::to_string(score);;
  res = core::stringw(inter.c_str());

  posX = (character.getId() - 1) * _size_mHUD_X;
  posY = ((_size_HUD_Y / 4) / 3) * 2;

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void		HUD::displayName(CharacterInfo const &character) const
{
  gui::IGUIFont	*font;
  core::stringw	res;
  int		posX;
  int		posY;
  std::string	name;

  name = character.getName();
  res = core::stringw(name.c_str());
  posX = (character.getId() - 1) * _size_mHUD_X;
  posY = 0;

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void		HUD::displayBonusBomb(CharacterInfo const &character) const
{
  gui::IGUIFont	*font;
  std::string	inter;
  core::stringw	res;
  int		posX_Image;
  int		posY_Image;
  int		posX;
  int		posY;
  int		num;

  posX_Image = (character.getId() - 1) * _size_mHUD_X;
  posY_Image = ((_size_HUD_Y / 4) / 3);


  posX = (character.getId() - 1) * _size_mHUD_X;
  posY = ((_size_HUD_Y / 4) / 3) + SIZE_IMAGE;

  num = character.getCountBomb();
  inter = std::to_string(num);
  res = core::stringw(inter.c_str());
  _bonus->setImage("media/lightFalloff.png");
  _bonus->displayImage(posX_Image, posY_Image, SIZE_IMAGE);

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void		HUD::displayBonusDeflagration(CharacterInfo const &character) const
{
  gui::IGUIFont	*font;
  std::string	inter;
  core::stringw	res;
  int		posX_Image;
  int		posY_Image;
  int		posX;
  int		posY;
  int		num;

  posX_Image = ((character.getId() - 1) * _size_mHUD_X) + (_size_mHUD_X / 3);
  posY_Image = ((_size_HUD_Y / 4) / 3);

  posX = ((character.getId() - 1) * _size_mHUD_X) + (_size_mHUD_X / 3);
  posY = ((_size_HUD_Y / 4) / 3) + SIZE_IMAGE;

  num = character.getDeflagration();
  inter = std::to_string(num);
  res = core::stringw(inter.c_str());
  _bonus->setImage("media/lightFalloff.png");
  _bonus->displayImage(posX_Image, posY_Image, SIZE_IMAGE);

  font = _device->getGUIEnvironment()->getBuiltInFont();
  if (font)
  font->draw(res, core::rect<s32>(posX, posY, 300, 50), video::SColor(255, 255, 255, 255));
}

void		HUD::displayBonusThird(CharacterInfo const &character) const
{
  int		posX_Image;
  int		posY_Image;

  posX_Image = ((character.getId() - 1) * _size_mHUD_X) + (2 * (_size_mHUD_X / 3));
  posY_Image = ((_size_HUD_Y / 4) / 3);

  _bonus->setImage("media/lightFalloff.png");
  _bonus->displayImage(posX_Image, posY_Image, SIZE_IMAGE);
}

void		HUD::displayBonus(CharacterInfo const &character) const
{
  displayBonusBomb(character);
  displayBonusDeflagration(character);
  if (character.getJump() == true)
    displayBonusThird(character);
}

void		HUD::display() const
{
  for (unsigned int i = 0; i < _characters.size(); ++i)
    {
      displayName(_characters[i]);
      displayBonus(_characters[i]);
      displayScore(_characters[i]);
    }
}
