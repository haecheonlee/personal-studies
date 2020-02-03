#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,num;
	cin>>n;
	
	vector<int> vec;
	for(int i=0; i<n; i++) {
		cin>>num;
		vec.push_back(num);
	}
	
	sort(vec.begin(), vec.end());

	int result=0;
	if(vec.size()%2==0) result=vec[vec.size()/2-1];
	else result=vec[vec.size()/2];

	cout<<result;

	return 0;
}

/*
boj.kr/18310

INPUT:
4
5 1 7 9

OUTPUT:
5
*/
