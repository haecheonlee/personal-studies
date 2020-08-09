/* reference: https://mygumi.tistory.com/160 */
#include <iostream>

using namespace std;
using ll=long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		int cnt=1;
		ll sum=0;
		
		ll a[6];
		ll quantity[6];

		for(int i=0; i<6; i++) {
			cin>>a[i];
			sum+=a[i];
		}
		
		while(sum<=N) {
			sum=0;
			cnt++;

			for(int i=0; i<6; i++) {
				quantity[i] = a[i] + a[(i + 1) % 6] + a[(i + 3) % 6] + a[(i + 5) % 6];
				sum+=quantity[i];
			}
			
			for(int i=0; i<6; i++) a[i]=quantity[i];
		}
		
		cout<<cnt<<'\n';
	}

	return 0;
}
