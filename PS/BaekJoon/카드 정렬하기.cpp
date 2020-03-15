#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n,card;
	cin>>n;
	
	priority_queue<int,vector<int>,greater<int>> pq;
	while(n--) {
		cin>>card;
		pq.push(card);
	}
	
	int sum=0;
	while(pq.size()>1) {
		int merge=0;
		merge+=pq.top();pq.pop();
		merge+=pq.top();pq.pop();
		pq.push(merge);
		sum+=merge;
	}
	
	cout<<sum;
	
	return 0;
}

/*
INPUT:
3
10
20
40

OUTPUT:
100
*/
