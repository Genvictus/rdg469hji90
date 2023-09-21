// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 21 September 2022
// Topik: ADT Matrix
// Deskripsi: Pra-praktikum matrix.c

/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include <stdio.h>
#include "boolean.h"
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
    return (0 <= i && i < ROW_CAP) && (0 <= j && j < COL_CAP);
	
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return COL_EFF(m)-1;
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (0 <= i && i <= getLastIdxRow(m)) && (0 <= j && j <= getLastIdxCol(m));
}

ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return ELMT(m, i, i);
}


/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */

	/* KAMUS LOKAL */
	int i, j;

	/* ALGORITMA */
	createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for(i=0; i <= getLastIdxRow(mIn); i++){
        for(j=0; j <= getLastIdxCol(mIn); j++){
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}


/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */

	/* KAMUS LOKAL */
    int i, j;
	
	/* ALGORITMA */
	createMatrix(nRow, nCol, m);
    for(i=0; i <= getLastIdxRow(*m); i++){
        for(j=0; j <= getLastIdxCol(*m); j++){
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

	/* KAMUS LOKAL */
    int i, j;
	
	/* ALGORITMA */
	for(i=0; i <= getLastIdxRow(m); i++){
        for(j=0; j < getLastIdxCol(m); j++){
            printf("%d ", ELMT(m, i, j));
        }
        printf("%d", ELMT(m, i, getLastIdxCol(m)));
        if(i <= getLastIdxRow(m))
            printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */

	/* KAMUS LOKAL */
    Matrix mRes;
    int i, j;
	
	/* ALGORITMA */
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mRes);
	for(i=0; i <= getLastIdxRow(mRes); i++){
        for(j=0; j <= getLastIdxCol(mRes); j++){
            ELMT(mRes, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return mRes;
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */

	/* KAMUS LOKAL */
    Matrix mRes;
    int i, j;
	
	/* ALGORITMA */
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &mRes);
	for(i=0; i <= getLastIdxRow(mRes); i++){
        for(j=0; j <= getLastIdxCol(mRes); j++){
            ELMT(mRes, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return mRes;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */

	/* KAMUS LOKAL */
    Matrix mRes;
    int i, j, k;
	
	/* ALGORITMA */
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &mRes);
	for(i=0; i <= getLastIdxRow(mRes); i++){
        for(j=0; j <= getLastIdxCol(mRes); j++){
            ELMT(mRes, i, j) = 0;
            for (k=0; k <= getLastIdxCol(m1); k++){
                ELMT(mRes, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return mRes;
}

Matrix multiplyByConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */

	/* KAMUS LOKAL */
    int i, j;
	
	/* ALGORITMA */
	for(i=0; i <= getLastIdxRow(m); i++){
        for(j=0; j <= getLastIdxCol(m); j++){
            ELMT(m, i, j) *= x;
        }
    }
    return m;
}

void pMultiplyByConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

	/* KAMUS LOKAL */
    int i, j;
	
	/* ALGORITMA */
	for(i=0; i <= getLastIdxRow(*m); i++){
        for(j=0; j <= getLastIdxCol(*m); j++){
            ELMT(*m, i, j) *= k;
        }
    }
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */

	/* KAMUS LOKAL */
    boolean eq;
    int i, j;
	
	/* ALGORITMA */
    eq = isMatrixSizeEqual(m1, m2);
	if(eq){
        for(i=0; i <= getLastIdxRow(m1); i++){
            for(j=0; j <= getLastIdxCol(m1); j++){
                eq = ELMT(m1, i, j) == ELMT(m2, i, j);
                if(!eq)
                    break;
            }
            if(!eq)
                break;
        }
    }
    return eq;
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return !isMatrixEqual(m1, m2);
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (ROW_EFF(m1) == ROW_EFF(m2)) && (COL_EFF(m1) == COL_EFF(m2));
}


/* ********** Operasi lain ********** */
int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return ROW_EFF(m)*COL_EFF(m);
}


/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */

	/* KAMUS LOKAL */
    boolean sym;
    int i, j;
	
	/* ALGORITMA */
    sym = isSquare(m);
    if(sym){
        for(i=0; i < getLastIdxRow(m); i++){
            for(j=i+1; j <= getLastIdxCol(m); j++){
                sym = (ELMT(m, i, j) == ELMT(m, j, i));
                if(!sym)
                    break;
            }
            if(!sym)
                break;
        }
    }
    return sym;
}

boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */

	/* KAMUS LOKAL */
    boolean id;
    int i, j;
	
	/* ALGORITMA */
    id = isSquare(m);
    if(id){
        for(i=0; i <= getLastIdxRow(m); i++){
            for(j=0; j <= getLastIdxCol(m); j++){
                id = ((ELMT(m, i, j) == 1) && i == j) || ((ELMT(m, i, j) == 0) && i != j);
                if(!id)
                    break;
            }
            if(!id)
                break;
        }
    }
    return id;
}

boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

	/* KAMUS LOKAL */
    float prcnt = 0;
    int i, j;
	
	/* ALGORITMA */
	for(i=0; i <= getLastIdxRow(m); i++){
        for(j=0; j <= getLastIdxCol(m); j++){
            if(ELMT(m, i, j) != 0)
                prcnt += 1;
        }
    }
    return (prcnt/countElmt(m) <= 0.05);
}

Matrix negation(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */

	/* KAMUS LOKAL */
    Matrix mRes;
    int i, j;
	
	/* ALGORITMA */
    createMatrix(ROW_EFF(m), COL_EFF(m), &mRes);
	for(i=0; i <= getLastIdxRow(mRes); i++){
        for(j=0; j <= getLastIdxCol(mRes); j++){
            ELMT(mRes, i, j) = -ELMT(m, i, j);
        }
    }
    return mRes;
}

void pNegation(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

	/* KAMUS LOKAL */
    int i, j;
	
	/* ALGORITMA */
	for(i=0; i <= getLastIdxRow(*m); i++){
        for(j=0; j <= getLastIdxCol(*m); j++){
            ELMT(*m, i, j) *= -1;
        }
    }
}

float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
/* menghitung nilai determinan dengan metode reduksi baris */

	/* KAMUS LOKAL */
    float det = 1;   // inisialisasi nilai determinan dengan 1

    int r, c;
    int rpivot;
    int i, j;

    ElType temp;
    float num, den;
	
	/* ALGORITMA */
    r=0;
    c=0;                                                                                // inisialisasi
    while (r < ROW_EFF(m) && c < COL_EFF(m)) {
        rpivot = r;
        while (rpivot < ROW_EFF(m)-1 && ELMT(m, rpivot, c) == 0) {                      // periksa kolom dari baris rpivot untuk kemunculan elemen bukan 0 (mencari indeks pivot)
            rpivot++;
        }
        // rpivot == this.row-1 (baris terakhir) ATAU this.mat[rpivot][col] != 0
        if (ELMT(m, rpivot, c) != 0) {                                                  // terdapat elemen bukan 0 dari kolom (pivot)
            if (r != rpivot) {
                for(i=0; i < COL_EFF(m); i++){                                          // tukar baris dengan baris pivot
                    temp = ELMT(m, r, i);
                    ELMT(m, r, i) = ELMT(m, rpivot, i);
                    ELMT(m, rpivot, i) = ELMT(m, r, i);
                }
                det *= (-1);                                                            // kalikan nilai det dengan -1 setiap operasi pertukaran baris
            }
            for (i=r+1; i < ROW_EFF(m); i++) {                                          // penjumlahan baris untuk setiap baris setelah rpivot
                num = ELMT(m, i, c);    // pembilang konstanta kelipatan baris
                den = ELMT(m, r, c);    // penyebut konstanta kelipatan baris
                for(j=c; j < COL_EFF(m); j++){                                          // operasi menjumlahkan baris dengan kelipatan baris lain, tetapi tidak melakukan pembagian untuk menghindari pembulatan
                    ELMT(m, i, j) = ELMT(m, i, j)*den - ELMT(m, r, j)*num;
                }
                det /= den;                                                             // bagi determinan dengan den, karena dilakukan perkalian baris dengan den
            }
            r++;
        }
        c++;
    }
    // r == this.row ATAU c == this.col
    for(i=0; i < ROW_EFF(m); i++) {                                                     // kalikan determinan dengan nilai diagonal matriks tereduksi
        det *= ELMT(m, i, i);
    }
    return det;
}

Matrix transpose(Matrix m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

	/* KAMUS LOKAL */
    Matrix mRes;
    int i, j;
	
	/* ALGORITMA */
    createMatrix(ROW_EFF(m), COL_EFF(m), &mRes);
	for(i=0; i <= getLastIdxRow(mRes); i++){
        for(j=0; j <= getLastIdxCol(mRes); j++){
            ELMT(mRes, i, j) = ELMT(m, j, i);
        }
    }
    return mRes;
}

void pTranspose(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

	/* KAMUS LOKAL */
    int i, j;
    ElType temp;
	
	/* ALGORITMA */
	for(i=0; i < getLastIdxRow(*m); i++){
        for(j=i+1; j <= getLastIdxCol(*m); j++){
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}

/* Operasi berbasis baris dan per kolom */


float AvgRow(Matrix M, IdxType i){

/* Menghasilkan rata-rata dari elemen pada baris ke-i */

/* Prekondisi: i adalah indeks baris efektif dari M */

	/* KAMUS LOKAL */
	int j;
    float avg;

	/* ALGORITMA */
    avg = 0;
	for(j=0; j <= getLastIdxCol(M); j++){
        avg += ELMT(M, i, j);
    }
    return avg/COL_EFF(M);
}

float AvgCol(Matrix M, IdxType j){

/* Menghasilkan rata-rata dari elemen pada kolom ke-j */

/* Prekondisi: j adalah indeks kolom efektif dari M */

    /* KAMUS LOKAL */
	int i;
    float avg;

	/* ALGORITMA */
    avg = 0;
	for(i=0; i <= getLastIdxRow(M); i++){
        avg += ELMT(M, i, j);
    }
    return avg/ROW_EFF(M);
}

void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min){

/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada baris i dari M

min berisi elemen minimum pada baris i dari M */

    /* KAMUS LOKAL */
	int j;
    
	/* ALGORITMA */
    *max = ELMT(M, i, 0);
    *min = ELMT(M, i, 0);
	for(j=1; j <= getLastIdxCol(M); j++){
        if(ELMT(M, i, j) > *max)
            *max = ELMT(M, i, j);
        if(ELMT(M, i, j) < *min)
            *min = ELMT(M, i, j);
    }
}

void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min){

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada kolom j dari M

min berisi elemen minimum pada kolom j dari M */

    /* KAMUS LOKAL */
	int i;
    
	/* ALGORITMA */
    *max = ELMT(M, 0, j);
    *min = ELMT(M, 0, j);
	for(i=1; i <= getLastIdxRow(M); i++){
        if(ELMT(M, i, j) > *max)
            *max = ELMT(M, i, j);
        if(ELMT(M, i, j) < *min)
            *min = ELMT(M, i, j);
    }
}

int CountNumRow(Matrix M, IdxType i, ElType X){

/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

    /* KAMUS LOKAL */
	int j;
    int count;
    
	/* ALGORITMA */
    count = 0;
	for(j=0; j <= getLastIdxCol(M); j++){
        if(ELMT(M, i, j) == X)
            count++;
    }
    return count;
}

int CountNumCol(Matrix M, IdxType j, ElType X){

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */

    /* KAMUS LOKAL */
	int i;
    int count;
    
	/* ALGORITMA */
    count = 0;
	for(i=0; i <= getLastIdxRow(M); i++){
        if(ELMT(M, i, j) == X)
            count++;
    }
    return count;
}

void RotateMat(Matrix *m){

/* I.S. m terdefinisi dan IsSquare(m) */

/* F.S. m "di-rotasi" searah jarum jam

   untuk semua "lapisan" elemen mulai dari yang terluar

   Contoh matrix 3x3 sebelum dirotasi:

   1 2 3

   4 5 6

   7 8 9


   Contoh matrix 3x3 setelah dirotasi:

   4 1 2

   7 5 3

   8 9 6

   Contoh matrix 4x4 sebelum dirotasi:

   1 2 3 4

   5 6 7 8

   9 10 11 12

   13 14 15 16

   Contoh matrix 4x4 setelah dirotasi:

   5 1 2 3

   9 10 6 4

   13 11 7 8

   14 15 16 12

*/

    
	/* KAMUS LOKAL */
	int layer, i;
    int frow, lrow, fcol, lcol;
    ElType temp;

	/* ALGORITMA */
    frow = 0;
    lrow = getLastIdxRow(*m);
    fcol = 0;
    lcol = getLastIdxCol(*m);
	for(layer=0; layer < ROW_EFF(*m)/2; layer++){
        temp = ELMT(*m, frow, fcol);

        for(i=frow; i < lrow; i++){                             // geser kolom kiri ke atas
            ELMT(*m, i, fcol) = ELMT(*m, i+1, fcol);
        }

        for(i=fcol; i < lcol; i++){                             // geser baris bawah ke kiri
            ELMT(*m, lrow, i) = ELMT(*m, lrow, i+1);
        }

        for(i=lrow; i > frow; i--){                             // geser kolom kanan ke bawah
            ELMT(*m, i, lcol) = ELMT(*m, i-1, lcol);
        }

        for(i=lcol; i > fcol+1; i--){                             // geser baris atas ke kanan
            ELMT(*m, frow, i) = ELMT(*m, frow, i-1);
        }

        ELMT(*m, frow, fcol+1) = temp;

        frow++;
        fcol++;
        lrow--;
        lcol--;
    }
}