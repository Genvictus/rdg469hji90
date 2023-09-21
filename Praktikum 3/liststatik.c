// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 14 September 2022
// Topik: ADT List Statik dan Dinamik
// Deskripsi: Pra-Praktikum liststatik.c

/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include <stdio.h>
#include "boolean.h"
#include "liststatik.h"

/* ********** SELEKTOR ********** */
//#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
	
	/* KAMUS LOKAL */
	int i;
	
	/* ALGORITMA */
	for(i=0;i<CAPACITY;i++){
		ELMT(*l, i) = MARK;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
	
	/* KAMUS LOKAL */
	int len, i;
	
	/* ALGORITMA */
	len = 0;	// inisialisasi jumlah elemen efektif list = 0
	for(i=0;i<CAPACITY;i++){	// periksa selagi elemen list bukan MARK, periksa dari indeks 0 secara berurut karena elemen rapat kiri
		if(ELMT(l, i) != MARK)
			len++;
	}
	return len;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return listLength(l)-1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return IDX_MIN <= i && i < CAPACITY;
}
boolean isIdxEff(ListStatik l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return 0 <= i && i <= listLength(l)-1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return listLength(l) == 0;
}

boolean isFull(ListStatik l){
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return listLength(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
	
	/* KAMUS LOKAL */
	int n, i;
	
	/* ALGORITMA */
	do{
		scanf("%d", &n);
	} while(!isIdxValid(*l, n));
	
	CreateListStatik(l);
	
	for(i=0;i<n;i++){
		scanf("%d", &ELMT(*l, i));
	}
	
}
void printList(ListStatik l){
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
	
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
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
    
    /* KAMUS LOKAL */
    int i, size;
    ListStatik lres;
	
	/* ALGORITMA */
	size = listLength(l1);
	CreateListStatik(&lres);
	for(i=0;i<size;i++){
		if(plus)
			ELMT(lres, i) = ELMT(l1, i) + ELMT(l2, i);
		else
			ELMT(lres, i) = ELMT(l1, i) - ELMT(l2, i);
	}
	
	return lres;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
	
	/* KAMUS LOKAL */
	int i, size;
	boolean flag = true;	// menjadi false jika ditemukan elemen l1 dan l2 yang tidak sama
	
	/* ALGORITMA */
	size = listLength(l1);
	
	if(size == listLength(l2)){
		for(i=0;i<size;i++){
			flag &= (ELMT(l1, i) == ELMT(l2, i));
		}
	}
	else
		flag = false;
	return flag;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
	
	/* KAMUS LOKAL */
	int i, last;
	
	/* ALGORITMA */
	if(isEmpty(l))
		return IDX_UNDEF;
	else{
		last = getLastIdx(l);
		i = 0;
		while(ELMT(l, i) != val && i < last){
			i++;
		}
		// ELMT(l, i) == val atau i = last
		if(ELMT(l, i) == val)
			return i;
		else
			return IDX_UNDEF;
	}
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
	
	/* KAMUS LOKAL */
	int i, size;
	
	/* ALGORITMA */
	*max = ELMT(l, 0);	// inisialisasi nilai
	*min = ELMT(l, 0);
	size = listLength(l);
	for(i=1;i<size;i++){
		if(*max < ELMT(l, i))
			*max = ELMT(l, i);
		if(*min > ELMT(l, i))
			*min = ELMT(l, i);
	}
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen pertama *** */
void insertFirst(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
	
	/* KAMUS LOKAL */
	int i;
	
	/* ALGORITMA */
	for(i=getLastIdx(*l);i>=0;i--){
		ELMT(*l, i+1) = ELMT(*l, i);
	}
	ELMT(*l, 0) = val;
	
}
void insertAt(ListStatik *l, ElType val, IdxType idx){
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
	
	/* KAMUS LOKAL */
	int i;
	
	/* ALGORITMA */
	for(i=getLastIdx(*l);i>=idx;i--){
		ELMT(*l, i+1) = ELMT(*l, i);
	}
	ELMT(*l, idx) = val;
}
void insertLast(ListStatik *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
	
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	ELMT(*l, getLastIdx(*l)+1) = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

	/* KAMUS LOKAL */
	int i, last;
	
	/* ALGORITMA */
	*val = ELMT(*l, 0);
	last = getLastIdx(*l);
	for(i=0;i<last;i++){
		ELMT(*l, i) = ELMT(*l, i+1);
	}
	ELMT(*l, last) = MARK;
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

	/* KAMUS LOKAL */
	int i, last;
	
	/* ALGORITMA */
	*val = ELMT(*l, idx);
	last = getLastIdx(*l);
	for(i=idx;i<last;i++){
		ELMT(*l, i) = ELMT(*l, i+1);
	}
	ELMT(*l, last) = MARK;
}
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	*val = ELMT(*l, getLastIdx(*l));
	ELMT(*l, getLastIdx(*l)) = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
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

