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

int main() {
    std::ofstream file("log.txt");
    file.close();
    srand((unsigned int)time(NULL));
    set_t heros;

    std::shared_ptr<NPC> hero;
    for (int i = 0; i < 10; ++i) {
        hero = Create(Type(std::rand() % 3 + 1), Names(std::rand() % 15), 
                            (std::rand() % 100), (std::rand() % 100));

        heros.insert(hero);
    }


    Observer_Console observer1;
    Observer_File observer2;

    std::shared_ptr<Observer_Console> observer11 = std::make_shared<Observer_Console>(observer1);
    std::shared_ptr<Observer_File> observer22 = std::make_shared<Observer_File>(observer2);


    for (auto &hero : heros) {
        std::cout << *hero;
        hero->subscribe(observer11);
        hero->subscribe(observer22);
    }
    std::cout << "\n";
    for (size_t distance = 20; (distance <= 50) and !heros.empty(); distance += 10) {
        auto dead_list = battle(heros, distance);
        for (auto &d : dead_list)
            heros.erase(d);
        std::cout << "Fight stats ----------" << std::endl
                  << "distance: " << distance << std::endl
                  << "killed: " << dead_list.size() << std::endl
                  << std::endl << std::endl;

    }

    std::cout << "Survivors: " << heros.size() << std::endl;
    for (auto &monster : heros) {
        std::cout << *monster;
    }

    return 0;
}

