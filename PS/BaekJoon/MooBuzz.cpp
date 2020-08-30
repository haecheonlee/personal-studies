/* reference: https://enjoyso.tistory.com/81 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> a;
	for(int i=1; i<=15; i++) {
		if(i%3==0 || i%5==0) continue;
		a.push_back(i);
	}
	cout<<(((N-1)/8)*15)+a[(N-1)%8]<<' ';
	
	return 0;
}
