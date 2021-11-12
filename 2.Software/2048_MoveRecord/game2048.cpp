#include "game2048.h"
#include "stdio.h"
#include <iostream>

/*
* ���ˢ��һ��2��4
* ����ˢ�µ�λ��
*/
int GAME2048::addRandom() {
    int random;
    if (Judge() != 0) {
        return NULL;
    }

    while (1) {
        random = rand() % 16;
        if (this->board[random / 4][random % 4] == 0) {
            //ʮ��֮һ���ʳ�4
            if (rand() % 10 == 0) {
                this->board[random / 4][random % 4] = 4;
            }
            else {
                this->board[random / 4][random % 4] = 2;
            }

            break;
        }
    }
    return random;
}
/*
*   ��¼�ƶ�ԭ����λ�ã��������򰴷�������ABCD
*   direction  1.�� 2.�� 3.�� 4.��
*   Ϊ�˼��ٴ������Ż�������Ҫ����߼���ֱ�ӿ����򲿷ֵĴ���
*   Ӧ�û������پ�������
*/
void GAME2048::recordLocation(int direction) {
    for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++) {
        //��������Ϊ��
        if (board[i][j] == 0) {
            Location[i][j] = "";
        } else {
            //�����ָ��ݷ�������ABCD
            switch (direction) {
            case 1://��
            case 2://��
                switch (i) {
                case 0: Location[i][j] = "A"; break;
                case 1: Location[i][j] = "B"; break;
                case 2: Location[i][j] = "C"; break;
                case 3: Location[i][j] = "D"; break;
                }
                break;
            case 3://��
            case 4://��
                switch (j) {
                case 0: Location[i][j] = "A"; break;
                case 1: Location[i][j] = "B"; break;
                case 2: Location[i][j] = "C"; break;
                case 3: Location[i][j] = "D"; break;
                }
                break;

            }
        }
    }}
}

/*
*   ͨ������Location�����ı仯����ȡ����¼�ƶ�����ͺϲ�λ��
*   direction  1.�� 2.�� 3.�� 4.��
*   >4���кϲ�,-8�����ƶ���ֵ
*   <4��ֱ�Ӿ����ƶ���ֵ
*/
void GAME2048::countMoveRecord(int direction) {

    //���
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            moveRecord[i][j] = 0;
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (direction) {
            case 1:
            case 2:
                //�ƶ����
                if (Location[i][j].find("A") != -1) {
                    moveRecord[0][j] += i;
                }
                if (Location[i][j].find("B") != -1) {
                    moveRecord[1][j] += i - 1;
                }
                if (Location[i][j].find("C") != -1) {
                    moveRecord[2][j] += i - 2;
                }
                if (Location[i][j].find("D") != -1) {
                    moveRecord[3][j] += i - 3;
                }
                break;
            case 3:
            case 4:
                //�ƶ����
                if (Location[i][j].find("A") != -1) {
                    moveRecord[i][0] += j;
                }
                if (Location[i][j].find("B") != -1) {
                    moveRecord[i][1] += j - 1;
                }
                if (Location[i][j].find("C") != -1) {
                    moveRecord[i][2] += j - 2;
                }
                if (Location[i][j].find("D") != -1) {
                    moveRecord[i][3] += j - 3;
                }
                break;
            }
            //�ϲ����
            if (Location[i][j].length() == 2) {
                moveRecord[i][j] += 8;
            }
        }
    }



}

void GAME2048::moveUp() {
    recordLocation(1);   //��¼λ��
    recordBoard();      //��¼��ֵ
    //�ƶ�����
    for (int x = 0; x < 2; x++) {
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i + 1][j];
                    board[i + 1][j] = 0;
                    //�����켣��¼
                    Location[i][j] = Location[i+1][j];
                    Location[i + 1][j] = "";
                }
            }
        }
    }

    //���
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == board[i + 1][j]) {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
                //�����켣��¼
                Location[i][j].append(Location[i+1][j]);
                Location[i + 1][j] = "";
            }
        }
    }

    //�ƶ�
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = 0;
                //�����켣��¼
                Location[i][j] = Location[i + 1][j];
                Location[i + 1][j] = "";
            }
        }
    }
    countMoveRecord(1);
}


