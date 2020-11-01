#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,X;
		cin>>N>>X;
 
		int a[N], b[N];		
		for(int i=0; i<N; i++) cin>>a[i];
		for(int i=0; i<N; i++) cin>>b[i];
		sort(a, a+N); sort(b, b+N);
		
		bool is_good = true;
		for(int i=0; i<N; i++) if(a[i] + b[N - i - 1] > X) is_good = false;
		cout<<(is_good ? "Yes\n" : "No\n");
	}
 
	return 0;
}
