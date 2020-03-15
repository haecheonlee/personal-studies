#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n,num;
	cin>>n;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for(int i=0; i<n; i++) { 
		cin>>num;
		
		if(num==0) {
			if(pq.empty()) cout<<0<<'\n';
			else {
				cout<<pq.top().second<<'\n';
				pq.pop();
			}
		} else {
			pq.push({abs(num),num});
		}
	}
	
	return 0;
}

/*
INPUT:
18
1
-1
0
0
0
1
1
-1
-1
2
-2
0
0
0
0
0
0
0

OUTPUT:
-1
1
0
-1
-1
1
1
-2
2
0
*/
