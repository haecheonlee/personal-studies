#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[101];
int cnt;
bool visited[101], finished[101];
vector<int> result;

void dfs(int current) {
	visited[current]=true;
	int next=d[current];
	
	if(visited[next]) {
		if(finished[next]==false) {
			result.push_back(current+1);
			for(int temp=next; temp!=current; temp=d[temp]) result.push_back(temp+1);
		}
	} else {
		dfs(next);
	}
	
	finished[current]=true;
}

int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) {
		cin>>d[i];
		d[i]-=1;
	}
	
	for(int i=0; i<n; i++) {
		if(!visited[i]) dfs(i);
	}
	
	sort(result.begin(), result.end());
	cout<<result.size()<<'\n';
	for(int i=0; i<result.size(); i++) cout<<result[i]<<'\n';
	
	return 0;
}

/*
INPUT:
7
3
1
1
5
5
4
6

OUTPUT:
3
1
3
5
*/
