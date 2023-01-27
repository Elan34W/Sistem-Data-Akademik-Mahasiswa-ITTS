#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Typdef UNTUK MENYIMPAN DATA DARI VARIABEL //
typedef struct {
    char nama[20];
    char kelamin[20];
    char agama[20];
    char status[20];
    char kelas[20];
    int nim;
}Mahasiswa;

// FUNGSI UNTUK MENAMBAHKAN DATA MAHASISWA //
void input(Mahasiswa x[])
{
        printf("======================================================");
        printf("\nData Mahasiswa");
        printf("\nMasukkan Nama Mahasiswa : ");
        fflush(stdin); gets(x->nama);
        printf("\nMasukkan NIM Mahasiswa : ");
        scanf("%d", &x->nim);
        printf("\nMasukkan Kelas Mahasiswa : ");
        fflush(stdin); gets(x->kelas);
        printf("\nMasukkan kelamin Mahasiswa (L / P) : ");
        printf("\nMasukkan agama Mahasiswa : ");
        fflush(stdin); gets(x->agama);
        printf("\nMasukkan status Mahasiswa (Aktif, Non-Aktif , Lulus) : ");
        fflush(stdin); gets(x->status);
    
}

// FUNGSI UNTUK MENAMPILAKAN DATA MAHASISWA //
void output(Mahasiswa x[],int y){
    printf("DATA - DATA MAHASISWA\n");
    for (int i = 0; i < y; i++)
    {
        printf("\nNama Mahasiswa : %s ", x[i].nama);
        printf("\nNim Mahasiswa : %d ", x[i].nim);
        printf("\nKelas Mahasiswa : %s ", x[i].kelas);
        printf("\nkelamin : %s ", x[i].kelamin);
        printf("\nagama : %s ", x[i].agama);
        printf("\nstatus : %s ", x[i].status);
        printf("\n");
    }
    
}

// FUNGSI UNTUK MENGEDIT DATA MAHASISWA //
void edit(Mahasiswa x[],int y)
{
    char editNama[20];
    int flag = 0;
    printf("Masukkan Nama Mahasiswa Yang Ingin di edit: ");
    fflush(stdin); gets(editNama);
    for (int i = 0; i < y; i++)
    {
        if (strcmp(editNama, x[i].nama)==0)
    {
    flag = 1;
    printf("\nMasukkan Nama Mahasiswa : ");
    fflush(stdin); gets(x[i].nama);
    printf("\nMasukkan NIM Mahasiswa : ");
    scanf("%d", &x[i].nim);
    printf("\nMasukkan Kelas Mahasiswa : ");
    fflush(stdin); gets(x[i].kelas);
    printf("\nMasukkan kelamin Mahasiswa (L / P) : ");
    fflush(stdin); gets(x[i].kelamin);
    printf("\nMasukkan agama Mahasiswa : ");
    fflush(stdin); gets(x[i].agama);
    printf("\nMasukkan status Mahasiswa (Aktif, Non-Aktif , Lulus) : ");
    fflush(stdin); gets(x[i].status);
        }
    }
    if (flag == 0) {
        printf("Data tidak ditemukan\n");
    }
  } 

// FUNGSI UNTUK MENCARI DATA MAHASISWA //
void pencarian(Mahasiswa x[],int y)
{
    char cariNama[20];
    int flag = 0;
    printf("Masukkan nama Mahasiswa yang ingin dicari : ");
    fflush(stdin); gets(cariNama);
    for (int i = 0; i < y; i++)
    {
        if (strcmp(cariNama, x[i].nama)==0)
        {
        flag = 1;
        printf("\nNama Mahasiswa : %s ", x[i].nama);
        printf("\nNim Mahasiswa : %d ", x[i].nim);
        printf("\nKelas Mahasiswa : %s ", x[i].kelas);
        printf("\nkelamin : %s ", x[i].kelamin);
        printf("\nagama : %s ", x[i].agama);
        printf("\nstatus : %s ", x[i].status);
        printf("\n");
        }
        
    }
    if (flag == 0) {
        printf("Data tidak ditemukan\n");
    }
}

// FUNGSU UNTUK PENGURUTAN ASCENDING DATA MAHASISWA //
void pengurutanAscending(Mahasiswa x[],int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = i + 1; j < y; j++) {
            if (strcmp(x[i].nama, x[j].nama) > 0) {
                Mahasiswa temp = x[i];
                x[i] = x[j];
                x[j] = temp;
        }
        }
    }
     for(int i = 0; i < y; i++)
        {
            printf("\nNama Mahasiswa : %s ", x[i].nama);
            printf("\nNim Mahasiswa : %d ", x[i].nim);
            printf("\nKelas Mahasiswa : %s ", x[i].kelas);
            printf("\nkelamin : %s ", x[i].kelamin);
            printf("\nagama : %s ", x[i].agama);
            printf("\nstatus : %s ", x[i].status);    
            printf("\n");
        }
    
}

