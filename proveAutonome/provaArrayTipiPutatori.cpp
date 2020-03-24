#include<iostream>
using namespace std;

const int in=7,en=3,jn=5;

void esplora(double A[][en][jn]){
    cout << A << " | " << *A << " | " << **A << " | " <<  ***A<<endl;
    //0x7ffffffedc10 | 0x7ffffffedc10 | 0x7ffffffedc10 | 0
    cout << typeid(A).name() << " | " << typeid(*A).name() << " | " << typeid(**A).name() << " | " <<  typeid(***A).name()<<endl;
    //PA3_A5_d | A3_A5_d | A5_d | d

    //Value
    cout << ***A << "\t | ";
    cout << **A[0] <<endl;
    //0        | 0
    cout << ***(A+1) << "\t | ";
    cout << **(A+1)[0] <<endl;
    //15       | 15
    cout << **((*A)+1) << "\t | ";
    cout << *((*A)+1)[0] <<endl;
    //5        | 5
    cout << *((**A)+1) << "\t | ";
    cout << ((**A)+1)[0] <<endl;
    //1        | 1

    double(*q1)[en][jn] = A;    q1=A;
    double(*q2)[jn] = A[0];     q2=(*A);
    double *q3 = A[0][0];       q3=(**A);
    cout << "\t" << q1 << "\t" << q2 << "\t" << q3 <<endl;
    //0x7ffffffedc10  0x7ffffffedc10  0x7ffffffedc10

    //sizeof
    cout << sizeof(double) <<endl;  //8
    cout << sizeof(q1) <<endl;      //8
    cout << sizeof(q2) <<endl;      //8
    cout << sizeof(q3) <<endl;      //8
    cout << sizeof(*q3) <<endl;     //8
    //sizeof REAL A
    cout << sizeof(double)*in*en*jn <<endl;
    
}


main()
{
    cout << "create"<<endl;
    int cont = 0;
    double A[in][en][jn];
    for(int i=0;i<in;i++)
        for(int e=0;e<en;e++)
            for(int j=0;j<jn;j++)
                A[i][e][j] = cont++;


    for(int i=0;i<in;i++){
        for(int e=0;e<en;e++){
            for(int j=0;j<jn;j++){
                cout << A[i][e][j] << "\t";
            }
            cout << endl;
        }
        cout <<"__"<<endl;
    } 

    cout << "esplora\n"<<endl;      
                
    esplora(A);
}