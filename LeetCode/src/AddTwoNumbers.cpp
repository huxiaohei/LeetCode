/*================================================================
* Description
* Email huxiaoheigame@gmail.com
* Created on 2020 6 26 20:4:1
* Copyright (c) 2020 huxiaohei
================================================================*/

#include "AddTwoNumbers.hpp"

void AddTwoNumbers::test() {
	AddTwoNumbers instance = AddTwoNumbers();
	vector<int> nums1 = {5, 5};
	vector<int> nums2 = {5, 4};
	ListNode *l1 = instance.createNodeList(nums1);
	ListNode *l2 = instance.createNodeList(nums2);
	ListNode *res = instance.addTwoNumbers(l1, l2);
	instance.printListNode(res);
	//instance.destroyListNode(l1);
	//instance.destroyListNode(l2);
	//instance.destroyListNode(res);
}

ListNode * AddTwoNumbers::createNodeList(vector<int> &nums) {
	ListNode *res = new ListNode(nums[0]);
	ListNode *tmp = res;
	for (int i = 1; i < nums.size(); i++) {
		tmp->next = new ListNode(nums[i]);
		tmp = tmp->next;
	}
	return res;
}

void AddTwoNumbers::printListNode(ListNode *l) {
	ListNode *tmp = l;
	cout << "list: ";
 	while (tmp) {
		cout << tmp->val << "  ";
		tmp = tmp->next;
	}
	cout << endl;
}

void AddTwoNumbers::destroyListNode(ListNode *l) {
	while (l) {
		ListNode *tmp = l;
		l = l->next;
		delete tmp;
		tmp = NULL;
	}
}

ListNode * AddTwoNumbers::addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *res = l1;
	ListNode *lastNode = l1;
	int flag = 0;
	while (l1 && l2) {
		int sum = l1->val + l2->val + flag;
		l1->val = sum % 10;
		flag = sum / 10;
		lastNode = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1 == NULL) {
		lastNode->next = l2;
		l1 = l2;
	}
	while (l1 && flag != 0) {
		int sum = l1->val + flag;
		l1->val = sum % 10;
		flag = sum / 10;
		lastNode = l1;
		l1 = l1->next;
	}
	if (flag != 0) {
		lastNode->next = new ListNode(flag);
	}
	return res;
}

