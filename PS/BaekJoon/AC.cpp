#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		string p,s;
		int N;
		cin>>p>>N>>s;
		
		int idx=0;
		while(1) {
			if(idx>=s.size()) break;
			if(s[idx]=='[' || s[idx]==']' || s[idx]==',') {
				idx++;
				continue;
			}
			
			int x=0;
			while(1) {
				if(s[idx]<'0' || s[idx]>'9') break;
				x=10*x+(s[idx]-'0');	
				idx++;
			}
			dq.push_back(x);
		}
		
		// operation starts
		bool front=true;
		bool is_error=false;
		for(auto& a : p) {
			if(a=='R') {
				// reverse
				front=!front;
			} else {
				// remove first
				if(dq.empty()) {
					is_error=true;
					break;	
				} else {
					if(front) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		
		// answer
		if(is_error) cout<<"error\n";
		else {
			cout<<"[";
			while(!dq.empty()) {
				if(front) {
					cout<<dq.front();
					dq.pop_front();
				} else {
					cout<<dq.back();
					dq.pop_back();
				}
				
				if(dq.size()) cout<<",";
			}
			cout<<"]\n";
		}
		
	}

	return 0;
}
