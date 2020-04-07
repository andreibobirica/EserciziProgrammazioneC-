#include<iostream>
using namespace std;
/**
 * Struttura orario, contenente int ore, minuti, secondi
 * Il formato è HH MM SS ma per 00 si intende il valore 0
 */
struct orario{
    int ore,minuti,secondi;
    orario(int a=0, int b=0, int c=0){
        ore=a; minuti=b;secondi=c;
    }
};

/**
 * Struttura rileva, contenitore di
 * ril: id rilevamento
 * corr: id corridore
 * time: tempo del rilevamento
 */ 
struct rileva{
    int ril, corr; orario time;
    rileva(int a=-1, int b=-1, orario c=orario()){
        ril=a; corr=b; time=c;
    }
};

/**
 * Definizione di operandi su orario e rileva
 */
istream & operator>>(istream & s, orario & x){s >> x.ore >> x.minuti >> x.secondi;}
ostream & operator<<(ostream & s, orario & x){s << x.ore << " | " << x.minuti << " | " << x.secondi;}
istream & operator>>(istream & s, rileva & x){s >> x.ril >> x.corr >> x.time;}
ostream & operator<<(ostream & s, rileva & x){s << x.ril << " | " << x.corr << " | " << x.time;}

//Funzioni
bool verificaSalto(rileva x);
bool verificaTempo(rileva x, rileva y,rileva z);


main(){
    //Leggo il numero di corridori
    int ncorr;
    cin >> ncorr;
    //definisco un orario z per la gara, totalmente INUTILMENTE
    orario z;
    cin >> z;
    
    /**
     * Definisco un array di rileva, detto rilevamenti
     * Al suo interno i rilevamenti saranno in ordine di sensore, e in ordine di corridore
     */
    rileva rilevamenti[ncorr*3];
    for(int i=0;i<ncorr*3;i++)
        rilevamenti[i] = rileva(-1,-1,orario());
        //Inizializzo array con valori predefiniti
        //Se il rilevamento sarà -1 significa che il corridore l'ha saltato
    int w;//Sentinella finale oppure (id rilevamento e indice del array dei rilevamenti)
    orario newOrario;//Orario di ogni rilevamento
    int idPart;//id Partecipante di ogni rilevamento
    cin >> w;
    while(w != -1){//R
        cin >> idPart;//leggo idPart aka idCorridore
        cin >> newOrario;//leggo un nuovo orario per il rilevamento
        rilevamenti[idPart*3+w] = rileva(w,idPart,newOrario);//registro il rilevamento
        //idPart*3+w corrisponde al indice del elemento rileva in ordine nel array, come voluto
        cin >> w;//leggo per la prossima, possibile, iterazione w detto sentinella finale oppure id rilevamento
    }
    
    //Controllo sui valori letti

    //Inizialmente do per scontato che tutti i rilevamenti siano regolari
    bool regolare=true;
    for(int i=0;i<ncorr*3;i++){//R2=Leggo tutti i valori ri rilevamenti, cioò tutti i rilevamenti
        //Verifico se il rilevamento è stato saltato
        if(verificaSalto(rilevamenti[i])){
            cout << i/3 << ": salto sensore" << endl;
            regolare=false;
        }

        //Verifico se i tempi sono normali
        //il rilevamento del tempo, richiamando la funzione rilevaTempo, lo faccio solamente una volta arrivato 
        //alla fine , al 2 sensore da analizzare;
        //Lo faccio solamente se non ci sono anomalie, e cioè se l'unico sesore che può essere saltato, NON è stato saltato
        if(rilevamenti[i].ril==2 && !verificaSalto(rilevamenti[i-1])){
            //Verifico il tempo, e se Non è CONFORME, stampo un messaggio di errore
            if(!verificaTempo(rilevamenti[i-2],rilevamenti[i-1],rilevamenti[i])){
                cout << i/3 << ": tempo sospetto" << endl;
                regolare=false;
            }
        }
    }

    //Nel caso precedentemente si è trovato un errore , lo si fa presente
    if(regolare)
        cout << "gara regolare" << endl;
}

/**
 * Funzione che verifica su un dato rileva dato da parametro se esso è stato saltato o no,
 * per definizione un rileva se è stato saltato ha al suo interno valori di identificazione -1
 * nel caso sia così , il sensore è stato saltato
 * TRUE il sensore è stato saltato
 * False il sensore non è stato saltato
 */
bool verificaSalto(rileva x){
    return x.ril==-1;
}

/**
 * La funzione verifica tempo, verifica la validità del tempo in base a un percorso diviso in due
 * segmenti di lunghezza diversa;
 * ha da parametro 3 rileva;
 * la prima verifica la si fa tra x e z
 * la seconda verifica la si fa tra x e y
 * la terza verifica la sifa tra y e z
 * se il delta T misurato è minore del tempo minimo richiesto, allora si ha un tempo sospetto
 * TRUE il tempo è normale
 * FALSE il tempo è sospetto
 */
bool verificaTempo(rileva x,rileva y, rileva z){
    //cout << x.corr <<endl;
    //Calcolo deltaT tra x e z
    double distanzaPercorso = 21.975;
    double xt = (x.time.ore*60*60) + (x.time.minuti*60) + (x.time.secondi); 
    double yt;
    double zt = (z.time.ore*60*60) + (z.time.minuti*60) + (z.time.secondi);
    double deltaT = zt - xt;
    //cout << deltaT/distanzaPercorso<<endl;
    bool regolare = deltaT/distanzaPercorso > (2*60 + 45);
    //calcolo percorsi intermedi
    if(regolare){
        distanzaPercorso = 11;
        xt = (x.time.ore*60*60) + (x.time.minuti*60) + (x.time.secondi);  
        yt = (y.time.ore*60*60) + (y.time.minuti*60) + (y.time.secondi);
        deltaT = yt - xt;
        //cout << deltaT/distanzaPercorso<<endl;
        regolare = deltaT/distanzaPercorso > (2*60 + 45);
    }
    if(regolare){
        distanzaPercorso = 10.975;
        yt = (y.time.ore*60*60) + (y.time.minuti*60) + (y.time.secondi);  
        zt = (z.time.ore*60*60) + (z.time.minuti*60) + (z.time.secondi);
        deltaT = zt - yt;
        //cout << deltaT/distanzaPercorso<<endl;
        regolare = deltaT/distanzaPercorso > (2*60 + 45);
    }
    return regolare;
}
