#include<iostream>
using namespace std;
void stampaTorta(int *X,int n_ele,int lim1,int lim2,int lim3);
void stampaS(int *X,int n_ele,int lim1,int lim2,int lim3,int strato);
main(){
    int n_ele,lim1,lim2, lim3, X[400];
    cin>>n_ele;
    for(int i=0; i<n_ele; i=i+1)
        cin>>X[i];
    cin>>lim1>>lim2>>lim3;
    cout<<"start"<<endl;
    stampaTorta(X,n_ele,lim1,lim2,lim3);
    cout<<"end"<<endl;
}

//PRE= X è un array contenente valori definiti per le prime n_ele posizioni,
//Bisogna interpretarlo con le dimensioni strati==lim1, righe==lim2, colonne==lim3, tutte > 0.
void stampaTorta(int *X,int n_ele,int lim1,int lim2,int lim3){
    //Calcolo stratoMax contenente valori
    int stratoMax = -1, temp = n_ele;
    for(int i=0;i<lim1 && temp>0;i++){
        temp=temp-(lim2*lim3);
        stratoMax++;
    }//R1
    //Stampa strato
    for(int i=0; i<=stratoMax;i++){
        cout << endl <<"strato" << i<<endl;
        stampaS(X,n_ele,lim1,lim2,lim3,i);
    }//R2
    /**
     * R1=
     * Condizione iniziale: i=0 && temp>0
     * Condizione intermedia: 0<=i<lim1 && temp>0
     * Condizione finale: i>lim1 || temp<=0 || (i>lim1 && temp<=0), quindi si esce dal ciclo
     * Il ciclo serve per calcolare lo stratoMax, cioè lo strato della torta che contiene ancora valori nelle
     * sue posizioni, anche se parzialmente.
     * Temp==n_ele, è una variabile temporanea.
     * Per farlo cicla tutti gli strati, e ad ogni iterazione, toglie dalla variabile temporanea i numeri di elementi
     * che ogni strato puù contenere, temp=temp-(lim2*lim3);
     * Il ciclo puù finire in due modi, se si raggiunge il numero massimo di strati disponibili,
     * oppure se la variabile temporanea ha raggiunto un valore negativo o  ==0.
     * Se la variabile temporanea ha raggiunto un valore <=0 allora significa che gli elementi disponibili del array X
     * sono minori del numero totale di elementi complessivi dello strato.
     * A ogni iterazione , sotraendo alla varibile temporanea il numero di elementi di ogni strato, calcoliamo anche gli strati
     * totali, con stratoMax++;
     * Alla fine del ciclo avremmo calcolato lo stratoMax che ancora contiene valori anche se parzialmente.
     * 
     * R2=
     * Condizione Iniziale: i=0
     * Condizione Intermedia: 0<=i<=stratoMax
     * Condizione Finale 0>stratoMax
     * Questo ciclo serve per iterare tutti gli strati contenenti valori, fino a fermarci allo stratoMax, incluso.
     * Ad ogni iterazione stampiamo il nome dello strato, e invochiamo la funzione stampaS(), la quale stampa lo strato
     * in riferimento.
     */
}
//POST=La funzione stampa l'array X formattato come fosse una torta lim1xlim2xlim3

//PRE= X è un array contenente valori definiti per le prime n_ele posizioni,
//Bisogna interpretarlo con le dimensioni strati==lim1, righe==lim2, colonne==lim3, tutte > 0.
//strato è >=0 e indica lo strato da stampare.
void stampaS(int *X,int n_ele,int lim1,int lim2,int lim3,int strato){
    //cout << n_ele << " " <<lim1 << " " << lim2 << " " << lim3 << " " << strato <<endl;
    int elemI = strato*lim2*lim3;//Primo Elemento
    int ultimoI = n_ele;//Ultimo Elemento
    for(int i=0;i<lim2 && elemI < ultimoI;i++){
        cout << "r"<<i<<":";
        for(int e=0;e<lim3 && elemI < ultimoI;e++)//R4
            cout << X[elemI++]<<" ";
        cout << endl;
    }//R3
    /**
     * elemI è un indice intero, che indica inizialmente il primo elemento dello strato da stampare.
     * nel corso delle iterazioni del ciclo R3 indichetà gli elementi elemI+1 successivi, fino ad arrivare ad ultimoI.
     * ultimoI è un indice intero, che indica l'ultimo elemento presente complessivamente in tutti gli strati.
     * Non indica l'ultimo elemento da stampare, serve per identificare, nel caso di uno strato parzialmente riempito, 
     * le successive posizioni vuote, quindi per fermare la stampa.
     * 
     * R3=
     * Condizione Iniziale: i=0 && elemI < ultimoI
     * Condizione Intermedia: 0<=i<lim2 && elemI < ultimoI
     * Condizione Finale: i>lim2 || elemI>ultimoI || (i>lim2 && elemI>ultimoI)
     * Il ciclo serve per stampare tutti gli elementi esistenti dello strato "stato".
     * Ad ogni iterazione viene stampata il nome della riga, e nel corpo, viene eseguito il ciclo R4
     * il quale stampa tutti gli elementi dellla riga i rispettiva.
     * Il ciclo puù finire o per esaurimento delle righe dello strato, oppure perchè non ci sono più
     * elementi definiti(elemI>ultimoI), oppure per entrambi i motivi contemporaneamente, nel caso l'ultimo elemento esistente
     * coincida con l'ultimo elemento dello strato.
     * 
     * R4=
     * Condizione Iniziale: e=0 && elemI < ultimoI
     * Condizione Intermedia: 0<=e<lim3 && elemI < ultimoI
     * Condizione Finale: e>lim2 || elemI>ultimoI || (e>lim2 && elemI>ultimoI)
     * Il ciclo stampa tutti gli elementi della riga e,
     * Il ciclo puù finire per 2 motivi, il primo è se sono stati esauriti tutti gli elementi della riga e
     * quindi se e>lim2.
     * Il secondo è nel caso non ci siano più elementi definiti quindi nel caso in cui elemI>ultimoI.
     * Ad ogni iterazione la variabile elemI viene incrementata di uno, quindi nella iterazione successiva avremmo 
     * il suo successivo.
     */
}
//POST=La funzione stampa lo strato specifico "strato" formattato con righe==lim2 e colonne lim3