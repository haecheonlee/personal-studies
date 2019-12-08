#include <iostream>

using namespace std;

int main()
{
    int d[101][101] = {0};
    int x1, y1, x2, y2;
    
    for(int i=0; i<4; i++) {
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1; x<x2; x++) {
            for(int y=y1; y<y2; y++) {
                d[x][y]++;
            }
        }
    }
    
    int sum = 0;
    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            if(d[i][j]) sum++; 
        }
    }

    cout<<sum<<endl;

    return 0;
}
