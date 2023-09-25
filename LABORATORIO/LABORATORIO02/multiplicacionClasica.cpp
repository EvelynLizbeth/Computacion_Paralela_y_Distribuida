#include<iostream>
#include <chrono>
using namespace std;


void multiplicacionClasica(double **A, double **B, double **C, int length){
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            for (int k = 0; k < length; k++)
                C[i][j] += A[i][k] * B[k][j];
}

void multiplicacion(int length){
    const int MAX = length;
    int i, j;

    double **A, **B, **C;
    A = new double*[MAX];
    B = new double*[MAX];
    C = new double*[MAX];

    for (i = 0; i < MAX; i++)
    {
        A[i] = new double[MAX];
        B[i] = new double[MAX];
        C[i] = new double[MAX];
        for (j = 0; j < MAX; j++)
        {
            A[i][j] = rand() % 200;
            B[i][j] = rand() % 200;
        }
    }
    


    auto begin = chrono::high_resolution_clock::now();
    multiplicacionClasica(A, B, C, MAX);
    auto end = chrono::high_resolution_clock::now();
    
    cout << "\t\t,\t" <<chrono::duration_cast<chrono::microseconds>(end - begin).count() << endl;

    for (i = 0; i < MAX; i++){
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}




int main(){
    cout << "Matriz(length)" <<  "\t\t" << "Tiempo( microsegundos )" <<endl;
    for (int i = 100; i <= 2000; i += 100){
        cout<<i;
        multiplicacion(i);
    }
        
    return 0;
}