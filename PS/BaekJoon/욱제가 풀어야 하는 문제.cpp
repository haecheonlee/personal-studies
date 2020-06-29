#include <iostream>

using namespace std;
const int MOD=1e9+7;

int d[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	d[1]=1;
	d[2]=2;
	
	for(int i=3; i<=191229; i++) d[i]=(d[i-1]+d[i-2])%MOD;
	while(T--) {
		int N;
		cin>>N;
		
		cout<<d[N]<<'\n';
	}
	
	return 0;
}
