#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		// 3 5 7
		bool is_possible=false;
		for(int i=0; i<=N/3; i++) {
			for(int j=0; j<=N/5; j++) {
				int three=(i*3), five=(j*5), rest=(N-(three+five))/7;
				int seven=rest*7;
				
				if(three+five+seven==N) {
					cout<<three/3<<' '<<five/5<<' '<<seven/7<<'\n';
					is_possible=true;
					break;
				}
			}
			if(is_possible) break;
		}
		if(is_possible==false) cout<<-1<<'\n';
	}

	return 0;
}
