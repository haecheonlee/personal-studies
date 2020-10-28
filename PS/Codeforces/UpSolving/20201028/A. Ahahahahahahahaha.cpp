#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N;
		cin>>N;

		int a[N];
		int cnt0=0, cnt1=0;

		for(int i=0; i<N; i++) {
			cin>>a[i];

			if(a[i]==0) cnt0++;
		}
		cnt1 = N - cnt0;

		if(cnt0 >= N / 2) {
			cout<<cnt0<<'\n';
			for(int i=0; i < cnt0; i++) cout<<0<<' ';
		} else {
			cout<<cnt1 - cnt1 % 2<<'\n';
			for(int i=0; i < cnt1 - cnt1 % 2; i++) {
				cout<<1<<' ';
			}
		}
		cout<<'\n';
	}	

	return 0;
}
