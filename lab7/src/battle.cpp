#include "../include/battle.hpp"


Battle& Battle::get() {
    static Battle instance;
    return instance;
}

void Battle::add_event(Fight &&event) {
    std::lock_guard<std::shared_mutex> lock(print_mutex);
    events.push(event);
}

void Battle::operator()() {
    time_t start_time = time(0);

    while (true) {
        if (time(0) - start_time > STOP + 1) break;

        {
            std::optional<Fight> event;
            {
                std::lock_guard<std::shared_mutex> lock(print_mutex);
                if (!events.empty()) {
                    event = events.back();
                    events.pop();
                }
            }
            {
            // std::lock_guard<std::shared_mutex> lock(print_mutex);
            if (event) {
                {
                // std::lock_guard<std::shared_mutex> lock(print_mutex);
                if (event->attacker->isAlive())     // no zombie fighting!
                    if (event->defender->isAlive()) // already dead!
                        {
                        // std::lock_guard<std::shared_mutex> lock(print_mutex);
                        if (event->defender->accept(event->attacker)) 
                            event->defender->must_die();
                        }
                }
            }
            
            // else
            //     std::this_thread::sleep_for(100ms);
            }
        }
    }
    
}