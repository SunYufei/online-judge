#include <bits/stdc++.h>
using namespace std;

const int M = 1000000;

FILE* f1;
FILE* f2;

int vertex_num = 0;
int edge_num = 0;

int u, v, od, pv, pe;

int query_num = 0;

int handel_model = 0;

int a, b, c, x, y, src, dist;
int max_q2_rst = -1;

// BFS
int* currentQueue;        // act as a queue read
int* nextQueue;           // modify
int currentEnd, nextEnd;  // pointer of two queue modify
char* visited;            // modify

// linklist
struct MyVertex {
    int pv;
    int outdegree;
    int* outvertex;
    int* outvertexPE;
};
MyVertex* vertex;

// linklist

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        ;  // printf("argv[%d] : %s\n", i, argv[i]);
    }

    // in.graph
    f1 = fopen(argv[1], "r");

    // vertex_num
    fscanf(f1, "%d", &vertex_num);
    // printf("vertex_num : %d\n", vertex_num);
    vertex = (MyVertex*)malloc(sizeof(MyVertex) * vertex_num);

    // PV
    for (int i = 0; i < vertex_num; i++) {
        fscanf(f1, "%d", &pv);
        vertex[i].pv = pv;
    }

    // for(int i=0; i<vertex_num; i++)
    // printf("%d\t", vertex[i].pv);
    // printf("\n");

    // edge_num
    fscanf(f1, "%d", &edge_num);
    // printf("edge_num : %d\n", edge_num);

    // outvertex
    int count = 0;
    for (int i = 0; i < vertex_num; i++) {
        fscanf(f1, "%d", &od);
        vertex[i].outdegree = od;
        vertex[i].outvertex = (int*)malloc(sizeof(int) * vertex[i].outdegree);
        vertex[i].outvertexPE = (int*)malloc(sizeof(int) * vertex[i].outdegree);
        for (int j = 0; j < od; j++) {
            fscanf(f1, "%d%d", &v, &pe);
            vertex[i].outvertex[j] = v;
            vertex[i].outvertexPE[j] = pe;
            count++;
        }
    }
    if (count != edge_num)
        printf("ERROR 1 !!!\n");
    /*
    for(int i=0; i<vertex_num; i++)
    {
            printf("%d : %d : ", i, vertex[i].outdegree);
            for(int j=0; j<vertex[i].outdegree; j++)
            {
                    printf("%d %d ", vertex[i].outvertex[j],
    vertex[i].outvertexPE[j]);
            }
            printf("\n");
    }
    */

    fclose(f1);

    // printf("graph read in finished\n");

    currentQueue =
        (int*)malloc(sizeof(int) * vertex_num);          // act as a queue read
    nextQueue = (int*)malloc(sizeof(int) * vertex_num);  // modify
    visited = (char*)malloc(sizeof(char) * vertex_num);  // modify
    memset(currentQueue, 0, sizeof(int) * vertex_num);
    memset(nextQueue, 0, sizeof(int) * vertex_num);
    memset(visited, 0, sizeof(char) * vertex_num);

    // in.query
    // ifstream fin(argv[2]);
    string s;

    // query_num
    // cin >> s;
    getline(cin, s);
    // getline(fin,s);
    query_num = atoi(s.c_str());
    // printf("query_num : %d\n", query_num);

    count = 0;
    int compare_count = 0;
    int error_count = 0;
    // f2 = fopen(argv[3], "r");

    // while ( getline(fin,s) )
    while (count < query_num) {
        getline(cin, s);
        // cout << s << endl;
        count++;
        // cout << s[0] << s[1] << endl;
        if (s[0] == 'u')
            handel_model = s[1] - '0';
        else if (s[0] == 'q')
            handel_model = s[1] - '0' + 3;
        else
            printf("ERROR 3 !!!\n");

        // handel_model = 0;

        // cout << s[0] << s[1] << " : " <<handel_model << '\t';

        const char* ss = s.c_str();

        if (handel_model == 1) {  // u1 a b
            sscanf(ss + 2, "%d%d", &a, &b);
            // cout << a << ' ' << b;
            for (int i = 0; i < vertex_num; i++) {
                if (vertex[i].pv % a == 0) {
                    vertex[i].pv += b;
                    if (vertex[i].pv > M)
                        vertex[i].pv -= M;
                }
            }
        } else if (handel_model == 2) {  // u2 a b
            sscanf(ss + 2, "%d%d", &a, &b);
            // cout << a << ' ' << b;
            for (int i = 0; i < vertex_num; i++) {
                int src_outdegree = vertex[i].outdegree;  // src_outdegree
                for (int j = 0; j < src_outdegree; j++) {
                    if (vertex[i].outvertexPE[j] % a == 0) {
                        vertex[i].outvertexPE[j] += b;
                        if (vertex[i].outvertexPE[j] > M)
                            vertex[i].outvertexPE[j] -= M;
                    }
                }
            }
        } else if (handel_model == 3) {  // u3 a b c
            sscanf(ss + 2, "%d%d%d", &a, &b, &c);
            // cout << a << ' ' << b << ' ' << c;
            for (int i = 0; i < vertex_num; i++) {
                if (vertex[i].pv % a == 0) {
                    int src_outdegree = vertex[i].outdegree;  // src_outdegree
                    for (int j = 0; j < src_outdegree; j++)
                        if (vertex[i].outvertexPE[j] % b == 0) {
                            vertex[i].outvertexPE[j] += c;
                            if (vertex[i].outvertexPE[j] > M)
                                vertex[i].outvertexPE[j] -= M;
                        }
                }
            }
        } else if (handel_model == 4) {  // q1 u v x y
            sscanf(ss + 2, "%d%d%d%d", &u, &v, &x, &y);
            // cout << u << ' ' << v << ' ' << x << ' ' << y;

            int rst = 0;

            for (int i = u; i <= v; i++) {
                int src_vertex = i;  // src_vertex
                int src_outdegree =
                    vertex[src_vertex].outdegree;  // src_outdegree
                for (int j = 0; j < src_outdegree; j++) {
                    if (vertex[src_vertex].outvertexPE[j] >= x &&
                        vertex[src_vertex].outvertexPE[j] <= y) {
                        rst++;
                    }
                }
            }
            /*
            int ans = 0;
            fscanf(f2, "%d", &ans);
            compare_count++;
            if(ans != rst)
            {
                    printf("q1 error : %d %d %d\n", compare_count, ans, rst);
                    error_count ++;
            }
            */
            cout << rst << endl;
        } else if (handel_model == 5) {  // q2 s d u v x y
            sscanf(ss + 2, "%d%d%d%d%d%d", &src, &dist, &u, &v, &x, &y);
            // cout << src << ' ' << dist << ' ' << u << ' ' << v << ' ' << x <<
            // ' ' << y;

            // BFS
            int rst = 0;
            int now_dist = 0;
            memset(visited, 0, sizeof(char) * vertex_num);
            currentEnd = 0;
            nextEnd = 0;

            if ((vertex[src].pv >= u) && (vertex[src].pv <= v)) {
                // cout << 0 << endl;
                visited[src] = 1;
                currentQueue[currentEnd] = src;
                currentEnd++;
            }

            while ((now_dist < dist) && (currentEnd > 0)) {
                now_dist++;
                for (int i = 0; i < currentEnd; i++) {
                    int src_vertex = currentQueue[i];  // src_vertex
                    int src_outdegree =
                        vertex[src_vertex].outdegree;  // src_outdegree
                    for (int j = 0; j < src_outdegree; j++) {
                        int dst_vertex = vertex[src_vertex].outvertex[j];
                        if (visited[dst_vertex] == 0)
                            if (vertex[src_vertex].outvertexPE[j] >= x &&
                                vertex[src_vertex].outvertexPE[j] <= y)
                                if (vertex[dst_vertex].pv >= u &&
                                    vertex[dst_vertex].pv <= v) {
                                    visited[dst_vertex] = 1;
                                    nextQueue[nextEnd] = dst_vertex;
                                    nextEnd++;
                                }
                    }
                }

                int* temp_q = currentQueue;
                currentQueue = nextQueue;
                nextQueue = temp_q;
                currentEnd = nextEnd;
                nextEnd = 0;
            }

            for (int i = 0; i < vertex_num; i++) {
                if (visited[i] == 1) {
                    rst++;
                }
            }

            if (max_q2_rst < rst)
                max_q2_rst = rst;

            /*
            int ans = 0;
            fscanf(f2, "%d", &ans);
            compare_count++;
            if(ans != rst)
            {
                    error_count ++;
                    printf("q2 error : %d %d %d\n", compare_count, ans, rst);
            }
            */
            cout << rst << endl;
        }

        // cout << endl;
    }
    // fin.close();

    // printf("count : %d\n", count);

    if (count != query_num)
        printf("ERROR 2 !!!\n");

    // printf("error_count : %d\n\n", error_count);
    // printf("max_q2_rst : %d\n\n", max_q2_rst);

    // printf("query finished\n");

    return 0;
}
