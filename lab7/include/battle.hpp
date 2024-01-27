#pragma once

#include "npc.hpp"

struct Fight {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class Battle {
    private:
        std::queue<Fight> events;
        std::shared_mutex mtx;

        Battle() {};
    public:
        static Battle& get();

        void add_event(Fight &&event);

        void operator()();
};