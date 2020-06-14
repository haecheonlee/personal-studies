#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int d[61][61][61];
int go(int i, int j, int k) {
	if(i<0) return go(0,j,k);
	if(j<0) return go(i,0,k);
	if(k<0) return go(i,j,0);
	
	if(i==0 && j==0 && k==0) return 0;
	
	int &ans=d[i][j][k];
	if(ans!=-1) return ans;
	ans=10000000;
	vector<int> p={1,3,9};
	
	do {
		if(ans>go(i-p[0], j-p[1], k-p[2])) ans=go(i-p[0], j-p[1], k-p[2]);
	} while(next_permutation(p.begin(), p.end()));
	ans+=1;
	
	return ans;
}

int main() {
	int n;
	cin>>n;
	
	int scv[3]={0,0,0};
	for(int i=0; i<n; i++) cin>>scv[i];
	memset(d, -1, sizeof(d));
	
	cout<<go(scv[0], scv[1], scv[2]);

	return 0;
}
