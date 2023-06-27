#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Node {
   char data[MAX_SIZE];
   struct Node* children[26]; // Her harf için bir çocuk düğümü
};

struct Node* createNode() {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   strcpy(newNode->data, "");
   for (int i = 0; i < 26; i++) {
      newNode->children[i] = NULL;
   }
   return newNode;
}

void insertWord(struct Node* root, char* word) {
   struct Node* current = root;

   for (int i = 0; i < strlen(word); i++) {
      int index = word[i] - 'a';

      if (current->children[index] == NULL) {
         current->children[index] = createNode();
      }

      current = current->children[index];
   }

   strcpy(current->data, word);
}

void searchWords(struct Node* root, char* prefix) {
   struct Node* current = root;

   for (int i = 0; i < strlen(prefix); i++) {
      int index = prefix[i] - 'a';

      if (current->children[index] == NULL) {
         return;
      }

      current = current->children[index];
   }

   if (strcmp(current->data, "") != 0) {
      printf("%s\n", current->data);
   }

   for (int i = 0; i < 26; i++) {
      if (current->children[i] != NULL) {
         searchWords(current->children[i], prefix);
      }
   }
}

int main() {
   struct Node* root = createNode();

   // Metin listesini oluşturma
   char words[][MAX_SIZE] = {"apple", "application", "banana", "art", "ball", "cat"};
   int numWords = sizeof(words) / sizeof(words[0]);

   // Metin listesini metin ağacına ekleme
   for (int i = 0; i < numWords; i++) {
      insertWord(root, words[i]);
   }

   // Belirli bir metinden başlayan kelimeleri bulma
   char prefix[MAX_SIZE];
   printf("Bir metin girin: ");
   scanf("%s", prefix);

   printf("Belirli bir metinden baslayan kelimeler:\n");
   searchWords(root, prefix);

   return 0;
}
