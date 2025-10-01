class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &cur) {
        if (nums.empty()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            cur.push_back(nums[0]);
            nums.erase(nums.begin());
            backtrack(ans, nums, cur);
            nums.push_back(cur[cur.size() - 1]);
            cur.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> helper;
        backtrack(ans, nums, helper);
        return ans;
    }
};