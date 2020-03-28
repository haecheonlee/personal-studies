#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,t;
	cin>>n;
		
	while(n--) {
		cin>>t;
		
		string num,result="SYJKGW";
		unordered_map<string,int> mp;
		for(int i=0; i<t; i++) {
			cin>>num;
			mp[num]+=1;
			
			if(mp[num]>(t/2)) result=num;
		}
		cout<<result<<'\n';
	}

	return 0;
}

/*
INPUT:
4
10 1 2 3 1 2 3 1 2 3 1
5 1 1 1 2 2
6 10 10 2 10 10 2
6 1 1 1 2 2 2 

OUTPUT:
SYJKGW
1
10
SYJKGW
*/
