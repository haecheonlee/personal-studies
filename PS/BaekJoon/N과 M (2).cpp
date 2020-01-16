#include <iostream>

using namespace std;

int list[10];
void show(int index, int selected, int n, int m) {
	if(selected == m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	if(index>n) return;
	list[selected]=index;
	show(index+1, selected+1, n, m);
	list[selected]=0;
	show(index+1, selected, n, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	show(1,0,N,M);
	return 0;
}

/*
boj.kr/15650

INPUT:
4 2

OUTPUT:
1 2
1 3
1 4
2 3
2 4
3 4
*/
