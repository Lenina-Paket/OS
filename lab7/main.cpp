#include "include/battle.hpp"
#include "include/npc.hpp"
#include "include/factory.hpp"

using NPC_ptr = std::shared_ptr<NPC>;

std::string Names(int n) {
    switch(n) {
    case 1:
        return "Asterix";
        break;
    case 2:
        return "Obelix";
        break;
    case 3:
        return "Adidas";
        break;
    case 4:
        return "Nike";
        break;
    case 5:
        return "Puma";
        break;
    case 6:
        return "Pudge";
        break;
    case 7:
        return "Nikitos";
        break;
    case 8:
        return "Kizaru";
        break;
    case 9:
        return "BigBayTape";
        break;
    case 10:
        return "Stromae";
        break;
    case 11:
        return "Pepper";
        break;
    case 12:
        return "Huskar";
        break;
    case 13:
        return "GabonskayaGaduka";
        break;
    case 14:
        return "Lololoshka";
        break;
    case 15:
        return "PashaTechnique";
        break;
    default:
        return "Noname";
    }
}

#define GRID 20

int main() {
    // std::shared_mutex mu;
    std::set<std::shared_ptr<NPC>> array;
    srand((unsigned int)time(NULL));
    int n = 1;
    for (size_t i = 0; i < 50; ++i)
    {
        array.insert(Create(Type(std::rand() % 3 + 1), Names(std::rand() % 15), 
                            (std::rand() % 100), (std::rand() % 100)));
        ++n;
    }

    int count = 0;
    for (auto &monster : array)
    {
        if (monster->isAlive())
        {
            std::cout << *monster;
            ++count;
        }
    }

    std::cout << "Survivors: " << count << '\n' << std::endl;


    Observer_Console obc;
    Observer_File obv;

    for (auto &monster : array)
    {
        monster->subscribe(std::make_shared<Observer_Console>(obc));
        monster->subscribe(std::make_shared<Observer_File>(obv));
    }

    bool stop = false;
    const int MAX_X{100};
    const int MAX_Y{100};
    
    std::thread fight_thread(std::ref(Battle::get()));

    std::thread move_thread([&array, MAX_X, MAX_Y, &stop]() {
        time_t start_time = time(0);

        while (true) {
            if (time(0) - start_time > 0.1) {
                stop = true;
                break;
            }
            {
            std::lock_guard<std::shared_mutex> lck(print_mutex);
            for (std::shared_ptr<NPC> npc : array) {
                if(npc->isAlive()) {
                    int distMove = npc->get_move();
                    int shift_x = (std::rand() % distMove) * (std::rand() % 3 - 1);
                    int shift_y;
                    if (shift_x >= 0) shift_y = (distMove - shift_x) * (std::rand() % 3 - 1);
                    else shift_y = (distMove + shift_x) * (std::rand() % 3 - 1);
                    {
                    // std::lock_guard<std::shared_mutex> lck(print_mutex);
                    npc->move(shift_x, shift_y, MAX_X, MAX_Y);
                    }
                }
            }
            }
            // std::lock_guard<std::shared_mutex> lck(print_mutex);
            for (std::shared_ptr<NPC> npc : array)
                for (std::shared_ptr<NPC> other : array)
                    if (other != npc)
                        if (npc->isAlive())
                            if (other->isAlive())
                                if (npc->isClose(other))
                                    Battle::get().add_event({npc, other});

            // std::this_thread::sleep_for(30ms);
        }
    });
    
    
    while (true) {
        if (stop) break;

        const int grid{GRID}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
        
        std::array<char, grid * grid> fields{0};
        
        for (std::shared_ptr<NPC> npc : array) {
            auto [x, y] = npc->position();
            int i = x / step_x;
            int j = y / step_y;
            if (i >= grid) --i;
            if (j >= grid) --j;
            
            if (npc->isAlive()) {
                switch (npc->get_int_type())
                {
                case DRUID:
                    fields[i + grid * j] = 'D';
                    break;
                case ELF:
                    fields[i + grid * j] = 'E';
                    break;
                case KNIGHT:
                    fields[i + grid * j] = 'K';
                    break;
                default:
                    break;
                }
            }
        }
        {
        std::lock_guard<std::shared_mutex> lck(print_mutex);
        for (int j = 0; j < grid; ++j)
        {
            for (int i = 0; i < grid; ++i)
            {
                char c = fields[i + j * grid];
                if (c != 0)
                    std::cout << "[" << c << "]";
                else
                    std::cout << "[ ]";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        }
        std::this_thread::sleep_for(30ms);
    };

    move_thread.join();
    fight_thread.join();

    std::cout << std::endl;

    count = 0;
    for (auto &monster : array)
    {
        if (monster->isAlive())
        {
            std::cout << *monster;
            ++count;
        }
    }

    std::cout << "Survivors: " << count << std::endl;

    return 0;
}