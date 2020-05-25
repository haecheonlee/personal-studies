#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		
		multiset<int> s;
		for(int i=0; i<n; i++) {
			char o;
			int x;
			
			cin>>o>>x;
			if(o=='I') {
				// insert
				s.insert(x);
			} else if(o=='D') {
				// delete
				if(s.empty()==false) {
					auto first=s.begin();
					auto last=prev(s.end());
					
					if(x==-1) s.erase(first);
					else s.erase(last);
				}
			}
		}
		
		if(s.empty()) cout<<"EMPTY\n";
		else cout<<*prev(s.end())<<" "<<*s.begin()<<endl;
	}
	
	return 0;
}
