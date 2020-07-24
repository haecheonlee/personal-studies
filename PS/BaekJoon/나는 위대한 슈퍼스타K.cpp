#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;
int check[101] {false};

int main() {
	int N,M,C;
	cin>>N>>M>>C;

	priority_queue<pair<double,int>> q;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			int idx;
			double score;
			
			cin>>idx>>score;
			q.push(make_pair(score,idx));
		}
	}

	double ans=0.0f;
	while(C) {
		int idx=q.top().second;
		if(check[idx]==false) {
			check[idx]=true;
			ans+=q.top().first;
			C--;	
		}
		q.pop();
	}
	cout<<setprecision(1)<<fixed<<ans;
	
	return 0;
}
