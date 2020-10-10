/* reference: https://nicotina04.tistory.com/37 */

#include <iostream>

using namespace std;

const int MOD=1e9+9;

int main() {
	int N;
	cin>>N;
	
	int cache[N];
	cache[0]=cache[1]=1;
	cache[2]=2;
	
	for(int i=3; i<=N; i++) cache[i]=(cache[i-1]+cache[i-3])%MOD;
	cout<<cache[N-1]%MOD;

	return 0;
}
