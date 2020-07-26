/*================================================================
* Description
* Email huxiaoheigame@gmail.com
* Created on 2020 6 26 18:57:10
* Copyright (c) 2020 huxiaohei
================================================================*/

#include "TwoSum.hpp"
#include <unordered_map>

void TwoSum::test() {
	TwoSum instance = TwoSum();
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	vector<int> indexs = instance.twoSum_1(nums, target);
	cout << "indexs[0] = " << indexs[0] << " index[1] = " << indexs[1] << endl;
	indexs = instance.twoSum_1(nums, target);
	cout << "indexs[0] = " << indexs[0] << " index[1] = " << indexs[1] << endl;
}

vector<int> TwoSum::twoSum_1(vector<int> &nums, int target) {
	if (nums.size() < 2) {
		return { -1, -1 };
	}
	for (int i = 0; i < nums.size(); i++) {
		int tmp = target - nums[i];
		for (int j = i + 1; j < nums.size(); j++) {
			if (tmp == nums[j]) {
				return { i, j };
			}
		}
	}
	return { -1, -1 };
}

vector<int> TwoSum::twoSum_2(vector<int> &nums, int target) {
	unordered_map<int, int> map = {};
	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++) {
		int tmp = target - nums[i];
		if (map.find(tmp) != map.end() && map.at(tmp) != i) {
			return { i, map.at(tmp) };
		}
	}
	return {-1, -1};
}