#include "solve.h"
#include <bits/stdc++.h>
using namespace std;

const int MY_MAX_EDGE_NUM = 200000000;
int handel_model = 0; // 0:link_list	1:compress

FILE *fp1;
FILE *fp2;
FILE *fp3;
FILE *fp4;

int vertex_num = 0;
int edge_num = 0;

int *outdegree;

int *buffer;
const int BUFFER_LEN = 1000000;
const int EDGE_LEN = 500000;
int buffer_idx = 0;

int u, v;

// linklist
typedef struct tagMyVertex {
    int outdegree;
    int *outvertex;
} MyVertex;
MyVertex *vertex;

int comp(const void *a, const void *b) { //用来做比较的函数。
    return *(int *)a - *(int *)b;
}
// linklist

// compress 1
const int COMPRESS_NUM = 2;
const int COMPRESS_LENGTH = 32 / COMPRESS_NUM; // 16
// 32768	// 2 ^ (COMPRESS_LENGTH-1)
const int THRESHOLD = 0x01 << (COMPRESS_LENGTH - 1);

typedef struct comMyVertex {
    int outdegree;
    int *outvertex;
} ComVertex;
ComVertex *com_vertex;

int compress_int = 0;
int compress_int_idx = 0;
int to_or = 0x00000001 << (COMPRESS_LENGTH - 1); // compress
int to_and = 0x7fffffff;                         // decompress
int compress_before = 0;
int compress_after = 0;
int com_outvertex_idx = 0;

int *buffer_outvertex;

// compress 1

// BFS
int *currentQueue;       // act as a queue read
int *nextQueue;          // modify
int currentEnd, nextEnd; // pointer of two queue modify
char *visited;           // modify
int rst_id, rst_parent, rst_dist, rst_undiscoverd;
// BFS

void my_init_link_list(int argc, char **argv) {
    // printf("my_init_link_list\n");
    // outdegree
    outdegree = (int *)malloc(sizeof(int) * vertex_num);
    memset(outdegree, 0, sizeof(int) * vertex_num);

    buffer = (int *)malloc(sizeof(int) * BUFFER_LEN);
    memset(buffer, 0, sizeof(int) * BUFFER_LEN);

    int count = 0;
    int buffer_use = 0;
    int edge_left = edge_num;
    int buffer_read = 0;
    int edge_read = 0;
    fp2 = fopen(argv[2], "rb");
    while (edge_left != 0) {
        buffer_read = BUFFER_LEN;
        if (edge_left < EDGE_LEN)
            buffer_read = edge_left * 2;
        edge_read = buffer_read / 2;
        fread(buffer, sizeof(int), buffer_read, fp2);

        int i = 0;
        while (i < buffer_read) {
            u = buffer[i];
            v = buffer[i + 1];
            i += 2;

            outdegree[u]++;
        }

        edge_left -= edge_read;
        buffer_use += buffer_read;
        count++;
    }
    fclose(fp2);
    // printf("   count : %d : %d %d\n", count, u, v);
    // printf("   buffer_use : %d\n", buffer_use);

    int sum = 0;
    int i = 0;
    for (i = 0; i < vertex_num; i++) {
        sum += outdegree[i];
    }
    // printf("\tsum_degree1 : %d\n", sum);
    // outdegree finish

    // link_list
    vertex = (MyVertex *)malloc(sizeof(MyVertex) * vertex_num);
    for (i = 0; i < vertex_num; i++) {
        vertex[i].outdegree = 0;
        vertex[i].outvertex = (int *)malloc(sizeof(int) * outdegree[i]);
        memset(vertex[i].outvertex, 0, sizeof(int) * outdegree[i]);
    }

    sum = 0;
    for (i = 0; i < vertex_num; i++)
        sum += vertex[i].outdegree;
    // printf("\tsum_degree2 : %d\n", sum);

    count = 0;
    buffer_use = 0;
    edge_left = edge_num;
    buffer_read = 0;
    edge_read = 0;
    fp3 = fopen(argv[2], "rb");
    while (edge_left != 0) {
        buffer_read = BUFFER_LEN;
        if (edge_left < EDGE_LEN)
            buffer_read = edge_left * 2;
        edge_read = buffer_read / 2;
        fread(buffer, sizeof(int), buffer_read, fp3);

        int i = 0;
        int idx = -1;
        while (i < buffer_read) {
            u = buffer[i];
            v = buffer[i + 1];
            i += 2;

            idx = vertex[u].outdegree;
            vertex[u].outvertex[idx] = v;
            vertex[u].outdegree++;
        }

        edge_left -= edge_read;
        buffer_use += buffer_read;
        count++;
    }
    fclose(fp3);
    // printf("   count : %d : %d %d\n", count, u, v);
    // printf("   buffer_use : %d\n", buffer_use);

    sum = 0;
    for (i = 0; i < vertex_num; i++) {
        if (vertex[i].outdegree != outdegree[i])
            printf("ERROR!!!!!\n");
        sum += vertex[i].outdegree;
    }
    // printf("\tsum_degree3 : %d\n", sum);

    /*
            int rub = vertex[0].outvertex[2];
            vertex[0].outvertex[2] = vertex[0].outvertex[5];
            vertex[0].outvertex[5] = rub;
    */

    int tmp = vertex[vertex_num - 1].outdegree;
    /*
    printf("vertex[%d].outdegree : %d\n\t", vertex_num-1,
    vertex[vertex_num-1].outdegree); for(i=0; i<tmp; i++) printf("%d ",
    vertex[vertex_num-1].outvertex[i]); printf("\n");
    */

    // sort
    for (i = 0; i < vertex_num; i++) {
        int temp = vertex[i].outdegree;
        if (temp > 1) {
            int j;
            for (j = 1; j < temp; j++)
                if (vertex[i].outvertex[j - 1] >= vertex[i].outvertex[j])
                    printf("ERROR1 !!!\n");
        }

        qsort(vertex[i].outvertex, vertex[i].outdegree, sizeof(int), comp);

        temp = vertex[i].outdegree;
        if (temp > 1) {
            int j;
            for (j = 1; j < temp; ++j)
                if (vertex[i].outvertex[j - 1] >= vertex[i].outvertex[j])
                    printf("ERROR2 !!!\n");
        }
    }

    // BFS
    // act as a queue read
    currentQueue = (int *)malloc(sizeof(int) * vertex_num);
    nextQueue = (int *)malloc(sizeof(int) * vertex_num); // modify
    visited = (char *)malloc(sizeof(char) * vertex_num); // modify
    memset(currentQueue, 0, sizeof(int) * vertex_num);
    memset(nextQueue, 0, sizeof(int) * vertex_num);
    memset(visited, 0, sizeof(char) * vertex_num);
    // BFS
}

