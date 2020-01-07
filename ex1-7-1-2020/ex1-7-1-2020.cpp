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
main()
{
  int A[100],P[20],dimA,dimP;
  cin>>dimA>>dimP;
  leggi(A,dimA);
  leggi(P,dimP);
  
  for (size_t i = 0; i < dimA; i++){
	  for (size_t e = 0; e < dimP; e++){
		  bool pat = true;
	  	  if(A[i+e]!=P[e]){
	  		pat=false;
	  		break;
	  	  }
	  	  if(e==dimP-1 && pat){
	  		  cout << "trovato match che inizia in posizione " << i <<" di A" << endl;
	  	  }
	  }
  }

}
