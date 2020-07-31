#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<vector<string>,int> group;

int main() {
	int N;
	cin>>N;

	int ans=0;
	for(int i=0; i<N; i++) {
		vector<string> s(3);
		cin>>s[0]>>s[1]>>s[2];
		
		sort(s.begin(), s.end());
		
		group[s]++;
		ans=max(group[s],ans);
	}
	cout<<ans;

	return 0;
}
