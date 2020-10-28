#include <iostream>

using namespace std;

const int MAX=1e2+1;

int a[MAX], one[MAX], zero[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i=1; i<=N; i++) cin>>a[i];

	for(int i=1; i<=N; i++) {
		if(a[i]==0) zero[i]++;
		else one[i]++;
		
		zero[i] += zero[i-1];
		one[i] += one[i-1];
	}
	
	if(N==1) {
		cout<<(a[1]==0 ? 1 : 0);	
	} else {
		int ans=one[N] - 1;
		for(int i=1; i<=N; i++) {
			for(int j=i+1; j<=N; j++) {
				int L = one[i-1], R=one[N] - one[j];
				ans=max(ans, (zero[j] - zero[i-1]) + L + R);
			}
		}
		cout<<ans;
	}
	
	return 0;
}
