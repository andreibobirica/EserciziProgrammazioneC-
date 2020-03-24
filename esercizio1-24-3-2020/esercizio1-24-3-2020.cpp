#include<iostream>
using namespace std;

void toStringA(int[][4][5]);
void scriviA(int[][4][5]);
void stampaH(int X[][4][5], int strati, int fetta);
void stampaV(int X[][4][5], int strati, int fetta);

main()
{
    int A[3][4][5];
    //definisco l'array A
    scriviA(A);
    //toStringA(A);
    cout<<"start"<<endl;
    //Leggo operazione
    char c;
    int f;
    cin >> c >> f;
    if(c=='H')
        stampaH(A,3,f);
    else
        stampaV(A,3,f);
    cout<<"end"<<endl;
}

//PRE=(X contiene strati*4*5 valori e 0<=fetta <4)
void stampaH(int X[][4][5], int strati, int fetta){
    //cout << strati << fetta << endl;
    for(int i=0;i<strati;i++){
        for(int e=0;e<5;e++){
            cout << X[i][fetta][e]<<" ";
        }//R2
        cout<<endl;
    }//R1
    /**
     *  R1=
     *  -Condizione Iniziale: i=0;strati è definito e fisso.
     *  -Condizione intermedia: 0<= i < strati.
     *  -Condizione Finale: i==strati, si esce dal ciclo
     *  Questo ciclo serve a scrollare tutti gli strati del Array X stratix4x5.
     *  A ogni iterazione viene incrementato l'intero i, indice dello strato del Array X,
     *  e viene eseguito il corpo, tra cui un'altro ciclo intermedio che stampa i dati, e una
     *  stampa cout con terminatore di riga endl, per formattare bene i dati stampati, andando
     *  a capo per ogni fetta corrispondente allo strato.
     * 
     * R2=
     * -Condizione Iniziale: e=0;
     * -Condizione intermedia: 0<= e < 4.
     * -Condizione Finale: e==4, si esce dal ciclo
     * Questo ciclo serve a scrollare tutti gli elementi della fetta "fetta", in particolare:
     * Avendo fisso (in questo contesto) i cioè strato corrispondente e fetta, cioè la fetta corrispondente,
     * Viene quindi stampato ogni valore della fettaH cioè la riga del Array [4][5].
     */
}
//POST=(stampa la H-fetta fetta)

//PRE=(X contiene strati*4*5 valori e 0<= fetta < 5)
void stampaV(int X[][4][5], int strati, int fetta){
    //cout << strati << fetta << endl;
    for(int i=0;i<strati;i++){
        for(int e=0;e<4;e++){
            cout << X[i][e][fetta]<<" ";
        }//R2
        cout<<endl;
    }//R1
    /**
     *  R1=
     *  -Condizione Iniziale: i=0;strati è definito e fisso.
     *  -Condizione intermedia: 0<= i < strati.
     *  -Condizione Finale: i==strati, si esce dal ciclo
     *  Questo ciclo serve a scrollare tutti gli strati del Array X stratix4x5.
     *  A ogni iterazione viene incrementato l'intero i, indice dello strato del Array X,
     *  e viene eseguito il corpo, tra cui un'altro ciclo intermedio che stampa i dati, e una
     *  stampa cout con terminatore di riga endl, per formattare bene i dati stampati, andando
     *  a capo per ogni fetta corrispondente allo strato.
     * 
     * R2=
     * -Condizione Iniziale: e=0;
     * -Condizione intermedia: 0<= e < 4.
     * -Condizione Finale: e==4, si esce dal ciclo
     * Questo ciclo serve a scrollare tutti gli elementi della fetta "fetta", in particolare:
     * Avendo fisso (in questo contesto) i cioè strato corrispondente e fetta, cioè la fetta corrispondente,
     * Viene quindi stampato ogni valore della fettaV cioè la colonna del Array [4][5].
     */
}
//POST=(stampa la V-fetta fetta)


//PRE=L'array A 3x4x5 contiene per tutte le sue posizioni valori interi
void toStringA(int A[][4][5]){
    for(int i=0; i<3; i=i+1){
        for(int j=0; j<4; j=j+1){
            for(int k=0; k<5; k=k+1){
                cout << A[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << "________________________________________" << endl;
    }
}
//POST=tutti i valori delle posizioni del Array A 3x4x5 vengono stampati a schermo.

//PRE= la matrice 3x4x5 è vuoto e non contiene nessun valore in nessuna sua posizione.
void scriviA(int A[][4][5]){
    int *q=**A;
    for(int i=0; i<3*4*5; i=i+1)
        cin >> q[i];
}
//POST=La matrice A 3x4x5 contiene 60 valori immessi in ordine per riga da cin, standard input.