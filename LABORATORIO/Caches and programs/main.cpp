#include <iostream>
using namespace std;
#include <chrono>
int MAX = 1000; 

void loops(){
    int i, j;
    // double A[MAX][MAX], x[MAX], y[MAX];
    double **A, *x, *y;
    A = new double*[MAX];
    x = new double[MAX];
    y = new double[MAX];
    
    // Initialize A and x, assign y = 0 
    for (i = 0; i < MAX; i++){
        A[i] = new double[MAX];
        for (j = 0; j < MAX; j++){
            A[i][j] = rand() % 1000;
        }
    }

    for (i = 0; i < MAX; i++)   x[i] = rand() % 1000;
    for (i = 0; i < MAX; i++)   y[i] = 0;

    // First pair of loops 
    auto begin = chrono::high_resolution_clock::now();
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            y[i] += A[i][j]*x[j];
    auto end = chrono::high_resolution_clock::now();

    cout << "Time(First pair of loops): " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " microseconds" << endl;
    
    //*************************
    //Assign y = 0
    for (i = 0; i < MAX; i++)   y[i] = 0;
    //Second pair of loops
    begin = chrono::high_resolution_clock::now();
    for (j = 0; j < MAX; j++)
        for (i = 0; i < MAX; i++)
            y[i] += A[i][j]*x[j];
    end = chrono::high_resolution_clock::now();

    cout << "Time(Second pair of loops): " << chrono::duration_cast<chrono::microseconds>(end - begin).count() << " microseconds" << endl;

    //*************************

    for (i = 0; i < MAX; i++)
        delete[] A[i];
    delete[] A;
    delete[] x;
    delete[] y;
}

int main(){
    loops();
    return 0;
}