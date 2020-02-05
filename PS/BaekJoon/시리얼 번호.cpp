#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getTotal(const string &s) {
	int total=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0' && s[i]<='9') {
			total+=(s[i]-'0');
		}
	}
	return total;
}

bool Sort(const string &l, const string &r) {
	if(l.size()!=r.size()) {
		return l.size()<r.size();
	}
	else {
		int l_total=getTotal(l);
		int r_total=getTotal(r);
		
        if(l_total!=r_total) return l_total<r_total;
	} 
	
	return l<r;
}

int main() {
	int n;
	cin>>n;
	
	vector<string> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i];
	
	sort(vec.begin(), vec.end(), Sort);
	for(int i=0; i<n; i++) cout<<vec[i]<<'\n';
	
	return 0;
}

/*
boj.kr/1431

INPUT:
5
ABCD
145C
A
A910
Z321

OUTPUT:
A
ABCD
Z321
145C
A910
*/
