#include "matrix.c"

int main(){
    Matrix m;
    int n;

    scanf("%d", &n);
    readMatrix(&m, n, n);
    RotateMat(&m);
    printf("\n");
    displayMatrix(m);
}