void GAME2048::moveDown() {
    recordLocation(2);   //��¼λ��
    recordBoard();
    //�ƶ�
    for (int x = 0; x < 2; x++) {
        for (int i = SIZE - 1; i > 0; i--) {
            for (int j = SIZE - 1; j >= 0; j--) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i - 1][j];
                    board[i - 1][j] = 0;
                    //�����ƶ��켣��¼
                    Location[i][j] = Location[i - 1][j];
                    Location[i - 1][j] = "";
                }
            }
        }
    }

    //���
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] == board[i - 1][j]) {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
                //�����ϲ��켣��¼
                Location[i][j].append(Location[i - 1][j]);
                Location[i - 1][j] = "";
            }
        }
    }

    //�ƶ�
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            if (board[i][j] == 0) {
                board[i][j] = board[i - 1][j];
                board[i - 1][j] = 0;
                //�����ƶ��켣��¼
                Location[i][j] = Location[i - 1][j];
                Location[i - 1][j] = "";
            }
        }
    }
    countMoveRecord(2);
}

void GAME2048::moveLeft() {
    recordLocation(3);   //��¼λ��
    recordBoard();
    //�ƶ�
    for (int x = 0; x < 2; x++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE - 1; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i][j + 1];
                    board[i][j + 1] = 0;
                    //�����ƶ��켣��¼
                    Location[i][j] = Location[i][j + 1];
                    Location[i][j+1] = "";
                }
            }
        }
    }
    //���
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
                //�����ϲ��켣��¼
                Location[i][j].append(Location[i][j+1]);
                Location[i][j+1] = "";
            }
        }
    }
    //�ƶ�
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == 0) {
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = 0;
                //�����ƶ��켣��¼
                Location[i][j] = Location[i][j + 1];
                Location[i][j + 1] = "";
            }
        }
    }
    countMoveRecord(3);
}
void GAME2048::moveRight() {
    recordLocation(4);   //��¼λ��
    recordBoard();
    //�ƶ�����
    for (int x = 0; x < 2; x++) {
        for (int i = SIZE - 1; i >= 0; i--) {  
            for (int j = SIZE - 1; j > 0; j--) {
                if (board[i][j] == 0) {
                    board[i][j] = board[i][j - 1];
                    board[i][j - 1] = 0;
                    //�����ƶ��켣��¼
                    Location[i][j] = Location[i][j - 1];
                    Location[i][j - 1] = "";
                }
            }
        }
    }

    //���
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == board[i][j - 1]) {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
                //�����ϲ��켣��¼
                Location[i][j].append(Location[i][j - 1]);
                Location[i][j - 1] = "";
            }
        }
    }

    //�ƶ�
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j > 0; j--) {
            if (board[i][j] == 0) {
                board[i][j] = board[i][j - 1];
                board[i][j - 1] = 0;
                //�����ƶ��켣��¼
                Location[i][j] = Location[i][j - 1];
                Location[i][j - 1] = "";
            }
        }
    }
    countMoveRecord(4);

}

/*
* Judge()�жϵ�ǰ��Ϸ״̬
* ����0����Ϸ���Լ���
* ����1����Ϸ��ʤ
* ����2����Ϸ�޷�������ʧ��
*/
int GAME2048::Judge() {
    //��Ӯ
    for (int i = 0; i <= SIZE * SIZE; i++) {
        if (board[i / 4][i % 4] >= WIN_SCORE) {
            return 1;       //Win
        }
    }
    //�п�
    for (int i = 0; i <= SIZE * SIZE; i++) {
        if (board[i / 4][i % 4] == 0) {
            return 0;
        }
    }

    //��������ͬ
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i < 3) {
                if (board[i][j] == board[i + 1][j]) {
                    return 0;
                }
            }
            if (j < 3) {
                if (board[i][j] == board[i][j + 1]) {
                    return 0;
                }
            }
        }
    }

    return 2;   //Defeatd

}
