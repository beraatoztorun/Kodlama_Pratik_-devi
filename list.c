#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

int countElements(struct Node* head) {
   int count = 0; // Eleman sayacı

   struct Node* current = head; // Listenin başından başla

   while (current != NULL) {
      count++; // Her bir elemanı say

      current = current->next; // Sonraki elemana geç
   }

   return count;
}

int main() {
   struct Node* head = NULL;
   struct Node* second = NULL;
   struct Node* third = NULL;

   // Bağlı liste oluşturma
   head = (struct Node*)malloc(sizeof(struct Node));
   second = (struct Node*)malloc(sizeof(struct Node));
   third = (struct Node*)malloc(sizeof(struct Node));

   head->data = 3;
   head->next = second;

   second->data = 7;
   second->next = third;

   third->data = 11;
   third->next = NULL;

   int elementCount = countElements(head);

   printf("Eleman sayisi: %d\n", elementCount);

   return 0;
}
