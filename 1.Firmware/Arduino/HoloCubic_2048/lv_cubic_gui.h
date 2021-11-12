#ifndef LV_CUBIC_GUI_H
#define LV_CUBIC_GUI_H



#ifdef __cplusplus
extern "C" {
#endif



#include "lvgl.h"

	//extern lv_img_dsc_t screen_buffer;


	extern lv_obj_t* scr1;


	void lv_holo_cubic_gui(void);
	const lv_img_dsc_t* getN(int i);
	void showBoard(int* map);
	void showAnim(int* animMap, int direction, int newborn, int* map);
	void born(int i);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  
