#include <iostream>

using namespace std;

int main()
{   
    int N;
    cin>>N;
    
    int l, h;
    int arr[101][101] {0};
    for(int x=0; x<N; x++) {
        cin>>l>>h;
        
        for(int i=l; i<(l+10); i++) {
            for(int j=h; j<(h+10); j++) {
                arr[i][j]++;
            }
        }
    }
    
    int total = 0;
    for(int i=0; i<=100; i++) {
        for(int j=0; j<=100; j++) {
            if(arr[i][j]) total++;
        }
    }
    
    cout<<total<<endl;
    
    return 0;
}

/*
INPUT:
3
3 7
15 7
5 2

OUTPUT:
260
*/
