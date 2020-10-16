/* https://jaimemin.tistory.com/775 */

#include <iostream>

using namespace std;

const int MAX=33333+1;
const int MOD=1e9+9;

long long d[MAX];

int main() {
	int N;
	cin>>N;
	
	d[2]=2;
	for(int i=3; i<=N; i++) d[i]=(d[i-1]*3)%MOD;
	cout<<d[N];
	
	return 0;
}
