#include <iostream>
#include <set>

using namespace std;

multiset<string> a;

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		string s;
		cin>>s;
		
		a.insert(s);
	}
	
	for(int i=0; i<N-1; i++) {
		string s;
		cin>>s;
		
		auto it = a.find(s);
		if(it != a.end()) a.erase(it);
	}
	
	for(auto& it : a) cout<<it<<'\n';
	
	return 0;
}
