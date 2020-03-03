#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string,bool> list;

int main() {
	int n,num;
	cin>>n;
	
	vector<int> vec;
	for(int i=0; i<n; i++) {
		cin>>num;
		
		list[to_string(num)]=true;
		vec.push_back(num);
	}
	
	int result=6;
	for(int i=0; i<n; i++) {
		int cnt=0;
		for(int j=vec[i]; j<vec[i]+5; j++) {
			if(list[to_string(j)]==false) cnt++; 	
		}
		
		result=min(result,cnt);
		if(result<=0) break;
	}
	
	cout<<result;
	
	return 0;
}

/*
boj.kr/1337

INPUT:
3
5
6
7

OUTPUT:
2
*/
