/* reference: https://onedaycoding.tistory.com/102 */

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
using pii=pair<int,int>;

int N,K;
vector<pii> a;
int d[101][10001];

int go(int now, int len) {
	if(len == K) return 1;
	if(len > K || now >= N) return 0;
	
	int& ret = d[now][len];
	if(ret != -1) return ret;
	ret = 0;
	
	for(int i = 0; i <= a[now].second; i++) {
		ret += go(now + 1, len + a[now].first * i);
	}

	return ret;
}

int main() {
	cin>>N>>K;
	
	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second;
	
	memset(d, -1, sizeof(d));
	cout<<go(0,0);
}
