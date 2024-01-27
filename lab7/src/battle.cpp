#include "../include/battle.hpp"


Battle& Battle::get() {
    static Battle instance;
    return instance;
}

void Battle::add_event(Fight &&event) {
    std::lock_guard<std::shared_mutex> lock(mtx);
    events.push(event);
}

void Battle::operator()() {
    time_t start_time = time(0);

    while (true) {
        if (time(0) - start_time > STOP + 1) break;

        {
            std::optional<Fight> event;
            {
                std::lock_guard<std::shared_mutex> lock(mtx);
                if (!events.empty()) {
                    event = events.back();
                    events.pop();
                }
            }

            if (event) {
                if (event->attacker->isAlive())     // no zombie fighting!
                    if (event->defender->isAlive()) // already dead!
                        if (event->defender->accept(event->attacker)) 
                            event->defender->must_die();
            }
            else
                std::this_thread::sleep_for(100ms);
        }
    }
}