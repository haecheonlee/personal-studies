#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	
	unordered_map<string,int> mp;
	for(int i=0; i<n; i++) {
		string s;
		cin>>s;
		
		mp[s]=1;
	}
	
	int ans=0;
	for(int i=0; i<m; i++) {
		string s;
		cin>>s;
		
		if(mp[s]) ans+=1;
	}
	cout<<ans;
	

	return 0;
}

/*
INPUT:
5 11
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
codeplus
codeminus
startlink
starlink
sundaycoding
codingsh
codinghs
sondaycoding
startrink
icerink

OUTPUT:
4
*/
