#include<iostream>
using namespace std;
void leggi(int X[],int m);
int trovaporz(int Y[], int q);
//void arrayToString(int A[], int n);
main()
{
    int A[100];
    int n;
    cin >> n;
    leggi(A,n);
    //arrayToString(A, n); 
    int k = trovaporz(A,n); 
    cout << "k=" << k;
    
    
}
void leggi(int X[], int m){
    for (size_t i = 0; i < m; i++){
        cin >> X[i];
    }
}

int trovaporz(int Y[], int q){
    int k = 1;
    int prec = Y[0];
    if(q > 1){
        for (size_t i = 1; i < q; i++){
            if(prec < Y[i]){
                k++;
            }
            else{
                break;
            }
        }
    }
    return k;   
}
