#include "../include/battle.hpp"


Battle& Battle::get() {
    static Battle instance;
    return instance;
}

void Battle::add_event(Fight &&event) {
    // std::lock_guard<std::shared_mutex> lock(print_mutex);
    events.push(event);
    // std::cout << "!!" << std::endl;
}

void Battle::operator()() {
    time_t start_time = time(0);

    while (true) {
        if (time(0) - start_time > STOP + 1) break;

        
        std::optional<Fight> event;
        {
        std::lock_guard<std::shared_mutex> lock(print_mutex);
            while (!events.empty()) {
                event = events.back();
                    
                if (event) {
                    if (event->attacker->isAlive()) 
                        if (event->defender->isAlive())
                            if (event->defender->accept(event->attacker)) 
                                event->defender->must_die();
                }
                events.pop();
            }
            
        }
    }
}
