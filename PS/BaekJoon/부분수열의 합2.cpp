#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
vector<int> vec;
unordered_map<int,bool> result;
int list[20];
bool check[20];

void go(int index, int start, int count) {
	if(index==count) {
		int r=0;
		for(int i=0; i<count; i++) {
			r+=vec[list[i]];
		}
		result[r]=true;
		return;
	}
	
	for(int i=start; i<vec.size(); i++) {
		if(check[i]) continue;
		list[index]=i; check[i]=true;
		go(index+1,i+1,count);
		check[i]=false;
	}
}

int main() {
	cin>>n;
	
	vec=vector<int>(n);
	for(int i=0; i<n; i++) {
		cin>>vec[i];
	}
	
	for(int i=1; i<=vec.size(); i++) {
		go(0,0,i);
	}
	
	int min_value=*min_element(vec.begin(), vec.end());
	if(min_value>1) {
		cout<<1;
	} else {
		while(result[min_value]!=false) {
			min_value++;
		}
		cout<<min_value;
	}
	
	return 0;
}

/*
boj.kr/14225

INPUT:
3
2 1 4

OUTPUT:
8
*/
