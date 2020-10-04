#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		long long a,b,c;
		cin>>a>>b>>c;
		
		long long d=a+b+c;
		cout<<d/2<<'\n';
	}
 
	return 0;	
}

/* failed */
