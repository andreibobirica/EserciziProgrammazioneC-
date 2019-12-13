#include<iostream>
using namespace std;
main()
{
    cout<<"start"<<endl;
    int p1 = 0,p2 = 0; //Punteggi
    int n = -1;
    cin >> n;
    if(n>0){
        //Lettura dei valori nelle coppie
        char coppie[n][2];
        for (size_t i = 0; i < n; i++)
        {
            cin >> coppie[i][0];
            cin >> coppie[i][1];
        }
        //Gioco
        for (size_t i = 0; i < n; i++)
        {
            char g1 = coppie[i][0]; //Mossa giocatore 1
            char g2 = coppie[i][1]; //Mossa giocatore 2
            bool v1 = false,v2 = false; //Vincita
            if((g1 == 'f' || g1 == 'c' || g1 == 's') && (g2 == 'f' || g2 == 'c' || g2 == 's')){
                switch (g1){
                    case 'f':
                        if(g2=='f'){
                            v1 = true;
                            v2 = true;
                        }else{
                            if(g2=='c')
                                v1 = true;
                            else
                                v2 = true;
                        }
                    break;
                    case 'c':
                        if(g2=='c'){
                            v1 = true;
                            v2 = true;
                        }else{
                            if(g2=='s')
                                v1 = true;
                            else
                                v2 = true;
                        }
                    break;
                    case 's':
                        if(g2=='s'){
                            v1 = true;
                            v2 = true;
                        }else{
                            if(g2=='f')
                                v1 = true;
                            else
                                v2 = true;
                        }
                    break;
                }
                //Verifica Vincita
                if(v1 && v2){}else{
                    if(v1)
                    p1++;
                    else if(v2)
                    p2++;
                }
            }
            else{
                cout << "mossa non valida" << endl;
                p1 = p2 = -1;
                break;
            }
        }

        //Verifica vincita
        if(p1 != -1 && p2 != -1){
            if(p1==p2){
                cout << "Pareggio" << endl;
            }else{
                if(p1 > p2)
                cout << "Vince il Giocatore 1" << endl;
                else
                cout << "Vince il Giocatore 2" << endl;
            }
        }        
    }

    cout<< "end"<<endl;
}