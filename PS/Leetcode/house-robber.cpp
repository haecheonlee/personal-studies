class Solution {
public:
    int DP[10001];
    int rob(vector<int>& nums) {
        int m=0;
        for(int i=0; i<nums.size(); i++) {
            if(i<2) DP[i]=nums[i];
            else if(i==2) DP[i]=DP[i-2]+nums[i];
            else DP[i]=max(DP[i-2], DP[i-3])+nums[i];
            
            m=max(DP[i], m);
        }
        
        return m;
    }
};

/*
  https://leetcode.com/problems/house-robber/
*/
