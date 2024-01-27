#pragma once

#include "npc.hpp"

//фабрика троллей
std::shared_ptr<NPC> Create(Type type, const std::string& name, int x, int y);
std::shared_ptr<NPC> Create(std::istream& stream);