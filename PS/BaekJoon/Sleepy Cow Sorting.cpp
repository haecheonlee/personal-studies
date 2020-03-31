#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) cin>>a[i];

	int move=0;
	for(int i=0; i<n; i++) {
		bool check=true;
		
		for(int j=i; j<n-1; j++) {
			if(a[j+1]<a[j]) {
				check=false;
				break;
			}
		}

		if(check) break;
		move++;
	}
	
	cout<<move;

	return 0;
}

/*
INPUT:
4
1 2 4 3

OUTPUT:
3
*/
