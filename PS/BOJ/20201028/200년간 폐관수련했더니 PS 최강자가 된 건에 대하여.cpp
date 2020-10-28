/* reference: rasauq1122 */

#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int sum = 0, d = -1;
	bool skipped = false, possible = true;
	for(int i=0; i<N; i++) {
		int x,p;
		
		if(sum > x) {
			if(skipped) { possible = false; break; }
			skipped = true;
			if(d > p && sum - d <= x) sum = sum + p - d;
		} else {
			sum += p;
		}
		
		d = max(d, p);
	}
	
	cout<<(possible ? "Kkeo-eok" : "Zzz");
	
	return 0;
}
