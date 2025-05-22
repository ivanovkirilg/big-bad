#include "Exercise.hpp"

#include "gmock/gmock.h"

TEST(TestExercise, SaysExercise)
{
    ASSERT_THAT(exercise(), ::testing::HasSubstr("Exercise"));
}
