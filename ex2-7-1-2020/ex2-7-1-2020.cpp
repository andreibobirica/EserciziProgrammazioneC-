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
// 1 2 3 4 1 2 3
// 1 2 3
main()
{
  int A[100],P[20],dimA,dimP,lungmax=0, inizio=0;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);
  
  for (size_t i = 0; i < dimA; i++){
	  for (size_t e = 0; e < dimP; e++){
	  	  if(A[i+e]!=P[e]){
	  		if(e > lungmax){
	  			inizio = i;
	  			lungmax = e;
	  		}
	  		break;
	  	  }

	  	  if(e==dimP-1 && A[i+e]==P[e] && e+1 > lungmax){
	  	        inizio = i;
	  		    lungmax = e+1;
	  	  }
	  }
  }
  cout<<"il massimo match ha lunghezza "<< lungmax<< " e inizia in posizione "<< inizio <<" di A"<<endl;
    	
}
