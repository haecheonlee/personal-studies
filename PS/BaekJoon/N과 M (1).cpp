#include <iostream>

using namespace std;

int list[10];
bool check[10];
void show(int index, int n, int m) {
	if(index==m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=1; i<=n; i++) {
		if(check[i]) continue;
		list[index]=i; check[i]=true;
		show(index+1,n,m);
		check[i]=false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	show(0,N,M);
	return 0;
}

/*
boj.kr/15649

INPUT:
4 4

OUTPUT:
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/
