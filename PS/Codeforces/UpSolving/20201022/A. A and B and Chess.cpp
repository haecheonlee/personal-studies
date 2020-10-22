#include <iostream>

using namespace std;

const int MAX=8;

char a[MAX][MAX];

int convert(char x) {
	if(x=='q' || x=='Q') return 9;
	if(x=='r' || x=='R') return 5;
	if(x=='b' || x=='B' || x=='n' || x=='N') return 3;
	if(x=='p' || x=='P') return 1;
	return 0;
}

int main() {
	int W=0, B=0;

	for(int i=0; i<MAX; i++) {
		for(int j=0; j<MAX; j++) {
			char x;
			cin>>x;
			
			if(x>='A' && x<='Z') W+=convert(x);
			else if(x>='a' && x<='z') B+=convert(x);
		}
	}

	if(W==B) cout<<"Draw";
	else if(W>B) cout<<"White";
	else cout<<"Black";

	return 0;
}
