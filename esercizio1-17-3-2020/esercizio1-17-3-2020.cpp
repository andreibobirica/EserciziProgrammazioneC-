#include<iostream>
using namespace std;

void elimina(int A[], int & dimA, int x);

main()
{
    int A[20],dimA,x,i=0;
    cin >> dimA;
    while(i<dimA)
    {cin>>A[i];i=i+1;}
    cin >> x;
    elimina(A,dimA,x);
    i=0;
    while(i<dimA)
    {cout<<A[i]<<' ';i=i+1;}
    cout<<endl;
}
//PRE =(A contiene dimA elementi, dimA>=0, A=vA) 
void elimina(int A[], int & dimA, int x){
    for(int i=0;i<dimA;i++){
        if(A[i]==x){
            for(int e=i;e<dimA-1;e++){
                A[e]=A[e+1];
            }/*
            Questo ciclo ha come obbiettivo quello di traslare tutti gli elementi di a successivi ad i
            Nella posizione precedente.
            Per fare questo inizia dalla posizione i, quindi e=i, e scorre gli elementi successivi fino ad arrivare alla posizione dimA-1 esclusa.
            Viene escluso l'ultimo elemento perchè non è disponibile un elemento successivo ad esso con cui sostituirlo.
            Viene nonostante tutto lasciato li in quanto avendo noi fuori dal ciclo decrementato dimA di 1, 
            Questo implica che l'ultimo elemento di A, non ha più importanza, quindi non è imporante sostituirlo con il suo successivo
            che non esiste.
            */
            i--;
            dimA--;
        }
    }/*
    R=Ciclo scorre tutti gli elementi di A a partire dalla posizione 0 fino alla posizione dimA
    , quando viene trovato un elemento i di A (A[i]) == x, allora
    si decide di eliminare quel elemento i, per fare questo si avvia un'altro ciclo che impostano 
    l'R valore del elemento i+i a i;
    Facendo questo tutti gli elementi successivi al i da eliminare vvengono traslati di una posizione precedente.
    Una volta eliminato l'elemento i == A, bisogna tornare ad analizzare gli elementi successivi.
    Avendo noi traslato tutti gli elementi sucessivi ad i, nella posizione precedente, quindi avendo
    eliminato un elemento dal array di A, decrementiamo dimA di uno.
    oltre a questo decrementiamo il contatore i di uno in maniera da esaminare al prossimo ciclo 
    l'elemento i-1 , i+1 , quindi dinnuovo l'emento su cui eravamo il ciclo precedente.
    Questo perchè la posizione i è stata sovrascritta con la posizione i+1.
    Una volta decrementati il contatore i e la lunghezza dimA, si procede con il ciclo, andando così avanti.
    Fino ad arrivare a scorrere tutto l'array A.
    Alla fine della elaborazione A avrà tutti gli elementi restanti, in ordine dato che
    abbiamo solamente sostituiro gli indesiderabili con gli elementi successivi, mantenendo l'ordine
    Oltre a questo dimA è diminuito della esatta lunghezza di A, avendo noi decrementato dimA ogni volta che 
    Trovavamo un elemento indesiderabile.
    */
}
//POST(A[0..dimA-1] contiene gli elementi di vA diversi da x nell’ordine relativo che essi avevano in vA)
