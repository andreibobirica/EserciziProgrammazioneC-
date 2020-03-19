#include<iostream>
using namespace std;
void superC(int X[][10], int righe, int& sc, int& rip);
main()
{
    int X[5][10];
    for(int i=0; i<5; i++)
        for(int j=0; j<10; j++)
        cin >> X[i][j];
    int supc, rip;
    superC(X,5,supc,rip);
    cout<<"la super colonna è "<< supc<<" e ripete "<<rip<<" volte"<<endl;
}


//PRE=(X è un array int [righe][10] completamente definito)
void superC(int X[][10], int righe, int& sc, int& rip) {
    rip=0;
    for(int i=0;i<10;i++){
        int ripetizioni=0;
        for(int j=i;j<10;j++){
            bool equal=true;
            for(int e=0;e<righe;e++){
                if(X[e][j]!=X[e][i]){
                    equal=false;
                    break;
                }
            }
            if(equal)
            ripetizioni++;
        }
        if(ripetizioni>rip){
            rip=ripetizioni;
            sc=i;
        }
    }
}
//POST=(sc è la colonna col massimo numero di colonne identiche e rip è il numero di ripetizioni di sc)

