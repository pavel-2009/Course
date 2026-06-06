#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Track {
    char title[50];
    int duration;
};


struct Track* create_track(char *name, int seconds) {

    struct Track* track = (struct Track*) malloc(sizeof(struct Track));
    if (track == NULL) {
        printf("Память закончилась!\n");
        return NULL;
    };

    strcpy(track->title, name);

    track->duration = seconds;

    return track;
    
}


void print_track(struct Track* track) {
    printf("Трек: %s (%d сек)", track->title, track->duration);
};


int main(int argc, char *args[]) {
    if (argc < 3) {
        printf("Использование: %s [Название] [Время_в_секундах]\n", args[0]);
        return 1;
    }

    char *name = args[1];
    int duration = atoi(args[2]);

    struct Track* track = create_track(name, duration);
    print_track(track);

    free(track);
    track = NULL;

    return 0;
}
