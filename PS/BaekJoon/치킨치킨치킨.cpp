#include <iostream>
#include <vector>

using namespace std;

int n,m;
int a[31][31];
int ans=0;

void go(int index, vector<int> list) {
	if(list.size()==3) {
		int total=0;
		for(int i=0; i<n; i++) {
			int mx=0;
			for(int idx : list) mx=max(mx,a[i][idx]);
			total+=mx;
		}
		ans=max(total,ans);
		return;
	}
	
	if(index>=m) return;
	list.push_back(index);
	go(index+1,list);
	list.pop_back();
	go(index+1,list);
}

int main() {
	cin>>n>>m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>a[i][j];
	}
	
	go(0,vector<int>());
	cout<<ans;
	
	return 0;
}

/*
INPUT:
4 6
1 2 3 4 5 6
6 5 4 3 2 1
3 2 7 9 2 5
4 5 6 3 2 1

OUTPUT:
25
*/
