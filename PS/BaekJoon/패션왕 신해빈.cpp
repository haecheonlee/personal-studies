#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		vector<string> category;
		map<string,int> types;
		
		int n;
		cin>>n;
		
		string cloth,type;
		for(int i=0; i<n; i++) {
			cin>>cloth>>type;
			
			if(types[type]==0) category.push_back(type);
			types[type]++;
		}
		
		if(n>0) {
			int ans=1;
			for(auto each : category) {
				ans*=(types[each]+1);
			}
			cout<<ans-1<<'\n';
		} else {
			cout<<0<<'\n';
		}
	}

	return 0;
}

/*
INPUT:
2
3
hat headgear
sunglasses eyewear
turban headgear
3
mask face
sunglasses face
makeup face

OUTPUT:
5
3
*/
