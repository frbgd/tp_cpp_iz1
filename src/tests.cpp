#include "gtest/gtest.h"

extern "C" {
#include "test_data.h"
#include "schedule.h"
}

TEST(schedule, schedule_first){
    train_schedule *t = find_schedule(12, 30, (char*)"Reutovo");
    ASSERT_TRUE(bool(t));
    ASSERT_EQ(t->number, 10);
}

TEST(schedule, schedule_second){
    train_schedule *t = find_schedule(0, 0, (char*)"Moscow");
    ASSERT_TRUE(bool(t));
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, schedule_third){
    train_schedule *t = find_schedule(23, 59, (char*)"pl. Gorenki");
    ASSERT_TRUE(bool(t));
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, schedule_fourth){
    train_schedule *t = find_schedule(0, 0, (char*)"Moskwa");
    ASSERT_FALSE(bool(t));
}

TEST(schedule, schedule_fifth){
    train_schedule *t = find_schedule(50, 0, (char*)"Moscow");
    ASSERT_FALSE(bool(t));
}

TEST(schedule, schedule_sixth){
    train_schedule *t = find_schedule(0, 100, (char*)"Moscow");
    ASSERT_FALSE(bool(t));
}

int main(int argc, char** argv){
    prepare_test_data();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
