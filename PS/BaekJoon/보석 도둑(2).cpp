#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Jewel {
	int m,v,w;
};

int main() {
	int n,k;
	cin>>n>>k;
	
	vector<Jewel> a(n+k);
	for(int i=0; i<n; i++) cin>>a[i].m>>a[i].v;
	
	for(int i=0; i<k; i++) {
		cin>>a[i+n].m;
		a[i+n].w=1;
	}
	
	sort(a.begin(), a.end(), [](const Jewel &u, const Jewel &v) {
		return u.m<v.m || (u.m==v.m && u.w<v.w);	
	});
	
	priority_queue<int> q;
	long long ans=0;
	for(auto &p : a) {
		if(p.w==0) {
			q.push(p.v);
		} else {
			if(!q.empty()) {
				ans+=(long long) q.top();
				q.pop();
			}
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
3 2
1 65
5 23
2 99
10
2

OUTPUT:
164
*/
