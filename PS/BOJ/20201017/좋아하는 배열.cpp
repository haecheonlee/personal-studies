/* reference: baekjoon/codeplus */

#include <iostream>
#include <vector>

using namespace std;
using ll=long long;

const ll MOD=1e9+7;

ll d[11][100001];
ll sum[11];
vector<int> divisors[100001];

int main() {
	int N,K;
	cin>>N>>K;
	
	for(int i=1; i<=K; i++) {
		for(int j=i*2; j<=K; j+=i) divisors[j].push_back(i);
	}
	
	for(int j=1; j<=K; j++) d[1][j]=1;
	
	sum[1]=K;
	for(int i=2; i<=N; i++) {
		for(int j=1; j<=K; j++) {
			d[i][j]=sum[i-1];
			
			for(auto& div : divisors[j]) {
				d[i][j]-=d[i-1][div];
				
				d[i][j]%=MOD;
				d[i][j]+=MOD;
				d[i][j]%=MOD;
			}
			
			sum[i]+=d[i][j];
			sum[i]%=MOD;
		}
	}
	
	cout<<sum[N];

	return 0;
}
