#include<iostream>
using namespace std;
main()
{
    cout << "start"<<endl; 
    //Variabile bilanciamento, se > 0  + parentesi aperta, se < 0 + parentesi chiusa, se 0 bilanciato
    int bil = 0;
    char c = ' ';
    while (c!='0' && bil >= 0)
    {
        cin >> c;
        switch (c)
        {
        case '(':
            bil++;
            break;
        case ')':
            bil--;
            break;
        default:
            break;
        }
    }
    if(bil==0){
        cout << "la sequenza e' bilanciata" << endl;
    }else{
        if(bil>0){
            cout << "la sequenza non e' bilanciata: ci sono parentesi aperte senza match" << endl;
        }else{
            cout << "la sequenza non e' bilanciata: ci sono parentesi chiuse senza match" << endl;
        }
    }
    

    cout << "end"<<endl; 
}