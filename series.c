#include <stdio.h>

int findMax(int array[], int size) {
   int max = array[0]; // En büyük sayıyı ilk eleman olarak varsayalım

   for (int i = 1; i < size; i++) {
      if (array[i] > max) {
         max = array[i]; // Dizi içindeki daha büyük bir sayı bulunursa en büyük olarak güncellenir
      }
   }

   return max; // En büyük sayıyı döndürür
}

int main() {
   int array[] = {55, 27, 2, 34, 46, 44, 35, 38, 6,}; // Örnek dizi
   int size = sizeof(array) / sizeof(array[0]); // Dizinin boyutunu hesaplar

   int maxNumber = findMax(array, size);

   printf("En büyük sayı: %d\n", maxNumber);

   return 0;
}
