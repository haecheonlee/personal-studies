#include <iostream>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		string s;
		cin>>s;
		
		int total=0;
		for(int i=s.size()-1; i>=0; i--) {
			int current=s[i]-'0';
			
			if(i%2==0) {
				current*=2;

				int new_value=current;
				if(current>=10) {
					new_value=0;
					for(int i=10; i>=1; i/=10) {
						new_value+=current/i; 
						current%=i;
					}
				}
				s[i]=new_value+'0';
			}
			total+=s[i]-'0';
		}

		if(total%10==0) cout<<"T\n";
		else cout<<"F\n";
	}

	return 0;
}

/*
boj.kr/14726

INPUT:
3
2720992711828767
3444063910462763
6011733895106094

OUTPUT:
T
F
T
*/
