#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 10010;

char md[MAXN];
int cnt;
string html;

int deal_h(int pos);
int deal_p(int pos);
int deal_list(int pos);
int deal_empha(int pos, string &text = html);
int deal_link(int pos);

int deal_h(int p) {
    int sc = 0; //对#计数
    while (md[p + sc] == '#')
        sc++;
    html += "<h" + string(1, '0' + sc) + ">";

    int i = p + sc;
    while (md[i] == ' ')
        i++;
    while (md[i] != '\n') {
        if (md[i] == '_')
            i = deal_empha(i);
        else if (md[i] == '[')
            i = deal_link(i);
        else
            html += md[i];
        i++;
    }
    html += "</h" + string(1, '0' + sc) + ">\n";
    return i;
}

int deal_p(int p) {
    html += "<p>";
    int i = p;
    while (true) {
        if (md[i] == '_')
            i = deal_empha(i);
        else if (md[i] == '[')
            i = deal_link(i);
        else if (md[i] == '\n' && md[i + 1] == '\n')
            break;
        else
            html += md[i];
        i++;
    }
    html += "</p>\n";
    return i;
}

int deal_list(int p) {
    html += "<ul>\n";
    int i = p;
    while (md[i] == '*') {
        html += "<li>";
        while (md[++i] == ' ')
            ;
        while (md[i] != '\n') {
            if (md[i] == '_')
                i = deal_empha(i);
            else if (md[i] == '[')
                i = deal_link(i);
            else
                html += md[i];
            i++;
        }
        html += "</li>\n";
        i++;
    }
    html += "</ul>\n";
    return i;
}

int deal_empha(int p, string &text) {
    int i = p + 1;
    text += "<em>";
    while (md[i] != '_') {
        if (md[i] == '[')
            i = deal_link(i);
        else
            text += md[i];
        i++;
    }
    text += "</em>";
    return i;
}

int deal_link(int p) {
    int i = p + 1;
    string text, url;
    while (md[i] != ']') {
        if (md[i] == '_')
            i = deal_empha(i, text);
        else
            text += md[i];
        i++;
    }
    i += 2;
    while (md[i] != ')') {
        url += md[i++];
    }
    html += "<a href=\"" + url + "\">" + text + "</a>";
    return i;
}

int main() {
    char ch;
    while ((ch = getchar()) != EOF) {
        md[cnt++] = ch;
    }
    md[cnt++] = '\n';
    md[cnt] = '\0';

    int i = 0;
    while (i < cnt) {
        if (md[i] == '\n')
            i++;
        else if (md[i] == '#')
            i = deal_h(i);
        else if (md[i] == '*')
            i = deal_list(i);
        else
            i = deal_p(i);
    }

    cout << html;
    return 0;
}