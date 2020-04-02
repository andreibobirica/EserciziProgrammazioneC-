#include<iostream>
using namespace std;

void newriga(bool (*B)[6], bool (*B1)[6],int r);
bool tutta_false(bool (*X)[6], int r);

//PRE X matrice 6x6 tutta vuota
void leggi(bool(*X)[6]){
    bool * y=*X;
    for(int i=0; i<36;i++)
    cin>>y[i];
}
//POST X matrice 6x6 tutta piena di valori immessi da tastiera.

//PRE= X matrice 6x6 tutta piena, viene richiesta la stampa della riga r con 0<=r<6
void stampa_r(bool(*X)[6], int r){
    cout<<"riga:"<<r<<'=';
    for(int i=0; i<6;i++)
        cout<<X[r][i]<<' ';
    cout << endl;
}
//POST=Viene eseguita la stampa della riga r della matrice X

//PRE= X matrice 6x6 tutta piena, viene richiesta la stampa della matrice fino alla rifa r compresa con r>=0
void stampa(bool (*X)[6],int r){
    for(int i=0; i<r; i++)
        stampa_r(X,i);
}
//POST= Viene eseguita la stampa della matrice X

main(){
    bool B[6][6],B1[6][6];
    leggi(B);
    // inizializza B1
    //copio la prima riga
    for(int i=0;i<6;i++)
        B1[0][i]=B[0][i];
    //controllo e copio modifcando le altre righe
    int riga;
    for(riga=0;riga<5 && !tutta_false(B1,riga);riga++)//R1
        newriga(B, B1,riga);
    stampa(B1,riga+1);
    if(riga<5 || (riga==5 && tutta_false(B1,5)))
        cout<< "non c'e' cammino"<<endl;
    else
        cout<<"c'e' cammmino"<<endl;
}
/**
 * Main POST=
 * Il main stampa interamente B1 ma se presente una riga tutta_false, si ferma a codesta riga
 * in aggiunta viene stampato anche un messaggio, se si è trovato un cammino o no;
 * Il main stampando B1 evidenzia se esiste o meno un camino in B;
 * per fare questo:
 * 
 * Il main inizialmente:
 * dichiara B e B1 dure matrici 6x6 di tipo bool;
 * inizializza B con valori immessi dal utente, utilizzando la funzione leggi();
 * Poi Passa alla giusta inizializzazione di B1,
 * per prima cosa copia la prima riga di B in B1;
 * Successivamente pensa a inizializzare le altre righe di B1 utilizzando un ciclo R1 e la funzinoe newRiga;
 * R1=
 * Condizione Iniziale: riga==0 && !tutta_false(B1,riga)!=0
 * Condizione Intermedia: 0<=riga<5 && !tutta_false(B1,riga)!=0
 * Condizione Finale: riga==5 || !tutta_false(B1,riga)==0
 * 
 * Ad ogni iterazione avremo: 
 *      abbiamo: (B1[riga][0...5] è definito) && (B1[riga+1...5][0...5] NON è definito)
 * 
 * Analizziamo ogni riga di B a partire da 0 fino alla penultima, quindi alla 4
 * questo perchè a ogni riga "riga" di B dovremmo inizializzare una riga "riga+1" di B1
 * detto ciò ci doppiamo fermare alla penultima
 * Se prima di iniziare il ciclo abbiamo definito la prima riga di B1, e se ad ogni iterazione definiamo
 * la riga "riga+1" di B1, allora avremmo che ad ogni iterazione avremo la riga "riga" di B1 definita;
 * 
 * Ad ogni iterazione, controllando tutte le righe dalla 0 fino alla 4, controlliamo che la riga "riga" di B1 non sia tutta_false, se fosse tutta false si dovrebbe uscire dal ciclo, 
 * in quanto non esiste nessun cammino che passa per una riga tutta false;
 * ad ogni iterazione richiamiamo la funzione newriga, la quale definisce la riga "riga+1" di B1 utilizzando 
 * B e definendola in maniera da far rimanere le posizioni con 1 che effetivamente servono per delimitare un cammino
 * attraverso B;
 * 
 * Alla fine del ciclo stampiamo B1
 * 
 * poi controlliamo se (riga<5 || (riga==5 && tutta_false(B1,5)))
 * cioò se la riga a cui si è arrivati col controllo è minore di 5
 * oppure, anche se si è arrivati alla riga 5, cioè se si è usciti dal ciclo senza incontrare
 * righe tutte_false, si controlla anche l'ultima riga, la quale anche lei non deve essere tuta false
 * con tutta_false(B1,5);
 * se TRUE
 *  viene stampato un messaggio di errore che non si è trovato il cammino
 * se FALSE
 *  viene stampato un messaggio col caso in cui si è trovato un cammino
 * 
 * 
 * 
 * 
 */

