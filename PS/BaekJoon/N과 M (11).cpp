#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int list[10];

void show(int index, int n, int m) {
	if(index==m) {
		for(int i=0; i<m; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=0; i<n; i++) {
		list[index]=v[i];
		show(index+1,n,m);
	}
}

int main() {
	int n,m,num;
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		cin>>num;
		if(find(v.begin(), v.end(), num) == v.end()) v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	n=v.size();
	show(0,n,m);
	
	return 0;
}

/*
boj.kr/15665

INPUT:
4 2
9 7 9 1

OUTPUT:
1 1
1 7
1 9
7 1
7 7
7 9
9 1
9 7
9 9
*/
