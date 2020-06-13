#include <iostream>
#include <vector>

using namespace std;
const int MOD=100003;

inline int mod(long long n) {
	if(n>=0) return n%MOD;
	return ((-n/MOD+1)*MOD+n)%MOD;
}

int main() {
	int L;
	string W;
	cin>>L>>W;

	int low=0, high=L;
	while(low+1 < high) {
		int mid=(low+high)/2;
		
		int H=0, power=1;
		vector<int> pos[MOD];
		bool found=false;
		
		for(int i=0; i<=L-mid; i++) {
			if(i==0) {
				for(int j=0; j<mid; j++) {
					H=mod(H + 1LL*W[mid-1-j] * power);
					if(j<mid-1) power=mod(power*2);
				}
			} else {
				H=mod(2 * (H - 1LL * W[i-1] * power) + W[i+mid-1]);
			}
			
			if(!pos[H].empty()) {
				for(int p : pos[H]) {
					bool same=true;
					for(int j=0; j<mid; j++) {
						if(W[i+j]!=W[p+j]) {
							same=false;
							break;
						}
					}
					
					if(same) {
						found=true;
						break;
					}
				}
			}
			
			if(found) break;
			else pos[H].push_back(i);
		}
		
		(found ? low : high)=mid;
	}

	cout<<low;

	return 0;
}
