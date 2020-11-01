#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

vector<pii> a[MAX];
int d[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    
    string s[N + 1];
    for(int i = 1; i <= N; i++) cin >> s[i];
    
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            int cost = 0;
            for(int k = 0; k < sz(s[i]); k++) 
                cost += (s[i][k] - s[j][k]) * (s[i][k] - s[j][k]); 
            
            a[i].push_back({j, cost});
            a[j].push_back({i, cost});
        }
    }
    
    int S,E;
    cin>>S>>E;
    
    memset(d, 0x3f, sizeof(d));
    priority_queue<pii> q;
    q.push({0,S});
    d[S] = 0;
    
    while(!q.empty()) {
        int c = -q.top().first;
        int x = q.top().second;
        q.pop();
        
        if(d[x] < c) continue;
        for(auto& next : a[x]) {
            int y = next.first;
            int nc = c + next.second;
            
            if(d[y] > nc) {
                d[y] = nc;
                q.push({-nc, y});
            }
        }
    }
    
    cout<<d[E];
    
	return 0;
}
