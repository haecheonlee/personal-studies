#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n,x;
	cin>>n;
	
	priority_queue<int,vector<int>,greater<int>> pq;
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
boj.kr/1927

INPUT:
9
0
12345678
1
2
0
0
0
0
32

OUTPUT:
0
1
2
12345678
0
*/
