//
// Created by 。 on 2024/4/7.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>
#include <climits>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <list>

using namespace std;

class ThroneInheritance1 {
    unordered_map<string, bool> deathMap;
    typedef struct node {
        string name;
        struct node *next;
        struct node *front;
    } Node;
    Node *head;
    unordered_map<string, Node *> pos;
public:
    ThroneInheritance(string
    kingName) {
        deathMap[kingName] = true;
        Node *pNode = new Node;
        head = pNode;
        pNode->name = kingName;
        head = pNode;
        head->front = nullptr;
        pos[head->name] = head;
    }

    void birth(string parentName, string childName) {
        Node *pNode = new Node;
        pos[childName] = pNode;
        deathMap[childName] = true;
        pNode->name = childName;
        pNode->front = pos[parentName];
        if (pos[parentName]->next == nullptr) {
            pNode->next = nullptr;
            pos[parentName]->next = pNode;
            pos[parentName] = pNode;
        } else {
            pNode->next = pos[parentName]->next;
            pos[parentName]->next = pNode;
            pos[parentName] = pNode;
        }
    }

    void death(string name) {
        deathMap[name] = false;
    }

    vector<string> getInheritanceOrder() {
        Node *node = head;
        vector<string> ans;
        while (!node) {
            if (deathMap[node->name]) {
                ans.push_back(node->name);
            }
            node = node->next;
        }
        return ans;
    }
};

class ThroneInheritance {
    unordered_map<string, bool> deathMap;
    unordered_map<string ,vector<string >> son;
    vector<string >ans;
    string  kingname;
public:
    ThroneInheritance(string kingName) {
        kingname = kingName;
        deathMap[kingName] = false;
    }

    void birth(string parentName, string childName) {
        son[parentName].push_back(childName);
        deathMap[childName] = false;
    }

    void death(string name) {
        deathMap[name] = true;
    }
    vector<string> getInheritanceOrder() {
        ans = vector<string >();
        dfs(kingname);
        return ans;
    }
    void dfs(string name){
        if (!deathMap[name]){
            ans.push_back(name);
        }
        for (int i = 0; i < son[name].size(); ++i) {
            dfs(son[name][i]);
        }
    }
};

//int main() {
//    ThroneInheritance *obj = new ThroneInheritance("king");
//    obj->birth("king", "andy");
//    obj->death("bob");
//    vector<string> param_3 = obj->getInheritanceOrder();
//    return 0;
//}