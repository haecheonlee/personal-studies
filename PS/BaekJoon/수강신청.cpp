#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX=5e5+2;

unordered_map<string,int> m;
vector<string> a;

int main() {
	int K,L;
	cin>>K>>L;

	for(int i=0; i<L; i++) {
		string s;
		cin>>s;
		
		m[s]=i;
		a.push_back(s);
	}
	
	vector<string> ans;
	for(int i=0; i<L; i++) {
		if(m[a[i]]==i) ans.push_back(a[i]);
	}
	
	if(ans.size()<K) K=ans.size();
	for(int i=0; i<K; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
