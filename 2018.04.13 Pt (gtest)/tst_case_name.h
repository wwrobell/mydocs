#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;
using namespace std;

class CommonResources:public testing::Test
{
protected:
    CommonResources()
    {
        cout<<"creating fixture";
    }

    ~CommonResources()
    {
        cout<<"Deleting fixture";
    }

    void SetUp() {cout<<"Setup"<<endl;}
    void TearDown() {cout<<"TearDown"<<endl;}
    int resource;
};

class FIFO
{
public:
    int maxsize;
    int size = 0;

    FIFO(int n){
        maxsize = n;
    }

    int getmaxsize(){
        return maxsize;
    }

    void putelement(int i){
        size+=i;
        if (size>maxsize){
            throw("error");
        }
    }

    int getsize(){
        return size;
    }
};

TEST(case_name, setname)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(case_name, nieprzechodzi)
{
   ASSERT_EQ(1, 2);

}

TEST(case_name, DISABLE_bb2)
{  EXPECT_EQ(2, 2);
   //ASSERT_EQ(1, 2);
   EXPECT_EQ(2, 3);
}

TEST_F(CommonResources, bbbb)
{
    FIFO kolejka(10);
    kolejka.putelement(3);
    EXPECT_EQ(kolejka.getsize(),3);
    EXPECT_EQ(kolejka.getmaxsize(),10);

}

TEST_F(CommonResources, ccc)
{
    FIFO kolejka(2);
    EXPECT_ANY_THROW(kolejka.putelement(3));
}

