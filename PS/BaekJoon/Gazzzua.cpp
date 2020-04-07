#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	
	int sum=0;
	int current=a[n-1];
	for(int i=n-2; i>=0; i--) {
		if(a[i]>current) current=a[i];
		else sum+=current-a[i];
	}
	cout<<sum;
	
	return 0;
}

/*
INPUT:
6
1 5 10 2 4 3

OUTPUT:
16
*/
