//
// Box.cpp for indie_studio in /home/monder_s/C++/cpp_indie_studio/srcs
//
// Made by Sacha Sacha Monderer
// Login   <monder_s@epitech.net>
//
// Started on  Thu Jun  2 15:56:21 2016 Sacha Sacha Monderer
// Last update Sun Jun  5 23:18:44 2016 Anaïs Foncel
//

#include "Box.hh"

Box::Box(scene::ISceneNode * const node) : Object(node)
{
  this->_node = node;
  if (this->_node)
  {
    this->_node->getPosition();
    this->_isdead = false;
    this->_destructible = true;
  }
}

Box::Box(scene::ISceneManager * const smgr, video::IVideoDriver * const driver) : Object(NULL)
{
  core::vector3df   size(1, 0.5f, 1);
  scene::IMesh *cube = smgr->getGeometryCreator()->createCubeMesh(size);
  this->_node = smgr->addMeshSceneNode(cube);
  this->_node->getPosition();
  this->_blockable = true;
  if (this->_node)
  {
    this->_node->setMaterialTexture(0, driver->getTexture("imgs/wall.bmp"));
    this->_node->setMaterialFlag(video::EMF_LIGHTING, false);
    this->_isdead = false;
  }
}

Box::~Box()
{
}
