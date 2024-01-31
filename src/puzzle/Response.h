#ifndef RESPONSE_H
#define RESPONSE_H
#include <bits/stdc++.h>

using namespace std;
class Response {
private:
    int x;
    int y;
    int count;

public:
    Response(int x, int y, int count) {
        this->x = x;
        this->y = y;
        this->count = count;
    }

    int getX() {
        return this->x;
    }

    int getY() {
        return this->y;
    }

    int getCount() {
        return this->count;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void setCount(int count) {
        this->count = count;
    }
};
#endif
