#include <iostream>
#include <map>
#include <set>

using namespace std; 

set<string> ans;
map<string,bool> enter;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string S,E,Q;
	cin>>S>>E>>Q;
	
	string time,name;
	while(cin>>time>>name) {
		if(time<=S) enter[name]=true;
		else {
			if(E<=time && time<=Q) {
				if(enter[name]) ans.insert(name);
			}
		}
	}
	cout<<ans.size();
	
	return 0;
}
