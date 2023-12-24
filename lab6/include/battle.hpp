#pragma once

#include "npc.hpp"

using set_t = std::set<std::shared_ptr<NPC>>;

set_t battle(const set_t& arr, int distance);