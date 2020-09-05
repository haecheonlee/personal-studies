#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int a,b;
		cin>>a>>b;
		
		int diff=abs(a-b);
		cout<<(diff/10)+(diff%10>0)<<'\n';
	}
 
	return 0;
}
