#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
#include <memory>
#include <mutex>
#include <sstream>
#include <thread>
#include <shared_mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;
extern std::shared_mutex print_mutex;

class Observer;
class Observer_Console;
class Observer_File;
class Knight;
class Elf;
class Druid;

enum Type {
    DRUID = 1,
    ELF = 2,
    KNIGHT = 3
};

#define STOP 7
#define ARENA_SIZE 100
#define KNIGTH_MOVE 30
#define KNIGHT_MURD 10
#define ELF_MOVE 10
#define ELF_MURD 50
#define DRUID_MOVE 10
#define DRUID_MURD 10

class NPC {
    protected:
        std::mutex mtx;
        Type _type;
        std::string _name;
        int _x, _y, _move, _murd;
        bool _alive = true;
        std::set<std::shared_ptr<Observer>> observers;

    public:
        NPC(const std::string& name, int x, int y);
        NPC(std::istream& stream);

        std::string get_type();
        int get_int_type();
        std::string get_name();
        virtual int get_murd() = 0;
        virtual int get_move() = 0;

        std::pair<int, int> position();
        bool isClose(const std::shared_ptr<NPC> &other);
        double distance(const std::shared_ptr<NPC> &other);
        void move(int shift_x, int shift_y, int max_x, int max_y);

        // bool win();
        bool isAlive();
        void must_die();
        
        virtual bool accept(std::shared_ptr<NPC> visitor) = 0;
        virtual bool visit(std::shared_ptr<Druid> hero);
        virtual bool visit(std::shared_ptr<Elf> hero);
        virtual bool visit(std::shared_ptr<Knight> hero);
        virtual ~NPC() = default;

        size_t countObservers();
        void subscribe(std::shared_ptr<Observer> observer);
        void unsubscribe(std::shared_ptr<Observer> observer);
        void notify(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender) const;

        friend std::ostream &operator<<(std::ostream& stream, NPC& hero) {
            stream << "Type : " << hero.get_type() << ", name : " << hero.get_name() << " x: " << hero._x << " y: " << hero._y << std::endl;
            return stream;
        }
};

class Druid : public NPC {
    public:
        Druid(const std::string& name, int x, int y);
        Druid(std::istream& stream);
        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Druid> hero) override;
        int get_murd() override;
        int get_move() override;
        virtual ~Druid() = default;
};

class Elf : public NPC {
    public:
        Elf(const std::string& name, int x, int y);
        Elf(std::istream& stream);
        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Druid> hero) override;
        bool visit(std::shared_ptr<Knight> hero) override;
        int get_murd() override;
        int get_move() override;
        virtual ~Elf() = default;
};

class Knight : public NPC {
    public:
        Knight(const std::string& name, int x, int y);
        Knight(std::istream& stream);
        bool accept(std::shared_ptr<NPC> visitor) override;
        bool visit(std::shared_ptr<Elf> hero) override;
        int get_murd() override;
        int get_move() override;
        virtual ~Knight() = default;
};

class Observer {
    public:
        virtual void update(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender) = 0;
};

class Observer_File : public Observer {
    public:
        void update(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender) override {
            std::ofstream file("log.txt", std::ios_base::app);
            file << std::endl << attacker->get_type() << ' ' << attacker->get_name() << " убил " << defender->get_type() << ' ' << defender->get_name() << std::endl;
            file.close();
        }
};

class Observer_Console : public Observer {
    public:

        void update(std::shared_ptr<NPC> attacker, std::shared_ptr<NPC> defender) override {
            {
            std::lock_guard<std::shared_mutex> lck(print_mutex);
            std::cout << attacker->get_type() << ' ' << attacker->get_name() << 
            " killed " << defender->get_type() << ' ' << defender->get_name() << std::endl;
            std::cout << *attacker << std::endl;
            std::cout << *defender << std::endl;
            }
        }
};