#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void findDuplicates(int array[], int size) {
   int hashTable[MAX_SIZE] = {0}; // Hash tablosu oluşturma

   printf("Tekrar Eden Elemanlar: ");

   for (int i = 0; i < size; i++) {
      hashTable[array[i]]++; // Hash tablosunda elemanları takip et

      if (hashTable[array[i]] > 1) {
         printf("%d ", array[i]); // Tekrar eden elemanları yazdır
      }
   }

   printf("\n");
}

int main() {
   int array[] = {3, 7, 2, 9, 4, 3, 7, 1, 2, 8}; // Örnek dizi
   int size = sizeof(array) / sizeof(array[0]); // Dizinin boyutunu hesapla

   findDuplicates(array, size);

   return 0;
}
