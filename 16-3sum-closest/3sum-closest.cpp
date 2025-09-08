/*  
          ／l、  
        （ﾟ､ ｡７          
          l、 ~ヽ  
          じしf_, )ノ  
*/

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<int>
#define pii pair<int,int>
#define MOD 1000000007
#define INF 1e18

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
        sort(all(nums));
        int n = nums.size();
        int best = nums[0] + nums[1] + nums[2];
        for(int i = 0;i < n - 2;i++){
            int l = i + 1,r = n - 1;
            while(l < r){
                int sm = nums[i] + nums[l] + nums[r];
                if(abs(sm - target) < abs(best - target)) best = sm;
                if(sm < target) l++;
                else if(sm > target) r--;
                else return sm;
            }
        }
        return best;     
    }
};

//   Sayonara ✨ さよなら