#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

const int MAX=1e3+1;

vector<pii> a[MAX];
vector<pii> places, hotels;
int d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin>>N;

	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			int c;
			cin>>c;

			if(c!=0) a[i].push_back({j,c});
		}
	}

	int P,Q;
	cin>>P>>Q;

	places.resize(P);
	for(int i=0; i<P; i++) cin>>places[i].first>>places[i].second;

	hotels.resize(Q);
	for(int i=0; i<Q; i++) cin>>hotels[i].first>>hotels[i].second;

	memset(d, -0x3f, sizeof(d));
	priority_queue<pii> q;
	for(auto& p : places) {
		q.push({p.second, p.first});
		d[p.first]=p.second;	
	}

	while(!q.empty()) {
		int c=q.top().first;
		int x=q.top().second;
		q.pop();

		if(d[x]>c) continue;
		for(auto& next : a[x]) {
			int y=next.first;
			int nc=c-next.second;
			
			if(d[y]<nc) {
				d[y]=nc;
				q.push({nc,y});
			}
		}
	}

	int ans=-1e9;
	for(auto& q : hotels) ans=max(ans, q.second + d[q.first]);
	cout<<ans;

	return 0;
}
