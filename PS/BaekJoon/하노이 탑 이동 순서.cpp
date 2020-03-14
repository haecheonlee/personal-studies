#include <iostream>

using namespace std;

void solve(int n, int x, int y) {
	if (n==0) return;
	solve(n-1,x,6-x-y);
	cout<<x<<" "<<y<<'\n';
	solve(n-1,6-x-y,y);
}

int main() {
	int n;
	cin>>n;
	cout<<((1<<n)-1)<<'\n';
	solve(n,1,3);
	return 0;
}

/*
boj.kr/11729

INPUT:
3

OUTPUT:
7
1 3
1 2
3 2
1 3
2 1
2 3
1 3
*/
