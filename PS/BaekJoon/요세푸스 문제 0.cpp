#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);

	vector<int> result;
	while(!q.empty()) {
		for(int i=0; i<k-1; i++) {
			int front=q.front();
			q.pop();
			q.push(front);
		}
		
		int popped=q.front();
		q.pop();
		
		result.push_back(popped);
	}

	cout<<"<";
	for(int i=0; i<result.size(); i++) {
		cout<<result[i];
		if(i!=result.size()-1) cout<<", ";
	}
	cout<<">";

	return 0;
}

/*
boj.kr/11866

INPUT:
7 3

OUTPUT:
<3, 6, 2, 7, 5, 1, 4>
*/
