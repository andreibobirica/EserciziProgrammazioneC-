#include<iostream>
using namespace std;
void superC(int X[][10], int righe, int& sc, int& rip) ;
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

void nMaxEqualColonna(int X[][10],int righe,int colonna, int& sr, int& rip){
    int ripetizioniMax=0;
    int indiceMax = 0;
    for(int e=0; e<righe;e++){
        int elemento = X[e][colonna];
        int ripetizioni = 0;
        for(int i=0;i<righe;i++){
            if(X[i][colonna]==elemento){
                ripetizioni++;
            }
        }
        if(ripetizioni>ripetizioniMax){
            ripetizioniMax=ripetizioni;
            indiceMax=e;
        }
    }
    sr=indiceMax;
    rip=ripetizioniMax;
}

//PRE=(X è un array int [righe][10] completamente definito)
void superC(int X[][10], int righe, int& sc, int& rip) {
    sc=0;
    rip=0;
    for(int i=0;i<10;i++){
        int sr,ripR;
        nMaxEqualColonna(X,righe,i,sr,ripR);
        //cout << sr << " | " << ripR << endl;
        if(ripR>rip){
            sc = i;
            rip = ripR;
        }
    }
}
//POST=(sc è la colonna col massimo numero di colonne identiche e rip è il numero di ripetizioni di sc)

