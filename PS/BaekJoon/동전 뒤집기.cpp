#include <iostream>
#include <vector>

using namespace std;

char flip(char x) {
	return (x=='T') ? 'H' : 'T';
}

int main() {
	int n;
	cin>>n;
	
	vector<string> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	int ans=n*n;
	for(int state=0; state<(1<<n); state++) {
		int sum=0;
		for(int i=0; i<n; i++) {
			int cnt=0;
			
			for(int j=0; j<n; j++) {
				char cur=a[i][j];

				if(state & (1<<j)) cur=flip(cur);	
				if(cur=='T') cnt++;
			}
			
			sum+=min(cnt,n-cnt);
		}
		if(ans>sum) ans=sum;
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
3
HHT
THH
THT

OUTPUT:
2
*/
