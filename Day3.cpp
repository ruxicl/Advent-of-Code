// Day 3
#include <bits/stdc++.h>

#define END_OF_FILE -1

using namespace std;

vector<int> nrList;
int maxNrBits;

int getNr() {
    int nr = 0;
    char ch = getc(stdin);
    if (ch == EOF)
        nr = END_OF_FILE;
    int nrBits = 0;
    while (ch >= '0' && ch <= '1') {
        nr = nr * 2 + (ch - '0');
        ch = getc(stdin);
        ++nrBits;
    }
    
    if (nrBits > maxNrBits)
        maxNrBits = nrBits;
    
    return nr;
}

char mostCommonBit(int bit) {
    int mask = 1 << bit;
    int count = 0;
    for (int i = 0; i < nrList.size(); ++i) {
        char currentBit = nrList[i] & mask;
        if (currentBit)
            ++count;
        else
            --count;
    }
    char mostCommonBit = count < 0 ? 0 : 1;
    return mostCommonBit;
}

int calculateGamma(int nrBits) {
    int gamma = 0;
    for (int i = 0; i < nrBits; ++i) 
        gamma = gamma * 2 + mostCommonBit(nrBits - i - 1);
    return gamma;
}

int main() {
    
    int x = getNr();
    while (x != END_OF_FILE) {
        nrList.push_back(x);
        x = getNr();
    }

    int gamma = calculateGamma(maxNrBits);
    // to obtain epsilon, we just need to flip every bit in gamma
    // alternatively: epsilon = (1 << maxNrBits) - 1 - gamma;
    int mask = (1 << maxNrBits) - 1;
    int epsilon = mask & (~gamma);
    
    printf("%d", gamma * epsilon);
    
    return 0;
}
