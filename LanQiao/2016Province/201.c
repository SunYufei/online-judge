/*
    抽签

    X星球要派出一个5人组成的观察团前往W星。
    其中：
    A国最多可以派出4人。
    B国最多可以派出2人。
    C国最多可以派出2人。
    ....

    那么最终派往W星的观察团会有多少种国别的不同组合呢？

    下面的程序解决了这个问题。
    数组a[] 中既是每个国家可以派出的最多的名额。
    程序执行结果为：
    DEFFF
    CEFFF
    CDFFF
    CDEFF
    CCFFF
    CCEFF
    CCDFF
    CCDEF
    BEFFF
    BDFFF
    BDEFF
    BCFFF
    BCEFF
    BCDFF
    BCDEF
    ....
    (以下省略，总共101行)


    #include <stdio.h>
    #define N 6
    #define M 5
    #define BUF 1024

    void f(int a[], int k, int m, char b[])
    {
        int i,j;

        if(k==N){
            b[M] = 0;
            if(m==0) printf("%s\n",b);
            return;
        }

        for(i=0; i<=a[k]; i++){
            for(j=0; j<i; j++) b[M-m+j] = k+'A';
            ______________________;  //填空位置
        }
    }
    int main()
    {
        int  a[N] = {4,2,2,1,1,3};
        char b[BUF];
        f(a,0,M,b);
        return 0;
    }

    仔细阅读代码，填写划线部分缺少的内容。

    注意：不要填写任何已有内容或说明性文字。


*/
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

// a[]  每个国家的最多指派人数
// k    哪个国家
// m    还需要派送几个人
// b[]  已经派送的人的字符串
void f(int a[], int k, int m, char b[]) {
    int i, j;

    // 已经到达最后一个国家，输出
    if (k == N) {
        b[M] = 0;
        if (m == 0)
            printf("%s\n", b);
        return;
    }

    for (i = 0; i <= a[k]; i++) {
        for (j = 0; j < i; j++)
            b[M - m + j] = k + 'A';
        ///////////////////////////////
        f(a, k + 1, m - i, b);
        ///////////////////////////////
    }
}
int main() {
    int a[N] = {4, 2, 2, 1, 1, 3};
    char b[BUF];
    f(a, 0, M, b);
    return 0;
}