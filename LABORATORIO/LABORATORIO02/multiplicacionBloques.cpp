#include<iostream>
#include <chrono>
using namespace std;

// multiplication of two matrices by blocks
void multiplicacionPorBLoques(double **A, double **B, double **C, int length, int stride){
    for(int ii = 0; ii < length; ii += stride){
        for(int jj = 0; jj < length; jj += stride){
            for(int kk = 0; kk < length; kk += stride){
                for(int i = ii; i< ii + stride; ++i){
                    for(int j = jj; j < jj + stride; ++j){
                        for(int k = kk; k < kk + stride; ++k){
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }               
            }
        }
    }
}

void multiplicacion(int length){
    const int MAX = length;
    int i, j;

    double **A, **B, **C;
    A = new double*[MAX];
    B = new double*[MAX];
    C = new double*[MAX];

    for (i = 0; i < MAX; i++){
        A[i] = new double[MAX];
        B[i] = new double[MAX];
        C[i] = new double[MAX];
        for (j = 0; j < MAX; j++){
            A[i][j] = rand() % 200;
            B[i][j] = rand() % 200;
        }
    }
    


    auto begin = chrono::high_resolution_clock::now();
    multiplicacionPorBLoques(A, B, C, MAX, 4);
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