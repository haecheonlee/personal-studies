class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int arr[cost.size()];
        
        arr[0]=cost[0];arr[1]=cost[1];    
        for(int i=2; i<cost.size(); i++) arr[i]=min(arr[i-1], arr[i-2])+cost[i];
        
        return min(arr[cost.size()-1],arr[cost.size()-2]);
    }
};

/*
https://leetcode.com/problems/min-cost-climbing-stairs/
*/
