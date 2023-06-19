#include <windows.h>                			//GetAsyncKeyState所需头文件
#include<winable.h>
#include <conio.h>
#include <iostream>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件
using namespace std;

int main() {
	//----------移除快速编辑模式(对于Win10用户)----------//
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);

	//----------循环检测----------//
	while (true) {
		Sleep(100);                  			//等待100毫秒，减少CPU占用
		if (KEY_DOWN(VK_ESCAPE))				//Esc键按下,退出循环
			break;
		else {
			if (KEY_DOWN(VK_LBUTTON)) {  			//鼠标左键按下
				POINT pt;
				BOOL bReturn;
				bReturn = GetCursorPos(&pt); //获取鼠标指针位置到pt
				if (bReturn != false)		 //如果函数执行成功
					cout << "0 0 " << pt.x << " " << pt.y << " 500    #mouse left click at (" << pt.x << "," << pt.y << ")" << endl; //显示pt中的数据
				else						//如果函数没有执行成功
					cerr << "#Error!" << endl;				//报错
			}
			else if (KEY_DOWN(VK_RBUTTON)) {  			//鼠标左键按下
				POINT pt;
				BOOL bReturn;
				bReturn = GetCursorPos(&pt); //获取鼠标指针位置到pt
				if (bReturn != false)		//如果函数执行成功
					cout << "0 3 " << pt.x << " " << pt.y << " 500    #mouse right click at (" << pt.x << "," << pt.y << ")" << endl; //显示pt中的数据
				else						//如果函数没有执行成功
					cerr << "#Error!" << endl;				//报错
			}
			else if (_kbhit()) {			//如果有按键按下，则_kbhit()函数返回真
				int ch = _getch();			//使用_getch()函数获取按下的键值
				if (ch == 27)				//Esc键按下,退出循环
					break;
				else {
					if (ch >= 97 && ch <= 122)		//a-z转大写A-Z
						ch -= 32;
					cout << "1 0 1 " << ch << " 100    #keyboard click button=" << (char)ch << endl;
				}
			}
		}
	}
	getchar();
	return 0;
}

