#pragma once
#pragma once
#ifndef GAME2048_H
#define GAME2048_H

#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 4
#define WIN_SCORE 64

class GAME2048 {
private:
    int board[4][4];
    int previous[4][4];
    string Location[4][4];
    int moveRecord[4][4];


public:
    GAME2048() {
        for (int i = 0; i < SIZE * SIZE; i++) {
            this->board[i / 4][i % 4] = 0;
            this->previous[i / 4][i % 4] = 0;
            this->moveRecord[i / 4][i % 4] = 0;
        }
    }
    void init() {
        addRandom();
        addRandom();
    };
    int addRandom();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int  Judge();
    void recordLocation(int direction);
    void countMoveRecord(int direction);

    void recordBoard() {
        for (int i = 0; i < SIZE * SIZE; i++) {
            this->previous[i / 4][i % 4] = this->board[i / 4][i % 4];
        }
    };



    int  comparePre() { //判断移动后是否相同
        int x = 0;
        for (int i = 0; i < SIZE * SIZE; i++) {
            if (this->board[i / 4][i % 4] == this->previous[i / 4][i % 4])
                x++;
        }

        if (x >= 16) {
            return 1;
        }
        return 0;
    };
    //获取棋盘指针
    int* getBoard() {
        return &this->board[0][0];
    };
    //获取位置数组指针
    string* getLocation() {
        return &this->Location[0][0];
    };
    //获取移动记录数组指针
    int* getMoveRecord() {
        return &this->moveRecord[0][0];
    };
};

#endif

