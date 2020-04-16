#include <iostream>
#include <map>

using namespace std;

map<int,int> cnt;

int main() {
	int n,m,a;
	cin>>n>>m;
	
	cnt[0]=1;
	long long ans=0;
	int sum=0;
	for(int i=0; i<n; i++) {
		cin>>a;
		
		sum+=a;
		sum%=m;
		ans+=cnt[sum];
		cnt[sum]+=1;
	}
	cout<<ans;

	return 0;
}

/*
INPUT:
5 3
1 2 3 1 2

OUTPUT:
7
*/
