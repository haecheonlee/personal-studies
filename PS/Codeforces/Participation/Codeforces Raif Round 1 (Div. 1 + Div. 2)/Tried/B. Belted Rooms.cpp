#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX=3e5+1;
 
vector<int> a[MAX];
bool check[MAX];
 
bool dfs(int x, int prev, int p) {
	for(auto& y : a[x]) {
		if(y==p) return true;
		if(y==prev) continue;
		
		check[x]=(check[x] || dfs(y, x, p));
	}
	
	return check[x];
}
 
int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		string s;
		cin>>s;
		
		for(int i=0; i<N; i++) {
			a[i].clear();
			check[i]=false;	
		}
		
		for(int i=0; i<N; i++) {
			int u=i, v=(i+1)%N;
			
			if(s[i]=='-') {
				check[u]=check[v]=true;
				a[u].push_back(v);
				a[v].push_back(u);
			} else if(s[i]=='>') {
				a[u].push_back(v);
			} else {
				a[v].push_back(u);
			}
		}
		
		for(int i=0; i<N; i++) {
			if(check[i]==false) check[i]=dfs(i, -1, i);
		}
		
		int ans=0;
		for(int i=0; i<N; i++) ans+=check[i];
		cout<<ans<<'\n';
	}
	
	return 0;
}

/* 
SOLUTION BY oolimry

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int TC; cin >> TC;
	while(TC--){
		int n; cin >> n;
		string s; cin >> s;
		
		bool hasCW = false;
		bool hasCCW = false;
		for(int i = 0;i < n;i++){
			if(s[i] == '<') hasCW = true;
			if(s[i] == '>') hasCCW = true;
		}
		
		if(hasCW && hasCCW){
			int ans = 0;
			s += s[0];
			for(int i = 0;i < n;i++){
				if(s[i] == '-' || s[i+1] == '-') ans++;
			}
			cout << ans << "\n";
		}
		else{
			cout << n << "\n";
		}
	}
}
*/
