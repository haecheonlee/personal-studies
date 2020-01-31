#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,l,num;
	cin>>n>>l;
	
	vector<int> vec;
	for(int i=0; i<n; i++) {
		cin>>num;
		vec.push_back(num);
	}
	
	sort(vec.begin(), vec.end());
	
	int count=0;
	
	while(!vec.empty()) {
		int current=vec[0]+l-1;
		int index=0;
		for(int i=0; i<vec.size(); i++) {
			if(vec[i]>current) break;
			index=i+1;
		}

		vec.erase(vec.begin(), vec.begin()+index);
		
		count++;
	}
	
	cout<<count;
	
	return 0;
}

/*
boj.kr/1449

INPUT:
4 2
1 2 100 101

OUTPUT:
2
*/
