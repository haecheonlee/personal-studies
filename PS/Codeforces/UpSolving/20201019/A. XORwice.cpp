#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int a,b;
		cin>>a>>b;
		
		int x=(a&b);
		cout<<(a^x) + (b^x)<<'\n';
	}
 
	return 0;
}
