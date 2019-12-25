#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin>>N>>K;

	queue<int> q;
	for(int i=1; i<=N; i++) {
		q.push(i);
	}

	queue<int> result;
	while(!q.empty()) {
		for(int i=0; i<K-1; i++) {
			int front = q.front();
			q.pop();
			q.push(front);
		}
		
		int last = q.front();
		result.push(last);
		q.pop();
	}

	cout<<"<";
	while(!result.empty()) {
		if(result.size() != 1) cout<<result.front()<<", ";
		else cout<<result.front();
		
		result.pop();
	}
	cout<<">";

	return 0;
}

/*
boj.kr/1158

INPUT:
7 3

OUTPUT:
<3, 6, 2, 7, 5, 1, 4>
*/
