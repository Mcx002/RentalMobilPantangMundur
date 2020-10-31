#include <stdio.h>
#include <stdlib.h>

struct HargaSewa{
    int kode;
    char jenis;
    int hargaSewa;
    int stok;
};

struct HargaSewa listHarga[50];
int selectedMenu = -2;
int lastIndex = 0;

void setData();
void addHargaSewa(int kode, char jenis, float hargaSewa, int stok);

void getItems();
void addForm();
void getSumStock();
int main()
{
    setData();
    while(selectedMenu!=4){
        system("cls");

        printf("Nama     : Muchlish Choeruddin\n");
        printf("NPM      : 0619204001\n");
        printf("Fakultas : teknik\n");
        printf("Prodi    : Informatika\n\n");

        printf("Menu\n");
        printf("1. Tambah Harga Sewa\n");
        printf("2. Data Harga Sewa\n");
        printf("3. Total Stok\n");
        printf("4. Exit\n\n");

        printf("Pilih Menu: ");
        scanf("%d",&selectedMenu);

        switch(selectedMenu){
            case 1:
                addForm();
                break;
            case 2:
                getItems();
                break;
            case 3:
                getSumStock();
                break;
            case 4:
                break;
            default:
                puts("Invalid value\nPress <enter> to continue");
                getch();
                break;
        }
    }
    return 0;
}

void setData(){
    addHargaSewa(101,'A',250000,5);
    addHargaSewa(102,'A',230000,3);
    addHargaSewa(104,'A',270000,2);
    addHargaSewa(203,'B',390000,1);
    addHargaSewa(205,'B',375000,10);
    addHargaSewa(206,'B',335000,4);
    addHargaSewa(301,'C',505000,1);
    addHargaSewa(305,'C',420000,2);
    addHargaSewa(307,'C',490000,3);
}

void addHargaSewa(int kode, char jenis, float hargaSewa, int stok){
    listHarga[lastIndex].kode = kode;
    listHarga[lastIndex].jenis = jenis;
    listHarga[lastIndex].hargaSewa = hargaSewa;
    listHarga[lastIndex].stok = stok;
    lastIndex = lastIndex+1;
}

void getItems(){
    system("cls");
    printf("DATA HARGA SEWA\n\n");
    printf("+------+-------+-----------------+------+\n");
    printf("| Kode | Jenis | Harga Sewa      | Stok |\n");
    printf("+------+-------+-----------------+------+\n");
    for(int i=0; i<100;i++){
        if(listHarga[i].kode!=0){
            char mark = ' ';
            if(i==lastIndex-1){
                mark = '*';
            }
            printf("|%c%d  | %c     | Rp. %d      | %d    |\n",mark,listHarga[i].kode,listHarga[i].jenis,listHarga[i].hargaSewa,listHarga[i].stok);
        }
    }
    printf("+------+-------+-----------------+------+\n");
    puts("\nPress <enter> to continue");
    getch();
}

void addForm(){
    system("cls");
    printf("TAMBAH HARGA SEWA\n\n");

    int kode, hargaSewa, stok;
    char jenis;

    printf("Masukan Kode: ");
    scanf("%d",&kode);
    printf("Masukan Jenis: ");
    scanf(" %c",&jenis);
    printf("Masukan Harga Sewa: Rp. ");
    scanf("%d",&hargaSewa);
    printf("Masukan Stok: ");
    scanf("%d",&stok);

    addHargaSewa(kode, jenis, hargaSewa, stok);
    printf("\nData has been added");
    puts("\nPress <enter> to continue");
    getch();
}

void getSumStock(){
    system("cls");
    printf("TOTAL STOK\n\n");
    int sum = 0;
    for(int i=0; i<100;i++){
        if(listHarga[i].kode!=0){
                sum = sum + listHarga[i].stok;
        }
    }
    printf("Total stok : %d\n",sum);
    puts("\nPress <enter> to continue");
    getch();
}
