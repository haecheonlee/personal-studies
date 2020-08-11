#include <iostream>

using namespace std;

int limit[101];
int driving[101];

int main() {
	int N,M;
	cin>>N>>M;
	
	int current=1;
	for(int i=0; i<N; i++) {
		int mile, speed;
		cin>>mile>>speed;
		
		mile+=(current-1);
		while(current<=mile) {
			limit[current]=speed;
			current++;
		}
	}
	
	current=1;
	for(int i=0; i<M; i++) {
		int mile, speed;
		cin>>mile>>speed;
		
		mile+=(current-1);
		while(current<=mile) {
			driving[current]=speed;
			current++;
		}
	}

	int ans=0;
	for(int i=0; i<=100; i++) {
		if(limit[i]<driving[i]) ans=max(ans, driving[i]-limit[i]);	
	}
	cout<<ans;

	return 0;
}
