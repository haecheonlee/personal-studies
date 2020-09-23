/* reference: http://www.usaco.org/current/data/sol_hoofball_bronze_feb18.html */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX=1e2;

int N;
int a[MAX], to[MAX];

int target(int i) {
	int left=-1, L=1e3;
	int right=-1, R=1e3;
	
	for(int j=0; j<N; j++) {
		if(a[j] < a[i] && a[i] - a[j] < L) {
			left=j;
			L=a[i]-a[j];
		}
	}
	
	for(int j=0; j<N; j++) {
		if(a[j] > a[i] && a[j] - a[i] < R) {
			right=j;
			R=a[j]-a[i];
		}
	}
	
	if(L<=R) return left;
	return right;
}

int main() {
	cin>>N;

	for(int i=0; i<N; i++) cin>>a[i];
	for(int i=0; i<N; i++) to[target(i)]++;

	int ans=0;
	for(int i=0; i<N; i++) {
		if(to[i]==0) ans++;
		if(i < target(i) && target(target(i))==i && to[i]==1 && to[target(i)]==1) {
			ans++;	
		}
	}
	cout<<ans;

	return 0;
}
