#include <iostream>
#include <set>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    
    while(T--) {
        int N;
        cin>>N;
        
        set<int> list;
        for(int i = 1; i <= N * 2; i++) list.insert(i);
        
        int b[N + 1];
        for(int i = 1; i <= N; i++) {
            cin>>b[i];
            list.erase(b[i]);
        }
        
        vector<int> ans;
        for(int i = 1; i <= N; i++) {
            ans.push_back(b[i]);
            
            auto it = list.lower_bound(b[i]);
            if(it == list.end()) break;
            else { ans.push_back(*it); list.erase(it); }
        }
            
        if(sz(ans) == N * 2) for(auto& x : ans) cout<<x<<' ';
        else cout<<-1;
    
        cout<<'\n';
    }

	return 0;
}
