#include "../my_list/TPolinom.h"
#include "gtest.h"

TEST(THeadList, Can_Create_List)
{
    ASSERT_NO_THROW(THeadList<int> list_project);
}


TEST(THeadList, Can_Insert_First)
{
    THeadList<int> list_project;
    ASSERT_NO_THROW(list_project.InsFirst(1));

    int value = list_project.Get_First();
    EXPECT_EQ(1, value);
}
TEST(THeadList, Can_Delete_First)
{
    THeadList<int> list_project;
    list_project.InsFirst(1);
    list_project.InsFirst(2);
    ASSERT_NO_THROW(list_project.DelFirst());

    int value = list_project.Get_First();
    EXPECT_EQ(1, value);
}
TEST(THeadList, Cant_Delete_First_In_Empty_List)
{
    THeadList<int> list_project;
    ASSERT_ANY_THROW(list_project.DelFirst());
}
TEST(THeadList, Can_Insert_Last)
{
    THeadList<int> list_project;
    ASSERT_NO_THROW(list_project.InsLast(1));

    list_project.InsLast(2);
    int value = list_project.Get_Last();
    EXPECT_EQ(2, value);
}
TEST(THeadList, Can_Delete_Last)
{
    THeadList<int> list_project;
    int value;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.setPos(1);
    ASSERT_NO_THROW(list_project.DelCurr());

    value = list_project.Get_Last();
    EXPECT_EQ(1, value);
}
TEST(THeadList, Cant_Delete_Last_In_Empty_List)
{
    THeadList<int> list_project;
    ASSERT_ANY_THROW(list_project.DelCurr());
}
TEST(THeadList, Can_Reset_Current)
{
    THeadList<int> list_project;
    int value1, value2;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(1);
    value1 = list_project.Get_pos();
    ASSERT_NO_THROW(list_project.Reset());

    value2 = list_project.Get_pos();
    EXPECT_NE(value1, value2);
    EXPECT_EQ(value2, 0);
}
TEST(THeadList, Can_Go_Next)
{
    int value1;
    THeadList<int> list_project;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(1);
    ASSERT_NO_THROW(list_project.GoNext());

    value1 = list_project.Get_pos();
    EXPECT_EQ(value1, 2);
}
TEST(THeadList, Can_Delete_List)
{
    int value1;
    THeadList<int> list_project;
    list_project.InsLast(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    ASSERT_NO_THROW(list_project.DelList());

    EXPECT_EQ(list_project.Get_pos(), -1);
    EXPECT_EQ(list_project.Get_length(), 0);
    EXPECT_EQ(list_project.Is_Empty(), 1);
}
TEST(THeadList, Can_Insert_First_By_InsCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.setPos(0);
    list_project.InsCurr(0);
    value = list_project.Get_First();
    EXPECT_EQ(0, value);
}
TEST(THeadList, Can_Insert_In_Center_By_InsCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(1);
    ASSERT_NO_THROW(list_project.InsCurr(4));

    value = list_project.Get_pos_value(1);
    EXPECT_EQ(4, value);
}
TEST(THeadList, Can_Insert_In_End_By_InsCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(2);
    ASSERT_NO_THROW(list_project.InsCurr(4));

    value = list_project.Get_pos_value(2);
    EXPECT_EQ(4, value);
}
TEST(THeadList, Can_Delete_First_By_DelCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.setPos(0);
    ASSERT_NO_THROW(list_project.DelCurr());

    value = list_project.Get_First();
    EXPECT_EQ(2, value);
}
TEST(THeadList, Can_Delete_From_Center_By_DelCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(1);
    ASSERT_NO_THROW(list_project.DelCurr());

    value = list_project.Get_pos_value(1);
    EXPECT_EQ(3, value);
}
TEST(THeadList, Can_Delete_Last_By_DelCurr)
{
    THeadList<int> list_project;
    int value;
    list_project.InsFirst(1);
    list_project.InsLast(2);
    list_project.InsLast(3);
    list_project.setPos(2);
    ASSERT_NO_THROW(list_project.DelCurr());

    value = list_project.Get_Last();
    EXPECT_EQ(2, value);

}
