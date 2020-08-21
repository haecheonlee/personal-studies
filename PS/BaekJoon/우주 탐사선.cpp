#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF=1e9;

int adj[10][10];
int d[10][10];

int main() {
	int N,K;
	cin>>N>>K;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>d[i][j];
	}

	for(int k=0; k<N; k++) {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
			}
		}
	}
	
	vector<int> a;
	a.push_back(K);
	for(int i=0; i<N; i++) if(i!=K) a.push_back(i);

	int ans=-1;
	do {
		int total=0;
		for(int i=0; i<N-1; i++) total+=d[a[i]][a[i+1]];
		if(ans==-1 || ans>total) ans=total;
	} while(next_permutation(a.begin()+1, a.end()));
	cout<<ans;
	
	return 0;
}
