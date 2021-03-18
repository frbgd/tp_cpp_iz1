#include "gtest/gtest.h"

extern "C" {
#include "test_data.h"
#include "schedule.h"
}

TEST(schedule, schedule_first){
    train_schedule *t = findSchedule(12, 30, (char*)"Reutovo");
    ASSERT_TRUE(!!t);
    ASSERT_EQ(t->number, 10);
}

TEST(schedule, schedule_second){
    train_schedule *t = findSchedule(0, 0, (char*)"Moscow");
    ASSERT_TRUE(!!t);
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, schedule_third){
    train_schedule *t = findSchedule(23, 59, (char*)"pl. Gorenki");
    ASSERT_TRUE(!!t);
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, schedule_fourth){
    train_schedule *t = findSchedule(0, 0, (char*)"Moskwa");
    ASSERT_FALSE(!!t);
}

TEST(schedule, schedule_fifth){
    train_schedule *t = findSchedule(50, 0, (char*)"Moscow");
    ASSERT_FALSE(!!t);
}

TEST(schedule, schedule_sixth){
    train_schedule *t = findSchedule(0, 100, (char*)"Moscow");
    ASSERT_FALSE(!!t);
}

int main(int argc, char** argv){
    prepare_test_data();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
