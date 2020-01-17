#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;
int A[8];
bool C[8];
void show(int index, int selected, int n, int m) {
	if(selected==m) {
		for(int i=0; i<m; i++) {
			cout<<A[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	if(index>n-1) return;
	A[selected]=list[index];
	show(index+1, selected+1, n, m);
	A[selected]=0;
	show(index+1, selected, n, m);
}

int main() {
	int n,m;
	cin>>n>>m;
	
	list=vector<int>(n);
	for(int i=0; i<n; i++) cin>>list[i];
	sort(list.begin(), list.end());
	
	show(0,0,n,m);

	return 0;
}

/*
boj.kr/15655

INPUT:
4 2
9 8 7 1

OUTPUT:
1 7
1 8
1 9
7 8
7 9
8 9
*/
