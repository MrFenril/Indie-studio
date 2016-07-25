//
// GUIBonus.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio/srcs/Header
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Mon May  2 18:44:01 2016 Anaïs Foncel
// Last update Sun Jun  5 22:29:27 2016 Anaïs Foncel
//

#include "GUIBonus.hh"

GUIBonus::GUIBonus(video::IVideoDriver * const driver)
{
  _driver = driver;
  _img = NULL;
}

GUIBonus::~GUIBonus()
{

}

void			GUIBonus::setImage(std::string const &name_image_file)
{
  _img = _driver->getTexture(name_image_file.c_str());
}

video::ITexture		*GUIBonus::getImage() const
{
  return (_img);
}

void			GUIBonus::displayImage(int const &posX, int const &posY, int const &size) const
{
  _driver->draw2DImage(_img, core::position2d<s32>(posX, posY),
		       core::rect<s32>(0, 0, size, size), 0,
		       video::SColor(255, 255, 255, 255), true);
}
