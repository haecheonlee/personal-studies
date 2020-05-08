#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using PI=pair<int,int>;

int ans=0;

int main() {
	int n;
	cin>>n;
	
	vector<int> a[1001];
	for(int i=0; i<n; i++) {
		int day, score;
		cin>>day>>score;
		
		a[day].push_back(score);
	}

	for(int i=1; i<=1000; i++) sort(a[i].begin(), a[i].end());
	
	priority_queue<int> pq;
	for(int i=1000; i>=1; i--) {
		for(auto &p : a[i]) pq.push(p);
		
		if(pq.empty()==false) {
			ans+=pq.top();
			pq.pop();
		}
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
7
4 60
4 40
1 20
2 50
3 30
4 10
6 5

OUTPUT:
185
*/
