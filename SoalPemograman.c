// Soal Pemograman Modul 5
// Muhammad Aqeel Ghani
// 13224071

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Struktur data untuk Node Tree nya
typedef struct Node{
    char Nama[100];
    struct Node *anak1, *anak2;
} Node;

// Fungsi Pencari LCA (Lowest Common Ancestor)
Node* LCA (Node *root, char *nama1, char *nama2){
    // Jika merupakan ujung tree
    if (root == NULL) return NULL;

    // Jika root merupakan salah satu keturunan yang dicari
    if ((strcmp(root->Nama, nama1) == 0) || (strcmp(root->Nama, nama1) == 0)) return root;

    Node *anak1LCA = LCA(root->anak1, nama1, nama2);
    Node *anak2LCA = LCA(root->anak2, nama1, nama2);

    // Jika kedua anak merupakan leluhur dari keturunan yang dicari, maka root ini merupakan LCA
    // (Berjalan/terpenuhi jika kedua variabel bukan NULL)
    if (anak1LCA && anak2LCA) return root;

    // Mengembalikan pointer anak yang bukan NULL (Jika ada)
    return (anak1LCA != NULL) ? anak1LCA : anak2LCA;
}

// Fungsi Create Node
Node* CreateNode(char *nama){
    Node *newNode = malloc(sizeof(Node));

    strcpy(newNode->Nama, nama);
    newNode->anak1 = NULL;
    newNode->anak2 = NULL;

    return newNode;
}

// Fungsi Pembuat Tree (Sesuai dengan ilustrasi soal)
Node* CreateTree(){
    // Generasi Pertama
    Node* root = CreateNode("Yoru");

    // Generasi Kedua
    root->anak1 = CreateNode("Reyna");
    root->anak2 = CreateNode("Killjoy");

    // Generasi Ketiga
    root->anak1->anak1 = CreateNode("Omen");
    root->anak1->anak2 = CreateNode("Breach");

    root->anak2->anak1 = CreateNode("Clove");
    root->anak2->anak2 = CreateNode("Brimstone");

    // Generasi Keempat
    root->anak2->anak1->anak1 = CreateNode("Cypher");
    root->anak2->anak1->anak2 = CreateNode("Vyse");

    return root;
}

int main(){

}

// Referensi
// https://www.geeksforgeeks.org/dsa/lowest-common-ancestor-binary-tree-set-1/