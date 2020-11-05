#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;
        
        set<int> a;
        for(int i = 1; i <= N; i++) { 
            int x;
            cin >> x;
            
            if(!(x&1)) a.insert(x);
        }
        
        if(a.empty()) {
            cout << 0;
        }
        else {
            int ans = 0;
            while(!a.empty()) {
                auto it = a.end();
                it--;
                int b = *it;
                
                while(!(b&1)) {
                    ans++;
                    if(a.find(b) != a.end()) a.erase(b);
                    b /= 2;
                }
            }
            cout << ans;
        }
        
        cout << '\n';
    }

	return 0;
}
