class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> s;
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && nums[s.top()]<nums[i]) {
                result[s.top()]=nums[i];
                s.pop();
            }
            
            s.push(i);
        }
        
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && nums[s.top()]<nums[i]) {
                result[s.top()]=nums[i];
                s.pop();
            }
        }
        
        return result;
    }
};
