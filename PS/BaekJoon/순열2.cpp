#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	int num;
	
	while(cin>>s>>num) {
		
		string initial=s;
		int cnt=1;
		bool isFound=false;
		do {
			if(cnt==num) {
				isFound=true;
				break;
			}
			
			cnt++;
		} while(next_permutation(s.begin(), s.end()));
		
		cout<<initial<<" "<<num<<" = ";
		if(isFound) cout<<s;
		else cout<<"No permutation";
		cout<<'\n';
	}
	
	return 0;
}
