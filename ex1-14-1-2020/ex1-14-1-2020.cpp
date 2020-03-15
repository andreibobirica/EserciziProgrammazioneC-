#include<iostream>
using namespace std;

void leggi(int A[],int dim)
{
    int i=0;
    while(i<dim)
    {
      cin>>A[i];
      i=i+1;
    }
}


int match( int A[], int P[], int dimA, int dimP){
    cout <<" A:" << A[0] <<" P:" <<P[0] <<endl;
    if(A[0]!=P[0])
    return -1;
    int lungmin = 0;
    bool any;
    for(int i=1; i<dimP;i++){
        any=true;
        for(int e=lungmin+1; e<dimA;e++){
            lungmin++;
            if(A[e]==P[i]){
                //cout << " == " << A[e] << P[i] << " p:" << e << " " << i << endl;
                any=false;
                break;
            }
        } 
    }
    if(any)
    lungmin=-1;
    return lungmin;
}

main()
{
    int A[100],P[20],dimA,dimP;
    cin>>dimA>>dimP;
    leggi(A,dimA);
    leggi(P,dimP);

    int lungmin=-1,lungminB = -1,inizio=-1;
    for(int i=0;i<dimA;i++){
        lungmin = match(A+i,P,dimA,dimP);
        //cout << lungmin <<endl;
        //cout << lungminB <<endl;
        if((lungmin>lungminB&&lungminB==-1)||(lungmin<lungminB&&lungminB>-1&&lungmin>-1)){
            //cout << "found" <<endl;
            lungminB = lungmin;
            inizio = i;
        }
    }
    lungmin = lungminB;
    if(lungmin==-1)
    cout<<" nessun match trovato"<<endl;
    else
    cout<<"il miglior match inizia in "<< inizio<< " e ha larghezza "<<++lungmin<<endl;
}
