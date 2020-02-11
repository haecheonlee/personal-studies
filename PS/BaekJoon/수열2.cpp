#include <iostream>

using namespace std;

int main() {
	int n, longest=0;
	cin>>n;
	
	int arr[n];
	int asc[n], dsc[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		
		if(i>0) {
			if(arr[i-1]<=arr[i]) asc[i]=asc[i-1]+1;
			else asc[i]=1;
			
			if(arr[i-1]>=arr[i]) dsc[i]=dsc[i-1]+1;
			else dsc[i]=1;			
		} else {
			asc[0]=1;
			dsc[0]=1;
		}
        
        longest=max(max(dsc[i], asc[i]), longest);
	}
	
	cout<<longest;

	return 0;
}

/*
boj.kr/2491

INPUT:
9
1 2 2 4 4 5 7 7 2

OUTPUT:
8
*/
