// reference: editorial

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		vector<int> a(N);
		for(int i=0; i<N; i++) cin>>a[i];
		
		int pos=N-1;
		while(pos>0 && a[pos-1]>=a[pos]) pos--;
		while(pos>0 && a[pos-1]<=a[pos]) pos--;
		cout<<pos<<'\n';
	}

	return 0;
}
