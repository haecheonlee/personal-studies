#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getResult(const vector<int> &v, int max, bool isFurther) {
	int result=0;
	
	for(int i=v.size()-1; i>=0; i--) {
		if(isFurther) {
			if(i==v.size()-1) {
				result+=v[i];
				i-=max;
				continue;
			}
		}
		
		result+=(v[i]*2);
		i-=max;
	}
	
	return result;
}

int main() {
	int N,M,num;
	cin>>N>>M;
	
	vector<int> pos, neg;
	for(int i=0; i<N; i++) {
		cin>>num;
		
		if(num>0) pos.push_back(num);
		else neg.push_back(abs(num));
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	
	int total=0;
	if(pos.size()==0) {
		total+=getResult(neg, M-1, true);
	} else if(neg.size()==0) {
		total+=getResult(pos, M-1, true);
	} else {
		if(pos[pos.size()-1]>neg[neg.size()-1]) {
			total+=getResult(pos, M-1, true);
			total+=getResult(neg, M-1, false);
		} else {
			total+=getResult(neg, M-1, true);
			total+=getResult(pos, M-1, false);
		}
	}
	
	cout<<total;
	
	return 0;
}

/*
boj.kr/1461

INPUT:
7 2
-37 2 -6 -39 -29 11 -28

OUTPUT:
131
*/
