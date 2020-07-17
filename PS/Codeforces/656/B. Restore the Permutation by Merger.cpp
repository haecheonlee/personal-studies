/* Codeforces */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    
    while(T--) {        
        int N;
        cin>>N;
        
        bool check[N+1] {false};
        vector<int> ans;
        int L=N*2;
        for(int i=0; i<L; i++) {
            int x;
            cin>>x;
            
            if(check[x]==false) {
                check[x]=true;
                ans.push_back(x);
            }
        }
        
        for(auto x : ans) cout<<x<<" ";
        cout<<endl;
    }

	return 0;
}