void my_init_compress(int argc, char **argv) {
    // printf("my_init_compress\n");

    // outdegree
    outdegree = (int *)malloc(sizeof(int) * vertex_num);
    memset(outdegree, 0, sizeof(int) * vertex_num);

    buffer = (int *)malloc(sizeof(int) * BUFFER_LEN);
    memset(buffer, 0, sizeof(int) * BUFFER_LEN);

    int count = 0;
    int buffer_use = 0;
    int edge_left = edge_num;
    int buffer_read = 0;
    int edge_read = 0;
    fp2 = fopen(argv[2], "rb");
    while (edge_left != 0) {
        buffer_read = BUFFER_LEN;
        if (edge_left < EDGE_LEN)
            buffer_read = edge_left * 2;
        edge_read = buffer_read / 2;
        fread(buffer, sizeof(int), buffer_read, fp2);

        int i = 0;
        while (i < buffer_read) {
            u = buffer[i];
            v = buffer[i + 1];
            i += 2;

            ++outdegree[u];
        }

        edge_left -= edge_read;
        buffer_use += buffer_read;
        ++count;
    }
    fclose(fp2);
    // printf("   count : %d : %d %d\n", count, u, v);
    // printf("   buffer_use : %d\n", buffer_use);

    int sum = 0;
    int i = 0;
    for (i = 0; i < vertex_num; ++i)
        sum += outdegree[i];

    // printf("\tsum_degree1 : %d\n", sum);
    // outdegree finish

    // compress
    // printf("\ncompress:\n%d %d %d\n", COMPRESS_NUM, COMPRESS_LENGTH,
    // THRESHOLD);

    buffer_outvertex = (int *)malloc(sizeof(int) * BUFFER_LEN);
    memset(buffer_outvertex, 0, sizeof(int) * BUFFER_LEN);

    fp3 = fopen(argv[2], "rb");

    com_vertex = (ComVertex *)malloc(sizeof(ComVertex) * vertex_num);
    buffer_idx = 0;
    int tmp_degree = 0;
    int delta = 0;
    for (i = 0; i < vertex_num; i++) {
        buffer_idx = 0;
        tmp_degree = outdegree[i];
        com_vertex[i].outdegree = outdegree[i];

        fread(buffer_outvertex, sizeof(int), tmp_degree * 2, fp3);

        int j;
        if (tmp_degree >= 1) {
            buffer[buffer_idx] = buffer_outvertex[1]; // 0
            buffer_idx++;
            compress_int = 0;
            compress_int_idx = 0;
            // compress 1
            for (j = 1; j < tmp_degree; j++) {
                delta =
                    buffer_outvertex[j * 2 + 1] - buffer_outvertex[j * 2 - 1];
                if (delta < THRESHOLD) { // can be compressed
                    if (compress_int_idx < COMPRESS_NUM - 1) {
                        delta = delta | to_or;
                        int to_shift = (COMPRESS_NUM - 1 - compress_int_idx) *
                                       COMPRESS_LENGTH;
                        delta = delta << to_shift;
                        compress_int = compress_int | delta;
                        compress_int_idx++;
                    } else if (compress_int_idx == COMPRESS_NUM - 1) {
                        delta = delta | to_or; //  | 0x80
                        compress_int = compress_int | delta;
                        compress_int_idx = 0;
                        buffer[buffer_idx] = compress_int;
                        compress_int = 0;
                        buffer_idx++;
                    }
                } else { // can not be compressed
                    if (compress_int_idx != 0) {
                        buffer[buffer_idx] = compress_int;
                        compress_int = 0;
                        compress_int_idx = 0;
                        buffer_idx++;
                    }
                    buffer[buffer_idx] = buffer_outvertex[j * 2 + 1];
                    buffer_idx++;
                }
            }
            if (compress_int_idx != 0) {
                buffer[buffer_idx] = compress_int;
                compress_int = 0;
                compress_int_idx = 0;
                buffer_idx++;
            }
            int k;
            com_vertex[i].outvertex = (int *)malloc(sizeof(int) * buffer_idx);
            for (k = 0; k < buffer_idx; k++) {
                com_vertex[i].outvertex[k] = buffer[k];
            }
            compress_before += com_vertex[i].outdegree;
            compress_after += buffer_idx;
        }
    }

    fclose(fp3);

    double ratio = ((double)compress_before) / ((double)compress_after);
    // printf("compress from %d to %d : %lf x\n\n", compress_before,
    // compress_after, ratio);
    // compress finish

    // BFS

    // act as a queue read
    currentQueue = (int *)malloc(sizeof(int) * vertex_num);
    nextQueue = (int *)malloc(sizeof(int) * vertex_num); // modify
    visited = (char *)malloc(sizeof(char) * vertex_num); // modify
    memset(currentQueue, 0, sizeof(int) * vertex_num);
    memset(nextQueue, 0, sizeof(int) * vertex_num);
    memset(visited, 0, sizeof(char) * vertex_num);
    // BFS
}

