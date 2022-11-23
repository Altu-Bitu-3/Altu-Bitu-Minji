//
// Created by KangMinji on 2022-11-22.
//

#include <iostream>
#include <map>
using namespace std;
typedef pair<char, char> ci;

map<char, ci> tree;

// 전위 순회 : V L R
void preorder(char v) {
    // null 처리
    if (v == '.'){
        return;
    }
    cout << v;
    preorder(tree[v].first);
    preorder(tree[v].second);
}

// 중위 순회 : L V R
void inorder(char v) {
    // null 처리
    if (v == '.'){
        return;
    }
    inorder(tree[v].first);
    cout << v;
    inorder(tree[v].second);
}

// 후위 순회 : L R V
void postorder(char v){
    // null 처리
    if (v == '.'){
        return;
    }
    postorder(tree[v].first);
    postorder(tree[v].second);
    cout << v;
}

int main() {
    int n;
    char root, left, right;

    // 입력
    cin >> n;
    while(n--){
        cin >> root >> left >> right;
        tree[root] = {left, right};
    }

    // 연산 & 출력
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}