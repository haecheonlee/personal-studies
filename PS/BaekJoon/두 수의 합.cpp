#include <iostream>

using namespace std;

bool check[2000001];

int main() {
	int n,x,cnt=0;
	cin>>n;
	
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
		check[a[i]]=true;
	}
	
	cin>>x;
	for(int i=0; i<n; i++) {
		int sub=x-a[i];
		if(sub>0) {
			if(check[sub] && sub!=a[i]) cnt++;
		}
	}
	
	cout<<cnt/2;
	
	return 0;
}

/*
INPUT:
9
5 12 7 10 9 1 2 3 11
13

OUTPUT:
3
*/
