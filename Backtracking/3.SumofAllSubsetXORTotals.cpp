class Solution {
public:

	int solve(vector<int>& nums, int level, int currXor){

		// Base Condition
		if(level == nums.size()){
			return currXor;
		}

		int include = solve(nums, level + 1, currXor ^ nums[level]);
		int exclude = solve(nums, level + 1, currXor);

		return include + exclude;
	}

	int subsetXORSum(vector<int>& nums) {
		return solve(nums, 0, 0);
	}

};