void my_bfs_link_list(int argc, char **argv, int begin_vertex) {
    rst_id = begin_vertex;
    rst_parent = -1;
    rst_dist = 0;
    rst_undiscoverd = 0;
    memset(visited, 0, sizeof(char) * vertex_num);

    currentQueue[0] = begin_vertex;
    visited[begin_vertex] = 1;
    currentEnd = 1;
    nextEnd = 0;
    int now_dist = 0;

    int i, j;

    while (currentEnd > 0) {
        now_dist++;
        for (i = 0; i < currentEnd; ++i) {
            int src_vertex = currentQueue[i];                 // src_vertex
            int src_outdegree = vertex[src_vertex].outdegree; // src_outdegree
            for (j = 0; j < src_outdegree; ++j) {
                int dst_vertex = vertex[src_vertex].outvertex[j];
                if (visited[dst_vertex] == 0) {
                    visited[dst_vertex] = 1;
                    nextQueue[nextEnd] = dst_vertex;
                    ++nextEnd;

                    if ((dst_vertex > rst_id) || (now_dist > rst_dist)) {
                        rst_id = dst_vertex;
                        rst_dist = now_dist;
                    }
                }
            }
        }

        int *temp_q = currentQueue;
        currentQueue = nextQueue;
        nextQueue = temp_q;
        currentEnd = nextEnd;
        nextEnd = 0;
    }

    for (i = 0; i < vertex_num; ++i)
        if (visited[i] == 0)
            ++rst_undiscoverd;

    MAIN_output(rst_id, rst_dist, rst_undiscoverd);
}

