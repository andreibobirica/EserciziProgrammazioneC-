#include<iostream>
using namespace std;

int S(int *A, int n);

main(){
    int X[400];
    cin>>X[0];
    for(int i=1; i<400 && X[i-1]!=-2; i++)
        cin >>X[i];
    int n;
    cin>>n;
    cout<<"start"<<endl;
    int b=S(X,n); // da fare
    if(b==-2)
        cout<<"sottosequenza "<<n<<" non presente"<<endl;
    else
        cout<<"inizio sottosequenza "<<n<<" indice="<<b<<endl;
    cout<<"end"<<endl;
 }

//PRE=(A contiene una sequenza di interi che termina con -2 e che consiste di una serie
//(possibilmente vuota) di sottosequenze ciascuna delle quali termina con -1, inoltre n
//>=0)
int S(int *A, int n){
    int i=0, sottosequenzaI = 0;
    while(A[i]!=-2){
        if(sottosequenzaI==n)
            return i;
        if(A[i]==-1)
            sottosequenzaI++;
        i++;
    }//R
    return -2;
}
//POST=(se A contiene la sottosequenza n ed essa inizia in A[i], allora S restituisce i,
//altrimenti S restituisce -2)

/**
 * Funzione S
 * int i è il contatore del ciclo while che va da 0 a dimA-1, cioè l'ultima posizione contenente -2;
 * int sottosequenzaI è l'indice della sottosequenza che attualmente si sta analizzando.
 * 
 * R=
 * Condizione Iniziale:  i==0 && A[i]!=-2 && sottosequenzaI == 0;
 *      contatore i sarà a zero, e si presuppone che la sottosequenza sia la 0; nel caso non esista non si entra nel ciclo dato che la
 *      condizione di permanenza implica che esista almeno la sottosequenza 0;
 * Condizione Intermedia: A[i]!=-2 && sottosequenzaI<n && 0<=i<"dimA"
 *      se si è nella condizione intermedia significa che il contatore i è tra 0 e "dimA";
 *      e che la sottosequenzaI è ancora < rispetto alla sottosequenza n cercata;
 *      Inoltre se si è ancora all'interno del ciclo significa che non si è trovata la sentinella finale;
 *      quindi significa che i non ha ancor trovato il massimo dimA, trovando la sentinella -2;
 * Condizione Finale: A[i]==-2 || sottosequenzaI==n
 *      La condizione finale si divide in due parti; 
 *      la prima è il caso in cui non si sia riusciti a trovare la sottosequenza n richeista all'interno
 *      del array A, questo significa che si è raggiunto il limite di A "dimA" quindi A[i] == -2;
 *      La seconda è invece il caso in cui si è riusciti a trovare la sottosequenza di A == n, il ciclo termina all'istante
 *      dando come return l'indice della prima posizione della sottosequenza quindi se sottosequenzaI==n;
 * 
 * Spiegazione Funzione:
 * Avendo presente la condizione Inizialead ogni iterazione si controlla inizialmente se
 * la sottosequenza esaminata coincide con la sottosequenza richiesta;
 * Tenendo in considerazione che se si è all'interno del ciclo significa che almeno la sequenza che stiamo analizzando
 * è la numero 0, allora ad ogni iterazione si può già controllare se corrisponde alla sottosequenza richiesta
 * e nel caso, returnare l'indice del primo elemento, il quale è proprio quello su cui la iterazione è.
 * Successivamente si verifica se alla posizione i del array A si incontra -1, quindi si verifica se
 * si è raggiunta la fine della sottosequenza, incrementando così di 1 sottosequenzaI;
 * Viene incrementato infine i di 1, in maniera da esaminare la posizione successiva del array.
 * 
 * Alla successiva iterazione il processo viene ripetuto, avendo questa volta i+1 e se la scorsa iterazione si incontrava
 * la sentinella di fine sottosequenza, avremmo sottosequenza+1;
 * facendo gli stessi passaggi di prima verifichiamo se la sottosequenza è quella richiesta,
 * e se l'indice del array i attuale corrisponde ad una posizione contenente -1;
 * 
 * Sono consapevole che il controllo if(sottosequenzaI==n) è ridondante dato che a molte iterazioni potrà capitare di avere la stessa sottosequenza
 * ma occorre comunque fare il controllo sempre, dato che facendolo sempre, di sicuro lo si farà a inizio sottosequenza, quindi si avrà a disposizione
 * il primo indice della sottosequenza;
 * In alternativa lo si potrebbe fare solo alla fine della sottosequenza ma richeiderebbe un algoritmo diverso, con la
 * memorizzazione temporanea del indice della prima posizione della sottosequenza;
 * 
 * Esempio
 * Avendo 1 -1 -1 -2 con n==1
 * Alla prima iterazione
 *      i==0    A[i]==1   sottosequenzaI==0   
 *          poi
 *      sottosequenzaI!=n  A[i]!=-1
 * Alla seconda iterazione
 *      i==1    A[i]==-1   sottosequenzaI==0   
 *          poi
 *      sottosequenzaI!=n   e   A[i]==-1 quindi sottosequenzaI==1
 * Alla terza iterazione
 *      i==2    A[i]==-1   sottosequenzaI==1
 *          poi
 *      sottosequenzaI==n   quindi return i
 * 
 * 2 è il primo indice della 1 sottosequenza
 */

