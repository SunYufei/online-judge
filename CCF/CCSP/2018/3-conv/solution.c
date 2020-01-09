#include "simd.h"
#include <stdio.h>
#include <stdlib.h>

void solve(int W, int H, int N, float *input, float *output) {
    const int CHUNK_SIZE = 64;

#pragma omp parallel for
    for (int i = 0; i < H; i += CHUNK_SIZE) {
        float *tmp_buf =
            (float *)malloc(sizeof(float) * W * (CHUNK_SIZE + N - 1));

        for (int ii = 0; ii < CHUNK_SIZE + N - 1 && i + ii < H + N - 1; ++ii) {
            float tmp = 0;
            for (int jj = 0; jj < N; ++jj)
                tmp += input[(i + ii) * (W + N - 1) + jj];

            tmp_buf[ii * W] = tmp;

            for (int j = 1; j < W; ++j)
                tmp_buf[ii * W + j] = tmp_buf[ii * W + (j - 1)] -
                                      input[(i + ii) * (W + N - 1) + (j - 1)] +
                                      input[(i + ii) * (W + N - 1) + j + N - 1];

            for (int j = 0; j < W; ++j)
                tmp_buf[ii * W + j] /= N;
        }

        for (int j = 0; j < W; ++j) {
            float tmp = 0;
            for (int jj = 0; jj < N; ++jj)
                tmp += tmp_buf[jj * W + j];

            output[i * W + j] = tmp / N;
        }

        for (int ii = 1; ii < CHUNK_SIZE && i + ii < H; ++ii)
            for (int j = 0; j < W; ++j)
                output[(i + ii) * W + j] = (output[(i + ii - 1) * W + j] * N -
                                            tmp_buf[(ii - 1) * W + j] +
                                            tmp_buf[(ii + N - 1) * W + j]) /
                                           N;

        free(tmp_buf);
    }
}