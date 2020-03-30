#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	
	while(1) {
		cin>>n;
		if(n==0) break;
		
		vector<pair<string, string>> vec;
		string s;
		for(int i=0; i<n; i++) {
			cin>>s;
			string lower="";
			for(auto &each : s) lower+=tolower(each);
			
			vec.push_back({lower,s});
		}
		
		sort(vec.begin(), vec.end(), [](const pair<string, string> &l, const pair<string, string> &r) {
			return l.first<r.first;	
		});
		
		cout<<vec[0].second<<'\n';
	}
	
	return 0;
}

/*
INPUT:
3
Cat
fat
bAt
4
call
ball
All
Hall
0

OUTPUT:
bAt
All
*/
