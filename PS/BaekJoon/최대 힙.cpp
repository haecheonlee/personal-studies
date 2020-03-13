#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	priority_queue<int> pq;
	
	int n,x;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		cin>>x;
		
		if(x==0) {
			if(pq.empty()) cout<<0<<'\n';
			else {
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		} else {
			pq.push(x);
		}
	}
	
	return 0;
}

/*
boj.kr/11279

INPUT:
13
0
1
2
0
0
3
2
1
0
0
0
0
0

OUTPUT:
0
2
1
3
2
1
0
0
*/
