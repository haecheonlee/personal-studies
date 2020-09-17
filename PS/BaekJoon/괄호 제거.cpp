#include <iostream>
#include <stack>
#include <vector>
#include <set>

using namespace std;
using pi=pair<int,int>;

const int SIZE=2e2+1;

int p[SIZE];
vector<pi> a;

int main() {
	string s;
	cin>>s;

	stack<int> stk;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='(') {
			stk.push(i);
		}
		else if(s[i]==')') {
			a.push_back(make_pair(stk.top(), i));
			p[stk.top()]=p[i]=(int)a.size()-1;
			stk.pop();
		}
	}
	
	set<string> ans;
	int L=(1<<a.size())-1;
	for(int x=1; x<=L; x++) {
		string r="";
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='(' || s[i]==')') {
				if((x&(1<<p[i]))==0) r+=s[i];
			} else {
				r+=s[i];
			}
		}
		
		ans.insert(r);
	}
	
	for(auto& x : ans) cout<<x<<'\n';

	return 0;
}
