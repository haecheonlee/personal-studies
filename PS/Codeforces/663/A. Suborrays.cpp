#include <iostream>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		for(int i=N; i>0; i--) cout<<i<<' ';
		cout<<'\n';
	}
	
	return 0;
}
