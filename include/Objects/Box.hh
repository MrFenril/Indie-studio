//
// Box.hh for indie_studio in /home/monder_s/C++/cpp_indie_studio/include
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Thu Jun  2 15:52:38 2016 Sacha Sacha Monderer
// Last update Sun Jun  5 23:18:21 2016 Anaïs Foncel
//

#ifndef BOX_HH_
# define BOX_HH_

#include "Object.hh"

class Box : public Object
{
public:
  Box(scene::ISceneNode * const);
  Box(scene::ISceneManager *const, video::IVideoDriver * const);
  ~Box();
};

#endif /* BOX_HH_ */
