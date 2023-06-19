#include<windows.h>
#include<winable.h>
#include "win_simu.h"

void initial()
{
	set_VK_num();
	screen_x = GetSystemMetrics(SM_CXSCREEN);
	screen_y = GetSystemMetrics(SM_CYSCREEN);
	flag_lm = false;
	flag_rm = false;
}

int main()
{
	initial();
	printf("* Welcome to $imulator~\n");
	printf("* Screen_x = %d px; Screen_y = %d px.\n",screen_x,screen_y);
	printf("-------------------------------------------------\n");
	
	/* open ./$input.txt */
	FILE *fd_input = fopen("$input.txt", "r");
	if(NULL == fd_input)
  	{
    	printf("* Can not open \"./$input.txt\"!\n");
		getchar();
    	return -1;
  	}
  	else printf("* Open \"./$input.txt\" successfully.\n");
	//Sleep(3000);	//pause for 3000ms
	
	printf("* Start to simulate!\n");
	printf("-------------------------------------------------\n");
	
 /*
  * In order to simulate two devices, mouse and keyboard, "dev" is required firstly
  * - dev(device) : 0-mouse, 1-keyboard, 9-pause
  *		1. dev = 0 = mouse
  *			- cmd : dev typ x y (slp)
  *				- dev : must be 0
  *				- typ(type) : 0-left click, 1-left press/release, 2-left double click, 3-right click, 4-right press/release, 5-move, 9-pause
  *				- x,y : absolute position
  *				- slp : sleep(microsecond)
  *					(1) type 0/1/2/3/4/5 : not necessary (default 1000ms, set by DEF_SLP_TIME in "win_simu.h")
  *					(2) type 9 : <=0 means pause until input a char, >0 means pause for specific microseconds
  *		2. dev = 1 = keyboard
  *			- cmd : dev typ num {key} (slp)
  *				- dev : must be 1
  *				- typ : 0-click, 1-press/release, 9-puase
  *				- num : number of key array
  *				- key : array of key value (support constant or value of virtual-key codes)
  *					(see at "win_simu.h"-set_VK_num or https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes)
  *					e.g. VK_LWIN or 0x5B or 91
  *					num > 1, for example, you must input cmd like "1 0 2 VK_LWIN D (slp)"
  *				- slp : sleep(microsecond)
  *					(1) type 0/1 : not necessary (default 1000ms, set by DEF_SLP_TIME in "win_simu.h")
  *					(2) type 9 : <=0 means pause until input a char, >0 means pause for specific microseconds
  *							tip: "1 9 0 slp" is recommended
  *		3. dev = 9 = pause
  *			- cmd : dev slp
  *				- dev : must be 9
  *				- slp : sleep(microsecond), <=0 means pause until input a char, >0 means pause for specific microseconds
  * tips:
  * 1. Use "win_getdata.exe" to get position data.
  * 2. PC's screen resolution doesn't matter.
  *	3. How to use pause function:
  *		dev = 0 = mouse: x and y is not used but required, so "0 9 0 0 slp" is recommended, though x and y can be any strings
  *		dev = 1 = keyboard: "1 9 0 slp" is recommended, though "1 9 2 VK_LWIN D slp",for example, also works(won't click keyboard)
  *		dev = 9 = pause: it's easy,  u know it!
  *		ATTENTION PLS : microsecond!!!
  * 4. DO Not forget to release keyboard after using press keyboard!!!
  * 5. Although actually it's OK if u forget to release before using click mouse, it's a good habit to release.
  * 6. Use "#" to add comments, just like "//" in C/C++
  * ATTENTION PLS: A newline at end of file-"$input.txt" or one comment,e.g. "#end", is SUPER necessary!!! 
  */
	
	
	char strline[100] = {0};
	int count_line = 0;
	int slp_index;
	int keys_num;
	int *keys;
	
	while(!feof(fd_input))
	{
		memset(strline, 0, sizeof(strline));
		fgets(strline, sizeof(strline) - 1, fd_input);
		count_line++;
		int stri = 0;
		if(strline[stri] != '\n' && strline[stri] != '#' && strline[stri] != '\0')  //# for comments
		{
			printf("- Executing LINE %d: %s", count_line, strline);
			while(strline[stri] == ' ' || strline[stri] == '\t')stri++; //to skip space and tab
			int dev = strline[stri] - '0';
			if(dev < 0 || dev > 9)continue;
			
			vector<int> temp;
			temp.push_back(dev);
			
				stri++; //skip dev
				int count_temp = 1;	//dev
				while(strline[stri] != '\n' && strline[stri] != '#')
				{
					char temp_c[20] = "";
					int temp_ci = 0;
					while(strline[stri] == ' ' || strline[stri] == '\t')stri++;
					while(strline[stri] != '\n' && strline[stri] != '#' && strline[stri] != ' ' && strline[stri] != '\t')
					{
					  temp_c[temp_ci++] = strline[stri++]; 
					}
					count_temp++;
					temp_c[temp_ci] = '\0';
					if(temp_c[0] != '\0'){
						if(dev == 1 && count_temp >= 4 && count_temp <= (3+temp[2]))	//keys
						{
							if(temp_c[0]=='V'&&temp_c[1]=='K')temp.push_back(get_VK(temp_c));
							else{
								if(temp_c[1]=='\0'&&((temp_c[0]>='A'&&temp_c[0]<='Z')||(temp_c[0]>='0'&&temp_c[0]<='9')))temp.push_back(get_VK(temp_c));
								else{
									if(temp_c[0]=='0'&&temp_c[1]=='x')
									{
										char *temp_c_temp;
										temp.push_back((int)(strtol(temp_c,&temp_c_temp,16)));
									}
									else temp.push_back(atoi(temp_c));
								}
							}
						}
						else{
							if(dev == 9 && count_temp == 2){
								temp.push_back(atoi(temp_c));
								continue;
							}
							else temp.push_back(atoi(temp_c));
						}
					}
				}
			
			//vector<int>::iterator it;
			//for(it=temp.begin();it!=temp.end();it++)cout<<*it<<" ";cout<<endl;
			
			int sleeptime = DEF_SLP_TIME;
			
			switch(temp[0]){
				case 0:	//mouse
						//cmd: dev typ x y (slp)
					if(temp.size() >= 4){
						switch(temp[1]){
							case 0:	//left click
								printf("   click the left mouse button at (%d,%d)\n",temp[2],temp[3]);
								break;
							case 1:	//left press/release
								if(flag_lm)printf("   release the left mouse button at (%d,%d)\n",temp[2],temp[3]);
								else printf("   press the left mouse button and hold at (%d,%d)\n",temp[2],temp[3]);
								break;
							case 2:	//left double-click
								printf("   double-click the left mouse button at (%d,%d)\n",temp[2],temp[3]);
								break;
							case 3:	//right click
								printf("   click the right mouse button at (%d,%d)\n",temp[2],temp[3]);
								break;
							case 4:	//right press/release
								if(flag_rm)printf("   release the right mouse button at (%d,%d)\n",temp[2],temp[3]);
								else printf("   press the right mouse button and hold at (%d,%d)\n",temp[2],temp[3]);
								break;
							case 5:
								simulate_mouse_move(temp[2],temp[3]);
								if(temp.size() >= 5)sleeptime = MAX(temp[4],1);
								break;
							case 9:
								if(temp.size() >= 5){
									if(temp[1] <= 0)
									{
										printf("* Pause until input a char : ");
										getchar();
									}
									else{
										printf("* Pause for %dms : 0/%d", temp[1], temp[1]);
										int remaining = temp[1];
										while(remaining != 0)
										{
											if(remaining < 1000)
											{
												Sleep(remaining);
												remaining = 0;
											}
											else{
												Sleep(1000);
												remaining -= 1000;
											}
											printf("\r* Pause for %dms : %d/%d", temp[1], temp[1]-remaining, temp[1]);
											fflush(stdout);
										}
										printf("\n");
									}
								}
								else{
									printf("* HEY MAN! U forgot to set sleep time! The program won't go on until input a char : ");
									getchar();
								}
								break;
							default:
								printf("* not support typ-%d of dev-%d \n",temp[1],temp[0]);
								break;
						}
						if(temp[1]>=0 && temp[1]<=4){
							simulate_mouse_move(temp[2],temp[3]);
							simulate_mouse_click(temp[1]);
							if(temp.size() >= 5)sleeptime = MAX(temp[4],1);
						}
					}
					if(temp[1]>=0 && temp[1]<=5)Sleep(sleeptime);
					break;
				case 1:	//keyboard
						//cmd: dev typ num {key} (slp)
					slp_index = 4 + temp[2];
					keys_num = temp[2];
					keys = new int[keys_num];
						for(int iii = 0; iii < keys_num; iii++){
							keys[iii] = temp[3+iii];
						}
					switch(temp[1]){
						case 0:	//click
							simulate_keyboard(keys_num,true,keys);
							if(temp.size() >= slp_index)sleeptime = MAX(temp[slp_index-1],1);
							break;
						case 1:	//press-release
							simulate_keyboard(keys_num,false,keys);
							if(temp.size() >= slp_index)sleeptime = MAX(temp[slp_index-1],1);
							break;
						case 9:
							if(temp.size() >= 5){
								if(temp[1] <= 0)
								{
									printf("* Pause until input a char : ");
									getchar();
								}
								else{
									printf("* Pause for %dms : 0/%d", temp[1], temp[1]);
									int remaining = temp[1];
									while(remaining != 0)
									{
										if(remaining < 1000)
										{
											Sleep(remaining);
											remaining = 0;
										}
										else{
											Sleep(1000);
											remaining -= 1000;
										}
										printf("\r* Pause for %dms : %d/%d", temp[1], temp[1]-remaining, temp[1]);
										fflush(stdout);
									}
									printf("\n");
								}
							}
							else{
								printf("* HEY MAN! U forgot to set sleep time! The program won't go on until input a char : ");
								getchar();
							}
							break;
						default:
							printf("* not support typ-%d of dev-%d \n",temp[1],temp[0]);
							break;
					}
					if(temp[1]==0 || temp[1]==1)Sleep(sleeptime);
					break;
				case 9:
					  if(temp[1] <= 0)
					  {
						printf("* Pause until input a char : ");
						getchar();
					  }
					  else{
						printf("* Pause for %dms : 0/%d", temp[1], temp[1]);
						int remaining = temp[1];
						while(remaining != 0)
						{
						  if(remaining < 1000)
						  {
							  Sleep(remaining);
							  remaining = 0;
						  }
						  else{
							  Sleep(1000);
							  remaining -= 1000;
						  }
						  printf("\r* Pause for %dms : %d/%d", temp[1], temp[1]-remaining, temp[1]);
						  fflush(stdout);
						}
						printf("\n");
					  }
					break;
				default:
					printf("* not support dev - %d\n",temp[0]);
					break;
			}
			
			
		}
	}
	
	
	printf("-------------------------------------------------\n");
	printf("* BYE~~\n");

	fclose(fd_input);  
	getchar();
	return 0;
}


