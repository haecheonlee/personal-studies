#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	string s;
	set<string> group;
	for(int i=0; i<n; i++) {
		cin>>s;
		sort(s.begin(), s.end());
		
		group.insert(s);
	}	
	
	cout<<group.size();

	return 0;
}

/*
INPUT:
4
cat
dog
god
tca

OUTPUT:
2
*/
