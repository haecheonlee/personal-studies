#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using plli=pair<ll,int>;

const int MAX=1e5+1;

ll N,M,D,E;
vector<pii> a[MAX];
ll h[MAX];
ll d1[MAX], d2[MAX];

void dijkstra(int start, ll *d) {
    fill(d, d+N+1, LLONG_MAX);
    
    // ascending
    priority_queue<plli> q;
    q.push({0,start});
    d[start]=0;
    
    while(!q.empty()) {
        ll c=-q.top().first;
        int x=q.top().second;
        q.pop();
        
        if(d[x]<c) continue;
        for(auto& next : a[x]) {
            int y=next.first;
            ll nc=c+next.second;
            
            // only ascending allowed
            if(h[y]<=h[x]) continue;
            if(d[y]>nc) {
                d[y]=nc;
                q.push({-nc,y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M>>D>>E;
    
    for(int i=1; i<=N; i++) cin>>h[i];
    for(int i=0; i<M; i++) {
        int u,v,c;
        cin>>u>>v>>c;
        
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
        
    // ascending from 1
    dijkstra(1,d1);
        
    // ascending from N
    dijkstra(N,d2);

    ll ans=LLONG_MIN;
    for(int i=2; i<N; i++) {
        if(d1[i]!=LLONG_MAX && d2[i]!=LLONG_MAX) {
            ans = max(ans, (h[i] * E) - ((d1[i] + d2[i]) * D));
        }
    }
    
    // print answer
    if(ans==LLONG_MIN) cout<<"Impossible";
    else cout<<ans;
    
    return 0;
}
