// #Hackerearth
// #Attribute Parser

// This challenge works with a custom-designed markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

// The opening tags follow the format:
// <tag-name attribute1-name = "value1" attribute2-name = "value2" ...>
// The closing tags follow the format:
// </tag-name>
// The attributes are referenced as:
// tag1~value  
// tag1.tag2~name
// Given the source code in HRML format consisting of  lines, answer  queries. For each query, print the value of the attribute specified. Print "Not Found!" if the attribute does not exist.

// Input:
// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value

// Output:
// Name1
// Not Found!
// HelloWorld

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    string stmt, query;
    string key, val;
    string tag = "";
    map<string, string> m;
    cin.ignore();
    while (n--)
    {
        getline(cin, stmt);
        int i = 1;
        if (stmt[1] != '/')
        {
            while (stmt[i] != ' ' && stmt[i] != '>')
                i++;
            if (tag == "")
                tag = stmt.substr(1, i - 1);
            else
                tag = tag + "." + stmt.substr(1, i - 1);
            int j;
            while (stmt[i] != '>')
            {
                j = ++i;
                while (stmt[i] != ' ')
                    i++;
                key = tag + "~" + stmt.substr(j, i - j);

                while (stmt[i] != '\"')
                    i++;
                j = ++i;
                while (stmt[i] != '\"')
                    i++;
                val = stmt.substr(j, i - j);

                m[key] = val;
                i++;
                cout << key << "=" << val << "\n";
            }
        }
        else
        {
            while (stmt[i] != '>')
                i++;
            if (tag.size() > (i - 2))
                tag = tag.substr(0, tag.size() - (i - 1));
            else
                tag = "";
        }
    }

    while (q--)
    {
        getline(cin, query);
        string res = m[query];
        if (res == "")
            res = "Not Found!";
        cout << res << "\n";
    }
    return 0;
}
