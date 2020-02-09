#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void removeZero(string &s) {
	if(s[0]=='0') {
		while(s[0]=='0' && s.size()>1) {
			s.erase(0,1);
		}
	}
}

int main() {
	int t;
	cin>>t;
	
	vector<string> vec;
	while(t--) {
		string s;
		cin>>s;	

		string current="";
		int current_num=0;
		for(int i=0; i<s.size(); i++) {
			if(s[i]>='0' && s[i]<='9') {
				current+=s[i];
			} else {
				if(current!="") {
					removeZero(current);
					vec.push_back(current);
					current="";
				}
			}
		}
		
		if(current!="") {
			removeZero(current);
			vec.push_back(current);
		}
	}

	sort(vec.begin(), vec.end(), [](const string &l, const string &r) {
		if(l.size()<r.size()) return true;
		else if(l.size()>r.size()) return false;
		
		for(int i=0; i<l.size(); i++) {
			if(l[i]<r[i]) return true;
			if(l[i]>r[i]) return false;
		}
		
		return true;
	});
	
	for(int i=0; i<vec.size(); i++) cout<<vec[i]<<'\n';
	
	return 0;
}

/*
boj.kr/2870

INPUT:
4
43silos0
zita002
le2sim
231233

OUTPUT:
0
2
2
43
231233
*/
