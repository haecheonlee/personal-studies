#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	
	long long total=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i==j) continue;
			total+=abs(arr[i]-arr[j]);
		}
	}
	cout<<total;

	return 0;
}

/*
boj.kr/2399

INPUT:
5
1 5 3 2 4

OUTPUT:
40
*/
