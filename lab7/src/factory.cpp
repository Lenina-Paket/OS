#include "../include/factory.hpp"

std::shared_ptr<NPC> Create(Type type, const std::string& name, int x, int y) {
    std::shared_ptr<NPC> hero;
    switch (type) {
        case DRUID:
            hero = std::make_shared<Druid>(name, x, y);
            break;
        case ELF:
            hero = std::make_shared<Elf>(name, x, y);
            break;
        case KNIGHT:
            hero = std::make_shared<Knight>(name, x, y);
            break;
    }
    return hero;
}

std::shared_ptr<NPC> Create(std::istream& stream) {
    std::shared_ptr<NPC> hero;
    int type;
    stream >> type;
    switch(type) {
        case DRUID:
            hero = std::make_shared<Druid>(stream);
            break;
        case ELF:
            hero = std::make_shared<Elf>(stream);
            break;
        case KNIGHT:
            hero = std::make_shared<Knight>(stream);
            break;
    }
    return hero;
}