#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
	
	while(T--) {
		string s;
		cin>>s;
		
		stack<char> left, right;
		for(auto& c : s) {
			if(c=='<') {
				if(left.size()) {
					right.push(left.top());
					left.pop();
				}
			} else if(c=='>') {
				if(right.size()) {
					left.push(right.top());
					right.pop();
				}
			} else if(c=='-'){
				if(left.size()) left.pop();
			} else {
				left.push(c);
			}
		}
		
		while(!right.empty()) {
			left.push(right.top());
			right.pop();
		}

		string ans="";
		while(!left.empty()) {
			ans+=left.top();
			left.pop();
		}
		reverse(ans.begin(), ans.end());
		cout<<ans<<'\n';
	}

	return 0;
}
