#include <Arduino.h>
#include "display.h"
#include "imu.h"
#include "rgb_led.h"
#include "lv_port_indev.h"
#include "lv_cubic_gui.h"

#include "lv_demo_encoder.h"

#include "game2048.h"


/*** Component objects ***/
Display screen;
IMU mpu;
Pixel rgb;
GAME2048 game;

int *p;
int* m;

long time1;


void taskOne( void * parameter ){
  while(1){
	//心跳任务
	lv_tick_inc(5);
	delay(5);
  }
  Serial.println("Ending task 1");
  vTaskDelete( NULL );
}

void taskTwo(void * parameter){
	while(1){
		//LVGL任务主函数
		screen.routine();
		delay(5);
	}
  Serial.println("Ending task 1");
  vTaskDelete( NULL );
}

void setup()
{
	Serial.begin(115200);
	randomSeed(analogRead(25));

	/*** Init screen ***/
	screen.init();
	screen.setBackLight(0.2);

	/*** Init IMU as input device ***/
	lv_port_indev_init();
	mpu.init();

	/*** Init on-board RGB ***/
	rgb.init();
	rgb.setBrightness(64).setRGB(153, 170, 255);


	lv_holo_cubic_gui();
	xTaskCreate(
				taskOne,          /*任务函数*/
				"TaskOne",        /*带任务名称的字符串*/
				10000,            /*堆栈大小，单位为字节*/
				NULL,             /*作为任务输入传递的参数*/
				1,                /*任务的优先级*/
				NULL);            /*任务句柄*/

	xTaskCreate(
				taskTwo,          /*任务函数*/
				"TaskTwo",        /*带任务名称的字符串*/
				10000,            /*堆栈大小，单位为字节*/
				NULL,             /*作为任务输入传递的参数*/
				1,                /*任务的优先级*/
				NULL);            /*任务句柄*/

	/*** Init 2048 game ***/
	game.init();
	p = game.getBoard();
	m = game.getMoveRecord();
	//刷新棋盘显示
	int new1 = game.addRandom();
	int new2 = game.addRandom();
	showBoard(p);
	//棋子出生动画
	born(new1);
	born(new2);
	//等待动画播放完毕
	delay(300);
	time1 = millis();





}

int flag = 0;	//用于防止误操作
int Normal = 0;	//记录移动的方向
int BornLocation = 0; //记录新棋子的位置 

void loop(){
	while(1){
		mpu.update(200);
		Serial.printf("AccelX:%d\n", mpu.getAccelX());
		Serial.printf("AccelY:%d\n", mpu.getAccelY());
		Serial.printf("AccelX:%d\n", mpu.getAccelZ());
		Serial.printf("GyroX:%d\n", mpu.getGyroX());
		Serial.printf("GyroY:%d\n", mpu.getGyroY());
		Serial.printf("GyroZ:%d\n", mpu.getGyroZ());

		//优先判断左右
		if(mpu.getAccelY() >= 5000 && flag == 0){	//左
			game.moveLeft();
			if (game.comparePre() == 0) { 
				showAnim(m,3,game.addRandom(),p);
			}
			flag = 1;
			Serial.println("Right!");
		}else if(mpu.getAccelY() <= -5000 && flag == 0){	//右
			game.moveRight();
			if (game.comparePre() == 0) {
				showAnim(m,4,game.addRandom(),p);
			}
			flag = 1;
			Serial.println("Left!");
		}else if(mpu.getAccelX() >= 9000 && flag == 0){	//上
			game.moveUp();
			if (game.comparePre() == 0) {
				showAnim(m,1,game.addRandom(),p);
			}
			flag = 1;
			Serial.println("Up!");

		}else if(mpu.getAccelX() <= -2000 && flag == 0){	//下
			game.moveDown();
			if (game.comparePre() == 0) {
				showAnim(m,2,game.addRandom(),p);
			}
			flag = 1;
			Serial.println("Down!");

		}else if(mpu.getAccelX() <= 7000 && mpu.getAccelX() >= -1000 && mpu.getAccelY() <= 5000 && mpu.getAccelY() >= -5000){
			flag = 0;
			continue;
		}else{
			continue;
		}
		
		if(game.Judge() == 1){
			rgb.setRGB(0, 255, 0);
			Serial.println("you win!");
		}else if(game.Judge() == 2){
			rgb.setRGB(255, 0, 0);
			Serial.println("you lose!");
		}


		delay(300);
	
	
	}
}