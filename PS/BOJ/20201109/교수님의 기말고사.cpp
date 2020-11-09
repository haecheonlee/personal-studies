#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S;
    cin >> N >> M >> S;
    
    vector<pii> a;
    a.push_back({0,0});
    a.push_back({S,S});
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        a.push_back({x,y});
    }
    sort(a.begin(), a.end());
    
    int ans = -1;
    for(int i = 0; i < (int)a.size() - 1; i++) {
        if(a[i].first + a[i].second + M <= a[i + 1].first) {
            ans = a[i].first + a[i].second;
            break;
        }
    }
    cout << ans;

    return 0;
}
