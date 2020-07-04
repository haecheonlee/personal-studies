#include <iostream>

using namespace std;

void convert(int num, int base) {
	if(num==0) return;
	convert(num/base, base);
	cout<<num%base<<" ";
}

int main() {
	int A,B;
	cin>>A>>B;
	
	int M;
	cin>>M;
	
	int ans=0;
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		
		ans=ans*A+x;
	}
	
	convert(ans,B);

	return 0;
}
