#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n, k;
    string input;
    stack<int> s;
    cin >> n;
    while (n--){
        cin >> input;
        if (input == "push"){
            cin >> k;
            s.push(k);
            continue;
        }
        if (input == "pop"){
            if (s.empty()){
                cout << -1 << "\n";
            }
            else {
                cout << s.top() << "\n";
                s.pop();
            }
            continue;
        }
        if (input == "size"){
            cout << s.size() << "\n";
            continue;
        }
        if (input == "empty"){
            if (s.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            continue;
        }
        if (input == "top"){
            if (s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
    }
}