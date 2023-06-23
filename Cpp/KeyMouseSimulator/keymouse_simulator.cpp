#include<windows.h>
#include<winable.h>
#include "win_simu.h"
#define FILENAME "$input.txt"

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

	printf("* Welcome to $imulatorV1.1!~\n");
	printf("* Screen_x = %d px; Screen_y = %d px.\n",screen_x,screen_y);
	printf("-------------------------------------------------\n");
	
	vector<string> lineArr;
	/* file to lines */
	FILE *fd_input;
	/* win verison */
	/*
	errno_t err;
	if ((err = fopen_s(&fd_input, FILENAME, "r")) != 0)
	{
		printf("* [ERROR] Can not open \"./%s\"!\nPress any key to exit...", FILENAME);
		getchar();
		return -1;
	}
	*/
	/* linux version */
	fd_input = fopen("$input.txt", "r");
	if (NULL == fd_input)
	{
		printf("* [ERROR] Can not open \"./%s\"!\nPress any key to exit...", FILENAME);
		getchar();
		return -1;
	}

	/* read input file */
	while (!feof(fd_input))
	{
		char strline[100] = { 0 };
		memset(strline, 0, sizeof(strline));
		fgets(strline, sizeof(strline) - 1, fd_input);
		lineArr.push_back(strline);
	}
	fclose(fd_input);
	printf("* Open & Read %s successfully, which has %d lines!\n", FILENAME, lineArr.size());

	printf("* Start to simulate!\n");
	printf("-------------------------------------------------\n");

	string strline;

	int slp_index;
	int keys_num;
	int *keys;
	int loopBeginLine = 0;
	int loopAllCount = 0;
	int loopCount = 0;

	//lines to commands
	//vector<string>::iterator lineArr_it;
	//for (lineArr_it = lineArr.begin(); lineArr_it != lineArr.end(); lineArr_it++)
	for (int lineIndex = 0; lineIndex < lineArr.size(); lineIndex++)
	{
		//strline = *lineArr_it;
		strline = lineArr[lineIndex];
		printf("- Executing LINE %d / %d: %s", lineIndex + 1, lineArr.size(), strline.data());
		int stri = 0;
		if(strline[stri] != '\n' && strline[stri] != '#' && strline[stri] != '\0')  //# for comments
		{
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
							if((dev == 8 || dev == 9) && count_temp >= 2){
								temp.push_back(atoi(temp_c));
								continue;
							}
							else temp.push_back(atoi(temp_c));
						}
					}
				}

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
				case 8:  //loop
						 //cmd: dev typ (num)
					if (temp[1] == 0)	//begin
					{
						if (loopAllCount <= 0)	//first loop
						{
							if (temp.size() >= 3 && temp[2] >= 1)
							{
								loopAllCount = temp[2];
							}
							else
							{
								loopAllCount = 1;
							}
							loopCount = 1;
							loopBeginLine = lineIndex;
							printf("   Loop: begin! times = %d / %d.", loopCount, loopAllCount);
						}
						else	//in the loop
						{
							loopCount++;
							printf("   Loop times = %d / %d.", loopCount, loopAllCount);
						}
					}
					else	//end
					{
						if (loopCount < loopAllCount)	//next loop
						{
							lineIndex = loopBeginLine - 1;	// for loopBeginLine++
							printf("   Next loop.");
						}
						else	//end loop
						{
							loopAllCount = 0;
							printf("   Loop: end!");
						}
					}
					printf("\n");
					break;
				case 9:  //pause
						 //cmd: dev slp
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
					printf("* [WARN] not support dev - %d\n",temp[0]);
					break;
			}
			
			
		}
	}
	
	printf("\n-------------------------------------------------\n");
	printf("* BYE~~\nPress any key to exit...");
	getchar();
	return 0;
}
