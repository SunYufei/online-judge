#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    unsigned int weight;
    unsigned int parent, left, right;
} Node, *Tree;

typedef char *Code;

void InputAndSave(const char *filename) {
    // 新建 / 打开文件
    FILE *fp = fopen(filename, "w");
    printf("Please input an essay, end with an enter: ");
    while (true) {
        // 从 stdin 中读取一个字符
        char ch = getchar();
        // 若字符为'\n'，退出循环
        if (ch == '\n')
            break;
        // 写入文件中
        fputc(ch, fp);
    }
    // 关闭文件
    fclose(fp);
}

void Select(Tree ht, int n, int &s1, int &s2) {
    int w1 = 0x3f3f3f3e, w2 = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        if (ht[i].parent == 0) {
            if (ht[i].weight <= w1 && ht[i].weight < w2) {
                w2 = w1;
                w1 = ht[i].weight;
                s2 = s1;
                s1 = i;
            }
            if (ht[i].weight > w1 && ht[i].weight < w2) {
                w2 = ht[i].weight;
                s2 = i;
            }
        }
    }
}

void CreateHuffmanTree(const char *filename, Tree &ht, int &n) {
    // 从文件中逐个读取字符并计数
    FILE *fp = fopen(filename, "r");
    int count[128] = {0};
    n = 0;
    while (true) {
        char ch = fgetc(fp);
        if (ch == EOF)
            break;
        if (count[ch] == 0)
            n += 1;
        count[ch] += 1;
    }
    fclose(fp);

    // 申请 Huffman 树空间
    ht = (Tree)malloc(2 * n * sizeof(Node));

    // 不使用 0 号单元
    // 将字符及权重存入树中
    // 置 parent, left, right 为 0
    Tree p = ht + 1;
    for (int i = 0; i < 128; i++) {
        if (count[i] != 0) {
            p->letter = i;
            p->weight = count[i];
            p->parent = 0;
            p->left = 0;
            p->right = 0;
            p += 1;
        }
    }

    // 构建 Huffman 树
    for (int i = n + 1; i < 2 * n; i++) {
        // 在 ht[1..i-1] 中选择 parent=0 且 weight 最小的两个结点
        int s1, s2;
        Select(ht, i - 1, s1, s2);

        ht[s1].parent = i;
        ht[s2].parent = i;
        ht[i].letter = ' ';
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[i].parent = 0;
        ht[i].left = s1;
        ht[i].right = s2;
    }
}

void CreateHuffmanCode(Code hc[], Tree ht, int n) {
    // 编码临时存储空间
    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    // 从叶子节点逆向求编码
    int start, c, f;
    for (int i = 1; i <= n; i++) {
        // 编码结束位置
        start = n - 1;
        for (c = i, f = ht[i].parent; f != 0; c = f, f = ht[f].parent) {
            if (ht[f].left == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        // 将编码存到指定位置
        char letter = ht[i].letter;
        hc[letter] = (char *)malloc((n - start) * sizeof(char));
        strcpy(hc[letter], &cd[start]);
    }
    // 释放临时存储空间
    free(cd);
}

void Encode(const char *src, const char *dst, Code hc[]) {
    FILE *fsrc = fopen(src, "r");
    FILE *fdst = fopen(dst, "w");

    // 从 src 中读字符
    // 查询编码后写入 dst
    while (true) {
        char ch = fgetc(fsrc);
        if (ch == EOF)
            break;
        fputs(hc[ch], fdst);
    }

    fclose(fsrc);
    fclose(fdst);
}

void Decode(const char *src, const char *dst, Tree ht, int n) {
    FILE *fsrc = fopen(src, "r");
    FILE *fdst = fopen(dst, "w");

    int i = 2 * n - 1;
    while (true) {
        char ch = fgetc(fsrc);
        if (ch == EOF)
            break;
        // 寻找叶子节点
        if (ch == '0')
            i = ht[i].left;
        else
            i = ht[i].right;
        // 到达叶子节点
        // 将对应字符写入文件
        if (ht[i].left == 0 && ht[i].right == 0) {
            fputc(ht[i].letter, fdst);
            i = 2 * n - 1;
        }
    }

    fclose(fsrc);
    fclose(fdst);
}

bool Compare(const char *first, const char *second) {
    // 打开文件
    FILE *f1 = fopen(first, "r");
    FILE *f2 = fopen(second, "r");

    int res = true;

    // 逐字符比较两个文件
    while (!feof(f1) && !feof(f2)) {
        char c1 = fgetc(f1);
        char c2 = fgetc(f2);
        // 字符不相同，跳出循环
        if (c1 != c2)
            break;
    }

    // 两个文件未同时到达末尾
    if (!feof(f1) || !feof(f2))
        res = false;

    // 关闭文件
    fclose(f1);
    fclose(f2);

    return res;
}

int main() {
    // 输入英文文章并保存到 a.txt 中
    InputAndSave("a.txt");

    // 构造 Huffman 树
    Tree ht;
    int n;
    CreateHuffmanTree("a.txt", ht, n);

    // 获取 Huffman 编码
    Code hc[128];
    CreateHuffmanCode(hc, ht, n);

    // 短文编码
    Encode("a.txt", "b.txt", hc);

    // 短文解码
    Decode("b.txt", "c.txt", ht, n);

    // a.txt 与 c.txt 比较
    printf("a.txt is %s to c.txt",
           Compare("a.txt", "c.txt") ? "equal" : "NOT equal");

    // 释放空间
    free(ht);
    return 0;
}