#include <iostream>
#include <vector>

using namespace std;
typedef pair<char,int> PI;

vector<int> children[150000];
PI info[150000];

long long dfs(int index) {
	long long ans=(info[index].first=='S') ? info[index].second : 0;

	for(int &next : children[index]) {
		long long current_sheeps=dfs(next);
		if(info[index].first=='W') {
			if(info[index].second>=current_sheeps) {
				info[index].second-=(long long)current_sheeps;
                current_sheeps=0;
			} else {
				current_sheeps-=(long long)info[index].second;
				info[index].second=0;
			}
		}
        
        ans+=current_sheeps;
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	info[1]=make_pair(' ',0);
	for(int i=2; i<=n; i++) {
		char t;
		int a,p;
		cin>>t>>a>>p;
		
		children[p].push_back(i);
		info[i]=make_pair(t,a);
	}
	
	cout<<dfs(1);

	return 0;
}

/*
INPUT:
7
S 100 1
S 100 1
W 100 1
S 1000 2
W 1000 2
S 900 6

OUTPUT:
1200
*/
