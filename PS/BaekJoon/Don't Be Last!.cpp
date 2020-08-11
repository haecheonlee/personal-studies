#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<string> names;
map<string,int> list;
vector<pair<int,string>> cows;

int main() {
	int N;
	cin>>N;

	for(int i=0; i<N; i++) {
		string name;
		int milk;
		cin>>name>>milk;
		
		names.insert(name);
		list[name]+=milk;
	}
	
	for(auto& each : names) cows.push_back({list[each], each});
	sort(cows.begin(), cows.end());

	// set the minimum
	int minimum=0;
	if(cows.size()==7) minimum=cows[0].first;

	string ans="";
	int second=-1, count=-1;
	for(auto& cow : cows) {
		if(second==-1){
			if(cow.first>minimum) {
				ans=cow.second;
				second=cow.first;
				count=1;	
			}
		} else {
			if(cow.first==second) count++;
		}
	}
	
	if(count==-1 || count>1) cout<<"Tie";
	else cout<<ans;
	
	return 0;
}
