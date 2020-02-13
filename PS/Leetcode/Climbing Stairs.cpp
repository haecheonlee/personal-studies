class Solution {
public:
    int climbStairs(int n) {
        int d[n+1];

        d[0]=1;
        if(n>=1) d[1]=1;
        for(int i=2; i<=n; i++) d[i]=d[i-1]+d[i-2];
        
        return d[n];
    }
};

/*
https://leetcode.com/problems/climbing-stairs/
*/
