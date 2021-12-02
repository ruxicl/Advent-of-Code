// 1.1
#include <bits/stdc++.h>

#define END_OF_FILE -1

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

int main() {
    int first = getNr();
    int second;
    int timesIncreased = 0;
    while ((second = getNr()) != END_OF_FILE) {
        if (second > first)
            ++timesIncreased;
        first = second;
    }
    printf("%d", timesIncreased);
    return 0;
}
