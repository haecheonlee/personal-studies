#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n=3;
bool check(vector<int> &d) {
	int sum=d[0*n+0]+d[0*n+1]+d[0*n+2];
	
	for(int i=0; i<n; i++) {
		int total1=0, total2=0;

		for(int j=0; j<n; j++) total1+=d[i*n+j];
		for(int j=0; j<n; j++) total2+=d[j*n+i];
		
		if(sum!=total1) return false;
		if(sum!=total2) return false;
	}
	
	if(sum!=(d[0*n+0]+d[1*n+1]+d[2*n+2])) return false;
	if(sum!=(d[0*n+2]+d[1*n+1]+d[2*n+0])) return false;

	return true;
}

int main() {
	vector<int> a(n*n);
	for(int i=0; i<n*n; i++) cin>>a[i];
	
	vector<int> d(n*n);
	for(int i=0; i<n*n; i++) d[i]=i+1;
	
	int mn=-1;
	do {
		if(check(d)) {
			int diff=0;
			for(int i=0; i<n*n; i++) diff+=abs(a[i]-d[i]);
			if(mn==-1 || diff<mn) mn=diff;
		}
	} while(next_permutation(d.begin(), d.end()));
	
	cout<<mn;
	
	return 0;
}

/*
INPUT:
4 8 2
4 5 7
6 1 6

OUTPUT:
4
*/
