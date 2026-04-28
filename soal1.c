#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nama[100];
    int id;
    char shift[7];
    int skor;
} Container;

void getInput(Container *l, int N) {
    for (int i = 0; i < N; i++) {
        scanf("%s %d %s %d", l[i].nama, &l[i].id, l[i].shift, &l[i].skor);
    }
}

void sorting(Container *l, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (strcmp(l[i + 1].shift, "PAGI") == 0 && strcmp(l[i].shift, "SIANG") == 0 ||
                strcmp(l[i + 1].shift, "PAGI") == 0 && strcmp(l[i].shift, "MALAM") == 0 ||
                strcmp(l[i + 1].shift, "SIANG") == 0 && strcmp(l[i].shift, "MALAM") == 0
            ) {
                Container temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (strcmp(l[i].shift, l[i + 1].shift) == 0 && l[i].skor < l[i + 1].skor ||
                strcmp(l[i].shift, l[i + 1].shift) == 0 && l[i].skor == l[i + 1].skor && l[i].id > l[i + 1].id ||
                strcmp(l[i].shift, l[i + 1].shift) == 0 && l[i].skor == l[i + 1].skor && l[i].id == l[i + 1].id && strcmp(l[i].nama, l[i + 1].nama) > 0
            ) {
                Container temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
            }
        }
    }
}

void display(Container *l, int N) {
    int pagi = 0, siang = 0, malam = 0;
    int pagit = 0, siangt = 0, malamt = 0;
    for (int i = 0; i < N; i++) {
        if (!pagit) {
            printf("PAGI ");
            if (strcmp(l[i].shift, "PAGI") != 0 && strcmp(l[i].shift, "SIANG") == 0) {
                printf("-\n");
                pagit = 1;
            }
            else {
                printf("%s %d %d\n", l[i].nama, l[i].id, l[i].skor);
                pagit = 1;
            }
            continue;
        }
        if (pagit && !siangt) {
            if (strcmp(l[i].shift, "PAGI") != 0 && strcmp(l[i].shift, "SIANG") != 0 && strcmp(l[i].shift, "MALAM") == 0) {
                printf("SIANG ");
                printf("-\n");
                siangt = 1;
            }
            else if (strcmp(l[i].shift, "SIANG") == 0){
                printf("SIANG ");
                printf("%s %d %d\n", l[i].nama, l[i].id, l[i].skor);
                siangt = 1;
            }
            continue;
        }
        if (pagit && siangt && !malamt) {
            if (strcmp(l[i].shift, "MALAM") == 0) {
                printf("MALAM ");
                printf("%s %d %d", l[i].nama, l[i].id, l[i].skor);
                malamt = 1;
            }
        }
    }

    if (!malamt) {
        printf("MALAM ");
        printf("-");
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);

    Container *myData = (Container*) malloc(N * sizeof(Container));
    getInput(myData, N);
    // for (int i = 0; i < N; i++) {
    //     printf("%s %d %s %d\n", myData[i].nama, myData[i].id, myData[i].shift, myData[i].skor);
    // }
    sorting(myData, N);

    // for (int i = 0; i < N; i++) {
    //     printf("%s %d %s %d\n", myData[i].nama, myData[i].id, myData[i].shift, myData[i].skor);
    // }
    display(myData, N);

    free(myData);
}