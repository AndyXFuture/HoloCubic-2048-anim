# HoloCubic-2048-anim

![](/3.Img/Img_1.jpg)

B站演示视频：https://www.bilibili.com/video/BV15T4y197Ly/

2048作为我学C语言做的第一个项目运行在HoloCubic上可以说是无比合适，所以我找到以前的代码想要移植到HoloCubic中，但两年前写的代码实在看不下去，所以我这次重新实现了一遍（只有游戏逻辑的部分开源在了https://github.com/AndyXFuture/2048，再此文档就不再次介绍了）

然后简单摸了摸LVGL就移植过来了，然后发现动画挺简单，就一起加上了，下面讲讲完成动画的思路。



**目录结构**

`Firmware`是HoloCubic的固件代码分为PlatformIO和Arduino环境，lvgl的部分都写在了`lv_cubic_gui.c`里

MPU的判断是给**Metal Version**外壳写的，所以前后的判断做了偏移



`Software`中有可以直接运行在VS2019的动画轨迹计算的测试程序







---



## 动画轨迹获取思路
因为2048移动时，移动垂直方向之间不会有任何影响，所以下面的示例都以**单行向右移动**做演示



通过String数组给存在数字的位置标记上ABCD，即棋盘移动前的位置信息

> 如：2024，即为：[A] [空] [C] [D]

然后将它的位移和合并操作并入棋盘的移动操作内

> 如：2024向右移动完成后则为0044
>
> 那么String数组那边则为[A] [空] [C] [D]变成[空] [空] [AC] [D]

之后就可以从变化完成的String数组读取到移动信息

> 如：[空] [空] [AC] [D]，则可以读出第一格向右移动了2格，第三格发生了合并

以上步骤循环即可获得一个int数组，里面存放着每格移动的方向、距离和是否发生了合并

我在这个项目设定的信息为：**`正负为方向，值为距离，存在合并则整个+8`**。



---

## LVGL动画实现思路
通过观察可以将2048的动画分为三种，方块出生动画，移动动画，合并动画

结合LVGL动画方面的操作，封装成了born()，move()，zoom()三个函数

然后根据动画轨迹获取到的int数组在`showAnim`函数做的调用。

---

## 存在的问题
* MPU有时会出现数据不稳乱抖的情况，暂时不影响正常游戏

* 没做游戏进度存储，断电就重开



---



## 其他的后续再补充，欢迎大家给视频三连