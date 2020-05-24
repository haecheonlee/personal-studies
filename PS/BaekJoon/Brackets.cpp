#include <iostream>
#include <stack>
using namespace std;

int main() {
	
	while(1) {
		string s;
		getline(cin, s);

		if(s=="#") break;
	
		stack<char> s1;
		bool check=true;
		for(auto &c : s) {
			if(c=='(' || c=='{' || c=='[') s1.push(c);
			
			if(c==')') {
				if(s1.top()!='(') check=false;
				else s1.pop();
			}

			if(c=='}') {
				if(s1.top()!='{') check=false;
				else s1.pop();
			}
				
			if(c==']') {
				if(s1.top()!='[') check=false;
				else s1.pop();
			}
			
			if(!check) break;
		}
		
		if(check && s1.empty()) cout<<"Legal\n";
		else cout<<"Illegal\n";
	}
	
	return 0;
}
