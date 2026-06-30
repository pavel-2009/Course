#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Task {
    int id;
    char text[100];
    struct Task *next;
};


struct Task* add_task(struct Task* head, int id, char *text) {

    struct Task* new_task = (struct Task*) malloc(sizeof(struct Task));
    if (new_task == NULL) {
        printf("Ошибка при выделении памяти.");
        return NULL;
    };

    new_task->id = id;
    strncpy(new_task->text, text, sizeof(new_task->text) - 1);
    new_task->text[sizeof(new_task->text) - 1] = '\0';
    new_task->next = head;

    return new_task;
}


void save_to_file(struct Task *head, char *filename) {

    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    };

    struct Task* current = head;

    while (current != NULL) {
        fprintf(file, "%d %s\n", current->id, current->text);
        current = current->next;
    };

    fclose(file);
    file = NULL;
}


struct Task* load_from_file(char *filename) {
    struct Task *head = NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL) return NULL;

    int id;
    char text[100];

    while (fscanf(file, "%d %s", &id, text) == 2) {
        head = add_task(head, id, text);
    };

    fclose(file);
    file = NULL;

    return head;
}


int main(int argc, char *args[]) {

    system("chcp 65001"); 

    char *filename = "tasks.txt";

    struct Task *head = load_from_file(filename);

    if (argc >= 2) {
        int new_id = 1;
        if (head != NULL) {
            new_id = head->id + 1;
        };

        head = add_task(head, new_id, args[1]);
        printf("Добавлена задача: [%d] %s\n", new_id, args[1]);
    };

    printf("\n=== ТВОЙ СПИСОК ЗАДАЧ ===\n");

    struct Task *current = head;
    if (current == NULL) printf("Задач пока нет. Добавь: %s \"Текст_задачи\"\n", args[0]);

    while (current != NULL) {
        printf("[%d] %s\n", current->id, current->text);
        current = current->next;
    };

    save_to_file(head, filename);

    current = head;
    while (current != NULL) {
        struct Task *next_task = current->next;
        free(current);
        current = next_task;
    };
    head = NULL;

    return 0;

}
