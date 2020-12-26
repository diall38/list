#include "tlist.h"

#include <gtest/gtest.h>

TEST(Tlist, can_create_list)
{
	ASSERT_NO_THROW(List<int> lst);
}
TEST(Tlist, can_copy_list)
{
	List<int> lst1;
	ASSERT_NO_THROW(List<int> lst2(lst1));
}
TEST(Tlist, can_get_size)
{
	List<int> lst1;
	int num = 3;
	lst1.InsertFirst(num);
	EXPECT_EQ(lst1.get_size(), 1);
	ASSERT_NO_THROW(lst1.get_size());
}
TEST(Tlist, correct_check_of_empty) {
	List<int> lst1, lst2;
	lst2.InsertFirst(2);
	EXPECT_EQ(lst1.empty(), true);
	EXPECT_EQ(lst2.empty(), false);
}
TEST(Tlist, can_insert_first) {
	List<int> lst1;
	int num = 5;
	ASSERT_NO_THROW(lst1.InsertFirst(num));
}
TEST(Tlist, can_insert) {
	List<int> lst1;
	int num1 = 5, num2 = 6, num3 = 7;
	lst1.InsertFirst(num1);
	lst1.InsertFirst(num2);
	List<int>::iterator it(lst1.get_first());
	++it;
	ASSERT_NO_THROW(lst1.Insert(*it, num3));
}
TEST(Tlist, can_delete_first) {
	List<int> lst1;
	lst1.InsertFirst(2);
	lst1.InsertFirst(3);
	ASSERT_NO_THROW(lst1.DeleteFirst());
	EXPECT_EQ(lst1.get_size(),1);
}
TEST(Tlist, can_delete_node) {
	List<int> lst1;
	List<int>::iterator it = lst1.begin();
	int num = 30;
	lst1.InsertFirst(2);
	lst1.InsertFirst(30);
	ASSERT_NO_THROW(lst1.Delete(*it));
	lst1.Print();
	EXPECT_EQ(lst1.get_size(), 1);
}
TEST(Tlist, can_search_node) {
	List<int> lst1;
	int num1 = 1, num2 = 2, num3 = 3;
	lst1.InsertFirst(num1);
	lst1.InsertFirst(num2);
	lst1.InsertFirst(num3);
	List<int>::iterator iter1(lst1.get_first());
	++iter1;
	EXPECT_EQ(iter1, lst1.Search(num2));
}
TEST(Iterator, can_create) {
	ASSERT_NO_THROW(List<int>::iterator it);
}
TEST(Iterator, can_copy) {
	List<int>::iterator it2;
	ASSERT_NO_THROW(List<int>::iterator it1(it2));
}
TEST(Iterator, operator_plus_plus_is_correct)
{
	List<int> lst1;
	lst1.InsertFirst(1);
	lst1.InsertFirst(2);
	lst1.InsertFirst(3);
	lst1.Print();
	List<int>::iterator iter1(lst1.get_first());
	++iter1;
	EXPECT_EQ(iter1->data, 2);
	List<int>::iterator iter2(iter1++);
	EXPECT_EQ(iter2->data, 2);
	EXPECT_EQ(iter1->data, 1);
}
TEST(Iterator, operator_equal_is_correct)
{
	List<int> lst1;
	lst1.InsertFirst(1);
	lst1.InsertFirst(2);
	lst1.InsertFirst(3);
	List<int>::iterator iter1(lst1.get_first());
	++iter1;
	List<int>::iterator iter2(iter1);
	EXPECT_EQ(iter2==iter1, true);
}
TEST(Iterator, operator_not_equal_is_correct)
{
	List<int> lst1;
	lst1.InsertFirst(1);
	lst1.InsertFirst(2);
	lst1.InsertFirst(3);
	List<int>::iterator iter1(lst1.get_first());
	++iter1;
	List<int>::iterator iter2(iter1++);
	EXPECT_EQ(iter2!=iter1, true);
}