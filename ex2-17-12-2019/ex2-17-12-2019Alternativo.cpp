#include<iostream>
using namespace std;
string getAlbero(int n);
main()
{
   int n;
   cin >> n;
   if(n<3){
      cout << "Altezza non valida";
   }else{
     cout << getAlbero(n);
   } 
}

string getAlbero(int n){
   string albero;
   int blanks = 0;
   int stars = 1;
   //calcolo blanks iniziali
   for(size_t i = 2; i < n; i++){
      blanks++;
   }
   //Salvo la base
   string base;
   for (size_t i = 0; i < blanks; i++){
      base+=" ";
   }
   base+="*";
   //riempio albero
   for (size_t i = 0; i < n-1; i++){
      //riempio blanks
      for (size_t e = 0; e < blanks; e++){
         albero+=" ";
      }
      //riempio stars
      for (size_t e = 0; e < stars; e++){
         albero+="*";
      }
      //decremento e incremento i blanks e gli star
      blanks--;
      stars = stars + 2;
      albero+="\n";
   }
   //aggiungo la bse
   albero+=base;
   //return della funzione
   return albero;
}