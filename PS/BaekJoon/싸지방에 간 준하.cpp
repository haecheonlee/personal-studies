#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
using PI=pair<int,int>;

priority_queue<PI, vector<PI>, greater<PI>> pq;
set<int> used;
int cnt[100001] {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<PI> a(n);
	for(int i=0; i<n; i++) cin>>a[i].first>>a[i].second;
	sort(a.begin(), a.end());
	
	int pos=0;
	for(int i=0; i<n; i++) {
		int p=a[i].first;
		int q=a[i].second;
		
		while(!pq.empty() && pq.top().first<=p) {
			used.insert(pq.top().second);
			pq.pop();
		}
		
		if(used.empty()) {
			cnt[pos]+=1;
			pq.push(make_pair(q,pos));
			
			pos++;
		} else {
			auto next=used.begin();
			cnt[*next]+=1;
			pq.push(make_pair(q, *next));
			
			used.erase(next);
		}
	}
	
	cout<<pos<<'\n';
	for(int i=0; i<pos; i++) cout<<cnt[i]<<" ";

	return 0;
}
