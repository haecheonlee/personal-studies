/* reference: baekjoon/codeplus */

#include <iostream>

using namespace std;

const int MAX=1e4;

int N;
int a[MAX], b[MAX];
int d[MAX][10];

int go(int index, int turn) {
	if(index==N) return 0;
	
	int& ret = d[index][turn];
	if(ret != -1) return ret;
	
	int cur = (a[index] + turn) % 10;
	
	int cost_left = (b[index] - cur + 10) % 10;
	int left = cost_left + go(index + 1, (turn + cost_left) % 10);
	
	int cost_right = (cur - b[index] + 10) % 10;
	int right = cost_right + go(index + 1, turn);
	
	if(left < right) d[index][turn] = left;
	else d[index][turn] = right;
	
	return d[index][turn];
}

int main() {
	scanf("%d", &N);
	
	for(int i=0; i<N; i++) scanf("%1d", &a[i]);
	for(int i=0; i<N; i++) scanf("%1d", &b[i]);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<10; j++) d[i][j]=-1;
	}
	
	printf("%d", go(0,0));
	
	return 0;
}
