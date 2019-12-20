#include<iostream>
#include <vector>
using namespace std;
main()
{
    vector<char> aperte;
    char inp;
    int bill = 0;
    string ret = "";
    do
    {
        cin >> inp;
        switch (inp){
        case '(':
        case '[':
        case '{':
            bill++;
            aperte.push_back(inp);
            break;
        case ')':
        case '}':
        case ']':
            bill--;
            if(aperte.size()!=0){
                char ultima = aperte.back();
                if((ultima == '(' && inp == ')')||(ultima == '[' && inp == ']')||(ultima == '{' && inp == '}')){
                    aperte.pop_back();
                }else{
                    inp='0';
                    ret = "Parentesi accavallate";
                } 
            }else{
                inp='0';
            }
        }
    }while (inp != '0' && bill >= 0);

    if(ret==""){
        if(bill>0){
            ret = "Troppe parentesi aperte";
        }else if(bill<0){
            ret = "Troppe parentesi chiuse";
        }else if(bill == 0){
            ret = "Sequenza bilanciata";
        }
    }
    //return output
    cout << ret;
}
