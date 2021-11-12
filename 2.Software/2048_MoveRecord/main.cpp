#include <stdio.h>
#include "game2048.h"
#include <conio.h>
#include <iostream>
using namespace std;


void showBoard(int* map);		//显示棋盘
void showLocation(string* map);	//显示移动后的位置
void showMoveRecord(int* map);	//显示移动轨迹

/*
* 懒癌备忘录
* 1、移动判断可代替数值判断用以判断是否需要生成新数字
* 2、旧的位置无需显示，因为ABCD本身已有位置信息（已做）
*/

int main(void) {
	srand((unsigned)time(NULL));	//随机数重则
	GAME2048 game;					//创建游戏对象
	game.init();					//游戏初始化
	char control;					//用于读取WASD
	int* p = game.getBoard();;		//用来存棋盘指针
	string *pl = game.getLocation();//用来存放位置地址
	int* mr = game.getMoveRecord();	//用来存放轨迹地址

	while (1) {
		system("cls");
		showBoard(p);
		showLocation(pl);
		showMoveRecord(mr);

		control = _getch();

		switch (control) {
		case 'H':
			game.moveUp();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Up!\n");
			break;
		case 'P':
			game.moveDown();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Down!\n");
			break;
		case 'M':
			game.moveRight();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Right!\n");
			break;
		case 'K':
			game.moveLeft();
			if (game.comparePre() == 0) {
				game.addRandom();
			}
			//printf("Left!\n");
			break;
		default:
			continue;
		}



		if (game.Judge() == 1) {
			printf("you win!\n");
			system("pause");
			return 1;
		}
		else if (game.Judge() == 2) {
			printf("you lose!\n");
			system("pause");
			return 2;
		}

	}

	return 3;
}

void showBoard(int* map) {
	//显示游戏进度
	int i = 0;

	cout << "用上下左右来操控,当有一个数字等于"<< WIN_SCORE <<"时，游戏成功" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[0], map[1], map[2], map[3]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[4], map[5], map[6], map[7]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[8], map[9], map[10], map[11]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[12], map[13], map[14], map[15]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
}

void showMoveRecord(int* map) {
	//显示游戏进度
	int i = 0;

	cout << "用于动画参数的移动轨迹数组" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[0], map[1], map[2], map[3]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[4], map[5], map[6], map[7]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[8], map[9], map[10], map[11]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	printf("丨%3d  丨%3d  丨%3d  丨%3d  丨\n", map[12], map[13], map[14], map[15]);
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
}

void showLocation(string* map) {
	//显示游戏进度
	int i = 0;

	cout << "新位置，原位置为由上到下ABCD或由左到右ABCD，根据移动的方向设定" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "丨   " << map[0] << "  丨   " << map[1] << "  丨   " << map[2] << "  丨   " << map[3] << "  丨"<<endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "丨   " << map[4] << "  丨   " << map[5] << "  丨   " << map[6] << "  丨   " << map[7] << "  丨" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "丨   " << map[8] << "  丨   " << map[9] << "  丨   " << map[10] << "  丨   " << map[11] << "  丨" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "丨   " << map[12] << "  丨   " << map[13] << "  丨   " << map[14] << "  丨   " << map[15] << "  丨" << endl;
	cout << "丨     丨     丨     丨     丨" << endl;
	cout << "------------------------------" << endl;
}