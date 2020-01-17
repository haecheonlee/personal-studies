#include <iostream>

using namespace std;

int list[8];
void show(int index, int selected, int n, int m) {
	if(selected==m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	if(index>n) return;
	list[selected]=index;
	show(index, selected+1, n, m);
	list[selected]=0;
	show(index+1, selected, n, m);
}

int main() {
	int n,m;
	cin>>n>>m;
	
	show(1, 0,n,m);

	return 0;
}

/*
boj.kr/15652

INPUT:
4 2

OUTPUT:
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4
*/
