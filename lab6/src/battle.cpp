#include "../include/battle.hpp"

set_t battle(const set_t& array, int distance) {
    set_t death_note;

    for (auto& attacker : array) {
        for (auto& defender : array) {
            if (death_note.find(defender) == death_note.end()) {
                if (attacker != defender and attacker->distance(*defender) <= distance) {
                    bool success = false;
                    success = defender->accept(*attacker);
                    if (success) {
                        death_note.insert(defender);
                    }
                }
            }
        }
    }

    return death_note;
}

