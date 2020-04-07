#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		
		int a[n];
		for(int i=0; i<n; i++) cin>>a[i];
		
		int current=a[n-1], sum=0;
		for(int i=n-2; i>=0; i--) {
			if(a[i]>current) current=a[i];
			else sum+=current-a[i];
		}
		cout<<sum<<'\n';
	}


	return 0;
}

/*
INPUT:
3
3
10 7 6
3
3 5 9
5
1 1 3 1 2

OUTPUT:
0
10
5
*/
