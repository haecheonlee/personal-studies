#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<string> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i];
	
	for(int i=0; i<vec.size(); i++) {
		for(int j=i+1; j<vec.size(); j++) {
			if(i==j) continue;
			
			bool isSame=false;
			for(int a=0; a<vec[j].size(); a++) {
				string new_s=vec[j].substr(a)+vec[j].substr(0,a);
				if(new_s==vec[i]) {
					isSame=true;
					break;
				}
			}
			
			if(isSame) {
				vec.erase(vec.begin()+j);
				i--;
				break;
			}
		}
	}
	
	cout<<vec.size();
	
	return 0;
}

/*
boj.kr/1544

INPUT:
5
picture
turepic
icturep
word
ordw

OUTPUT:
2
*/
