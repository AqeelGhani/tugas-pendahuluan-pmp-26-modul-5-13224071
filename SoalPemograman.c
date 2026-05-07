// Soal Pemograman Modul 5
// Muhammad Aqeel Ghani
// 13224071

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Struktur data untuk Node Tree nya
typedef struct Node{
    char Nama[100];
    struct Node *anak1, *anak2, *orangTua;
} Node;

// Fungsi Pencari LCA (Lowest Common Ancestor)
Node* LCA (Node *root, char *nama1, char *nama2){
    // Jika merupakan ujung tree
    if (root == NULL) return NULL;

    // Jika root merupakan salah satu keturunan yang dicari
    if ((strcmp(root->Nama, nama1) == 0) || (strcmp(root->Nama, nama2) == 0)) return root;

    Node *anak1LCA = LCA(root->anak1, nama1, nama2);
    Node *anak2LCA = LCA(root->anak2, nama1, nama2);

    // Jika kedua anak merupakan leluhur dari keturunan yang dicari, maka root ini merupakan LCA
    // (Berjalan/terpenuhi jika kedua variabel bukan NULL)
    if (anak1LCA && anak2LCA) return root;

    // Jika Ternyata Salah satu anaknya merupakan keturunan yang dicari, apakah dia juga leluhur keturunan yang lain
    // Jika iya, maka orangtuanya adalah LCA
    else if (anak1LCA != NULL) if ((strcmp(anak1LCA->Nama, nama1) == 0) || (strcmp(anak1LCA->Nama, nama2) == 0)) if (LCA(anak1LCA->anak1, nama1, nama2) || LCA(anak1LCA->anak2, nama1, nama2)) return root;
    else if (anak2LCA != NULL) if ((strcmp(anak2LCA->Nama, nama1) == 0) || (strcmp(anak2LCA->Nama, nama2) == 0)) if (LCA(anak2LCA->anak1, nama1, nama2) || LCA(anak2LCA->anak2, nama1, nama2)) return root;

    // Mengembalikan pointer anak yang bukan NULL (Jika ada)
    return (anak1LCA != NULL) ? anak1LCA : anak2LCA;
}

// Fungsi Create Node
Node* CreateNode(char *nama, Node *orangTua){
    Node *newNode = malloc(sizeof(Node));

    strcpy(newNode->Nama, nama);
    newNode->anak1 = NULL;
    newNode->anak2 = NULL;
    newNode->orangTua = orangTua;

    return newNode;
}

// Fungsi Pembuat Tree (Sesuai dengan ilustrasi soal)
Node* CreateTree(){
    // Generasi Pertama
    Node* root = CreateNode("Yoru", NULL);

    // Generasi Kedua
    root->anak1 = CreateNode("Reyna", root);
    root->anak2 = CreateNode("Killjoy", root);

    // Generasi Ketiga
    root->anak1->anak1 = CreateNode("Omen", root->anak1);
    root->anak1->anak2 = CreateNode("Breach", root->anak1);

    root->anak2->anak1 = CreateNode("Clove", root->anak2);
    root->anak2->anak2 = CreateNode("Brimstone", root->anak2);

    // Generasi Keempat
    root->anak2->anak1->anak1 = CreateNode("Cypher", root->anak2->anak1);
    root->anak2->anak1->anak2 = CreateNode("Vyse", root->anak2->anak1);

    return root;
}

// Fungsi Main
int main(){
    // Pendefinisian dan inisialisasi Variabel
    Node *pohonKeluarga = CreateTree();
    char nama1[100], nama2[100];

    // Pengambilan Input
    printf("Masukkan orang pertama: ");
    scanf("%s", nama1);

    printf("Masukkan orang kedua: ");
    scanf("%s", nama2);

    // Mencari LCA
    Node *lca = LCA(pohonKeluarga, nama1, nama2);

    // Print hasil
    printf("Leluhur mereka adalah %s.\n", lca->Nama);

    return 0;
}

// Referensi
// https://www.geeksforgeeks.org/dsa/lowest-common-ancestor-binary-tree-set-1/