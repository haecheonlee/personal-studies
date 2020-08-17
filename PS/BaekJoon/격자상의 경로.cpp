/* reference: https://jaimemin.tistory.com/462 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX=20;

int N,M,K;
int a[MAX][MAX];
int d[MAX][MAX];

int go(int x, int y) {
	if(x==N && y==M) return 1;
	if(x>N || y>M) return 0;

	int& ret=d[x][y];
	if(ret!=-1) return ret;
	
	ret=0;
	int right=((x-1)*M)+(y+1);
	int down=(x*M)+y;
	
	if(right!=K && down!=K) {
		if(right<K && down<K) ret+=go(x+1,y)+go(x,y+1);
		else if(right<K) ret+=go(x,y+1);
		else if(right>K && down>K) ret+=go(x+1,y)+go(x,y+1);
	}
	if(right==K) ret+=go(x,y+1);
	if(down==K) ret+=go(x+1,y);
	
	return ret;
}

int main() {
	cin>>N>>M>>K;

	int idx=1;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) a[i][j]=idx++;
	}

	memset(d,-1,sizeof(d));
	cout<<go(1,1);
	
	return 0;
}
