#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define TOTAL 6

int list[6]{0};
bool visited[50];
void show(const vector<int> &v, int index, int start, int n) {
	if(index == TOTAL) {
		for(int i=0; i<TOTAL; i++) {
			cout<<list[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	for(int i=start; i<n; i++) {
		if(visited[v[i]]) continue;
		visited[v[i]]=true;
		list[index]=v[i];
		show(v,index+1,i+1,n);
		visited[v[i]]=false;
	}
}

int main() {
	int T=1;
	
	while(T!=0) {
		cin>>T;
		
		vector<int> v(T);
		for(int i=0; i<T; i++) cin>>v[i];
		show(v,0,0,T);
		cout<<'\n';
	}

	return 0;
}

/*
boj.kr/6603

INPUT:
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

OUTPUT:
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34
*/
