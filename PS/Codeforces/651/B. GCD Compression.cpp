/* Codeforces */

#include <iostream>
#include <vector>

using namespace std;
const int MAX=2e6;

int n;
int a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--) {
        cin>>n;
        
        vector<int> odd, even;
        for(int i=1; i<=2*n; i++) {
            cin>>a[i];
            
            if(a[i]%2) odd.push_back(i);
            else even.push_back(i);
        }
        
        vector<pair<int,int>> ans;
        for(int i=0; i+1<odd.size(); i+=2) {
            ans.push_back({odd[i], odd[i+1]});
        }
        
        for(int i=0; i+1<even.size(); i+=2) {
            ans.push_back({even[i], even[i+1]});
        }
        
        for(int i=0; i<n-1; i++) {
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
    }

	return 0;
}
