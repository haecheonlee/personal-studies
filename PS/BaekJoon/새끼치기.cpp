#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin>>n;
		
	vector<int> vec;
	for(int i=1; i<=n; i++) {
		if(vec.size()==0) {
			vec.push_back(3);
		} else {
			int current_size=vec.size();
			int erased=0;
			for(int j=0; j<current_size-erased; j++) {
				vec[j]--;
				if(vec[j]==0) {
					vec.erase(vec.begin()+j);
					j--;
					erased++;
				}
				int year=((i%2==0)?4:3);
				vec.push_back(year);
			}
		}
	}
	
	cout<<vec.size();

	return 0;
}

/*
boj.kr/17291

INPUT:
4

OUTPUT:
7
*/
