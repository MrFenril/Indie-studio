/*
** Character.cpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:17:50 2016 drozdz_b
// Last update Sun Jun  5 23:22:33 2016 Maxime Mollonguet
*/

#include "Character.hpp"

/*
** Construtors & Destructor
*/
Character::Character(scene::ISceneNode* node)
: Object(node)
{
  _animated = true;
}

Character::Character(scene::ISceneManager* smgr, video::IVideoDriver * driver)
: Object(NULL)
{
  scene::IAnimatedMesh *bomber = smgr->getMesh("imgs/tris.md2");
  //bomber->setFrameLoop(0, 10);
  _nodeAnim = smgr->addAnimatedMeshSceneNode(bomber);
  _size = core::vector3df(1, 1, 1);
  _col = smgr->getSceneCollisionManager();
  _smgr = smgr;
  _driver = driver;
  _animated = true;
  _vectorBomb = core::vector3df(1, -0.2f, 0);
  _nb_bomb = 1;
  if (_nodeAnim)
  {
      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
      _nodeAnim->setMaterialFlag(video::EMF_LIGHTING, false);
      _nodeAnim->setScale(core::vector3df(0.03f, 0.03f, 0.03f));
      _nodeAnim->setFrameLoop(400, 600);
      _nodeAnim->setAnimationSpeed(30);
      _moving = false;
      _movingPreced = false;
  }
}

Character::~Character()
{
}

bool		Character::isAnimated() const
{
  return (true);
}


CharacterInfo&	Character::getInfo()
{
  return (this->_info);
}

/*
** Actions of Character
*/
void	Character::move(f32 x, f32 y)
{
    if (x > 0)
      _nodeAnim->setRotation(core::vector3df(0, -30, 0));
    if (x < 0)
      _nodeAnim->setRotation(core::vector3df(0, 150, 0));

    if (_moving)
      _movingPreced = true;
    _moving = true;

    this->_pos = this->_nodeAnim->getPosition();
    this->_pos.X += x;
    this->_pos.Y += y;
    this->_nodeAnim->setPosition(this->_pos);
}

void	Character::move(f32 x, f32 y, f32 z)
{
    if (x > 0)
    {
      if (_nodeAnim)
        _nodeAnim->setRotation(core::vector3df(0, -30, 0));
      _vectorBomb = core::vector3df(1, -0.2f, 0);
    }
    if (x < 0)
    {
      if (_nodeAnim)
        _nodeAnim->setRotation(core::vector3df(0, 150, 0));
      _vectorBomb = core::vector3df(-1, -0.2f, 0);
    }
    if (z > 0)
    {
      if (_nodeAnim)
        _nodeAnim->setRotation(core::vector3df(0, -60, 0));
      _vectorBomb = core::vector3df(0, -0.2f, 1);
    }
    if (z < 0)
    {
      if (_nodeAnim)
        _nodeAnim->setRotation(core::vector3df(0, 60, 0));
      _vectorBomb = core::vector3df(0, -0.2f, -1);
    }

    if (_moving)
      _movingPreced = true;
    _moving = true;

    if (_nodeAnim)
    {
      this->_pos = this->_nodeAnim->getPosition();
      this->_pos.X += x;
      this->_pos.Y += y;
      this->_pos.Z += z;
      this->_nodeAnim->setPosition(this->_pos);
    }
}

void	Character::stati()
{
  if (!_moving)
    _movingPreced = false;
  _moving = false;
}

void	Character::updateAnim()
{
  if (_nodeAnim && _moving && _movingPreced == false)
  {
    _nodeAnim->setFrameLoop(160, 180);
    _nodeAnim->setAnimationSpeed(100);
  }
  else if (_nodeAnim && !_moving && _movingPreced)
  {
      _nodeAnim->setFrameLoop(400, 600);
      _nodeAnim->setAnimationSpeed(30);
  }
}

void	Character::putBomb(IrrlichtDevice *device)
{
  if (_nb_bomb > 0)
    {
      Bomb	*bomb = new Bomb(_smgr, _driver, device);
      core::vector3df	pos;

      if (bomb)
	{
	  _bombList.push_back(bomb);
	  if (bomb->getNode())
	    {
	      _nb_bomb--;
	      bomb->getNode()->setPosition(_nodeAnim->getPosition() + _vectorBomb);
	    }
	  bomb->addCollision(_charList);
	}
    }
}

void	Character::update()
{
  std::list<Bomb *>::iterator	it;
  this->updateAnim();
}

void		Character::setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr)
{
  scene::ITriangleSelector *selector =
    smgr->createOctreeTriangleSelector(mesh, mapNode, 128);
  if (selector)
  {
    mapNode->setTriangleSelector(selector);
    scene::ISceneNodeAnimator	*anim =
      smgr->createCollisionResponseAnimator(selector, mapNode,
        core::vector3df(0.5,0.5,0.5),core::vector3df(0,0,0),
        core::vector3df(0,0,0));
    selector->drop();
    _nodeAnim->addAnimator(anim);
    anim->drop();
  }
}

void		Character::setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr, core::vector3df	vect)
{
  scene::ITriangleSelector *selector =
    smgr->createOctreeTriangleSelector(mesh, mapNode, 128);
  if (selector && mapNode)
  {
    mapNode->setTriangleSelector(selector);
    scene::ISceneNodeAnimator	*anim =
      smgr->createCollisionResponseAnimator(selector, mapNode,
        vect,core::vector3df(0,0,0),
        core::vector3df(0,0,0));
    selector->drop();
    _nodeAnim->addAnimator(anim);
    anim->drop();
  }
}

void		Character::setCharacterList(std::list<Object*> list)
{
  _charList = list;
}

Bomb*	Character::getBomb() const
{
  return !_bombList.size() ? NULL : _bombList.front();
}

std::list<Object*>		Character::getObjectList() const
{
  return (_objList);
}

void		Character::setObjectList(std::list<Object*> list)
{
  _objList = list;
}

void		Character::setNbBomb(int nb)
{
  _nb_bomb = nb;
}

int		Character::getNbBomb() const
{
  return (_nb_bomb);
}
