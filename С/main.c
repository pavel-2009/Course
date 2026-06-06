#include <stdio.h>

int my_strlen(char *str) {

    int len = 0;

    int i = 0;

    while (str[i] != '\0')
    {
        len += 1;
        i += 1;
    }
    
    return len;
}

void my_strcpy(char *dest, char *src) {
    
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i += 1;
    };
}

int main() {
    char s1[] = "Hello";
    char s2[10]; // Выделили массив с запасом под копию

    // Тестируем strlen
    printf("Длина s1: %d\n", my_strlen(s1)); // Должно вывести: 5

    // Тестируем strcpy
    my_strcpy(s2, s1);
    printf("Скопированная строка s2: %s\n", s2); // Должно вывести: Hello

    return 0;
}