void my_bfs_compress(int argc, char **argv, int begin_vertex) {
    rst_id = begin_vertex;
    rst_parent = -1;
    rst_dist = 0;
    rst_undiscoverd = 0;
    memset(visited, 0, sizeof(char) * vertex_num);

    currentQueue[0] = begin_vertex;
    visited[begin_vertex] = 1;
    currentEnd = 1;
    nextEnd = 0;
    int now_dist = 0;

    int i, j;

    while (currentEnd > 0) {
        ++now_dist;

        for (i = 0; i < currentEnd; i++) {
            int src_vertex = currentQueue[i]; // src_vertex
            int src_outdegree =
                com_vertex[src_vertex].outdegree; // src_outdegree

            // decompress to get src_outvertex
            compress_int = 0;
            compress_int_idx = 0;

            if (src_outdegree > 0) {
                buffer_idx = 0;
                com_outvertex_idx = 0;
                buffer[buffer_idx] =
                    com_vertex[src_vertex].outvertex[com_outvertex_idx];
                ++buffer_idx;
                ++com_outvertex_idx;

                compress_int = 0;
                int compress_temp_data = 0;
                int tmp8 = 0;
                int left_shift = COMPRESS_LENGTH;
                int right_shift = (COMPRESS_NUM - 1) * COMPRESS_LENGTH;
                while (buffer_idx < src_outdegree) {
                    compress_int =
                        com_vertex[src_vertex].outvertex[com_outvertex_idx];
                    if (compress_int < 0) { // flag:1 compress
                        int jj;
                        for (jj = 0; jj < COMPRESS_NUM; jj++) {
                            tmp8 = compress_int;
                            if (tmp8 == 0)
                                break;
                            tmp8 = tmp8 & to_and;
                            tmp8 = tmp8 >> right_shift;
                            buffer[buffer_idx] = buffer[buffer_idx - 1] + tmp8;
                            buffer_idx++;
                            compress_int = compress_int << left_shift;
                        }
                    } else { // flag:0 did not compress
                        buffer[buffer_idx] =
                            com_vertex[src_vertex].outvertex[com_outvertex_idx];
                        buffer_idx++;
                    }
                    ++com_outvertex_idx;
                }

                // BFS
                for (j = 0; j < src_outdegree; j++) {
                    int dst_vertex = buffer[j];
                    if (visited[dst_vertex] == 0) {
                        visited[dst_vertex] = 1;
                        nextQueue[nextEnd] = dst_vertex;
                        ++nextEnd;

                        if ((dst_vertex > rst_id) || (now_dist > rst_dist)) {
                            rst_id = dst_vertex;
                            rst_dist = now_dist;
                        }
                    }
                }

                // BFS
            }
        }

        int *temp_q = currentQueue;
        currentQueue = nextQueue;
        nextQueue = temp_q;
        currentEnd = nextEnd;
        nextEnd = 0;
    }

    for (i = 0; i < vertex_num; i++)
        if (visited[i] == 0)
            ++rst_undiscoverd;

    MAIN_output(rst_id, rst_dist, rst_undiscoverd);
}

void my_init(int argc, char **argv) {
    fp1 = fopen(argv[1], "r");
    fscanf(fp1, "%d", &vertex_num);
    fscanf(fp1, "%d", &edge_num);
    fclose(fp1);

    if (edge_num > MY_MAX_EDGE_NUM)
        handel_model = 1;
    else
        handel_model = 0;

    if (handel_model == 0)
        my_init_link_list(argc, argv);
    else if (handel_model == 1)
        my_init_compress(argc, argv);
}

void my_solve(int argc, char **argv, int begin_vertex) {
    if (handel_model == 0)
        my_bfs_link_list(argc, argv, begin_vertex);
    else if (handel_model == 1)
        my_bfs_compress(argc, argv, begin_vertex);
}
