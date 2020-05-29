#include <iostream>
#include <unordered_map>
#include <set>
#include <iomanip>

using namespace std;

unordered_map<string,int> m;
set<string> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string name;
	int cnt=0;
	while(getline(cin,name)) {
		m[name]++;
		s.insert(name);
		cnt++;
	}
	
	for(auto name : s) {
		cout<<name<<" "<<setprecision(4)<<fixed<<(double)m[name]/cnt*100<<'\n';
	}

	return 0;
}
