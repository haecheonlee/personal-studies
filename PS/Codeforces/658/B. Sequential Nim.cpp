// reference: ediotorial

#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int a[N];
		for(int i=0; i<N; i++) cin>>a[i];
		
		int k=0;
		while(k<N && a[k]==1) k++;
		
		if((k==N)^(k%2)) cout<<"Second\n";
		else cout<<"First\n";
	}
	
	return 0;
}
