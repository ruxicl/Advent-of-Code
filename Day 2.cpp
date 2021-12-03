// Day 2
#include <bits/stdc++.h>

#define END_OF_FILE -1

using namespace std;

int getNr() {
    char ch = getc(stdin);
    int nr = 0;
    if (ch < '0' || ch > '9')
        nr = END_OF_FILE;
    while (ch >= '0' && ch <= '9') {
        nr = nr * 10 + (ch - '0');
        ch = getc(stdin);
    }
    return nr;
}

string getStr() {
    vector<char> str; 
    char ch = getc(stdin);
    while (ch >= 'a' && ch <= 'z') {
        str.push_back(ch);
        ch = getc(stdin);
    }
    
    string finalStr(str.begin(), str.end());
    return finalStr;
}

int finalPosition() {
    int depth, horizontalPos, nr;
    depth = horizontalPos = 0;
    nr = 0;
    while (nr != END_OF_FILE) {
        string command = getStr();
        nr = getNr();
        if (command == "up")
            depth -= nr;
        else if (command == "down")
            depth += nr;
        else if (command == "forward")
            horizontalPos += nr;
    }
    
    return depth * horizontalPos;
}

int finalPositionUpdated() {
    int depth, horizontalPos, aim, nr;
    depth = horizontalPos = aim = 0;
    nr = 0;
    while (nr != END_OF_FILE) {
        string command = getStr();
        nr = getNr();
        if (command == "up")
            aim -= nr;
        else if (command == "down")
            aim += nr;
        else if (command == "forward") {
            horizontalPos += nr;
            depth += (aim * nr);
        }
    }
    
    return depth * horizontalPos;
}

int main() {
    
    // printf("%d", finalPosition());
    printf("%d", finalPositionUpdated());
    return 0;
}
