#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
    int n;
    string s;
    cin >> n;
    getchar();
    while (n--) {
        getline(cin, s);
        cout << s << endl << "AI: ";
        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (s[i] == '?')
                s[i] = '!';
            else if (isupper(s[i]) && s[i] != 'I')
                s[i] = tolower(s[i]);
        }

        v.clear();

        for (int i = 0; i < len;) {
            string tmp = "";
            if (isalpha(s[i]))
                while (i < len && isalpha(s[i]))
                    tmp += s[i++];
            else if (isdigit(s[i]))
                while (i < len && isdigit(s[i]))
                    tmp += s[i++];
            else if (s[i] == ' ') {
                tmp = " ";
                while (i < len && s[i] == ' ')
                    i++;
            } else {
                tmp += s[i];
                i++;
                if (v.size() > 0 && v.back() == " ")
                    v.pop_back();
            }
            if (tmp == " " && (v.empty() || i == len))
                continue;
            v.push_back(tmp);
        }
        for (size_t i = 0; i < v.size(); i++)
            if (v[i] == "I" || v[i] == "me")
                v[i] = "you";
            else if (v[i] == "you") {
                if (i < 2 ||
                    !(v[i - 1].length() == 1 && (!isalnum(v[i - 1][0]))))
                    continue;
                if (v[i - 2] == "can")
                    v[i - 2] = "I", v[i] = "can";
                else if (v[i - 2] == "could")
                    v[i - 2] = "I", v[i] = "could";
            }
        for (auto i = v.begin(); i < v.end(); i++)
            cout << *i;
        cout << endl;
    }
    return 0;
}