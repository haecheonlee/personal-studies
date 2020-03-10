#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	while(n--) {
		vector<int> vec(10);
		for(int i=0; i<10; i++) {
			cin>>vec[i];
		}
		sort(vec.begin(), vec.end());
		cout<<vec[7]<<'\n';
	}

	return 0;
}

/*
boj.kr/2693

INPUT:
4
1 2 3 4 5 6 7 8 9 1000
338 304 619 95 343 496 489 116 98 127
931 240 986 894 826 640 965 833 136 138
940 955 364 188 133 254 501 122 768 408

OUTPUT:
8
489
931
768
*/
