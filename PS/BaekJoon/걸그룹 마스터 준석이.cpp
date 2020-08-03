#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string,vector<string>> team;
map<string,string> member;

int main() {
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		string name;
		int num;
		cin>>name>>num;
		
		vector<string> a(num);
		for(int j=0; j<num; j++) {
			cin>>a[j];
			member[a[j]]=name;	
		}
		sort(a.begin(), a.end());
		team[name]=a;
	}

	while(M--) {
		int x;
		string name;
		cin>>name>>x;
		
		if(x==0) {
			vector<string> a=team[name];
			for(auto& x : a) cout<<x<<'\n';
		} else {
			cout<<member[name]<<'\n';
		}
	}

	return 0;
}
