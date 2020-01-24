#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[101];
bool check[1001];

int dfs(int x) {
	int count=0;
	check[x]=true;
	
	for(int i=0; i<vec[x].size(); i++) {
		int current=vec[x][i];
		if(check[current]==false) {
			check[current]=true;
			count++;
			count+=dfs(current);
		}
	}
	
	return count;
}

int main() {
	int n,m;
	cin>>n>>m;
	
	int c1,c2;
	for(int i=0; i<m; i++) {
		cin>>c1>>c2;
		
		vec[c1].push_back(c2);
		vec[c2].push_back(c1);
	}

	cout<<dfs(1);

	return 0;
}

/*
boj.kr/2606

INPUT:
7
6
1 2
2 3
1 5
5 2
5 6
4 7

OUTPUT:
4
*/
