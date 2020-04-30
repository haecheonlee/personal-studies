#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,m;
		cin>>n>>m;
		
		int cnt=0;
		for(int a=1; a<n; a++) {
			for(int b=a+1; b<n; b++) {
				int x=(a*a)+(b*b)+m;
				int y=a*b;
				
				if(x%y==0) cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}

/*
INPUT:
3
10 1
20 3
30 4

OUTPUT:
2
4
5
*/
