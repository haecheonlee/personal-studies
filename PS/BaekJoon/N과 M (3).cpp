#include <iostream>

using namespace std;

int list[10]; bool check[10];
void show(int index, int n, int m) {
	if(index == m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=1; i<=n; i++) {
		list[index]=i;
		show(index+1, n, m);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	show(0, N,M);
	return 0;
}

/*
boj.kr/15651

INPUT:
3 3

OUTPUT:
1 1 1
1 1 2
1 1 3
1 2 1
1 2 2
1 2 3
1 3 1
1 3 2
1 3 3
2 1 1
2 1 2
2 1 3
2 2 1
2 2 2
2 2 3
2 3 1
2 3 2
2 3 3
3 1 1
3 1 2
3 1 3
3 2 1
3 2 2
3 2 3
3 3 1
3 3 2
3 3 3
*/
