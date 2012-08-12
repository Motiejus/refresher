#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef unsigned Val;

#define MAX_VERTICES 1000
#define MAX_EDGE_LEN 0xfffffff

#define INPUT "input-dijkstra.txt"

int num_v; /* Vertices */
int from, to; /* Our source and destination */
/*
 * key = 0 means infinity
 * parent = -1 means no parent
 */
typedef struct {
    Val key;
    int in_g;
    int parent;
} g_i;

g_i G[MAX_VERTICES];
/*
 * w[i][j] = 0 iff i is not adjacent to j
 */
Val w[MAX_VERTICES][MAX_VERTICES];

int find_smallest();
void read();

void dijkstra() {
    int done = 0;

    while(done < num_v) {
        int i, v = find_smallest();
        G[v].in_g = 0; /* Remove smallest from G */
        done++;
        for (i = 0; i < num_v; i++)
            if (G[i].in_g && w[v][i] != 0 &&
                    (G[v].key + w[v][i] < G[i].key || G[i].key == 0)) {
                G[i].key = G[v].key + w[v][i];
                G[i].parent = v;
            }
    }
}

void print_result() {
    int i = to;
    printf("Length from %c to %c: %u\n", from + 97, to + 97, G[to].key);
    printf("Path:\n");
    while(i != from) {
        printf("%c <- %c\n", i + 97, G[i].parent + 97);
        i = G[i].parent;
    }
}

int main() {
    read();
    dijkstra();
    print_result();
    return 0;
}

int find_smallest() {
    Val min = MAX_EDGE_LEN;
    int i, index = from;
    for (i = 0; i < num_v; i++)
        if (G[i].in_g && G[i].key != 0 && G[i].key < min)
            min = G[index = i].key;

    return index;
}

void read() {
    int i = 0;
    FILE *f = fopen(INPUT, "r");
    char tmp_from, tmp_to;

    fscanf(f, "%d %c %c\n", &num_v, &tmp_from, &tmp_to);
    from = tmp_from - 97;
    to = tmp_to - 97;
    for (i = 0; i < num_v; i++) {
        char from, to;
        Val val;
        G[i].in_g = 1;
        G[i].key = 0;
        G[i].parent = -1;
        fscanf(f, "%c %c %u\n", &from, &to, &val);
        w[from-97][to-97] = val;
        w[to-97][from-97] = val;
    }
    fclose(f);
}

