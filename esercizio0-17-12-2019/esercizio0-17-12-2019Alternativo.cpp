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
    int kSave = k;
    int prec = Y[0];
    if(q > 1){
        for (size_t i = 1; i < q; i++){
            if(prec < Y[i]){
                k++;
            }
            else{
                if(kSave < k)
                    kSave = k;
                k = 1;
            }
            prec = Y[i];
            
            if(i==q-1 && kSave < k){
                kSave = k;
            }
        }
    }
    return kSave;   
}
/*
void arrayToString(int A[], int n){
    //int size = sizeof(A) / sizeof(int); 
    //cout << size << endl;
    for (size_t i = 0; i < n; i++)
    {
        cout << "n." << i << ") " << A[i] << endl;
    }
}
*/