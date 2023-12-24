#include "../include/npc.hpp"

//--------------------------------NPC-----------------------------------------//

NPC::NPC(const std::string& name, int x, int y) {
    _name = name;
    _x = x;
    _y = y;
}

NPC::NPC(std::istream& stream) {
    stream >> _name >> _x >> _y;
}

Type NPC::get_type() const {
    return this->_type;
}

std::string NPC::get_name() const {
    return this->_name;
}

double NPC::distance(NPC& other) {
    return sqrt(pow((_x - other._x), 2) + pow((_y - other._y), 2));
}

bool NPC::visit(Druid& hero) {
    return false;
}

bool NPC::visit(Elf& hero) {
    return false;
}

bool NPC::visit(Knight& hero) {
    return false;
}

size_t NPC::countObservers() {
    return observers.size();
}

void NPC::subscribe(std::shared_ptr<Observer> observer) {
    observers.insert(observer);
}

void NPC::unsubscribe(std::shared_ptr<Observer> observer) {
    std::cout << observers.size() << std::endl;
    observers.erase(observer);
    std::cout << observers.size() << std::endl;
}

void NPC::notify(NPC &attacker, NPC &defender) {
    for (auto observer : observers) {
        observer->update(attacker, defender);
    }
}



//--------------------------------DRUID-----------------------------------------//

Druid::Druid(const std::string& name, int x, int y) : NPC(name, x, y) {
    _type = DRUID;
}

Druid::Druid(std::istream& stream) : NPC(stream) {
    _type = DRUID;
}

bool Druid::accept(NPC& visitor) {
    return visitor.visit(*this);
}

bool Druid::visit(Druid& hero) {
    notify(*this, hero);
    return true;
}

//--------------------------------ELF-----------------------------------------//

Elf::Elf(const std::string& name, int x, int y) : NPC(name, x, y) {
    _type = ELF;
}

Elf::Elf(std::istream& stream) : NPC(stream) {
    _type = ELF;
}

bool Elf::accept(NPC& visitor) {
    return visitor.visit(*this);
}

bool Elf::visit(Druid& hero) {
    notify(*this, hero);
    return true;
}

bool Elf::visit(Knight& hero) {
    notify(*this, hero);
    return true;
}

//--------------------------------KNIGHT-----------------------------------------//


Knight::Knight(const std::string& name, int x, int y) : NPC(name, x, y) {
    _type = KNIGHT;
}

Knight::Knight(std::istream& stream) : NPC(stream) {
    _type = KNIGHT;
}

bool Knight::accept(NPC& visitor) {
    return visitor.visit(*this);
}

bool Knight::visit(Elf& hero) {
    notify(*this, hero);
    return true;
}