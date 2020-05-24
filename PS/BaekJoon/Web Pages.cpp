#include <iostream>
#include <stack>

using namespace std;

int main() {
	while(1) {
		string s;
		getline(cin, s);
		
		if(s=="#") break;
		
		bool isLegal=true;
		bool opening=false;
		bool closing=false;
		string tag="";
		stack<string> stk;
		
		for(auto &c : s) {
			// tag open
			if(c=='<') {
				opening=true;
				continue;	
			}
			
			// tag close
			if(c=='>') {
				opening=false;
				
				// closing tag
				if(tag[0]=='/') {
					if(stk.empty()) {
						isLegal=false;
						break;
					}
					else {
						if(stk.top()==tag.substr(1)) stk.pop();
						else {
							isLegal=false;
							break;
						}
					}
				} else {
					// opening and closing possible
					if(tag[tag.size()-1]!='/') {
						auto pos_of_space=tag.find(" ");
						if(pos_of_space!=string::npos) tag=tag.substr(0,pos_of_space);
						stk.push(tag);
					}
				}
				
				// reset tag
				tag="";
				continue;
			}
			
			if(opening) tag+=c;
		}
		
		if(isLegal && stk.empty()) cout<<"legal\n";
		else cout<<"illegal\n";
	}
	
	return 0;
}
