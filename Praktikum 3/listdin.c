// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 14 September 2022
// Topik: ADT List Statik dan Dinamik
// Deskripsi: Pra-Praktikum listdin.c

/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
    BUFFER(*l) = malloc(capacity * sizeof(ElType));
	CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
    free(BUFFER(*l));
	CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return NEFF(l);
}

/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return NEFF(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (IDX_MIN <= i && i <= CAPACITY(l));
}

boolean isIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (IDX_MIN <= i && i <= NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return NEFF(l) == 0;
}

/* *** Test list penuh *** */
boolean isFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */

	/* KAMUS LOKAL */
	int n, i;
	
	/* ALGORITMA */
	do{
		scanf("%d", &n);
	} while(!isIdxValid(*l, n));
	
    NEFF(*l) = n;
    
    for (i=0;i<n;i++){
        scanf("%d", &ELMT(*l, i));
    }
}
void printList(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

	/* KAMUS LOKAL */
	int i, last;
	
	/* ALGORITMA */
	printf("[");
	last = getLastIdx(l);
	for(i=0;i<=last;i++){	// pengulangan iterate-stop pilihan yang tepat >:O <- salah, nevermind
		printf("%d", ELMT(l, i));
		if(i != last)
			printf(",");
	}
	printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

	/* KAMUS LOKAL */
    int i, size;
    ListDin lres;
	
	/* ALGORITMA */
	CreateListDin(&lres, CAPACITY(l1));
	NEFF(lres) = NEFF(l1);
	for(i=0;i<listLength(l1);i++){
		if(plus)
			ELMT(lres, i) = ELMT(l1, i) + ELMT(l2, i);
		else
			ELMT(lres, i) = ELMT(l1, i) - ELMT(l2, i);
	}
	
	return lres;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

	/* KAMUS LOKAL */
	int i, size;
	boolean flag = true;	// menjadi false jika ditemukan elemen l1 dan l2 yang tidak sama
	
	/* ALGORITMA */
	size = listLength(l1);
	
	if(size == listLength(l2)){
		for(i=0;i<size;i++){
			flag &= (ELMT(l1, i) == ELMT(l2, i));
		}
		return flag;
	}
	else
		return false;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
	
	/* KAMUS LOKAL */
	int i, size;
	
	/* ALGORITMA */
	if(isEmpty(l))
		return IDX_UNDEF;
	else{
		size = listLength(l);
		i = 0;
		while(ELMT(l, i) != val && i < size-1){
			i++;
		}
		// ELMT(l, i) == val atau i = size-1
		if(ELMT(l, i) == val)
			return i;
		else
			return IDX_UNDEF;
	}
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
	
	/* KAMUS LOKAL */
	int i, init;
	
	/* ALGORITMA */
	init = getFirstIdx(l);
	*max = ELMT(l, init);	// inisialisasi nilai
	*min = ELMT(l, init);
	for(i=init+1;i<listLength(l);i++){
		if(*max < ELMT(l, i))
			*max = ELMT(l, i);
		if(*min > ELMT(l, i))
			*min = ELMT(l, i);
	}
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

	/* KAMUS LOKAL */
	int i;
	
	/* ALGORITMA */
	CreateListDin(lOut, CAPACITY(lIn));
    for (i=0;i<listLength(lIn);i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
}

ElType sumList(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */

	/* KAMUS LOKAL */
	int i, jml;
	
	/* ALGORITMA */
    jml = 0;
    for (i=0;i<listLength(l);i++)
    {
        jml += ELMT(l, i);
    }
    return jml;
}
int countVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

	/* KAMUS LOKAL */
	int i, jml;
	
	/* ALGORITMA */
	jml = 0;
	for (i=0;i<listLength(l);i++)
    {
        if (ELMT(l, i) == val)
        {
            jml += 1;
        }
    }
    return jml;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

	/* KAMUS LOKAL */
	int i, j, size;
	ElType temp;
	
	/* ALGORITMA */
	size = listLength(*l);
	for(i=1;i<size;i++){
		temp = ELMT(*l, i);
		j = i-1;
		while(((temp < ELMT(*l, j) && asc) || (temp > ELMT(*l, j) && !asc)) && j > 0){
			ELMT(*l, j+1) = ELMT(*l, j);
			j--;
		}
		// ditemukan tempat yang tepat atau j == 0
		if((temp < ELMT(*l, j) && asc) || (temp > ELMT(*l, j) && !asc)){
			ELMT(*l, j+1) = ELMT(*l, j);
			ELMT(*l, j) = temp;
		}
		else{
			ELMT(*l, j+1) = temp;
		}
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	ELMT(*l, getLastIdx(*l)+1) = val;
	NEFF(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	*val = ELMT(*l, getLastIdx(*l));
	NEFF(*l) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

	/* KAMUS LOKAL */
	ListDin ltemp;
	int i;
	
	/* ALGORITMA */
    CreateListDin(&ltemp, CAPACITY(*l)+num);
    for (i=0;i<listLength(*l);i++)
    {
        ELMT(ltemp, i) = ELMT(*l, i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateList(l);
    *l = ltemp;
}

void shrinkList(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

	/* KAMUS LOKAL */
	ListDin ltemp;
	int i;
	
	/* ALGORITMA */
    CreateListDin(&ltemp, CAPACITY(*l)-num);
    for (i=0;i<listLength(*l);i++)
    {
        ELMT(ltemp, i) = ELMT(*l, i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateList(l);
    *l = ltemp;
}

void compressList(ListDin *l){
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */

	/* KAMUS LOKAL */
	ListDin ltemp;
	int i;
	
	/* ALGORITMA */
    CreateListDin(&ltemp, NEFF(*l));
    for (i=0;i<listLength(*l);i++)
    {
        ELMT(ltemp, i) = ELMT(*l, i);
    }
    NEFF(ltemp) = NEFF(*l);
    dealocateList(l);
    *l = ltemp;
}


