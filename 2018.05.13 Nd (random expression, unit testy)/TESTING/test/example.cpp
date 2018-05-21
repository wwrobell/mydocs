#include "gtest/gtest.h"
#include "example.hpp"
#include "list.h"
#include <cmath>

//TEST(ExampleTest, StringComparisonWorks) {
//  EXPECT_STREQ("Ala", "Ala");
//  EXPECT_STRNE("Ala", "kot");
//}
//
//TEST(ExampleTest, BrokenTest) {
//    const char* text = "Ala";
//    char buf[sizeof(text)];
//    strcpy(buf, text);
//    EXPECT_EQ(text, buf);
//}
//
//TEST(ExampleTest, FiveReturnsFive) {
//    EXPECT_EQ(five(), 5);
//}
//
//TEST(ExampleTest, PassedTest) {
//    EXPECT_EQ(5, 5);
//}

TEST(RootsTest, PositiveDelta) {
    Solution s = roots(1,-3,2);
    constexpr double eps = 1e-5;
    ASSERT_EQ(s.count,2);
    EXPECT_DOUBLE_EQ(s.x1, 2);
    EXPECT_DOUBLE_EQ(s.x2, 1);
    //EXPECT_TRUE(std::abs(s.x1 - 1.0) < eps || std::abs(s.x1 - 2.0) < eps );
    //EXPECT_TRUE(std::abs(s.x2 - 1.0) < eps || std::abs(s.x2 - 2.0) < eps );
    EXPECT_NE(s.x1, s.x2);
    EXPECT_FALSE(s.identity);
}


TEST(RootsTest, ZeroDelta) {
    Solution s = roots(1,-2,1);
    ASSERT_EQ(s.count,1);
    EXPECT_EQ(s.x1, s.x2);
    EXPECT_FALSE(s.identity);
}

TEST(RootsTest, IdentityCheckWorks) {
    Solution s = roots(0,0,0);
    EXPECT_TRUE(s.identity);
}


//LIST TESTING
TEST(ExampleTest, containsInsertedElem) {
    List l;
    l.insert(2);
    EXPECT_EQ(l.contains(2),true);
}

TEST(ExampleTest, notContainsNotInsertedElem) {
    List l;
    l.insert(2);
    EXPECT_EQ(l.contains(3),false);
}

TEST(ExampleTest, constructsFromArray) {
    constexpr int arr1[] = {1,2,3,4,5,6,7,8,9};
    List* l = List::fromArray(arr1, 9);
    EXPECT_EQ(l->contains(8),true);
}
