#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int arr[n];
	int d[n] {0};
	
	int total=0;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		
		if(i>0) { 
			if(arr[i]==1) d[i]=d[i-1]+1; 
		}
		else d[i]=arr[i];
		
		total+=d[i];
	}
	
	cout<<total;

	return 0;
}

/*
boj.kr/2506

INPUT:
10
1 0 1 1 1 0 0 1 1 0

OUTPUT:
10
*/