/*
	INPUT input[4];
	memset(input, 0, sizeof(input));
	
	input[0].type = input[1].type = input[2].type = input[3].type = INPUT_KEYBOARD;

	input[0].ki.wVk = input[3].ki.wVk = VK_LWIN;
	input[1].ki.wVk = input[2].ki.wVk = 0x44;

	input[2].ki.dwFlags = input[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, input, sizeof(INPUT));
*/


/*
	INPUT input[2];
	memset(input, 0, sizeof(input));
	
	input[0].type = input[1].type = INPUT_KEYBOARD;

	//input[0].ki.wVk = input[3].ki.wVk = VK_LWIN;
	input[0].ki.wVk = input[1].ki.wVk = 0x44;

	input[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, input, sizeof(INPUT));
*/

/*
	INPUT input[2];
	memset(input, 0, sizeof(input));
	input[0].type = input[1].type = INPUT_MOUSE;

	input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

	SendInput(sizeof(input)/sizeof(INPUT), input, sizeof(INPUT));
*/

/*
	INPUT input[4];
	memset(input, 0, sizeof(input));
	input[0].type = input[1].type = input[2].type = input[3].type = INPUT_MOUSE;

	input[0].mi.dwFlags = input[2].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	input[1].mi.dwFlags = input[3].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	
	SendInput(sizeof(input)/sizeof(INPUT), input, sizeof(INPUT));
*/

/*
	POINT pt;
	BOOL bReturn;
	while(getchar()!='\n')
	{
		bReturn = GetCursorPos(&pt); //获取鼠标指针位置到pt

		if (bReturn != false) //如果函数执行成功
			cout << "Cursor postition is: " << pt.x << "," << pt.y << endl; //显示pt中的数据
		else //如果函数没有执行成功
			cout << "Error!" << endl; //报错
	}
*/

/*
	INPUT Input;
	memset(&Input, 0, sizeof(Input));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = get_dx(1750);
	Input.mi.dy = get_dy(170);
	SendInput(1, &Input, sizeof(INPUT));
*/
