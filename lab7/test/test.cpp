#include <gtest/gtest.h>
#include "../include/battle.hpp"
#include "../include/npc.hpp"
#include "../include/factory.hpp"

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
        break;
    }
}

TEST(Test_Druid, Constructor) {
    std::string name = "Asterix";
    Druid druid(name, 1, 1);
    EXPECT_TRUE(druid.get_name() == name and druid.get_type() == "Druid");
}

TEST(Test_Druid, FightElfKnigth){
    std::string name = "Obelix";
    std::shared_ptr<Druid> druid = std::make_shared<Druid> (name, 1, 1);
    std::shared_ptr<Elf> elf = std::make_shared<Elf> (name, 1, 2);
    std::shared_ptr<Knight> knight = std::make_shared<Knight> (name, 1, 3);
    ASSERT_EQ(elf->accept(druid), false);
    ASSERT_EQ(knight->accept(druid), false);
}

TEST(Test_Knight, Constr)
{
    std::string name = "Obelix";
    Knight knight{name, 1, 1};
    EXPECT_TRUE(knight.get_name() == name and knight.get_type() == "Knight");
}

TEST(Test_Knight, FightKnight)
{
    std::string name = "Obelix";
    std::shared_ptr<Knight> knight1 = std::make_shared<Knight> (name, 1, 1);
    std::shared_ptr<Knight> knight2 = std::make_shared<Knight> (name, 1, 2);
    EXPECT_TRUE(knight1->accept(knight2) == false and knight2->accept(knight1) == false);
}

TEST(Test_Knight, FightDruid) {
    std::string name = "Obelix";
    std::shared_ptr<Knight> knight = std::make_shared<Knight> (name, 1, 1);
    std::shared_ptr<Druid> druid = std::make_shared<Druid> (name, 1, 2);
    EXPECT_TRUE(druid->accept(knight) == false);
}

TEST(Test_Knight, FightElf) {
    std::string name = "Obelix";
    std::shared_ptr<Knight> knight = std::make_shared<Knight> (name, 1, 1);
    std::shared_ptr<Elf> elf = std::make_shared<Elf> (name, 1, 2);
    EXPECT_TRUE(elf->accept(knight) == true);
}

TEST(Test_Elf, Constr) {
    std::string name = "Obelix";
    Elf elf{name, 1, 1};
    EXPECT_TRUE(elf.get_name() == name and elf.get_type() == "Elf");
}

TEST(Test_Elf, FightElf) {
    std::string name = "Obelix";
    std::shared_ptr<Elf> elf1 = std::make_shared<Elf> (name, 1, 1);
    std::shared_ptr<Elf> elf2 = std::make_shared<Elf> (name, 1, 2);
    EXPECT_TRUE(elf1->accept(elf2) == false and elf2->accept(elf1) == false);
}

TEST(Test_Elf, FightDruid)
{
    std::string name = "Obelix";
    std::shared_ptr<Elf> elf = std::make_shared<Elf> (name, 1, 1);
    std::shared_ptr<Druid> druid = std::make_shared<Druid> (name, 1, 2);
    EXPECT_TRUE(druid->accept(elf) == true);
}

TEST(Test_Elf, FightKnight)
{
    std::string name = "Obelix";
    std::shared_ptr<Elf> elf = std::make_shared<Elf> (name, 1, 1);
    std::shared_ptr<Knight> knight = std::make_shared<Knight> (name, 1, 2);
    EXPECT_TRUE(knight->accept(elf) == true);
}

TEST(Test_NPC, Distance) {
    std::string name = "Obelix";
    std::shared_ptr<Elf> elf1 = std::make_shared<Elf> (name, 1, 1);
    std::shared_ptr<Elf> elf2 = std::make_shared<Elf> (name, 4, 5);
    double distance = 5.0;
    EXPECT_TRUE(elf1->distance(elf2) == distance);
}

TEST(Test_NPC, InsertObservers) {
    std::string name = "Obelix";
    Elf elf{name, 1, 1};
    Observer_Console observer;
    elf.subscribe(std::make_shared<Observer_Console>(observer));
    EXPECT_TRUE(elf.countObservers() == 1);
}

TEST(Test_NPC, EraseObservers) {
    std::string name = "Obelix";
    Elf elf{name, 1, 1};
    Observer_File observer;
    std::shared_ptr observer1 = std::make_shared<Observer_File>(observer);
    elf.subscribe(observer1);
    elf.unsubscribe(observer1);
    EXPECT_TRUE(elf.countObservers() == 0);
}

TEST(Test_Factory, CreateNPC) {
    std::string name = "Obelix";
    std::shared_ptr<NPC> obj = Create(DRUID, name, 1, 1);
    EXPECT_TRUE(obj->get_name() == name and obj->get_type() == "Druid");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}