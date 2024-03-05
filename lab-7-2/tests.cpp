#include <gtest/gtest.h>

#include "npc.hpp"
#include "observer.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "dragon.hpp"


TEST(FightTest1, ElfVsDruid) {
    testing::internal::CaptureStdout();

    auto elf = factory(ElfType, "Elf", 0, 0, "test_fight.txt");
    auto druid = factory(DruidType, "Druid", 1, 1, "test_fight.txt"); 
    ASSERT_TRUE(druid->accept(elf));
    druid->mustDie();

    ASSERT_TRUE(elf->isAlive());
    ASSERT_FALSE(druid->isAlive());

    testing::internal::GetCapturedStdout();
}

TEST(FightTest2, ElfVsDragon) {
    testing::internal::CaptureStdout();

    auto elf = factory(ElfType, "Elf", 0, 0, "test_fight.txt");
    auto dragon = factory(DragonType, "Dragon", 1, 1, "test_fight.txt"); 
    ASSERT_FALSE(dragon->accept(elf));
    dragon->mustDie();

    ASSERT_TRUE(elf->isAlive());
    ASSERT_FALSE(dragon->isAlive());

    testing::internal::GetCapturedStdout();
}

TEST(FightTest3, MainFighting) {
    
    set_t NPCs;
    NPCs.insert(factory(ElfType, "Elf1", 15, 15, "test_fight.txt")); 
    NPCs.insert(factory(ElfType, "Elf2", 10, 10, "test_fight.txt"));
    NPCs.insert(factory(ElfType, "Elf3", 15, 15, "test_fight.txt"));
    NPCs.insert(factory(ElfType, "Elf4", 10, 10, "test_fight.txt"));
    NPCs.insert(factory(DruidType, "Druid1", 10, 10, "test_fight.txt")); 
    NPCs.insert(factory(DruidType, "Druid2", 30, 30, "test_fight.txt")); 
    NPCs.insert(factory(DragonType, "Dragon1", 10, 10, "test_fight.txt")); 
    NPCs.insert(factory(DragonType, "Dragon2", 15, 15, "test_fight.txt")); 
    set_t NPCsKilled;
    
    ASSERT_EQ(8, NPCs.size());
    testing::internal::CaptureStdout();
    for (auto& attacker : NPCs) {
        for (auto& defender : NPCs) {
            if (attacker->isAlive())
                if (defender->isAlive())
                    if (defender->accept(attacker)) {
                        defender->mustDie();
                        NPCsKilled.insert(defender);
                    }
        }
    }
    testing::internal::GetCapturedStdout();
    
    ASSERT_EQ(6, NPCsKilled.size());
    for (const auto& npc : NPCsKilled) {
        NPCs.erase(npc);
    }
    ASSERT_EQ(2, NPCs.size());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}