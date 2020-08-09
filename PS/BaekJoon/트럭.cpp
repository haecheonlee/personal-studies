#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int main() {
	int N,W,L;
	cin>>N>>W>>L;
	
	int a[N];
	for(int i=0; i<N; i++) cin>>a[i];
	
	int t=0, idx=0, weight=0;
	queue<pi> q;
	while(1) {
		if(q.size()) {
			if((t-q.front().second)>=W) {
				weight-=q.front().first;
				q.pop();
			}
		}
		
		if(idx<N) {
			if(weight+a[idx]<=L) {
				weight+=a[idx];
				q.push(make_pair(a[idx],t));
				idx++;
			}
		}
		
		if(q.empty()) break;
		t++;
	}
	cout<<t+1;
	
	return 0;
}
