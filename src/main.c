/*main.c*/
#include <stdio.h>
#include <string.h>

// Функция для разворота строки
void reverseString(char *str, int start, int end) {
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

// Функция для разворота слов в строке
void reverseWords(char *str) {
  int start = 0;
  int end = 0;
  int length = strlen(str);

  while (end < length) {
    // Находим начало слова
    while (str[end] != ' ' && str[end] != ',' && str[end] != '\0') {
      end++;
    }
    // Разворачиваем слово
    reverseString(str, start, end - 1);

    // Пропускаем разделители
    while ((str[end] == ' ' || str[end] == ',') && str[end] != '\0') {
      end++;
    }
    start = end;
  }

  // Разворачиваем последнее слово, если оно есть
  reverseString(str, start, end - 1);

  // Разворачиваем всю строку
  reverseString(str, 0, length - 1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  char *str = argv[1];

  printf("Original string: %s\n", str);

  // Разворачиваем слова в строке
  reverseWords(str);

  printf("Reversed string: %s\n", str);

  return 0;
}
