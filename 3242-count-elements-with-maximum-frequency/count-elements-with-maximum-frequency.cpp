class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        int maxfr = *max_element(freq.begin(), freq.end());
        int result = 0;
        for(int i = 1; i<101; i++){
            if(freq[i]==maxfr) result += freq[i];
        }
        return result;
    }
};