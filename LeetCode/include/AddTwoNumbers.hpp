/*================================================================
* Description
* Email huxiaoheigame@gmail.com
* Created on 2020 6 26 20:3:50
* Copyright (c) 2020 huxiaohei
================================================================*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers {
public:
	static void test();
private:
	ListNode * addTwoNumbers(ListNode *l1, ListNode *l2);
	ListNode * createNodeList(vector<int> &nums);
	void printListNode(ListNode *l1);
	void destroyListNode(ListNode *l);
};