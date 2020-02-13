class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum[nums.size()]{0};
        
        int largest=nums[0];
        for(int i=0; i<nums.size(); i++) {
            sum[i]=nums[i];
            
            if(i>0) {
                if(sum[i]<sum[i-1]+nums[i]) {
                    sum[i]=sum[i-1]+nums[i];
                }
            }
            
            largest=max(sum[i],largest);
        }
        
        return largest;
    }
};

/*
https://leetcode.com/problems/maximum-subarray
*/
