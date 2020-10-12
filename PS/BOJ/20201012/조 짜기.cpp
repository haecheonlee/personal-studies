#include <iostream>

using namespace std;

const int MAX=2e3+1;

int a[MAX], d[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];
	
	for(int i=1; i<=N; i++) {
		d[i]=0;
		int mx=a[i], mn=a[i];
		for(int j=i; j>=1; j--) {
			mx=max(mx, a[j]);
			mn=min(mn, a[j]);
			
			d[i]=max(d[i], d[j-1] + (mx - mn));
		}
	}
	
	cout<<d[N];

	return 0;
}
