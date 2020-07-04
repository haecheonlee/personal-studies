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
		
		int ans=0;
		for(int i=0; i<N; i++) {
			int j=i;
			while(j>0 && a[j-1]>a[j]) {
				swap(a[j-1],a[j]);
				j--;
				
				ans++;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}
