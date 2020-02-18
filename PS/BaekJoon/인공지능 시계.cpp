#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	int hrs=a,mins=b,secs=c;
	hrs+=d/3600;d%=3600;
	mins+=d/60;d%=60;
	secs+=d;

	mins+=secs/60;secs%=60;
	hrs+=mins/60;mins%=60;
	cout<<((hrs>23) ? hrs%24:hrs)<<" "<<mins<<" "<<secs;
	
	return 0;
}

/*
boj.kr/2530

INPUT:
14 30 0
200

OUTPUT:
14 33 20
*/
