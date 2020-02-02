#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec[10001];
bool check[10001];
int n,m,a,b;

int dfs(int index) {
	check[index]=true;
	int count=0;
	
	for(int i=0; i<vec[index].size(); i++) {
		int current=vec[index][i];
		
		if(check[current]==false) {
			count++;
			count+=dfs(current);
		}
	}
	
	return count;
}

void reset() {
	for(int i=1; i<=n; i++) check[i]=false;
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<m ;i++) {
		cin>>a>>b;
		vec[b].push_back(a);
	}
	
	vector<int> result;
	int biggest=0;
	for(int i=1; i<=n; i++) {
		reset();
		int count=dfs(i);
		if(count>biggest) {
			result.erase(result.begin(), result.end());
			biggest=count;
			result.push_back(i);
		} else if(count==biggest) result.push_back(i);
	}
	
	for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
	
	return 0;
}

/*
boj.kr/1325

INPUT:
5 4
3 1
3 2
4 3
5 3

OUTPUT:
1 2
*/
