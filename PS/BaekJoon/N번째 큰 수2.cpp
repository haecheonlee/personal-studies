#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,num;
	cin>>n;
	
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0; i<n; i++) {
		cin>>num;
		pq.push(num);
	}
	
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n; j++) {
			cin>>num;
			
			if(pq.top()<num) {
				pq.push(num);
				pq.pop();
			}
		}
	}
	
	cout<<pq.top();

	return 0;
}

/*
INPUT:
5
12 7 9 15 5
13 8 11 19 6
21 10 26 31 16
48 14 28 35 25
52 20 32 41 49

OUTPUT:
35
*/
