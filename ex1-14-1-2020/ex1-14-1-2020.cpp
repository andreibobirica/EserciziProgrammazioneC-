#include<iostream>
using namespace std;

void findMatch(int dimA,int dimP, int A[], int P[], int matchPrec, int posPrec);

void leggi(int A[],int dim)
{
  int i=0;
  while(i<dim)
    {
      cin>>A[i];
      i=i+1;
    }
}

main()
{
  int A[100],P[20],dimA,dimP,lungmin=-1,inizio=-1;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);
  int scorriA=0;
  
  findMatch(dimA, dimP, A, P, dimP+1,-1);


  if(lungmin==-1)
    cout<<" nessun match trovato"<<endl;
  else
    cout<<"il miglior match inizia in "<< inizio<< " e ha larghezza "<<lungmin<<endl;
}

void findMatch(int dimA,int dimP, int A[], int P[], int matchPrec, int posPrec){
  for (size_t i = 1; i < dimA; i++)
  {
     if(A[posPrec+i] == P[0]){
       int match = dimP;
       for (size_t e = 0; e < dimA; e++)
       {
          for (size_t z = 0; z < dimP; z++)
          {
            int var1 =A[e];
            int var2 =P[z+(dimP-match)];
            if(var1==var2){
              match--;
              break;
            }
          }
       }
        if(match<matchPrec){
         matchPrec=match;
        findMatch(dimA, dimP, A, P, matchPrec,posPrec+1);
         break;
       }
     }//FineIF
  }
}
