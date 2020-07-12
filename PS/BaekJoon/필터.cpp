#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int a[41][41];

int search(int x, int y) {
	int nx=x+2;
	int ny=y+2;
	
	vector<int> list;
	for(int i=x; i<=nx; i++) {
		for(int j=y; j<=ny; j++) list.push_back(a[i][j]);
	}
	sort(list.begin(), list.end());
	
	return list[list.size()/2];
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) cin>>a[i][j];
	}

	int K;
	cin>>K;
	
	int ans=0;
	for(int i=0; i+2<N; i++) {
		for(int j=0; j+2<M; j++) {
			if(K<=search(i,j)) ans++;
		}
	}
	cout<<ans;

	return 0;
}
