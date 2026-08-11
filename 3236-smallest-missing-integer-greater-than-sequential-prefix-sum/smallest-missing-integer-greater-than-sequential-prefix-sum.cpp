class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        // Store all numbers
        unordered_set<int> st(nums.begin(), nums.end());

        // Find sum of longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } 
            else {
                break;
            }
        }

        // Find smallest missing number >= sum
        int x = sum;

        while (st.count(x)) {
            x++;
        }

        return x;
    }
};