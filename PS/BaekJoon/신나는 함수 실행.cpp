#include <iostream>
#include <cstring>

using namespace std;
const int K=50;

int d[101][101][101];

int solve(int a, int b, int c) {
	if(d[a][b][c]!=-1) return d[a][b][c];
	
	if(a<=K || b<=K || c<=K) return d[a][b][c]=1;
	if(a>20+K || b>20+K || c>20+K) return d[a][b][c]=solve(20+K,20+K,20+K);
	
	if(a<b && b<c) return d[a][b][c]=solve(a,b,c-1)+solve(a,b-1,c-1)-solve(a,b-1,c);
	else return d[a][b][c]=solve(a-1,b,c)+solve(a-1,b-1,c)+solve(a-1,b,c-1)-solve(a-1,b-1,c-1);
}

int main() {
	memset(d,-1,sizeof(d));
	
	while(1) {
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c);
		
		if(a==-1 && b==-1 && c==-1) break;
		int sa=a+K, sb=b+K, sc=c+K;
		printf("w(%d, %d, %d) = %d\n", a, b, c, solve(sa,sb,sc));
	}

	return 0;
}
