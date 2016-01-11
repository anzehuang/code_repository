#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> r;
		if (nums.size()==0 || sizeof(target)==0) {
			return r;	
		}
		int m, n;
		int l = nums.size();
		for (int i=0; i<l; i++) {
			for (int j=i+1; j<l; j++) {
				if (nums[i]+nums[j]==target) {
					r.push_back(i+1);
					r.push_back(j+1);
					return r;
				}
				else {
					continue;
				}
			} 
		}
		return r;
	}
};

class Solution2 {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> r;
			if(nums.size()==0 || sizeof(target)==0) {
				return r;
			}
			map<int, int> temp;
			map<int, int>::iterator iter;
			int len = nums.size();
			
			for (int i=0; i<len; i++) {
				iter = temp.find(nums[i]);
				// cout << iter->first << " " << iter->second << endl;
				if (iter==temp.end()) {
					temp.insert(pair<int, int>(target-nums[i], i+1));
				}
				else {
					r.push_back(temp[nums[i]]);
					r.push_back(i+1);
				}
			}
			return r;
		}
};

int main() {
	int temp[3] = {3, 2, 4};
	vector<int> nums(temp, temp+sizeof(temp)/sizeof(temp[0]));
	int target = 6;
	Solution s;
	vector<int> r = s.twoSum(nums, target);
	copy(r.begin(), r.end(), ostream_iterator<int> (cout, "\n"));
	cout << endl;
	Solution2 s2;
	vector<int> r2 = s2.twoSum(nums, target);
	copy(r2.begin(), r2.end(), ostream_iterator<int> (cout, "\n"));
	return 0;
}
