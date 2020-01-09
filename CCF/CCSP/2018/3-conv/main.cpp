#include "solve.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <thread>

void solve_naive(int W, int H, int N, float *input, float *output) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            float tmp = 0;
            for (int ii = 0; ii < N; ii++)
                for (int jj = 0; jj < N; jj++)
                    tmp += input[(i + ii) * (W + N - 1) + j + jj];

            tmp = tmp / (N * N);
            output[i * W + j] = tmp;
        }
    }
}

void gen_input(int W, int H, int N, float *input) {
    for (int i = 0; i < (W + N - 1) * (H + N - 1); i++)
        input[i] = rand() / (float)RAND_MAX;
}

int check_result(float *x, float *y, int n) {
    const float eps = 1e-5;

    for (int i = 0; i < n; i++) {
        if (fabsf(x[i] - y[i]) > eps)
            return 0;
    }

    return 1;
}

void test(int W, int H, int N) {

    fprintf(stderr, "Begin to test, W = %d, H = %d, N = %d \n", W, H, N);

    float *input = (float *)valloc(sizeof(float) * (W + N - 1) * (H + N - 1));
    float *output_baseline = (float *)valloc(sizeof(float) * W * H);
    float *output = (float *)valloc(sizeof(float) * W * H);

    gen_input(W, H, N, input);

    struct timeval begin, end, result;

    gettimeofday(&begin, NULL);
    solve_naive(W, H, N, input, output_baseline);
    gettimeofday(&end, NULL);

    timersub(&end, &begin, &result);

    float time = result.tv_sec * 1000.0 + result.tv_usec / 1000.0;

    fprintf(stderr, "Time consumed by naive method: %.2fms\n", time);

    gettimeofday(&begin, NULL);
    solve(W, H, N, input, output);
    gettimeofday(&end, NULL);

    timersub(&end, &begin, &result);

    if (check_result(output_baseline, output, W * H))
        fprintf(stderr, "Your result is correct.\n");
    else
        fprintf(stderr, "Your result is wrong.\n");

    time = result.tv_sec * 1000.0 + result.tv_usec / 1000.0;
    fprintf(stderr, "Time consumed by your method: %.2fms\n", time);

    free(input);
    free(output);
    free(output_baseline);
}

int main(int argc, char **argv) {
    srand(0);

    test(8192, 8192, 3);

    return 0;
}
