#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n{
char isim[20];
char soyisim[20];
char numara[11];
struct n * next;
}node;

node * listeEkle(node * liste,char isim[20],char soyisim[20],char numara[11]){
node * iter = liste;
while(iter != NULL){
    if(strcmp(numara,iter->numara) == 0){
        printf("\n Girdiginiz numara zaten kayitli...");
        return liste;
    }
    iter = iter->next;
}

iter = liste;
if(liste == NULL){
    liste = (node *)malloc(sizeof(node));
    strcpy(liste->isim,isim);
    strcpy(liste->soyisim,soyisim);
    strcpy(liste->numara,numara);
    liste->next = NULL;
    return liste;
}
/*if(liste->next == NULL){
    node * temp = (node *)malloc(sizeof(node));
     strcpy(temp->isim,isim);
    strcpy(temp->soyisim,soyisim);
    strcpy(temp->numara,numara);
    liste->next = temp;
    temp->next = NULL;
    return liste;
}*/
//iter = liste;
while(iter->next != NULL){
    iter = iter->next;
}
 node * temp = (node *)malloc(sizeof(node));
     strcpy(temp->isim,isim);
    strcpy(temp->soyisim,soyisim);
    strcpy(temp->numara,numara);
    iter->next = temp;
    temp->next = NULL;
    return liste;

}


void listele(node * liste){
node * iter = liste;
while(iter->next != NULL){
    printf("\n Isim : %s \n Soyisim : %s \n Telefon : %s",iter->isim,iter->soyisim,iter->numara);
iter = iter->next;
}
printf("\n Isim : %s \n Soyisim : %s \n Telefon : %s",iter->isim,iter->soyisim,iter->numara);
}


void isimAra(node * liste,char aranan[20]){
int uzunluk = strlen(aranan);
node * iter = liste;
while(iter!= NULL){
    int kontrol  =0;
    for(int i  =0 ;i<uzunluk;i++){
        if(aranan[i] != iter->isim[i]){
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("\n Isim : %s \n Soyisim : %s \n Telefon : %s",iter->isim,iter->soyisim,iter->numara);
    }
    iter = iter->next;
}

}


void soyisimAra(node * liste,char aranan[20]){
int uzunluk = strlen(aranan);
node * iter = liste;
while(iter!= NULL){
    int kontrol  =0;
    for(int i  =0 ;i<uzunluk;i++){
        if(aranan[i] != iter->soyisim[i]){
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("\n Isim : %s \n Soyisim : %s \n Telefon : %s",iter->isim,iter->soyisim,iter->numara);
    }
    iter = iter->next;
}
}

void numaraAra(node * liste, char aranan[20]){
int uzunluk = strlen(aranan);
node * iter = liste;
while(iter!= NULL){
    int kontrol  =0;
    for(int i  =0 ;i<uzunluk;i++){
        if(aranan[i] != iter->numara[i]){
            kontrol = 1;
        }
    }
    if(kontrol == 0){
        printf("\n Isim : %s \n Soyisim : %s \n Telefon : %s",iter->isim,iter->soyisim,iter->numara);
    }
    iter = iter->next;
}
}


node * kisiSil(node * liste,char aranan[11]){

if(liste->next == NULL){
    if(strcmp(aranan,liste->numara) == 0){
            printf("\n kisi silindi...");
        return NULL;
    }
    else{
        printf("\n Numara kayitli degil");
        return liste;
    }
}

if(liste->next != NULL && strcmp(aranan,liste->numara) == 0){
    liste = liste->next;
    printf("\n Kisi Silindi...");
    return liste;
}

node * iter = liste;
while(iter->next != NULL){
    if(strcmp(aranan,iter->next->numara) == 0){
        node * temp = iter->next->next;
        iter->next = temp;
        printf("\n Kisi silindi...");
        return liste;
    }
    iter = iter->next;
}
return liste;
}

int main()
{
    node * liste = NULL;
   liste = listeEkle(liste,"mehmet","tasli","05442711297");
   liste = listeEkle(liste,"ugur","tasli","124545");
    liste =listeEkle(liste,"ufuk","tasli","5445555");
    liste =listeEkle(liste,"james","hetfield","66666");
    liste =listeEkle(liste,"cliff","burton","4545");
    liste = listeEkle(liste,"ozzy","osbourne","0544274652");

int secim;
while(1 == 1){
system("CLS");

printf(" 1-> Yeni Kisi Ekle \n 2-> Kisileri Listele \n 3-> Kisi Bul \n 4-> Kisi Sil \n   Secim : ");
scanf("%d",&secim);
switch(secim){
case 1:{
    char isim[20];
    char soyisim[20];
    char numara[11];
    printf("\n Isim : ");
    scanf("%s",isim);
    printf("\n Soyisim : ");
    scanf("%s",soyisim);
    printf("\n Telefon No : ");
    scanf("%s",numara);
    liste = listeEkle(liste,isim,soyisim,numara);
    getch();
    break;
}
case 2:
    listele(liste);
    getch();
    printf("\n Devam Etmek Icin Herhangi bir tusa basiniz...");
    break;
case 3:{
char aranacak[20];
printf("Aranacak degeri giriniz : ");
scanf("%s",aranacak);
isimAra(liste,aranacak);
soyisimAra(liste,aranacak);
numaraAra(liste,aranacak);
getch();
break;
}
case 4:{
    char aranan[11];
    printf("\n Silmek istediginiz numara : ");
    scanf("%s",aranan);
    liste = kisiSil(liste,aranan);
    getch();
    break;
}
default:{printf("\n Hatalı giris yaptiniz...");
    break;}

}
}

    return 0;
}
