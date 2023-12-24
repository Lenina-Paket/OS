#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <memory>
#include <fstream>


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


class NPC {
    protected:
        Type _type;
        std::string _name;
        int _x, _y;
        std::set<std::shared_ptr<Observer>> observers;
    public:
        NPC(const std::string& name, int x, int y);
        NPC(std::istream& stream);

        Type get_type() const;
        std::string get_name() const;
        double distance(NPC& other);

        virtual bool accept(NPC& visitor) = 0;
        virtual bool visit(Druid& hero);
        virtual bool visit(Elf& hero);
        virtual bool visit(Knight& hero);
        virtual ~NPC() = default;

        size_t countObservers();
        void subscribe(std::shared_ptr<Observer> observer);
        void unsubscribe(std::shared_ptr<Observer> observer);
        void notify(NPC &attacker, NPC &defender);

        friend std::ostream &operator<<(std::ostream& stream, NPC& hero) {
            stream << "Type : " << hero.get_type() << ", name : " << hero.get_name() << " x: " << hero._x << " y: " << hero._y << std::endl;
            return stream;
        }
};

class Druid : public NPC {
    public:
        Druid(const std::string& name, int x, int y);
        Druid(std::istream& stream);
        bool accept(NPC& visitor) override;
        bool visit(Druid& hero) override;
        virtual ~Druid() = default;
};

class Elf : public NPC {
    public:
        Elf(const std::string& name, int x, int y);
        Elf(std::istream& stream);
        bool accept(NPC& visitor) override;
        bool visit(Druid& hero) override;
        bool visit(Knight& hero) override;
        virtual ~Elf() = default;
};

class Knight : public NPC {
    public:
        Knight(const std::string& name, int x, int y);
        Knight(std::istream& stream);
        bool accept(NPC& visitor) override;
        bool visit(Elf& hero) override;
        virtual ~Knight() = default;
};


class NPC;


class Observer {
    public:
        virtual void update(NPC& attacker, NPC& defender) = 0;
};

class Observer_File : public Observer {
    public:
        void update(NPC& attacker, NPC& defender) override {
            std::ofstream file("log.txt", std::ios_base::app);
            file << std::endl << attacker.get_type() << ' ' << attacker.get_name() << " убил " << defender.get_type() << ' ' << defender.get_name() << std::endl;
            file.close();
        }
};

class Observer_Console : public Observer {
    public:
        void update(NPC& attacker, NPC& defender) override {
            std::cout << attacker.get_type() << ' ' << attacker.get_name() << 
            " killed " << defender.get_type() << ' ' << defender.get_name() << std::endl;
        }
};