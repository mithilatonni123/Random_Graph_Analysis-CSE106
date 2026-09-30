#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10000

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

int main(void) {
    int n;
    clock_t start, end;

    printf("Enter n vertices: ");
    scanf("%d", &n);
    printf("\n");

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices. Enter a value between 1 and %d.\n",
               MAX_VERTICES);
        return 1;
    }

    srand((unsigned int)time(NULL));
    start = clock();

    /* Generate a randomly generated undirected graph
       using an adjacency matrix. */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int rand_num = rand() % 2;
            adj_matrix[i][j] = rand_num;
            adj_matrix[j][i] = rand_num;
        }
    }

    /* Count the number of edges. */
    int edges_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                edges_count++;
            }
        }
    }

    printf("Number of edges in the graph: %d\n", edges_count);

    /* Calculate the degree of every vertex. */
    printf("Degree of vertices:\n");

    int total_degree = 0;

    for (int i = 0; i < n; i++) {
        int degree = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) {
                degree += 2 * adj_matrix[i][j];
            } else {
                degree += adj_matrix[i][j];
            }
        }

        total_degree += degree;
        printf("Degree %d: %d\n", i + 1, degree);
    }

    printf("Total degree of the whole graph: %d\n", total_degree);

    /* Handshaking theorem check:
       Sum of all vertex degrees = 2 * number of edges. */
    int handshaking = total_degree / 2;

    if (edges_count == handshaking) {
        printf("Handshaking theorem is proved\n");
    } else {
        printf("Handshaking theorem check failed\n");
    }

    end = clock();

    double duration =
        ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("\nComputational time = %.2f ms\n", duration);

    return 0;
}
