//
// SaveHandler.cpp for IndieStudio in /home/pujol_n/rendu/cpp_indie_studio/srcs
//
// Made by Nicolas Pujol
// Login   <pujol_n@epitech.net>
//
// Started on  Thu May 26 21:59:55 2016 Nicolas Pujol
// Last update Sun Jun  5 23:40:00 2016 Nicolas Pujol
//

#include "SaveHandler.hh"

SaveHandler::SaveHandler() {
  preload();
}

SaveHandler::~SaveHandler() {
  writeSavefile();
}

std::string			SaveHandler::getCurrentTime() const
{
  std::stringstream ss;

  auto now = std::chrono::system_clock::now();
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

  ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
  return ss.str();
}

void				SaveHandler::save(Save &save)
{
  std::map<std::string, Save*>::iterator		tmp;

  tmp = _saves.find(save.getName());
  if (tmp != _saves.end())
    {
      _saves.erase(tmp);
      _saves[save.getName()] = &save;
      return;
    }
  _saves[save.getName()] = &save;
}


nlohmann::json SaveHandler::saveToJson(Save* save)
{
  nlohmann::json j;

  j["player"] = save->getName();
  j["date"] = save->getDate();
  j["score"] = save->getScore();
  j["map"] = save->getMap();
  return j;
}

void SaveHandler::writeSavefile() {
    std::string saves("");
    nlohmann::json j = nlohmann::json::array();

    for (auto save : _saves) {
      j.push_back(saveToJson(save.second));
    }

    saves = j.dump();
    std::ofstream outfile(".saves");
    outfile << saves << std::endl;
    outfile.close();
}

Save				*SaveHandler::operator[](const std::string &name)
{
  if (_saves.find(name) == _saves.end())
    throw std::invalid_argument("Name not valid\n");
  return (_saves[name]);
}

void				SaveHandler::preload()
{
  std::ifstream t(".saves");
  std::string buffer((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

  auto o = nlohmann::json::parse(buffer);
  for (size_t i = 0; i < o.size(); i++) {
    _saves[o[i]["player"]] = new Save(o[i]["player"], o[i]["date"], o[i]["map"], o[i]["score"]);
  }
}
