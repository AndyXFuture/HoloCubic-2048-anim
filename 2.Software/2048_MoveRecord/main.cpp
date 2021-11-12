#include <stdio.h>
#include "game2048.h"
#include <conio.h>
#include <iostream>
using namespace std;


void showBoard(int* map);		//��ʾ����
void showLocation(string* map);	//��ʾ�ƶ����λ��
void showMoveRecord(int* map);	//��ʾ�ƶ��켣

/*
* ��������¼
* 1���ƶ��жϿɴ�����ֵ�ж������ж��Ƿ���Ҫ����������
* 2���ɵ�λ��������ʾ����ΪABCD��������λ����Ϣ��������
*/

int main(void) {
	srand((unsigned)time(NULL));	//���������
	GAME2048 game;					//������Ϸ����
	game.init();					//��Ϸ��ʼ��
	char control;					//���ڶ�ȡWASD
	int* p = game.getBoard();;		//����������ָ��
	string *pl = game.getLocation();//�������λ�õ�ַ
	int* mr = game.getMoveRecord();	//������Ź켣��ַ

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
	//��ʾ��Ϸ����
	int i = 0;

	cout << "�������������ٿ�,����һ�����ֵ���"<< WIN_SCORE <<"ʱ����Ϸ�ɹ�" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[0], map[1], map[2], map[3]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[4], map[5], map[6], map[7]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[8], map[9], map[10], map[11]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[12], map[13], map[14], map[15]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
}

void showMoveRecord(int* map) {
	//��ʾ��Ϸ����
	int i = 0;

	cout << "���ڶ����������ƶ��켣����" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[0], map[1], map[2], map[3]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[4], map[5], map[6], map[7]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[8], map[9], map[10], map[11]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	printf("ح%3d  ح%3d  ح%3d  ح%3d  ح\n", map[12], map[13], map[14], map[15]);
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
}

void showLocation(string* map) {
	//��ʾ��Ϸ����
	int i = 0;

	cout << "��λ�ã�ԭλ��Ϊ���ϵ���ABCD��������ABCD�������ƶ��ķ����趨" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "ح   " << map[0] << "  ح   " << map[1] << "  ح   " << map[2] << "  ح   " << map[3] << "  ح"<<endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "ح   " << map[4] << "  ح   " << map[5] << "  ح   " << map[6] << "  ح   " << map[7] << "  ح" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "ح   " << map[8] << "  ح   " << map[9] << "  ح   " << map[10] << "  ح   " << map[11] << "  ح" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "ح   " << map[12] << "  ح   " << map[13] << "  ح   " << map[14] << "  ح   " << map[15] << "  ح" << endl;
	cout << "ح     ح     ح     ح     ح" << endl;
	cout << "------------------------------" << endl;
}