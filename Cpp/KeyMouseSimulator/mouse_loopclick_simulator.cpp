#include<windows.h>
#include<winable.h>
#include "win_simu.h"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)  //用来检测按键的点击事件

int main() {
	//----------移除快速编辑模式(对于Win10用户)----------//
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);
	printf("* Welcome! Please click mouse middle button to start or end loop~\n");
	bool startFlag = false;
	bool endFlag = false;
	int counter = 0;
	//----------循环检测----------//
	while (true) {
		Sleep(50);                  			//等待50毫秒，减少CPU占用
		if (startFlag)
		{
			counter++;
			printf("\r    loop time=%d", counter);
			fflush(stdout);
			simulate_mouse_click(0);
		}
		if (endFlag)
		{
			printf("\n* End loop!\n");
			break;
		}
		if (KEY_DOWN(VK_MBUTTON)) {  			//鼠标中键按下
			if (!startFlag)
			{
				startFlag = true;
				printf("* Start loop!\n");
			}
			else if(counter > 20)
			{
				endFlag = true;
			}
		}
	}
	cout << "Press any key to exit...";
	getchar();
	return 0;
}

