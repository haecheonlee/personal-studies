#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

void go(vector<vector<int>> &a, tuple<int,int,int> t) {
	int row, col, size;
	tie(row, col, size)=t;
	
	vector<vector<int>> groups;
	for(int s=1; s<=size; s++) {
		vector<int> group;
		
		for(int r=row-s, c=col-s; c<col+s; c++) {
			group.push_back(a[r][c]);
		}
		
		for(int r=row-s, c=col+s; r<row+s; r++) {
			group.push_back(a[r][c]);
		}
		
		for(int r=row+s, c=col+s; c>col-s; c--) {
			group.push_back(a[r][c]);
		}
		
		for(int r=row+s, c=col-s; r>row-s; r--) {
			group.push_back(a[r][c]);
		}
		
		groups.push_back(group);
	}
	
	for(int s=1; s<=size; s++) {
		auto &group=groups[s-1];
		rotate(group.rbegin(), group.rbegin()+1, group.rend());
		
		int len=group.size();
		int index=0;
		
		for(int r=row-s, c=col-s; c<col+s; c++) a[r][c]=group[index++];
		for(int r=row-s, c=col+s; r<row+s; r++) a[r][c]=group[index++];
		for(int r=row+s, c=col+s; c>col-s; c--) a[r][c]=group[index++];
		for(int r=row+s, c=col-s; r>row-s; r--) a[r][c]=group[index++];
	}
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<vector<int>> a(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) cin>>a[i][j];
	}
	
	vector<tuple<int,int,int>> d(k);
	for(int i=0; i<k; i++) {
		int r,c,s;
		cin>>r>>c>>s;
		d[i]=make_tuple(r-1,c-1,s);
	}
	sort(d.begin(), d.end());
	int ans=100*100;
	
	do {
		auto b=a;
		for(auto &t : d) go(b,t);
		
		for(int i=0; i<n; i++) {
			int sum=0;
			for(int j=0; j<m; j++) sum+=b[i][j];
			if(ans>sum) ans=sum;
		}
	} while(next_permutation(d.begin(), d.end()));
	cout<<ans;
	
	return 0;
}
