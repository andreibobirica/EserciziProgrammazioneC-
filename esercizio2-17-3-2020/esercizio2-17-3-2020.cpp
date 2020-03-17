#include<iostream>
using namespace std;

void togliDoppi(int A[],int & dimA);
void elimina(int A[], int & dimA, int x);

main()
{
    int A[20],dimA,i=0;
    cin>>dimA;
    while(i<dimA)
    {
        cin>>A[i];
        i=i+1;
    }
    togliDoppi(A,dimA);
    i=0;
    while(i<dimA)
    {cout<<A[i]<<' '; i=i+1;}
    cout<<endl;
}

//PRE=(A ha dimA elementi, vA=A)
void togliDoppi(int A[],int & dimA){
    for(int i=0;i<dimA-1;i++){
        dimA= dimA-(1+i);
        elimina(A+i+1,dimA,A[i]);
        dimA= dimA+(1+i);
    }/*
    L0bbiettivo della funzione togli Doppi, è quello di togliere i doppioni all'interno di un array A.
    Per fare questo scroriamo uno alla volta gli elementi del array A di dimA posizioni.
    Ci avvaliamo della funzione elimina, la quale dato un array, e dato una variabile x, elimina dal suddetto array
    tutte le occorenze di x, mantenendo l'ordine del array e modificando la variabile dimA con la lunghezza effettiva del array.
    Il ciclo comincia da i=0 e finisce fino a dimA-1, in quanto non serve esaminare l'ultima posizione, doppo spiegato il perchè.
    se siamo sulla posizione i, il contenuto di A[i] non si deve ripetere nelle successive i+1 posizioni di A.
    ridefiniamo quindi la lunghezza di A, per eliminare solo i successivi elementi, con dimA= dimA-(1+i);, togliendo dal conteggio
    le posizioni iniziali, più la attuale, invochiamo come chiamante la funzione elimina, e come puntatore
    di array passiamo A+i+1, cioè l'ultima parte del array, a partire dalla posizione successiva di A.
    come x della nostra funzione elimina avremo A[i], nel caso questo sia veramente presente nelle posizioni successive esse
    verranno eliminate, nel caso contrario nulla accadrà.
    Una volta terminata la funzione elimina, dobbiamo costare che sono state rimosse, se presenti, le occorenze indesiderabili all'interno di A
    Ora quindi dobbiamo riprestinare A allo stato di partenza, cioè incrementando dim con le posizioni precedenti a i che aveva tolto precedentemente
    Questo lo facciamo con dimA= dimA+(1+i);
    A questo punto dal nostrao array A sono state tolte tutte le occorenze doppie della posine di A i, (A[i]),
    nelle iterazioni successive verrano esaminate le restanti posizioni, e a ogni ciclo dimA verrà ridimensianato, e gli elementi del array subiranno mmodifiche , in tal
    modo gli elementi doppi di A verranno tolti.
    */
}
//POST=(in A[0..dimA-1] è prodotto da A togliendo i doppi e mantenendo solo la prima occorrenza di ciascun
//valore distinto in vA)



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