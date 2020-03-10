#include <iostream>
#include <math.h>/* pow */
using namespace std;

int f1(int B[], int posB){
    int cif =  pow(2,posB-1);
    int n = 0;
    for(int i=0;i<posB;i++){
        if(B[i]==1){
            n+=cif;
        }
        cif/=2;
    }
    return n;
}

double f2(int B[], int posB){
    int esp=posB;
    double n = 0;
    for(int i=0;i<posB;i++){
        double cif =  pow(2,-(i+1));
        cout << cif <<endl;
        if(B[i]==1){
            n+=cif;
        }
    }
    return n;
}

main()
{
  int B[10];
  
  for(int i=0; i<10; i++)
    cin >>B[i];
 
int pi= f1(B,4); //traduci parte intera
double pdec=f2(B+4,6); //traduci parte decimale
  
  cout<<"value="<<pi+pdec<<endl;
} 
