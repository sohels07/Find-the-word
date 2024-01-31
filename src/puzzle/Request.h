#ifndef REQUEST_H
#define REQUEST_H
#include <bits/stdc++.h>

using namespace std;

class Request {
private:
    vector<vector<char> > puzzle;
    string pattern;
    int rowSize;
    int colSize;
    int patternSize;

public:
    vector<vector<char> > getPuzzle() {
        return this->puzzle;
    }

    string getPattern() {
        return this->pattern;
    }

    int getRowSize() {
        return this->puzzle.size();
    }

    int getColSize() {
        return this->puzzle[0].size();
    }

    int getPatternSize() {
        return this->pattern.size();
    }

    int getPuzzleCell(int x, int y) {
        return this->puzzle[x][y];
    }

    void setPuzzle(vector<vector<char> > puzzle) {
        this->puzzle = puzzle;
    }

    void setPattern(string pattern) {
        this->pattern = pattern;
    }
};
#endif
