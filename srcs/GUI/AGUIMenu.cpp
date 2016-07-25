//
// AGUIMenu.cpp for Menus in /home/rigola_s/test_repo/test_irrlicht/test_indie/srcs/Menus
//
// Made by Rigolat Sébastien
// Login   <rigola_s@epitech.net>
//
// Started on  Sat May  7 16:41:22 2016 Rigolat Sébastien
// Last update Mon Jun 20 23:44:25 2016 Rigolat Sébastien
//

#include "MenuManager.hpp"

AGUIMenu::AGUIMenu(SAppContext const &context)
  :	gui::IGUIElement(context.type, context.device->getGUIEnvironment(),
			 context.parent, context.id,context.rect), _context(context)
{
}

AGUIMenu::~AGUIMenu()
{}

bool				AGUIMenu::OnEvent(const SEvent& event)
{
  if (event.EventType == EET_GUI_EVENT
      || event.EventType == EET_KEY_INPUT_EVENT)
    {
      onGUIEvent(event);
      if (event.EventType == EET_KEY_INPUT_EVENT)
	return (keyInputTreatment(event));
      return (true);
    }
  return false;
}

void				AGUIMenu::draw()
{
  if ( isVisible() )
    {
      core::list<IGUIElement*>::Iterator it = Children.begin();
      for (; it != Children.end(); ++it)
	(*it)->draw();
    }
}

gui::IGUIImage			*AGUIMenu::getSelectorImage() const
{
  return (_selector);
}

gui::IGUIImage			*AGUIMenu::getBackgroundImage() const
{
  return (_selector);
}

void					AGUIMenu::setSelectorImage(video::ITexture * const t)
{
  _selector->setImage(t);
}

void					AGUIMenu::setBackgroundImage(video::ITexture * const t)
{
  _background->setImage(t);
}

bool AGUIMenu::onGUIEvent(const SEvent &e)
{
  if (e.GUIEvent.EventType == gui::EGET_ELEMENT_HOVERED)
    onButtonHover(e.GUIEvent.Caller);
  else if (e.GUIEvent.EventType == gui::EGET_BUTTON_CLICKED)
    {
      return (onButtonClicked(e.GUIEvent.Caller->getID()));
    }
  return false;
}

bool AGUIMenu::onButtonClicked(s32 ID)
{
  if (_mMap.count(ID) != 0)
    {
      _context.device->setEventReceiver(NULL);
      _currentButton = getElementFromId(ID, true);
      (this->*_mMap[ID])();
      return true;
    }
  return false;
}

void AGUIMenu::upKeyPressed()
{
  core::list<gui::IGUIElement *>::Iterator it =	_selectableButtons.begin();

  for (; it != _selectableButtons.end(); ++it)
    {
      gui::IGUIElement *tmp = (*it);
      if (tmp->getType() == gui::EGUIET_BUTTON)
	{
	  if (tmp == _currentButton
	      && it != _selectableButtons.begin())
	    {
	      _currentButton = *(it - 1);
	      moveSelector();
	      return;
	    }
	  else if (tmp == _currentButton
		   && it == _selectableButtons.begin())
	    {
	      _currentButton = *_selectableButtons.getLast();
	      moveSelector();
	      return;
	    }
	}
    }
}

void AGUIMenu::downKeyPressed()
{
  core::list<gui::IGUIElement *>::Iterator it =	_selectableButtons.begin();

  for (; it != _selectableButtons.end(); ++it)
    {
      gui::IGUIElement *tmp = (*it);
      if (tmp->getType() == gui::EGUIET_BUTTON)
	{
	  if (tmp == _currentButton
	      && (it + 1)  != _selectableButtons.end())
	    {
	      _currentButton = (*++it);
	      moveSelector();
	      return;
	    }
	  else if (tmp == _currentButton
		   && it + 1 == _selectableButtons.end())
	    {
	      _currentButton = *(_selectableButtons.begin());
	      moveSelector();
	      return;
	    }
	}
    }
}

bool					AGUIMenu::onButtonHover(gui::IGUIElement * const button)
{
  core::list<gui::IGUIElement *>::Iterator it =	_selectableButtons.begin();

  for (; it != Children.end(); ++it)
    if ((*it) == button)
      {
	if ((*it)->getType() != gui::EGUIET_BUTTON)
	  return true;
	_currentButton = (*it);
	moveSelector();
	return true;
      }
  return false;
}

void			AGUIMenu::enterKeyPressed()
{
  onButtonClicked(_currentButton->getID());
}

inline void			AGUIMenu::moveSelector()
{
  if (!_currentButton)
    return;
  core::rect<s32> buttonRect = _currentButton->getAbsoluteClippingRect();
  core::rect<s32> selectorRect = _selector->getAbsoluteClippingRect();
  core::vector2d<s32> subPos(selectorRect.getWidth() / 2,
			     selectorRect.getHeight() / 2);

  _selector->setRelativePosition(buttonRect.getCenter() - subPos);
  _selector->move(core::vector2d<s32>(-buttonRect.getWidth(), 0));

}

inline bool			AGUIMenu::keyInputTreatment(const SEvent &e)
{
  if (_mMap.count(e.KeyInput.Key) != 0
      && e.KeyInput.PressedDown)
    {
      (this->*_mMap[e.KeyInput.Key])();
      return true;
    }
  return false;
}

inline void			AGUIMenu::initGUIelements()
{
  _driver = _context.device->getVideoDriver();
  _background = Environment->addImage(core::rect<s32>(0, 0, 1024, 980), this);
  _background->setImage(_driver->getTexture("imgs/Background.png"));
  _background->setScaleImage(true);
  _selector = Environment->addImage(_driver->getTexture("imgs/cursor_tmp.png"), core::position2di(0, 0), true, this);
}

void					AGUIMenu::setButtonImage(int ID, std::string const &path)
{
  core::list<IGUIElement*>::Iterator it;

  for (it = Children.begin(); it != Children.end(); ++it)
    {
      if (ID == (*it)->getID())
	{
	  gui::IGUIButton *tmp = reinterpret_cast<gui::IGUIButton *>((*it));
	  tmp->setImage(_driver->getTexture(path.c_str()));
	  tmp->setMaxSize(core::dimension2du(200, 70));
	  tmp->setScaleImage(true);
	  return;
	}
    }
}
