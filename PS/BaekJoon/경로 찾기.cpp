#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec[101];
bool check[101];

void dfs(int start, int index) {
	for(int i=0; i<vec[start].size(); i++) {
		int current=vec[start][i];
		if(find(vec[index].begin(), vec[index].end(), current)==vec[index].end()) {
			vec[index].push_back(current);
		}
		
		if(check[current]==false) {
			check[current]=true;
			dfs(current, index);
		}
	}
}

void reset(int end) {
	for(int i=0; i<end; i++) check[i]=false;
}

int main() {
	int n,e;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>e;
			if(e==1) vec[i].push_back(j);
		}
	}
	
	for(int i=0; i<n; i++) {
		reset(n);
		dfs(i,i);
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(find(vec[i].begin(), vec[i].end(), j)!=vec[i].end()) cout<<"1 ";
			else cout<<"0 ";
		}
		cout<<endl;
	}

	return 0;
}

/*
boj.kr/11403

INPUT:
7
0 0 0 1 0 0 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0
0 0 0 0 1 1 0
1 0 0 0 0 0 0
0 0 0 0 0 0 1
0 0 1 0 0 0 0

OUTPUT:
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 0 0 0 0 0
1 0 1 1 1 1 1
1 0 1 1 1 1 1
0 0 1 0 0 0 1
0 0 1 0 0 0 0
*/
