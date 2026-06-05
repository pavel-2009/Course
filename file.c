#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Ошибка: Передайте число при запуске программы.\n");
        return 1;
    };

    int age = atoi(argv[1]);

    // Запись в файл
    FILE *file = fopen("age.txt", "w");

    if (file == NULL) {
        printf("Ошибка: Не удалось создать или открыть файл для записи!\n");
        return 1;
    };

    fprintf(file, "Age: %d\n", age);

    fclose(file);
    file = NULL;

    // Чтение из файла
    FILE *file_in = fopen("age.txt", "r");

    if (file_in == NULL) {
        printf("Ошибка: Файл не найден для чтения!\n");
        return 1;
    };

    char label[20];
    int parsed_age;

    fscanf(file_in, "%s %d", label, &parsed_age);

    fclose(file_in);
    file_in = NULL;

    printf("Данные успешно прочитаны из файла!\n");
    printf("Метка: %s, Значение: %d\n", label, parsed_age);

    return 1;
}
