#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Ogrenci {
    char ad[50];
    int yas;
    int numara;
    struct Ogrenci* next;
};

struct Node* ekle(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void yazdir(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Ogrenci* ogrenciEkle(struct Ogrenci* head, char ad[50], int yas, int numara) {
    struct Ogrenci* newNode = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(newNode->ad, ad);
    newNode->yas = yas;
    newNode->numara = numara;
    newNode->next = head;
    return newNode;
}

void yazdirOgrenci(struct Ogrenci* head) {
    struct Ogrenci* current = head;
    while (current != NULL) {
        printf("%s %d %d\n", current->ad, current->yas, current->numara);
        current = current->next;
    }
}

void serbestBirak(struct Node* head) {
    struct Node* current = head;
    struct Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

void serbestBirakOgrenci(struct Ogrenci* head) {
    struct Ogrenci* current = head;
    struct Ogrenci* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* tekSayilar = NULL;
    struct Node* ciftSayilar = NULL;
    struct Ogrenci* ogrenciHead = NULL;

    int secim;
    char ad[50];
    int yas, numara;
    int num;

    while (1) {
        printf("\nYapmak istediginiz islemi secin:\n");
        printf("1. Ogrenci Ekle\n");
        printf("2. Isme Gore Ogrenci Ara ve Sil\n");
        printf("3. En Uzun Ogrenci Ismi Bul\n");
        printf("4. Tek ve Cift Sayilari Ayir ve Listele\n");
        printf("5. Ogrenci Listesini Goster\n");
        printf("6. Cikis\n");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Ad: ");
                scanf("%s", ad);
                printf("Yas: ");
                scanf("%d", &yas);
                printf("Numara: ");
                scanf("%d", &numara);
                ogrenciHead = ogrenciEkle(ogrenciHead, ad, yas, numara);
                break;
            case 2:
                printf("Aranacak ismi girin: ");
                scanf("%s", ad);
                // Ýlgili fonksiyonu çaðýrýn
                break;
            case 3:
                // Ýlgili fonksiyonu çaðýrýn
                break;
            case 4:
                printf("Tek ve cift sayilari sirasiyla girin (-1 girerek bitirin):\n");
                while (1) {
                    scanf("%d", &num);
                    if (num == -1) {
                        break;
                    }
                    if (num % 2 == 1) {
                        tekSayilar = ekle(tekSayilar, num);
                    } else {
                        ciftSayilar = ekle(ciftSayilar, num);
                    }
                }
                printf("Tek Sayilar: ");
                yazdir(tekSayilar);
                printf("Cift Sayilar: ");
                yazdir(ciftSayilar);
                // Bellekten serbest býrakma iþlemleri
                serbestBirak(tekSayilar);
                serbestBirak(ciftSayilar);
                tekSayilar = NULL;
                ciftSayilar = NULL;
                break;
            case 5:
                printf("Ogrenci Listesi:\n");
                yazdirOgrenci(ogrenciHead);
                break;
            case 6:
                printf("Programdan cikiliyor...\n");
                // Bellekten serbest býrakma iþlemleri
                serbestBirakOgrenci(ogrenciHead);
                exit(0);
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }

    return 0;
}

