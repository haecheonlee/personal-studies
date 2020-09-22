/* reference: https://songhayoung.github.io/2020/09/06/PS/BOJ/10653/ */

#include <iostream>
#include <cstring>

using namespace std;
using pi=pair<int,int>;

const int MAX=501;

int N,K;
pi a[MAX];
int d[MAX][MAX];

int get_distance(pi x, pi y) {
	return abs(x.first-y.first)+abs(x.second-y.second);
}

int go(int now, int skip) {
	if(now==N-1) return 0;
	
	int& ret=d[now][skip];
	if(ret!=-1) return ret;
	
	if(skip==0) {
		return ret=go(now+1, skip)+get_distance(a[now], a[now+1]);
	} else {
		ret=go(now+1, skip)+get_distance(a[now], a[now+1]);
		for(int next=now+2; next<N && next<now+skip+2; next++) {
			d[now][skip]=min(d[now][skip], go(next, now+skip+1-next)+
										   get_distance(a[now], a[next]));
		}
		return d[now][skip];
	}
}

int main() {
	cin>>N>>K;
	
	for(int i=0; i<N; i++) cin>>a[i].first>>a[i].second;

	memset(d, -1, sizeof(d));
	cout<<go(0,K);

	return 0;
}
