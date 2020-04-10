#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	vector<int> s;
	
	string a;
	int n;
	cin>>a>>n;
	
	s.push_back(stoi(a));
	int duplicate;
	while(1) {
		int next=0;
		
		for(int i=0; i<a.size(); i++) {
			int digit=a[i]-'0';
			int total=pow(digit,n);
			
			next+=total;
		}
		
		a=to_string(next);
		
		if(find(s.begin(),s.end(),next)==s.end()) s.push_back(next);
		else {
			duplicate=next;
			break;
		}
	}
	
	int index=distance(s.begin(), find(s.begin(),s.end(),duplicate));
	cout<<index;
	
	return 0;
}

/*
INPUT:
57 2

OUTPUT:
4
*/
