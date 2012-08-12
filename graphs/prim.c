#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef unsigned Val;

#define MAX_VERTICES 1000
#define MAX_EDGE_LEN 0xfffffff

#define INPUT "input-prim.txt"

int num_v; /* Vertices */

/*
 * key = 0 means infinity
 */
typedef struct {
    int in_g;
    Val key;
} g_i;

g_i G[MAX_VERTICES];
/*
 * w[i][j] = 0 iff i is not adjacent to j
 */
Val w[MAX_VERTICES][MAX_VERTICES];

int find_smallest();
void read();

void prims() {
    int done = 0;

    while(done < num_v) {
        int i, v = find_smallest();
        G[v].in_g = 0; /* Remove smallest from G */
        done++;
        for (i = 0; i < num_v; i++)
            if (G[i].in_g && w[v][i] != 0 && (w[v][i] < G[i].key || G[i].key == 0))
                G[i].key = w[v][i];
    }
}

Val calc_result() {
    int i;
    Val result = 0;
    for (i = 0; i < num_v; i++)
        result += G[i].key;
    return result;
}

int main() {
    Val ret;
    read();
    prims();
    ret = calc_result();
    printf("MSP: %u\n", ret);
    return 0;
}

int find_smallest() {
    Val min = MAX_EDGE_LEN;
    int i, index = 0;
    for (i = 0; i < num_v; i++)
        if (G[i].in_g && G[i].key != 0 && G[i].key < min)
            min = G[index = i].key;

    return index;
}

void read() {
    int i = 0;
    FILE *f = fopen(INPUT, "r");

    fscanf(f, "%d\n", &num_v);
    for (i = 0; i < num_v; i++) {
        char from, to;
        Val val;
        G[i].key = 0;
        G[i].in_g = 1;
        fscanf(f, "%c %c %u\n", &from, &to, &val);
        w[from-97][to-97] = val;
        w[to-97][from-97] = val;
        /*printf("%d %d -> %ld\n", from - 97, to - 97, val);*/
    }
    fclose(f);
}

