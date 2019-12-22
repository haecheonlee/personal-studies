#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N=0;
	cin>>N;

	vector<int> v;
	int num=0;
	
	int index = 0;
	for(int i=0; i<N; i++) {
		cin>>num;
		if(num==-1) index = i;
		v.push_back(num);
	}
	
	// find left smallest
	int left_smallest = v[0];
	for(int i=0; i<index; i++) {
		if(left_smallest > v[i]) left_smallest = v[i];
	}
	
	// find right smallest
	int right_smallest = v[index+1];
	for(int i=index+1; i<v.size(); i++) {
		if(right_smallest > v[i]) right_smallest = v[i];
	}
	
	cout<<left_smallest+right_smallest;
	
	return 0;
}

/*
boj.kr/18228

INPUT:
8
5 2 -1 9 9 9 9 1

OUTPUT:
3
*/
