#include <iostream>

using namespace std;
using pi=pair<int,int>;

const int MAX=1e5+1;
const int SIZE=1e3;

pi a[SIZE];
int d[MAX];

int main() {
	int K,N;
	cin>>K>>N;
	
	for(int i=0; i<N; i++) {
		cin>>a[i].first>>a[i].second;
	}
	
	for(int i=0; i<N; i++) {
		for(int j=K; j>=0; j--) {
			if(j-a[i].second>=0) {
				d[j]=max(d[j-a[i].second]+a[i].first, d[j]);
			}
		}
	}
	
	cout<<d[K];

	return 0;
}
