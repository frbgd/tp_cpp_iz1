#include "gtest/gtest.h"

extern "C" {
#include "test_data.h"
#include "schedule.h"
}

TEST(schedule, FirstCorrectTime) {
    train_schedule *t = find_schedule(12, 30, const_cast<char*>("Reutovo"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 10);
}

TEST(schedule, SecondCorrectTime) {
    train_schedule *t = find_schedule(5, 30, const_cast<char*>("Kuskovo"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 2);
}

TEST(schedule, ThirdCorrectTime) {
    train_schedule *t = find_schedule(15, 2, const_cast<char*>("Nizhegorodskaya"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 13);
}

TEST(schedule, FourthCorrectTime) {
    train_schedule *t = find_schedule(22, 11, const_cast<char*>("Stroika"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 22);
}

TEST(schedule, MidnigthTime) {
    train_schedule *t = find_schedule(0, 0, const_cast<char*>("Moscow"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, PreMidnigthTime) {
    train_schedule *t = find_schedule(23, 59, const_cast<char*>("pl. Gorenki"));
    ASSERT_NE(t, nullptr);
    ASSERT_EQ(t->number, 1);
}

TEST(schedule, InCorrectStopName) {
    train_schedule *t = find_schedule(0, 0, const_cast<char*>("Moskwa"));
    ASSERT_EQ(t, nullptr);
}

TEST(schedule, IncorrectHours) {
    train_schedule *t = find_schedule(50, 0, const_cast<char*>("Moscow"));
    ASSERT_EQ(t, nullptr);
}

TEST(schedule, IncorrectMinutes) {
    train_schedule *t = find_schedule(0, 100, const_cast<char*>("Moscow"));
    ASSERT_EQ(t, nullptr);
}

TEST(schedule, NullptrSchedule) {
    schedule = nullptr;
    train_schedule *t = find_schedule(0, 0, const_cast<char*>("Moscow"));
    ASSERT_EQ(t, nullptr);
}

TEST(train_schedule, NullptrTrainSchedule) {
    train_schedule *input = nullptr;
    train_schedule *output = find_by_station_name(input, const_cast<char*>("Some Name"));
    ASSERT_EQ(output, nullptr);
}

int main(int argc, char** argv) {
    prepare_test_data();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
