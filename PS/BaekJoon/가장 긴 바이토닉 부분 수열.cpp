#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> vec(n,0);
	for(int i=0; i<n; i++) cin>>vec[i];

	int lis[n], lds[n];
	
	for(int i=0; i<n; i++) {
		lis[i]=1;
		for(int j=0; j<i; j++) {
			if(vec[i]>vec[j] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
		}
	}

	for(int i=n-1; i>=0; i--) {
		lds[i]=1;
		for(int j=n-1; j>i; j--) {
			if(vec[i]>vec[j] && lds[i]<lds[j]+1) lds[i]=lds[j]+1;
		}
	}
	
	int largest=0;
	for(int i=0; i<n; i++) largest=max(largest,lis[i]+lds[i]-1);
	cout<<largest;

	return 0;
}

/*
boj.kr/11054

INPUT:
10
1 5 2 1 4 3 4 5 2 1

OUTPUT:
7
*/
