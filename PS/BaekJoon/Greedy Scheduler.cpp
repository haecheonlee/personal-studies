#include <iostream>
#include <queue>

using namespace std;
using pi=pair<int,int>;

int main() {
	int K,N;
	cin>>K>>N;
	
	int a[N], ans[N];
	for(int i=0; i<N; i++) cin>>a[i];

	priority_queue<int> list;
	for(int i=1; i<=K; i++) list.push(-i);
	
	priority_queue<pi> q, temp;
	for(int i=0; i<N; i++) {
		if(list.size()) {
			int L=-list.top();
			list.pop();
			
			ans[i]=L;
			q.push({-a[i], L});
		} else {
			int removed=-q.top().first;
			while(removed==-q.top().first && q.empty()==false) {
				list.push(-q.top().second);
				q.pop();
			}

			while(!q.empty()) {
				temp.push(q.top());
				q.pop();
			}
			
			while(!temp.empty()) {
				int updated=(-temp.top().first)-removed;
				q.push({-updated, temp.top().second});
				temp.pop();
			}
			
			i--;
		}
	}
	
	for(int i=0; i<N; i++) cout<<ans[i]<<' ';
	
	return 0;
}
