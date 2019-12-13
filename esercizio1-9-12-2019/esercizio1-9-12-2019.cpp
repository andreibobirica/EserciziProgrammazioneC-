#include<iostream>
using namespace std;
main()
{
    cout << "start"<<endl;
    char g1 = ' ';
    char g2 = ' ';
    bool v1 = false,v2 = false;
    cin >> g1;
    cin >> g2;

    //Controllo sulle mosse dei Giocatori
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
        if(v1 && v2)
            cout << "pareggio" << endl;
        else if(v1)
            cout << "vince il giocatore 1" << endl;
        else if(v2)
            cout << "vince il giocatore 2" << endl;
    }
    else{
        cout << "mossa non valida" << endl;
    }
   
    
    cout << "end" << endl;
}