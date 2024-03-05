#include <gtest/gtest.h>

#include "npc.hpp"
#include "visitor.hpp"
#include "factory.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "dragon.hpp"

TEST(FightTest1, Fighting) {
    Elf elf("Elf", 10, 40);
    Druid druid("Druid", 5, 5);
    Dragon dragon("Dragon", 0, 50);

    EXPECT_FALSE(druid.fight(std::make_shared<Elf>(elf)));
    EXPECT_TRUE(druid.fight(std::make_shared<Dragon>(dragon)));
    EXPECT_TRUE(elf.fight(std::make_shared<Druid>(druid)));
    EXPECT_FALSE(elf.fight(std::make_shared<Dragon>(dragon)));
    EXPECT_TRUE(dragon.fight(std::make_shared<Elf>(elf)));
    EXPECT_FALSE(dragon.fight(std::make_shared<Druid>(druid)));
}

TEST(FightTest2, MainFighting) {
    testing::internal::CaptureStdout();
    
    set_t array;

    array.insert(factory(ElfType, "Elf1", 0, 50, "test_fight.txt")); 
    array.insert(factory(DruidType, "Druid1", 5, 5, "test_fight.txt")); 
    array.insert(factory(DragonType, "Dragon1", 10, 40, "test_fight.txt"));  

    array.insert(factory(ElfType, "Elf2", 60, 90, "test_fight.txt")); 
    array.insert(factory(DruidType, "Druid2", 25, 35, "test_fight.txt"));
    array.insert(factory(DragonType, "Dragon2", 0, 2, "test_fight.txt")); 

    array.insert(factory(ElfType, "Elf3", 20, 100, "test_fight.txt")); 
    array.insert(factory(DruidType, "Druid3", 40, 50, "test_fight.txt"));
    array.insert(factory(DragonType, "Dragon3", 80, 90, "test_fight.txt"));

    auto dead_list = fight(array, 20);
    for (auto &d : dead_list)
        array.erase(d);

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(array.size(), 5);
}

TEST(VisitorTest, Visitor) {
    auto elf = std::make_shared<Elf>("Elf", 0, 5);
    auto druid = std::make_shared<Druid>("Druid", 10, 20);
    auto dragon = std::make_shared<Dragon>("Dragon", 5, 10);

    auto npcVisitor = std::make_shared<NPCVisitor>(elf);

    EXPECT_FALSE(elf->accept(*npcVisitor));
    EXPECT_TRUE(druid->accept(*npcVisitor));
    EXPECT_FALSE(dragon->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(druid);

    EXPECT_FALSE(elf->accept(*npcVisitor));
    EXPECT_FALSE(druid->accept(*npcVisitor));
    EXPECT_TRUE(dragon->accept(*npcVisitor));

    npcVisitor = std::make_shared<NPCVisitor>(dragon);

    EXPECT_TRUE(elf->accept(*npcVisitor));
    EXPECT_FALSE(druid->accept(*npcVisitor));
    EXPECT_FALSE(dragon->accept(*npcVisitor));
}

TEST(ObserverTest, Observer) {
    auto dragon = std::make_shared<Elf>("Elf", 0, 5);
    auto druid = std::make_shared<Druid>("Druid", 5, 10);
    
    testing::internal::CaptureStdout();

    auto textObserver = std::make_shared<TextObserver>();
    dragon->subscribe(textObserver);
    dragon->fight(druid);

    std::string textOutput = testing::internal::GetCapturedStdout();
    std::string expectedOutput = "\nMurder: --------\nelf: Elf {0, 5} \ndruid: Druid {5, 10} \nElf killed Druid\n";

    EXPECT_EQ(textOutput, expectedOutput);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}