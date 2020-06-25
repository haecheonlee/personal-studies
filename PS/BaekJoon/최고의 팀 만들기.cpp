#include <iostream>
#include <cstring>

using namespace std;

int w[1001], b[1001];
int d[1001][16][16];
int idx=0;

int go(int W, int B, int now) {
	if(now==idx) return 0;

	int &ret=d[now][W][B];
	if(ret!=-1) return ret;
	
	if(W>0) ret=max(ret, go(W-1,B,now+1)+w[now]);
	if(B>0) ret=max(ret, go(W,B-1,now+1)+b[now]);
	ret=max(ret,go(W,B,now+1));
	
	return ret;
}

int main() {
	int W,B;
	
	while(cin>>W>>B) {
		w[idx]=W;
		b[idx]=B;
		
		idx++;
	}

	memset(d,-1,sizeof(d));
	cout<<go(15,15,0);

	return 0;
}
