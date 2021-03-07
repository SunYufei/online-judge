#include "../main.h"

class Solution {
   public:
    string entityParser(string text) {
        string res, sig;
        int n = text.size();
        for (int i = 0; i < n; i++) {
            if (text[i] == '&') {
                sig.clear();
                for (int j = i; j < n; j++, i++) {
                    sig += text[j];
                    if (text[j] == ';')
                        break;
                }
                if (sig == "&quot;")
                    res += "\"";
                else if (sig == "&apos;")
                    res += "'";
                else if (sig == "&amp;")
                    res += "&";
                else if (sig == "&gt;")
                    res += ">";
                else if (sig == "&lt;")
                    res += "<";
                else if (sig == "&frasl;")
                    res += "/";
                else
                    res += sig;
            } else
                res += text[i];
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.entityParser(
        "&amp; is an HTML entity but &ambassador; is not.\n");
    cout << solution.entityParser("and I quote: &quot;...&quot;\n");
    cout << solution.entityParser("Stay home! Practice on Leetcode :)\n");
    cout << solution.entityParser(
        "x &gt; y &amp;&amp; x &lt; y is always false\n");
    cout << solution.entityParser("leetcode.com&frasl;problemset&frasl;all\n");
    return 0;
}