#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> m;
int sum[200001];

int main() {
	int n,k,a;
	cin>>n>>k;
	
	m[0]=1;
	long long ans=0;
	for(int i=1; i<=n; i++) {
		cin>>a;
		
		sum[i]=sum[i-1]+a;
		ans+=m[sum[i]-k];
		m[sum[i]]++;
	}
	cout<<ans;
	
	return 0;
}

/*
INPUT:
4 0
2 -2 2 -2

OUTPUT:
4
*/
