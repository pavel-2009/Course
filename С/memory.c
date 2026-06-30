#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *args[]) {

    if (argc < 2) {
        printf("Ошибка: Передайте число N при запуске!\n");
        return 1;
    }
    
    int N = atoi(args[1]);

    int* arr = (int*) malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Система отказала в выделении памяти\n");
        return 1;
    };

    for (int i = 0; i < N; i++)
    {
        arr[i] = i * i;
        printf("%d ", arr[i]);
    };

    free(arr);
    arr = NULL;
    

    return 0;
}