// FUNGSU UNTUK PENGURUTAN DESCENDING DATA MAHASISWA //
void pengurutanDescending(Mahasiswa x[], int y)
{
        for (int i = 0; i < y; i++) {
        for (int j = i + 1; j < y; j++) {
            if (strcmp(x[i].nama, x[j].nama) < 0) {
                Mahasiswa temp = x[i];
                x[i] = x[j];
                x[j] = temp;
        }
        }
    }
     for(int i = 0; i < y; i++)
        {
            printf("\nNama Mahasiswa : %s ", x[i].nama);
            printf("\nNim Mahasiswa : %d ", x[i].nim);
            printf("\nKelas Mahasiswa : %s ", x[i].kelas);
            printf("\nkelamin : %s ", x[i].kelamin);
            printf("\nagama : %s ", x[i].agama);
            printf("\nstatus : %s ", x[i].status);    
            printf("\n");
        }
}

// FUNGSI UNTUK MEMASUKKAN INPUT KE DALAM FILE //
void saveA(Mahasiswa x[]){
  FILE* file = fopen("students.txt", "a");
  if (file == NULL) {
    printf("File tidak tersedia!\n");
    return;
  } 
    fprintf(file, "%s_ %d IF-%s %s  %s%s \n", x->nama, x->nim, x->kelas, x->kelamin, x->agama, x->status);
    fclose(file);
}

// FUNGSI UNTUK MEMASUKKAN INPUT EDIT KE DALAM FILE //
void saveB(Mahasiswa x[], int y){
    FILE* file = fopen("students.txt","w");
  if (file == NULL) {
    printf("File tidak tersedia!\n");
    return;
  }
    for (int i = 0; i < y; i++) {
        fprintf(file, "%s_ %d %s %s %s %s \n", x[i].nama, x[i].nim, x[i].kelas, x[i].kelamin, x[i].agama, x[i].status);
    }
        fclose(file);
}

// FUNGSI UNTUK MEMBACA DAN MENGAMBIL DATA DARI DALAM FILE //
void load(Mahasiswa x[], int y[]) {
  FILE* file = fopen("students.txt", "r");
  if (file == NULL) {
    printf("File tidak tersedia!\n");
    return;
  }

  *y = 0;
  while (fscanf(file, "%[^_]_ %d %s %s %s %s \n", x[*y].nama, &x[*y].nim, &x[*y].kelas, x[*y].kelamin, x[*y].agama, x[*y].status) != EOF) {
    (*y)++;
  }

  fclose(file);
}


int main()
{
    Mahasiswa data[100];
    int pilih,banyak,opsisort;

do {
    printf("\n\tSistem Data Akademik Mahasiswa Prodi IF");
    printf("\n======================================================");
    printf("\n1. Tambah Data Mahasiswa ");
    printf("\n2. Tampilkan Data Mahasiswa ");
    printf("\n3. Edit Data Mahasiswa ");
    printf("\n4. Pencarian Data Mahasiswa ");
    printf("\n5. Pengurutan Data Mahasiswa ");
    printf("\n6. Keluar ");
    printf("\n======================================================");
    printf("\nMasukkan Pilihan : ");
    scanf("%d", &pilih);

    switch(pilih){
        case 1:
            system("cls");
            input(data);
            saveA(data);
            break;
        case 2:
            system("cls");
            load(data,&banyak);
            output(data,banyak);
            break;
        case 3:
            system("cls");
            load(data,&banyak);
            edit(data,banyak);
            saveB(data,banyak);
            break;
        case 4:
            system("cls");
            load(data,&banyak);
            pencarian(data,banyak);
            break;
        case 5:
        system("cls");
        printf("\n======================================================\n");
        printf("Pilihan Pengurutan\n");
        printf("1. Acsending\n");
        printf("2. Descending\n");
        printf("======================================================\n");
        printf("Pilih opsi : ");
        scanf("%d",&opsisort);
        load(data,&banyak);
        system("cls");
        if (opsisort == 1)
        {
            pengurutanAscending(data,banyak);
        }
        else if (opsisort == 2)
        {
            pengurutanDescending(data,banyak);
        }
        saveB(data,banyak);
            break;
        case 6:
            system("cls");
            return 0;
            break;
        default:
            printf("\nMohon pilih menu yang ada ! ");
    }
    printf("\n");
    system("pause");
    system("cls");
} while (pilih != 6);
return 0;
}
