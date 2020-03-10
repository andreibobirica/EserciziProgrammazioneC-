#include <iostream>
using namespace std;

void X2B(int X,int B[],int posB){
    int q = X;
    for(int i=posB-1;i>=0;i--){
        B[i]=q%2;
        q=q/2;
    }
}
void Y2B(float Y,int B[],int posB){
    for(int i=0;i<posB;i++){
        Y*=2;
        if(Y>=1){B[i]=1;Y--;}
        else{B[i]=0;}
    }
}


main()
{
  int X;
  int B[10];
  float Y;
  cin >> X >> Y;
  X2B(X,B,4);
  Y2B(Y,B+4,6);
  for(int i=0; i<10; i++)
    cout<<B[i]<<' ';
  cout<<endl;
} 
