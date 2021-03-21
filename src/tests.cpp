#include "gtest/gtest.h"

extern "C" {
#include "test_data.h"
#include "schedule.h"
}

TEST(schedule, schedule_first) {
    train_schedule *t = find_schedule(12, 30, const_cast<char*>("Reutovo"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 10);
}

TEST(schedule, schedule_second) {
    train_schedule *t = find_schedule(0, 0, const_cast<char*>("Moscow"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, schedule_third) {
    train_schedule *t = find_schedule(23, 59, const_cast<char*>("pl. Gorenki"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, schedule_fourth) {
    train_schedule *t = find_schedule(0, 0, const_cast<char*>("Moskwa"));
    ASSERT_EQ(t, nullptr);
}

TEST(schedule, schedule_fifth) {
    train_schedule *t = find_schedule(50, 0, const_cast<char*>("Moscow"));
    ASSERT_EQ(t, nullptr);
}

TEST(schedule, schedule_sixth) {
    train_schedule *t = find_schedule(0, 100, const_cast<char*>("Moscow"));
    ASSERT_EQ(t, nullptr);
}

int main(int argc, char** argv) {
    prepare_test_data();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
