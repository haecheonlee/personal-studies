#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list;int A[8];bool C[8];
void show(int index, int n, int m) {
	if(index==m) {
		for(int i=0; i<m; i++) {
			cout<<A[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=0; i<n; i++) {
		if(C[i]) continue;
		C[i]=true;
		A[index]=list[i];
		show(index+1,n,m);
		C[i]=false;
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	
	list=vector<int>(n);
	for(int i=0; i<n; i++) cin>>list[i];
	sort(list.begin(), list.end());
	
	show(0,n,m);

	return 0;
}

/*
boj.kr/15654

INPUT:
4 2
9 8 7 1

OUTPUT:
1 7
1 8
1 9
7 1
7 8
7 9
8 1
8 7
8 9
9 1
9 7
9 8
*/
