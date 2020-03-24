#include<iostream>
using namespace std;

void toStringA(int[][4][5],int n_ele);
void scriviA(int[][4][5]);
void stampaH(int X[][4][5], int n_ele, int fetta);
void stampaV(int X[][4][5], int n_ele, int fetta);

main()
{
    cout<<"start"<<endl;
    //Creazione A
    int A[3][4][5], *p=A[0][0], n_ele;
    cin>>n_ele;
    for(int i=0; i<n_ele; i=i+1)
        cin>>p[i];
    //toStringA(A,n_ele);
    //StampaFetta
    char c;
    int f;
    cin >> c >> f;
    
    if(c=='H')
        stampaH(A,n_ele,f);
    else
        stampaV(A,n_ele,f);
    
    cout<<"end"<<endl;
}
////PRE=(X contiene 3*4*5 valori di cui i primi n_ele sono interi, gli altri sono indefiniti, e 0<= fetta < 4)
void stampaH(int X[][4][5], int n_ele, int fetta){
    //Calcolo stratoMax contenente valori
    int stratoMax = -1, temp = n_ele;
    for(int i=0;i<3 && temp>0;i++){
        temp=temp-20;
        stratoMax++;
    }
    //Variabile empty, di base si presuppone che la fetta sia vuota
    bool empty=true;
    //Trovo Fette esistenti
    for(int i=0;i<=stratoMax;i++){
        //Puntatore all'inizio dell'array
        int *q= **X;
        //Calcolo primo elemento della fetta;
        int primoI = 5*4*i + fetta*5;
        //Calcolo ultimo elemento della fetta;
        int ultimoI = 5*4*i + fetta*5 + n_ele%5;
        //cout << "q " << *q << "primI " << primoI << " ultI " << ultimoI << " n_ele " << n_ele <<endl;
        if(primoI<=n_ele){
            empty=false;
            //Stampo gli elementi della fetta
            for(int e=primoI;e<=ultimoI;e++)
                cout <<q[e]<<" ";
            cout <<endl;
        }
    }//R1
    if(empty)
    cout << "fetta richiesta vuota" <<endl;
    
}
//POST=(stampa la H-fetta fetta se ha almeno un valore intero, se tutti i valori sono indefiniti
//stampa: "fetta richiesta vuota")

////PRE=(X contiene 3*4*5 valori di cui i primi n_ele sono interi, gli altri sono indefiniti, e 0<= fetta < 5)
void stampaV(int X[][4][5], int n_ele, int fetta){
    //Calcolo stratoMax contenente valori
    int stratoMax = -1, temp = n_ele;
    for(int i=0;i<3 && temp>0;i++){
        temp=temp-20;
        stratoMax++;
    }
    //Variabile empty, di base si presuppone che la fetta sia vuota
    bool empty=true;
    //Trovo Fette esistenti
    //Puntatore all'inizio dell'array
    int *q= **X;
    //Calcolo ultimo elemento della fetta;
    int ultimoI = fetta;
    if(n_ele>4)ultimoI+= ((n_ele/5)-1)*5;
    for(int i=0;i<=stratoMax;i++){
        //Calcolo primo elemento della fetta;
        int primoI = 5*4*i + fetta;
        //cout << "q " << *q << "primI " << primoI << " ultI " << ultimoI << " n_ele " << n_ele <<endl;
        if(primoI<=n_ele-1){
            empty=false;
            //Stampo gli elementi della fetta
            for(int e=primoI,n=0;n<4 && e<=ultimoI;e=e+5,n++)//R2
                cout <<q[e]<<" ";
            cout <<endl;
        }
    }//R1
    if(empty)
    cout << "fetta richiesta vuota" <<endl;
}
//POST=(stampa la V-fetta fetta se ha almeno un valore intero, se tutti i valori sono indefiniti
//stampa: "fetta richiesta vuota")

//PRE=L'array A 3x4x5 contiene per tutte le sue posizioni valori interi
void toStringA(int A[][4][5],int n_ele){
    int contNEle = 0;
    for(int i=0; i<3; i=i+1){
        for(int j=0; j<4; j=j+1){
            for(int k=0; k<5; k=k+1){
                if(contNEle<n_ele)
                    cout << A[i][j][k] << "\t";
                else
                    cout << "[]\t";
                contNEle++;
            }
            cout << endl;
        }
        cout << "________________________________________" << endl;
    }
}
//POST=tutti i valori delle posizioni del Array A 3x4x5 vengono stampati a schermo.

