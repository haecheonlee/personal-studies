#include <iostream>
#include <vector>

using namespace std;
using ll=long long;
using pi=pair<ll,ll>;

int N;
vector<pi> a;
ll ans=-1;

void go(ll sum1, ll sum2, int index, int count) {
	if(count>0) {
		int diff=abs(sum1-sum2);
		if(ans==-1 || ans>diff) ans=diff;
	}
	
	if(index>=N) return;
	
	go(sum1*a[index].first, sum2+a[index].second, index+1, count+1);
	go(sum1,sum2,index+1,count);
}

int main() {
	cin>>N;
	
	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second;

	go(1,0,0,0);
	cout<<ans;
	
	return 0;
}
