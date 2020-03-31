#include<iostream>
using namespace std;

int& TV(int*p, int lim1,int lim2, int lim3, int f, int n_ele, int n,bool & ok);
int& TH(int*p, int lim1,int lim2, int lim3, int f, int n_ele, int n,bool & ok);

void stampa(int*X, int n_ele, int colonne)
{   
    int nr=n_ele/colonne, resto=n_ele%colonne;
    for(int i=0; i<nr; i++)
    {
        for(int j=0; j<colonne; j++)
            cout<< X[i*colonne+j]<<' ';
            cout<<endl;
        }
        for(int i=0; i< resto; i++)
            cout<< X[nr*colonne+i]<<' ';
        cout<< endl;
    }

main()
{
    int X[100],lim1,lim2,lim3,n_ele;
    cin >>lim1 >> lim2 >> lim3 >> n_ele;
    for(int i=0; i<n_ele;i++)
        cin >> X[i];
    bool stop=false, b1=true,b2=true;
    while (!stop)//R
    {
        int fV,nV, fH,nH;
        cin >> fV ;
        if(fV==-1)
        stop=true;
        else
        {
            cin >> nV >> fH >> nH;
            int &y=TV(X,lim1,lim2,lim3,n_ele, fV, nV, b1);
            int &z=TH(X,lim1,lim2,lim3,n_ele, fH, nH, b2);
            if(b1 && b2 )
            {
                int app = y;
                y=z;
                z=app;
            }
            else
                cout<<"operazione non consentita"<<endl;
	    }
    }
    stampa(X, n_ele, lim3);
}
/**
 * X è un array di 100 posizioni definito sulle prime n_ele posizioni con numeri interi
 * lim1,lim2,lim3 sono definiti e > 0, indicano rispettivamente strati, righe e colonne del come leggere X
 * stop è una variabile booleana che serve per stoppare nel caso l'input di fv venga inserito come -1, si esce dal ciclo principale
 * b1 e b2 sono due variabili booleane che indicano il risultato del calcolo rispettivamente di tv e th
 * 
 * R=
 * Condizione iniziale: stop==false => (fV!=-1)
 * Condizione intermedia: stop==false => (fV!=-1)
 * Condizione finale: stop==true => (fV==-1)
 * 
 * Ad ogni iterazione viene letta la quadrupla fV,nV, fH,nH;
 * Si verifica il caso in cui (fV==-1) e nel caso true si setta stop == true, quindi si dovrà uscire dal ciclo
 * Si continua leggendo gli altri parametri della quadrupla;
 * vengono invocate TV e TH, che oltre a restituire corrispettivamente i loro valori trovati in y e z, modificano il valore dei corrispettivi valori 
 * booleani immessi a parametro, cioè b1 e b2;
 * se b1 && b2 == TRUE
 *      vengono scambiati y e z
 * se b1 && b2 == FALSE
 *      viene stampato un messaggio di errore.
 * il valore di b1,b2, e l'esecuzione di tv e th non influisce sul ciclo.
 * Influisce solo sulla possibilità o meno di scambiare tra di loro y e z;
 * 
 */

//PRE=(p punta al primo elemento di X e gli altri parametri sono ben definiti)
int& TV(int*p, int lim1,int lim2, int lim3, int n_ele,int f, int n,bool & ok){
    ok= f<=(n_ele-1)%lim3 && n<=(n_ele-1)/lim3;
    return *(p+n*lim3+f);
}
//POST=(ok=true sse l’elemento n della V-fetta di indice f esiste ed è definito) &&(se ok=true allora la
//funzione restituisce questo elemento per riferimento)

//PRE=(p punta al primo elemento di X e gli altri parametri sono ben definiti)
int& TH(int*p, int lim1,int lim2, int lim3, int n_ele,int f, int n,bool & ok){
    ok = f*lim3 + (n/lim3)*lim2*lim3 + n%lim3 < n_ele;
    return *(p+f*lim3+(n/lim3)*lim2*lim3 + n%lim3);
}
//POST=(ok=true sse l’elemento n della H-fetta di indice f esiste ed è definito) &&(se ok=true allora la
//funzione restituisce questo elemento per riferimento)
