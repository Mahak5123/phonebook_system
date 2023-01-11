#include <bits/stdc++.h>
using namespace std;

class Node_Trie
{
public:
    map<char, Node_Trie *> dr;
    bool is_end;
    long long int contact;
    Node_Trie()
    {
        is_end = false;
        contact = 0;
    }
};

void insert(Node_Trie *&head, string s, long long int c)
{
    Node_Trie *temp = head;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (temp->dr.find(c) == temp->dr.end())
            temp->dr[c] = new Node_Trie();

        temp = temp->dr[c];
    }
    temp->is_end = true;
    temp->contact = c;
    cout << temp->contact << endl;
}
// Recusive check all nodes (DFS)
void print(Node_Trie *head, string s)
{
    if (head->is_end)
    {
        cout << s << endl;
        cout << head->contact;
    }

    map<char, Node_Trie *>::iterator it;
    for (it = head->dr.begin(); it != head->dr.end(); it++)
    {
        print(it->second, s + it->first);
    }
}

void printAll(Node_Trie *head, string query)
{
    Node_Trie *temp = head;
    for (int i = 0; i < query.length(); i++)
    {
        char c = query[i];

        if (temp->dr.find(c) == temp->dr.end())
        {
            cout << " No records found for " << query << endl;
            return;
        }
        temp = temp->dr[c];
    }
    cout << " The matching Records for " << query << " are " << endl;
    print(temp, query);
}

int main()
{
    int n = 5;
    string arr[5] = {"Mr Abc", "Xyz", "Xyz abc", "abcd ", "Xyz abcde"};
    long long int c[5] = {9234777609, 8210015218, 9070203841, 8023456718, 1234567895};

    Node_Trie *head = new Node_Trie();

    for (int i = 0; i < n; i++)
    {
        insert(head, arr[i], c[i]);
        cout << " done " << endl;
    }

    string query = "Mr Abc";
    printAll(head, query);

    cout << "********************************" << endl
         << endl;

    query = "Mr Xyz Abc";
    printAll(head, query);
    return 0;
}