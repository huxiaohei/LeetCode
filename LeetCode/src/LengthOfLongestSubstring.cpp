/*================================================================
* Description 
* Email huxiaoheigame@gmail.com
* Created on 2020 6 27 23:41:29
* Copyright (c) 2020 huxiaohei
================================================================*/

#include "LengthOfLongestSubstring.hpp"
#include <unordered_map>

void LengthOfLongestSubstring::test() {
	LengthOfLongestSubstring lengthOfLongestSubstring = LengthOfLongestSubstring();
	int len = lengthOfLongestSubstring.lengthOfLongestSubstring("pwwkew");
	cout << "len = " << len << endl;
}

int LengthOfLongestSubstring::lengthOfLongestSubstring(string s) {
	unordered_map<char, int> map = {};
	int len = 0;
	int start = 0;
	int end = 0;
	while (end < s.size()) {
		if (map.find(s.at(end)) != map.end() && map[s.at(end)] >= start) {
			len = end - start > len ? end - start : len;
			start = map[s.at(end)] + 1;
		}
		map[s.at(end)] = end;
		end++;
	}
	return end - start > len ? end - start : len;
}