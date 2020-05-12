#include <iostream>
#define MAX 10000000

using namespace std;

int computer[MAX+1];

int main() {
	int n;
	cin>>n;
	
	long long total=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int x;
			
			cin>>x;
			total+=x;
			computer[x]++;
		}
	}
	
	if(total==0) {
		cout<<0;
	} else {
		long long server=n*n-computer[0];
		long long sum=0;
		
		for(int i=1; i<=MAX; i++) {
			sum+=server;
			server-=computer[i];
			
			if(sum*2>=total) {
				cout<<i;
				break;
			}
		}
		
	}
	
	return 0;
}

/*
INPUT:
5
1 4 0 2 1
0 0 5 6 3
8 4 7 2 0
7 1 0 5 3
4 5 7 9 1

OUTPUT:
3
*/
