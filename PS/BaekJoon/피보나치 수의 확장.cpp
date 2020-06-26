#include <iostream>

using namespace std;
const int MOD=1e9;
const int M=1e6;

int d[2000001];

int main() {
	int n;
	cin>>n;

	d[M-1]=1;
	d[M]=0;
	d[M+1]=1;
	
	for(int i=M-2; i>=0; i--) {
		d[i]=d[i+2]-d[i+1];
		d[i]%=MOD;	
	}
	
	for(int i=M+2; i<=2000000; i++) {
		d[i]=d[i-1]+d[i-2];
		d[i]%=MOD;
	}
	

	if(d[M+n]<0) cout<<-1<<endl;
	else if(d[M+n]==0) cout<<0<<endl;
	else cout<<1<<endl;
	cout<<abs(d[M+n]);

	return 0;
}
