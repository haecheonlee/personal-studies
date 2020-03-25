#include <iostream>

using namespace std;

int main() {
	int l,p,v;
	int index=1;
	
	while(1) {
		cin>>l>>p>>v;
		if(l==0 && p==0 && v==0) break;
		
		long long ans=((v/p)*l);
		
		long long rest=v%p;
		if(rest<=l) ans+=rest;
		else ans+=l;
		
		cout<<"Case "<<(index++)<<": "<<ans<<'\n';
	}

	return 0;
}

/*
INPUT:
5 8 20
5 8 17
0 0 0

OUTPUT:
Case 1: 14
Case 2: 11
*/
