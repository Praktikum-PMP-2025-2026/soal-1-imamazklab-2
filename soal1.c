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
    for (int j = 0; j < N - 1; j++) {
        for (int i = 0; i < N - 1; i++) {
            if (l[i].skor < l[i + 1].skor ||
                l[i].skor == l[i + 1].skor && l[i].id > l[i + 1].id ||
                l[i].skor == l[i + 1].skor && l[i].id == l[i + 1].id && strcmp(l[i].nama, l[i + 1].nama) > 0
            ) {
                Container temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
            }
        }
    }
}

void separate(Container *l, Container *pagi, int *idxpagi, Container *siang, int *idxsiang, Container *malam, int *idxmalam, int N) {
    *idxpagi = 0;
    *idxsiang = 0;
    *idxmalam = 0;
    for (int i = 0; i < N; i++) {
        if (strcmp(l[i].shift, "PAGI") == 0) {
            pagi[*idxpagi] = l[i];
            *idxpagi = *idxpagi + 1;
        }
        if (strcmp(l[i].shift, "SIANG") == 0) {
            siang[*idxsiang] = l[i];
            *idxsiang = *idxsiang + 1;
        }
        if (strcmp(l[i].shift, "MALAM") == 0) {
            malam[*idxmalam] = l[i];
            *idxmalam = *idxmalam + 1;
        }
    }
}

void display(Container *pagi, int idxpagi, Container *siang, int idxsiang, Container *malam, int idxmalam) {
    if (idxpagi) {
        printf("PAGI ");
        printf("%s %d %d\n", pagi[0].nama, pagi[0].id, pagi[0].skor);
    } else {
        printf("PAGI ");
        printf("-\n");
    }

    if (idxsiang) {
        printf("SIANG ");
        printf("%s %d %d\n", siang[0].nama, siang[0].id, siang[0].skor);
    } else {
        printf("SIANG ");
        printf("-\n");
    }

    if (idxmalam) {
        printf("MALAM ");
        printf("%s %d %d", malam[0].nama, malam[0].id, malam[0].skor);
    } else {
        printf("MALAM ");
        printf("-");
    }
}

int main() {
    int N = 0;
    int idxpagi = 0, idxsiang = 0, idxmalam = 0;
    scanf("%d", &N);

    Container *myData = (Container*) malloc(N * sizeof(Container));
    Container *myDataPagi = (Container*) malloc(N * sizeof(Container));
    Container *myDataSiang = (Container*) malloc(N * sizeof(Container));
    Container *myDataMalam = (Container*) malloc(N * sizeof(Container));

    getInput(myData, N);

    separate(myData, myDataPagi, &idxpagi, myDataSiang, &idxsiang, myDataMalam, &idxmalam, N);
    sorting(myDataPagi, idxpagi);
    sorting(myDataSiang, idxsiang);
    sorting(myDataMalam, idxmalam);

    display(myDataPagi, idxpagi, myDataSiang, idxsiang, myDataMalam, idxmalam);

    free(myData);

    return 0;
}