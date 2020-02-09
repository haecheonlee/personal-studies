#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int up=0;
	string total="";
	for(int i=0; i<max(a.size(), b.size()); i++) {
		int	i_a=0; if(i<a.size()) i_a=a[i]-'0';
		int i_b=0; if(i<b.size()) i_b=b[i]-'0';
		
		int i_total=i_a+i_b+up;
		if(i_total>=10) {
			i_total-=10;
			up=1;
		} else up=0;
		total+=to_string(i_total);
	}
	if(up==1) total+="1";
	
	reverse(total.begin(), total.end());
	cout<<total;
	
	return 0;
}

/*
boj.kr/15353

INPUT:
9223372036854775807 9223372036854775808

OUTPUT:
18446744073709551615
*/
