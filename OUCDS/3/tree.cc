#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char letter;
    unsigned int weight;
    struct Node *left;
    struct Node *right;
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

void Select(Tree nodes[], int n, int &s1, int &s2) {
    int w1 = 0x3f3f3f3f, w2 = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        Tree p = nodes[i];
        if (p != NULL) {
            if (p->weight <= w1) {
                w2 = w1;
                w1 = p->weight;
                s2 = s1;
                s1 = i;
            }
            if (p->weight > w1 && p->weight <= w2) {
                w2 = p->weight;
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

    // huffman 结点临时存储空间
    Tree *nodes = (Tree *)malloc(2 * n * sizeof(Tree));

    for (int i = 0, p = 1; i < 128; i++) {
        if (count[i] != 0) {
            // printf("%c %d\n", i, count[i]);
            nodes[p] = (Tree)malloc(sizeof(Node));
            nodes[p]->letter = i;
            nodes[p]->weight = count[i];
            nodes[p]->left = NULL;
            nodes[p]->right = NULL;
            p += 1;
        }
    }

    // 构建 Huffman 树
    for (int i = n + 1; i < 2 * n; i++) {
        int s1, s2;
        Select(nodes, i - 1, s1, s2);

        nodes[i] = (Node *)malloc(sizeof(Node));
        nodes[i]->left = nodes[s1];
        nodes[i]->right = nodes[s2];
        nodes[i]->weight = nodes[s1]->weight + nodes[s2]->weight;

        nodes[s1] = NULL;
        nodes[s2] = NULL;
    }

    ht = nodes[2 * n - 1];
    free(nodes);
}

void PreOrder(Tree root, Code hc[], char cd[], int level, char code) {
    if (root->left == NULL && root->right == NULL) {
        cd[level] = code;
        cd[level + 1] = '\0';
        // 将编码存到指定位置
        char letter = root->letter;
        hc[letter] = (char *)malloc((level + 2) * sizeof(char));
        strcpy(hc[letter], cd);
        return;
    }
    cd[level] = code;
    PreOrder(root->left, hc, cd, level + 1, '0');
    PreOrder(root->right, hc, cd, level + 1, '1');
}

void CreateHuffmanCode(Code hc[], Tree ht, int n) {
    char *cd = (char *)malloc(n * sizeof(char));

    PreOrder(ht->left, hc, cd, 0, '0');
    PreOrder(ht->right, hc, cd, 0, '1');

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

void Decode(const char *src, const char *dst, Tree ht) {
    FILE *fsrc = fopen(src, "r");
    FILE *fdst = fopen(dst, "w");

    Tree p = ht;
    while (true) {
        char ch = fgetc(fsrc);
        if (ch == EOF)
            break;
        // 寻找叶子节点
        if (ch == '0')
            p = p->left;
        else
            p = p->right;
        // 到达叶子节点
        // 将对应字符写入文件
        if (p->left == NULL && p->right == NULL) {
            fputc(p->letter, fdst);
            p = ht;
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

void DestroyTree(Tree root) {
    if (root == NULL)
        return;
    DestroyTree(root->left);
    DestroyTree(root->right);
    free(root);
}

int main() {
    // 输入英文文章并保存到 a.txt 中
    // InputAndSave("a.txt");

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
    Decode("b.txt", "c.txt", ht);

    // a.txt 与 c.txt 比较
    printf("a.txt is %s to c.txt",
           Compare("a.txt", "c.txt") ? "equal" : "NOT equal");

    // 释放空间
    DestroyTree(ht);
    return 0;
}