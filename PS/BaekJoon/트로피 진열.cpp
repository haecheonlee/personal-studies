#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int current=a[0],cnt=1;
	for(int i=1; i<n; i++) {
		if(current<a[i]) {
			current=a[i];
			cnt++;
		}
	}
	cout<<cnt<<'\n';

	current=a[n-1],cnt=1;
	for(int i=n-2; i>=0; i--) {
		if(current<a[i]) {
			current=a[i];
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
}

/*
INPUT:
5
1
2
3
4
5

OUTPUT:
5
1
*/