//PRE=(0<=r<=4)&&(le righe r di B e B1 sono definite)
void newriga(bool (*B)[6], bool (*B1)[6],int r){
    //Controllo primo elemento
    if(B[r+1][0]==1 && (B1[r][0] == 1 || B1[r][1] == 1))
        B1[r+1][0]=1;
    else
        B1[r+1][0]=0;
    //Controllo ultimo elemento
    if(B[r+1][5]==1 && (B1[r][4] == 1 || B1[r][5] == 1))
        B1[r+1][5]=1;
    else
        B1[r+1][5]=0;
    //Controllo elementi intermedi
    for(int i=1;i<5;i++){
        if(B[r+1][i]==1 && (B1[r][i-1] == 1 || B1[r][i] == 1 || B1[r][i+1] == 1))
            B1[r+1][i]=1;
        else
            B1[r+1][i]=0;
    }//R2
}
//POST=(calcola, nel modo descritto in consegna, la nuova riga r+1 di B1 usando la riga r+1 di B e la riga r di B1)
/**
 * La Funzione new riga, utilizza una data riga r di B per definire una richiesta riga r di B1;
 * La richiesta è specificata nella consegna;
 * Per non complicare l'algoritmo si elabora la funzione tenendo conto delle due eccezzioni della riga r+1 nella matrice B1;
 * Il primo e l'ultimo elemento della riga in B1;
 * Inizialmente si elabora il primo elemento:
 * Si controlla se l'elemento primo di r+1 è == 1 e se anche 
 * i suoi elementi alla "testa" cioè B1[r][0] == 1 oppure B1[r][1] == 1
 * Nel caso TRUE l'elemento primo della riga r+1 di B1 viene inizializzata a 1 nel caso FALSE a 0
 * Successivamente si elabora l'ultimo elemento:
 * Si controlla se l'elemento ultimo di r+1 è == 1 e se anche 
 * i suoi elementi alla "testa" cioè B1[r][4] == 1 oppure B1[r][5] == 1
 * Nel caso TRUE l'elemento ultimo della riga r+1 di B1 viene inizializzata a 1 nel caso FALSE a 0
 * 
 * Una volta esaminate le ecezioni, si passa al controllo dei valori intermedi i quali seguono tutti
 * lo stesso pattern di controllo e lo si può fare con un ciclo
 * R2=
 * Condizione Iniziale:     i==1
 * Condizione Intermedia: 1<=i<5
 * Condizione Finale: i==5
 * 
 * Il ciclo esamina man mano tutti gli elementi della riga r+1
 * Si controlla se l'elemento i di r+1 è == 1 e se anche 
 * i suoi elementi alla "testa" cioè B1[r][i-1] == 1 oppure B1[r][i] == 1 oppure B1[r][i+1] == 1 
 * Nel caso TRUE l'elemento i della riga r+1 di B1 viene inizializzata a 1 nel caso FALSE a 0
 * 
 * Alla fine del ciclo avremmo gli elementi della riga richiesta dal main di B1 sono inizializzati corettamente
 * cioè tenendo conto degli elementi della riga "riga" in testa, cioè a destra a sinistra o sopra tranne per le ecezzioni del primo e del ultimo elemento;
 * 
 */


//PRE= X matrice 6x6, r è la riga richiesta
bool tutta_false(bool (*X)[6], int r){
    bool allFalse=true;
    for(int i=0;i<6 && allFalse;i++){
        if(X[r][i]==1)
            allFalse=false;
    }
    return allFalse;
}
//POST= return true sse la riga r di X è tutta false
//return false sse la riga r di X è tutta true;
