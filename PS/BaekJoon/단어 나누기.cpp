#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	string ans="";
	for(int i=1; i<s.size()-2; i++) {
		for(int j=1; j<s.size()-i; j++) {
			string first=s.substr(0,i);
			string second=s.substr(i,j);
			string third=s.substr(i+j,s.size());
			
			// reversing
			reverse(first.begin(), first.end());
			reverse(second.begin(), second.end());
			reverse(third.begin(), third.end());
			
			string reversed=first+second+third;
			if(ans=="" || ans>reversed) ans=reversed;
		}
	}
	cout<<ans;
	
	return 0;
}
