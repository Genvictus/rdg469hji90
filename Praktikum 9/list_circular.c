// Nama: Johann Christian Kandani
// NIM: 13521138
// Tanggal: 2 November 2022
// Topik: ADT Variasi List Linier
// Deskripsi: Pra-praktikum list_circular.c

/* File : list_circular.c */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

#include <stdio.h>
#include <stdlib.h>

#include "list_circular.h"
#include "boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong. Lihat definisi di atas. */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return FIRST(l) == NULL;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	p = (Address) malloc(sizeof(ElmtList));
    if(p != NULL){  // alokasi berhasil
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void deallocate(Address P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
    if(isEmpty(l)){
        p = NULL;
    }
    else{
        p = FIRST(l);
        while((INFO(p) != val) && (NEXT(p) != FIRST(l))){
            p = NEXT(p);
        }
        /* INFO(p) == val atau NEXT(p) == FIRST(l) */
        if(INFO(p) != val){
            p = NULL;
        }
    }
    return p;
}

boolean addrSearch(List l, Address p){
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

	/* KAMUS LOKAL */
    Address pt;
	
	/* ALGORITMA */
    if(isEmpty(l)){
        return false;
    }
    else{
        pt = FIRST(l);
        while((pt != p) && (NEXT(pt) != FIRST(l))){
            pt = NEXT(pt);
        }
        /* pt == p atau NEXT(p) == FIRST(l) */
        return pt == p;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */

	/* KAMUS LOKAL */
	Address p, pnew;

	/* ALGORITMA */
	pnew = allocate(val);
    if(pnew != NULL){
        if(isEmpty(*l)){
            NEXT(pnew) = pnew;
        }
        else {
            p = FIRST(*l);
            while(NEXT(p) != FIRST(*l)){
                p = NEXT(p);
            }
            /* NEXT(p) == FIRST(*l), p adalah node terakhir */
            NEXT(pnew) = FIRST(*l);
            NEXT(p) = pnew;
        }
        FIRST(*l) = pnew;
    }
}

void insertLast(List *l, ElType val){
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

	/* KAMUS LOKAL */
	Address p, pnew;

	/* ALGORITMA */
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else {
	    pnew = allocate(val);

        if(pnew != NULL){
            p = FIRST(*l);
            while(NEXT(p) != FIRST(*l)){
                p = NEXT(p);
            }
            /* NEXT(p) == FIRST(*l), p adalah node terakhir */
            NEXT(p) = pnew;
            NEXT(pnew) = FIRST(*l);
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */

	/* KAMUS LOKAL */
	Address p, last;

	/* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    if(NEXT(FIRST(*l)) == FIRST(*l)){
        FIRST(*l) = NULL;
    }
    else {
        last = FIRST(*l);
        while(NEXT(last) != FIRST(*l)){
            last = NEXT(last);
        }
        /* NEXT(last) == FIRST(*l), last adalah node terakhir */
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(last) = FIRST(*l);
    }
	deallocate(p);
}

void deleteLast(List *l, ElType * val){
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */

	/* KAMUS LOKAL */
    Address last, preclast;
	
	/* ALGORITMA */
	last = FIRST(*l);
    preclast = NULL;
    while(NEXT(last) != FIRST(*l)){
        preclast = last;
        last = NEXT(last);
    }
    /* NEXT(last) == FIRST(*l), last adalah node terakhir */
    if(preclast == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(preclast) = FIRST(*l);
    }

    *val = INFO(last);
    deallocate(last);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

	/* KAMUS LOKAL */
    Address p;
	
	/* ALGORITMA */
	printf("[");
    if(!isEmpty(l)){
        p = FIRST(l);
        // printf("%d", INFO(p));
        // p = NEXT(p);
        // while(p != FIRST(l)){
        //     printf(",%d", INFO(p));
        //     p = NEXT(p);
        // }
        // /* p == FIRST(l) */
        for(;;){
            printf("%d", INFO(p));
            p = NEXT(p);

            if(p == FIRST(l)) break;

            printf(",");
        }
    }
    printf("]");
}
