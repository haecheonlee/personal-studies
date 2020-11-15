#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        
        if(N <= 2) {
            cout << 1 <<'\n' << 2 << '\n';
        } else {
            int a[N + 1];
            for(int i = 1; i <= N; i++) a[i] = i;
            
            vector<int> ans;
            for(int i = 1; i <= 10000; i++) {
                int skip = 1, mx = a[1];
                bool is_all_same = true;
                int mn = a[1];
                
                for(int j = 2; j <= N; j++) {
                    mn = min(a[j], mn);
                    if(a[j] > mx) mx = a[j], skip = j;
                    if(a[j] != a[j - 1]) is_all_same = false;
                }
                
                if(is_all_same) break;
                ans.push_back(skip);
                
                for(int j = 1; j <= N; j++) {
                    if(j == skip) continue;
                    a[j] += (mx - mn);
                }
            }
            
            cout << sz(ans) << '\n';
            for(auto& x: ans) cout << x << ' ';
            cout << '\n';
        }
    }
    
	return 0;
}
