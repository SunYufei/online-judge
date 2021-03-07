#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "solve.h"

#define TEST_NUM 5

// 123 {3,4321,4892,54321,5555555};
static int QW_BFS_vertex[5] = {4892, 3, 4321, 54321, 5555555};

static long QW_init_time_begin, QW_init_time_end, QW_init_time;
static long QW_solve_time_begin, QW_solve_time_end, QW_solve_time;

static FILE* QW_file;
static int QW_vertex_num = 0;
static int QW_edge_num = 0;

static long QW_get_time_ms() {
    struct timeval QW_my_time;  // us
    gettimeofday(&QW_my_time, NULL);
    long QW_runtime_us =
        1000000 * QW_my_time.tv_sec + QW_my_time.tv_usec;     // us
    long QW_runtime_ms = QW_runtime_us / 1000;                // ms
    double QW_runtime_s = ((double)QW_runtime_us) / 1000000;  // s
    // printf("\n\truntime : %.9lf s = %ld us\n\n", runtime_s, runtime_us);
    return QW_runtime_ms;
}

static void QW_init() {
    int i;
    for (i = 0; i < TEST_NUM; i++) {
        QW_BFS_vertex[i] += QW_vertex_num;
        QW_BFS_vertex[i] %= QW_vertex_num;
    }
    /*
    for(i=0; i<TEST_NUM; i++)
    {
            printf("QW_BFS_vertex[%d] : %d\n", i, QW_BFS_vertex[i]);
    }
    printf("\n");
    */
}

void MAIN_output(int id, int dist, int undiscoverd) {
    printf("%d %d %d\n", id, dist, undiscoverd);
}

int main(int argc, char** argv) {
    QW_file = fopen(argv[1], "r");
    fscanf(QW_file, "%d", &QW_vertex_num);
    fscanf(QW_file, "%d", &QW_edge_num);
    fclose(QW_file);
    // printf("QW_vertex_num : %d\n", QW_vertex_num);
    // printf("QW_edge_num : %d\n", QW_edge_num);

    QW_init();

    // my init
    QW_init_time_begin = QW_get_time_ms();
    my_init(argc, argv);
    QW_init_time_end = QW_get_time_ms();
    QW_init_time = QW_init_time_end - QW_init_time_begin;
    // printf("yuchuli %ld us\n", QW_init_time);

    // BFS
    int QW_i;
    QW_solve_time_begin = QW_get_time_ms();
    for (QW_i = 0; QW_i < TEST_NUM; QW_i++) {
        my_solve(argc, argv, QW_BFS_vertex[QW_i]);

        printf("wanchengyige\n");
    }
    QW_solve_time_end = QW_get_time_ms();
    QW_solve_time = QW_solve_time_end - QW_solve_time_begin;
    printf("solve %ld ms\n", QW_solve_time);

    /*
    while(1)
    {
            ;
    }
    */

    return 0;
}
