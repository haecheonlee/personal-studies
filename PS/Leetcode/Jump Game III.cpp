class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int MAX=5*1e5+1;
        bool check[MAX] {false};
                
        queue<int> q;
        q.push(start);
        check[start]=true;
        
        while(!q.empty()) {
            int current=q.front();
            q.pop();
        
            if(arr[current]==0) return true;

            int next=arr[current]+current;
            if(next<arr.size() && check[next]==false) {
                q.push(next);
                check[next]=true;
            }
            
            next=current-arr[current];
            if(0<=next && check[next]==false) {
                q.push(next);
                check[next]=true;
            }
        }
        
        return false;
    }
};
