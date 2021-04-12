#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char letter;
    unsigned int weight;
    unsigned int parent, left, right;
} Node, *Tree;

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

Tree CreateHuffmanTree(const char *filename) {
    // 从文件中逐个读取字符并计数
    FILE *fp = fopen(filename, "r");
    int count[128] = {0};
    int n = 0;
    while (true) {
        char ch = fgetc(fp);
        if (ch == EOF)
            break;
        if (count[ch] == 0)
            n += 1;
        count[ch] += 1;
    }
    fclose(fp);

    // 构建
    Tree ht = (Tree)malloc(sizeof(Node));

    return ht;
}

bool Compare(const char *first, const char *second) {
    // 打开文件
    FILE *f1 = fopen(first, "r");
    FILE *f2 = fopen(second, "r");

    int res = true;

    // 逐字符比较两个文件
    char c1, c2;
    while (!feof(f1) && !feof(f2)) {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        // 字符不相同，跳出循环
        if (c1 != c2) {
            res = false;
            break;
        }
    }

    // 两个文件长度不相同
    if (c1 != EOF || c2 != EOF)
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
    Tree HT = CreateHuffmanTree("a.txt");
    // 获取 Huffman 编码

    // 短文编码

    // 短文解码

    // a.txt 与 c.txt 比较
    printf("a.txt is %s to c.txt",
           Compare("a.txt", "c.txt") ? "equal" : "not equal");
    return 0;
}