//
// Created by KangMinji on 2022-09-22.
//

#include <iostream>
#include <vector>

using namespace std;

bool isNewWord(string str, vector<string> &words) {
    for (string word : words) {
        // 1) 단어 길이 일치하지 않는 경우
        if (str.size() != word.size()) {
            continue;
        }

        // 2) 비교군과 단어 돌려보면서 일치하는지 확인
        string tmp = str;
        for (int i=0; i<word.size(); i++){
            if (tmp == word){
                return false;
            }

            tmp += tmp[0];
            tmp.erase(0, 1);
        }
    }
    return true;
}

int main() {
    int n;
    string str;
    vector<string> words; // 만들 수 있는 단어 저장(비교군)

    // 입력
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (isNewWord(str, words)){
            words.push_back(str);
        }
    }

    // 연산
    cout << words.size();
}

//bool canMakeWord(string word, vector<string> &possibleWord){
//    for (string s : possibleWord){
//        if (s == word) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int findDiffWord(int n, vector<string> &v) {
//    vector<string> words; // 서로 다른 단어 저장하는 비교군
//
//    // 1. 비교군에 단어 하나 넣어놓기
//    words.push_back(v[0]);
//
//    // 2. 덱 돌면서 비교군과 일치하는 단어 있는지 확인
//    for (int i = 1; i < n; i++) {
//        // 돌릴 수 있는 모든 경우의 수 저장
//        vector<string> possibleWords;
//
//        string tmp = v[i];
//        for (int j = 0; j < v[i].size(); j++) {
//            tmp += tmp[0];
//            tmp.erase(0, 1);
//            possibleWords.push_back(tmp);
//        }
//
//        // 비교군과 일치하는 단어 있는지 확인
//        bool is_new = false;
//        string new_word = "";
//        for (string word: words) {
//            // 만약 일치하지 않으면 비교군에 단어 추가
//            if (!canMakeWord(word, possibleWords)) {
//                is_new = true;
//                new_word = v[i];
//            } else {
//                is_new = false;
//            }
//        }
//
//        if (is_new) {
//            words.push_back(new_word);
//        }
//    }
//
//    for (int i=0; i<words.size(); i++)
//        cout << words[i] << " ";
//    return words.size();
//}