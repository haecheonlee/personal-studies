/* reference: https://js1jj2sk3.tistory.com/43 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=1e3;

int N,K;
int a[MAX];
int d[MAX][3][31];

int go(int now, int pos, int cnt) {
	if(now==N) return 0;
	
	int& ret = d[now][pos][cnt];
	if(ret!=-1)  return ret;
	
	if(pos==a[now]) {
		int r1=0, r2=0;
		if(cnt+1<=K) r1=max(go(now+1, pos, cnt)+1, go(now+1, 3-pos, cnt+1));
		else r2=go(now+1, pos, cnt)+1;
		
		return ret=max(r1, r2);
	} else {
		int r1=0, r2=0;
		if(cnt+1<=K) r1=max(go(now+1, pos, cnt), go(now+1, 3-pos, cnt+1)+1);
		else r2=go(now+1, pos, cnt);
		
		return ret=max(r1, r2);
	}
}

int main() {
	cin>>N>>K;
	
	for(int i=0; i<N; i++) cin>>a[i];

	memset(d, -1, sizeof(d));
	cout<<go(0,1,0);

	return 0;
}
