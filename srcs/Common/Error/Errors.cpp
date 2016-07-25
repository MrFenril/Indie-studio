//
// Errors.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Wed Apr 27 16:42:29 2016 Anaïs Foncel
// Last update Sun Jun  5 22:19:01 2016 Anaïs Foncel
//

#include "Errors.hh"

Errors::Exceptions::~Exceptions() throw() {}

Errors::Exceptions::Exceptions(Exceptions_Type const type, const std::string &mess)
  : std::exception()
{
  static std::string    message[max_exception] = {""};

  message[unknown] = mess;
  message[FuncFail] = mess + " failed.";

  _message = message[static_cast<int>(type)];
}

const char *Errors::Exceptions::what() const throw ()
{
  return _message.c_str();
}
