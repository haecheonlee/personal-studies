/* reference: Green55 */

#include <iostream>

using namespace std;

const int MAX=1e4+1;
const int MOD=1e9+7;
int d[MAX];

int main() {
	int N,M;
	cin>>N>>M;
	
	d[0]=1;
	for(int i=1; i<=N; i++) {
		d[i]=d[i-1];
		if(i-M>=0) d[i]=(d[i]+d[i-M])%MOD;
	}
	cout<<d[N];
	
	return 0;
}
