#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int W[N][N];
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) cin>>W[i][j];
	}
	
	vector<int> v;
	for(int i=0; i<N; i++) v.push_back(i);
	
	int result=2147483647;
	do {
		int sum=0;
		bool check=true;
		for(int i=0; i<N-1; i++) {
			if(W[v[i]][v[i+1]]==0) {
				check=false;
				break;
			}else {
				sum+=W[v[i]][v[i+1]];
			}
		}
		
		if(check&&W[v[N-1]][v[0]]) {
			sum+=W[v[N-1]][v[0]];
			result=min(result,sum);
		}
	}while(next_permutation(v.begin(), v.end()));
	
	cout<<result;
    
	return 0;
}

/*
boj.kr/10971

INPUT:
4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0

OUTPUT:
35
*/
