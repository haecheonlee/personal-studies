#include <iostream>

using namespace std;

int check[1000001] {0};

int main() {
	int n,largest=-1;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
		
		if(check[a[i]-1]==0) {
			check[a[i]]=1;
		} else {
			check[a[i]]=check[a[i]-1]+1;
		}
		
		largest=max(largest,check[a[i]]);
	}
	
	cout<<largest;
	
	return 0;
}

/*
boj.kr/15966

INPUT:
6
1 2 3 4 5 6

OUTPUT:
6
*/
