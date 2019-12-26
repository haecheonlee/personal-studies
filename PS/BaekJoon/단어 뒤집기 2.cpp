#include <iostream>
#include <stack>

using namespace std;

void print(stack<char> &st) {
    while(!st.empty()) {
	    cout<<st.top();
		st.pop();
	}
}

int main() {
	string s;
	
	getline(cin, s);
	stack<char> st;
	bool opened=false;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '<') {
            print(st);
			cout<<s[i];
			opened = true;	
			continue;
		} else if(s[i] == '>') {
			cout<<s[i];
			opened = false;
			continue;
		} else if(opened) {
			cout<<s[i];	
		} else {
            if(s[i] == ' ') {
			    print(st);
                cout<<s[i];
            } else {
                st.push(s[i]);
            }
		}
	}

	print(st);
	return 0;
}

/*
boj.kr/17413

INPUT:
<int><max>2147483647<long long><max>9223372036854775807

OUTPUT:
<int><max>7463847412<long long><max>7085774586302733229
*/
