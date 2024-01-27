#include "../include/npc.hpp"

//--------------------------------NPC-----------------------------------------//
std::shared_mutex print_mutex;

NPC::NPC(const std::string& name, int x, int y) {
    _name = name;
    _x = x;
    _y = y;
}

NPC::NPC(std::istream& stream) {
    stream >> _name >> _x >> _y;
}

std::string NPC::get_type() {
    std::lock_guard<std::mutex> lck(mtx);
    switch(_type) {
        case DRUID:
            return "Druid";
            break;
        case ELF:
            return "Elf";
            break;
        case KNIGHT:
            return "Knight";
            break;
    }
}

int NPC::get_int_type() {
    std::lock_guard<std::mutex> lck(mtx);
    return this->_type;
}

std::string NPC::get_name() {
    std::lock_guard<std::mutex> lck(mtx);
    return this->_name;
}

double NPC::distance(const std::shared_ptr<NPC> &other) {
    std::lock_guard<std::mutex> lck(mtx);
    return sqrt(pow((_x - other->_x), 2) + pow((_y - other->_y), 2));
}

std::pair <int, int> NPC::position() {
    std::lock_guard<std::mutex> lck(mtx);
    return std::pair <int, int> {_x, _y};
}

bool NPC::isClose(const std::shared_ptr<NPC> &other) {
    auto [other_x, other_y] = other->position();
    double dist = this->distance(other);

    std::lock_guard<std::mutex> lck(mtx);
    if (dist <= this->get_murd())
        return true;
    else
        return false;
}


void NPC::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lck(mtx);
    if ((_x + shift_x >= 0) && (_x + shift_x <= max_x))
        _x += shift_x;
    if ((_y + shift_y >= 0) && (_y + shift_y <= max_y))
        _y += shift_y;
}

bool NPC::win() {
    int attack = std::rand() % 6 + 1;
    int defend = std::rand() % 6 + 1;
    if (attack > defend) 
        return true;
    return false;
}

bool NPC::isAlive() {
    std::lock_guard<std::mutex> lck(mtx);
    return _alive;
}

void NPC::must_die() {
    std::lock_guard<std::mutex> lck(mtx);
    _alive = false;
}

bool NPC::visit(std::shared_ptr<Druid> hero) {
    return false;
}

bool NPC::visit(std::shared_ptr<Elf> hero) {
    return false;
}

bool NPC::visit(std::shared_ptr<Knight> hero) {
    return false;
}

size_t NPC::countObservers() {
    return observers.size();
}

void NPC::subscribe(std::shared_ptr<Observer> observer) {
    observers.insert(observer);
}

void NPC::unsubscribe(std::shared_ptr<Observer> observer) {
    std::lock_guard<std::shared_mutex> lck(print_mutex);
    std::cout << observers.size() << std::endl;
    observers.erase(observer);
    std::cout << observers.size() << std::endl;
}

void NPC::notify(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender) const {
    for (auto observer : observers) {
        observer->update(attacker, defender);
    }
}



//--------------------------------DRUID-----------------------------------------//

Druid::Druid(const std::string& name, int x, int y) : NPC(name, x, y) {
    _type = DRUID;
    _move = DRUID_MOVE;
    _murd = DRUID_MURD;
}

Druid::Druid(std::istream& stream) : NPC(stream) {
    _type = DRUID;
    _move = DRUID_MOVE;
    _murd = DRUID_MURD;
}

bool Druid::accept(std::shared_ptr<NPC> visitor) 
{
    return visitor->visit(std::shared_ptr<Druid>(this,[](Druid*){}));
}

bool Druid::visit(std::shared_ptr<Druid> hero) 
{
    if (win()) 
    {
        notify(std::shared_ptr<Druid>(this,[](Druid*){}), hero);
        return true;
    }
    return false;
}

int Druid::get_murd() {
    return this->_murd;
}

int Druid::get_move() {
    return this->_move;
}

//--------------------------------ELF-----------------------------------------//

Elf::Elf(const std::string& name, int x, int y) : NPC(name, x, y) {
    _type = ELF;
    _move = ELF_MOVE;
    _murd = ELF_MURD;
}

Elf::Elf(std::istream& stream) : NPC(stream) {
    _type = ELF;
    _move = ELF_MOVE;
    _murd = ELF_MURD;
}

bool Elf::accept(std::shared_ptr<NPC> visitor) {
    return visitor->visit(std::shared_ptr<Elf>(this,[](Elf*){}));
}

bool Elf::visit(std::shared_ptr<Druid> hero) {
    if (win()) {
        notify(std::shared_ptr<Elf>(this,[](Elf*){}), hero);
        return true;
    }
    return false;
}

bool Elf::visit(std::shared_ptr<Knight> hero) {
    if (win()) {
        notify(std::shared_ptr<Elf>(this,[](Elf*){}), hero);
        return true;
    }
    return false;
}

int Elf::get_murd() {
    return this->_murd;
}

int Elf::get_move() {
    return this->_move;
}

//--------------------------------KNIGHT-----------------------------------------//


Knight::Knight(const std::string& name, int x, int y) : NPC(name, x, y) {
    _type = KNIGHT;
    _move = KNIGTH_MOVE;
    _murd = KNIGHT_MURD;
}

Knight::Knight(std::istream& stream) : NPC(stream) {
    _type = KNIGHT;
    _move = KNIGTH_MOVE;
    _murd = KNIGHT_MURD;
}

bool Knight::accept(std::shared_ptr<NPC> visitor) {
    return visitor->visit(std::shared_ptr<Knight>(this,[](Knight*){}));
}

bool Knight::visit(std::shared_ptr<Elf> hero) {
    if (win()) {
        notify(std::shared_ptr<Knight>(this,[](Knight*){}), hero);
        return true;
    }
    return false;
}

int Knight::get_murd() {
    return this->_murd;
}

int Knight::get_move() {
    return this->_move;
}