// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 26 Oktober 2022
// Topik: ADT Linked List
// Deskripsi: Pra-praktikum listlinier.c

/* File : listlinier.c */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include <stdlib.h>
#include <stdio.h>

#include "boolean.h"
#include "listlinier.h"

Address newNode(ElType val){
    
	/* KAMUS LOKAL */
	Address p;

	/* ALGORITMA */
	p = (Address) malloc(sizeof(Node));
    if(p != NULL){  // alokasi berhasil
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	*l = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return (l == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

	/* KAMUS LOKAL */
	Address p;
    int i;

	/* ALGORITMA */
	p = l;

    i = 0;
    while(i < idx){
        p = NEXT(p);
        i++;
    }
    /* i == idx */
    return INFO(p);
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

	/* KAMUS LOKAL */
	Address p;
    int i;

	/* ALGORITMA */
	p = *l;

    i = 0;
    while(i < idx){
        p = NEXT(p);
        i++;
    }
    /* i == idx */
    INFO(p) = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

	/* KAMUS LOKAL */
	Node *p;
    int idx;

	/* ALGORITMA */
	p = l;

    idx = 0;
    while((INFO(p) != val) && (NEXT(p) != NULL)){
        p = NEXT(p);
        idx++;
    }
    /* INFO(p) == val atau NEXT(p) == NULL */
    if(INFO(p) != val){
        idx = IDX_UNDEF;
    }
    return idx;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	p = newNode(val);
    if(p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

	/* KAMUS LOKAL */
    Address p, new;
	
	/* ALGORITMA */
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else {
	    new = newNode(val);

        if(new != NULL){
            p = *l;
            while(NEXT(p) != NULL){
                p = NEXT(p);
            }
            /* NEXT(p) == NULL, p adalah node terakhir/last */
            NEXT(p) = new;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

	/* KAMUS LOKAL */
    Address p, new;
    int i;
	
	/* ALGORITMA */
    if(idx == 0){
        insertFirst(l, val);
    }
    else{
        new = newNode(val);

        if(new != NULL){
            p = *l;

            i = 0;
            while(i < idx-1){
                p = NEXT(p);
                i++;
            }
            /* i == idx-1 */
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

	/* KAMUS LOKAL */
    Address p;

	/* ALGORITMA */
    p = *l;
    
	*val = INFO(p);
    *l = NEXT(p);

    free(p);
}

void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

	/* KAMUS LOKAL */
    Address p, prev;
	
	/* ALGORITMA */
	p = *l;
    prev = NULL;
    while(NEXT(p) != NULL){
        prev = p;
        p = NEXT(p);
    }
    /* NEXT(p) == NULL, p adalah node terakhir/last */

    if(prev == NULL){   // hanya terdapat satu elemen dalam list
        *l = NULL;
    }
    else{
        NEXT(prev) = NULL;
    }

    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

	/* KAMUS LOKAL */
    Address p, prev;
    int i;
	
	/* ALGORITMA */
	if(idx == 0){
        deleteFirst(l, val);
    }
    else{
        p = *l;
        i = 0;
        while(i < idx-1){
            p = NEXT(p);
            i++;
        }
        /* i == idx-1, p berada pada indeks idx-1 */
        prev = p;       // prev menjadi p; indeks idx-1
        p = NEXT(p);    // p berada pada indeks idx

        NEXT(prev) = NEXT(p);
        *val = INFO(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	printf("[");

    p = l;
    if(p != NULL){
        while(NEXT(p) != NULL){
            printf("%d,", INFO(p));
            p = NEXT(p);
        }
        /* NEXT(p) == NULL, p adalah node terakhir/last */
        printf("%d", INFO(p));
    }

    printf("]");
}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

	/* KAMUS LOKAL */
	Address p;
    int len;

	/* ALGORITMA */
	p = l;

    len = 0;
    while(p != NULL){
        p = NEXT(p);
        len++;
    }

    return len;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

	/* KAMUS LOKAL */
    Address p;
    List l3;
	
	/* ALGORITMA */
    CreateList(&l3);
    
    p = l1;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    /* NEXT(p) == NULL, p adalah node terakhir l1 */

    return l3;
}
