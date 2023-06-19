#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y

#define DEF_SLP_TIME 1000	//default sleep time/ms

/**********全局变量***********/
map<string, int> VK_num;
int screen_x, screen_y;
bool flag_lm, flag_rm;	//mouse status, false means up, true means down
/***************************/

void showmap(map<string, int> v)
{
    for (map<string, int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout<<it->first<<"  "<<it->second<<endl;
    }
    cout << endl;
}


void set_VK_num()
{
	VK_num.insert(pair<string, int>("VK_LBUTTON",1));	//鼠标左键
	VK_num.insert(pair<string, int>("VK_RBUTTON",2));	//鼠标右键
	VK_num.insert(pair<string, int>("VK_CANCEL",3));	//Cancel
	VK_num.insert(pair<string, int>("VK_MBUTTON",4));	//鼠标中键
	VK_num.insert(pair<string, int>("VK_XBUTTON1",5));
	VK_num.insert(pair<string, int>("VK_XBUTTON2",6));
	VK_num.insert(pair<string, int>("VK_BACK",8));		//Backspace
	VK_num.insert(pair<string, int>("VK_TAB",9));		//Tab
	VK_num.insert(pair<string, int>("VK_CLEAR",12));	//Clear
	VK_num.insert(pair<string, int>("VK_RETURN",13));	//Enter
	VK_num.insert(pair<string, int>("VK_SHIFT",16));	//Shift
	VK_num.insert(pair<string, int>("VK_CONTROL",17));	//Ctrl
	VK_num.insert(pair<string, int>("VK_MENU",18));		//Alt
	VK_num.insert(pair<string, int>("VK_PAUSE",19));	//Pause
	VK_num.insert(pair<string, int>("VK_CAPITAL",20));	//Caps Lock
	VK_num.insert(pair<string, int>("VK_KANA",21));
	VK_num.insert(pair<string, int>("VK_HANGUL",21));
	VK_num.insert(pair<string, int>("VK_JUNJA",23));
	VK_num.insert(pair<string, int>("VK_FINAL",24));
	VK_num.insert(pair<string, int>("VK_HANJA",25));
	//VK_num.insert(pair<string, int>(e "VK_KANJI",25*));
	VK_num.insert(pair<string, int>("VK_ESCAPE",27));	//Esc
	VK_num.insert(pair<string, int>("VK_CONVERT",28));
	VK_num.insert(pair<string, int>("VK_NONCONVERT",29));
	VK_num.insert(pair<string, int>("VK_ACCEPT",30));
	VK_num.insert(pair<string, int>("VK_MODECHANGE",31));
	VK_num.insert(pair<string, int>("VK_SPACE",32));	//Space
	VK_num.insert(pair<string, int>("VK_PRIOR",33));	//Page Up
	VK_num.insert(pair<string, int>("VK_NEXT",34));		//Page Down
	VK_num.insert(pair<string, int>("VK_END",35));		//End
	VK_num.insert(pair<string, int>("VK_HOME",36));		//Home
	VK_num.insert(pair<string, int>("VK_LEFT",37));		//Left Arrow
	VK_num.insert(pair<string, int>("VK_UP",38));		//Up Arrow
	VK_num.insert(pair<string, int>("VK_RIGHT",39));	//Right Arrow
	VK_num.insert(pair<string, int>("VK_DOWN",40));		//Down Arrow
	VK_num.insert(pair<string, int>("VK_SELECT",41));	//Select
	VK_num.insert(pair<string, int>("VK_PRINT",42));	//Print
	VK_num.insert(pair<string, int>("VK_EXECUTE",43));	//Execute
	VK_num.insert(pair<string, int>("VK_SNAPSHOT",44));	//Snapshot
	VK_num.insert(pair<string, int>("VK_INSERT",45));	//Insert
	VK_num.insert(pair<string, int>("VK_DELETE",46));	//Delete
	VK_num.insert(pair<string, int>("VK_HELP",47));		//Help

	VK_num.insert(pair<string, int>("0",48));
	VK_num.insert(pair<string, int>("1",49));
	VK_num.insert(pair<string, int>("2",50));
	VK_num.insert(pair<string, int>("3",51));
	VK_num.insert(pair<string, int>("4",52));
	VK_num.insert(pair<string, int>("5",53));
	VK_num.insert(pair<string, int>("6",54));
	VK_num.insert(pair<string, int>("7",55));
	VK_num.insert(pair<string, int>("8",56));
	VK_num.insert(pair<string, int>("9",57));
	VK_num.insert(pair<string, int>("A",65));
	VK_num.insert(pair<string, int>("B",66));
	VK_num.insert(pair<string, int>("C",67));
	VK_num.insert(pair<string, int>("D",68));
	VK_num.insert(pair<string, int>("E",69));
	VK_num.insert(pair<string, int>("F",70));
	VK_num.insert(pair<string, int>("G",71));
	VK_num.insert(pair<string, int>("H",72));
	VK_num.insert(pair<string, int>("I",73));
	VK_num.insert(pair<string, int>("J",74));
	VK_num.insert(pair<string, int>("K",75));
	VK_num.insert(pair<string, int>("L",76));
	VK_num.insert(pair<string, int>("M",77));
	VK_num.insert(pair<string, int>("N",78));
	VK_num.insert(pair<string, int>("O",79));
	VK_num.insert(pair<string, int>("P",80));
	VK_num.insert(pair<string, int>("Q",81));
	VK_num.insert(pair<string, int>("R",82));
	VK_num.insert(pair<string, int>("S",83));
	VK_num.insert(pair<string, int>("T",84));
	VK_num.insert(pair<string, int>("U",85));
	VK_num.insert(pair<string, int>("V",86));
	VK_num.insert(pair<string, int>("W",87));
	VK_num.insert(pair<string, int>("X",88));
	VK_num.insert(pair<string, int>("Y",89));
	VK_num.insert(pair<string, int>("Z",90));

	VK_num.insert(pair<string, int>("VK_LWIN",91));		//左WIN键
	VK_num.insert(pair<string, int>("VK_RWIN",92));		//右WIN键
	VK_num.insert(pair<string, int>("VK_APPS",93));		//应用程序键
	VK_num.insert(pair<string, int>("VK_SLEEP",95));	//睡眠键
	VK_num.insert(pair<string, int>("VK_NUMPAD0",96));	//小键盘 0
	VK_num.insert(pair<string, int>("VK_NUMPAD1",97));	//小键盘 1
	VK_num.insert(pair<string, int>("VK_NUMPAD2",98));	//小键盘 2
	VK_num.insert(pair<string, int>("VK_NUMPAD3",99));	//小键盘 3
	VK_num.insert(pair<string, int>("VK_NUMPAD4",100));	//小键盘 4
	VK_num.insert(pair<string, int>("VK_NUMPAD5",101));	//小键盘 5
	VK_num.insert(pair<string, int>("VK_NUMPAD6",102));	//小键盘 6
	VK_num.insert(pair<string, int>("VK_NUMPAD7",103));	//小键盘 7
	VK_num.insert(pair<string, int>("VK_NUMPAD8",104));	//小键盘 8
	VK_num.insert(pair<string, int>("VK_NUMPAD9",105));	//小键盘 9
	VK_num.insert(pair<string, int>("VK_MULTIPLY",106));//小键盘 *
	VK_num.insert(pair<string, int>("VK_ADD",107));		//小键盘 +
	VK_num.insert(pair<string, int>("VK_SEPARATOR",108));//小键盘 Enter
	VK_num.insert(pair<string, int>("VK_SUBTRACT",109));//小键盘 -
	VK_num.insert(pair<string, int>("VK_DECIMAL",110));	//小键盘 .
	VK_num.insert(pair<string, int>("VK_DIVIDE",111));	//小键盘 /
	VK_num.insert(pair<string, int>("VK_F1",112));		//F1
	VK_num.insert(pair<string, int>("VK_F2",113));		//F2
	VK_num.insert(pair<string, int>("VK_F3",114));		//F3
	VK_num.insert(pair<string, int>("VK_F4",115));		//F4
	VK_num.insert(pair<string, int>("VK_F5",116));		//F5
	VK_num.insert(pair<string, int>("VK_F6",117));		//F6
	VK_num.insert(pair<string, int>("VK_F7",118));		//F7
	VK_num.insert(pair<string, int>("VK_F8",119));		//F8
	VK_num.insert(pair<string, int>("VK_F9",120));		//F9
	VK_num.insert(pair<string, int>("VK_F10",121));		//F10
	VK_num.insert(pair<string, int>("VK_F11",122));		//F11
	VK_num.insert(pair<string, int>("VK_F12",123));		//F12

	VK_num.insert(pair<string, int>("VK_NUMLOCK",144));	//Num Lock
	VK_num.insert(pair<string, int>("VK_SCROLL",145));	//Scroll
	VK_num.insert(pair<string, int>("VK_LSHIFT",160));	//左shift
	VK_num.insert(pair<string, int>("VK_RSHIFT",161));	//右shift
	VK_num.insert(pair<string, int>("VK_LCONTROL",162));
	VK_num.insert(pair<string, int>("VK_RCONTROL",163));
	VK_num.insert(pair<string, int>("VK_LMENU",164));
	VK_num.insert(pair<string, int>("VK_RMENU",165));
	
	VK_num.insert(pair<string, int>("VK_OEM_1",186));	// ; :
	VK_num.insert(pair<string, int>("VK_OEM_PLUS",187));	// = +
	VK_num.insert(pair<string, int>("VK_OEM_COMMA",188));	// ,
	VK_num.insert(pair<string, int>("VK_OEM_MINUS",189));	// - _
	VK_num.insert(pair<string, int>("VK_OEM_PERIOD",190));	// .
	VK_num.insert(pair<string, int>("VK_OEM_2",191));	// / ?
	VK_num.insert(pair<string, int>("VK_OEM_3",192));	// ` ~
	VK_num.insert(pair<string, int>("VK_OEM_4",219));	// [ {
	VK_num.insert(pair<string, int>("VK_OEM_5",220));	// \ |
	VK_num.insert(pair<string, int>("VK_OEM_6",221));	// ] }
	VK_num.insert(pair<string, int>("VK_OEM_7",222));	// ' "
	
}

int get_VK(string str)
{
	return VK_num[str];
}

int get_dx(int i)
{
	//取绝对坐标时，屏幕相当于被分为65536等份
	return 65535 * i / screen_x;
}

int get_dy(int i)
{
	//取绝对坐标时，屏幕相当于被分为65536等份
	return 	65535 * i / screen_y;
}

void simulate_keyboard(int keys_num, bool is_click, int *keys)
{
	int str_num = is_click?(keys_num*2):keys_num;
	INPUT * input = new INPUT[str_num];
	memset(input, 0, sizeof(INPUT)*str_num);
	
	for(int i = 0; i < keys_num; i++)
	{
		input[i].type = INPUT_KEYBOARD;
		input[i].ki.wVk = keys[i];
		if(is_click){
			input[keys_num*2-1-i].type = INPUT_KEYBOARD;
			input[keys_num*2-1-i].ki.wVk = keys[i];
			input[keys_num*2-1-i].ki.dwFlags = KEYEVENTF_KEYUP;
		}
	}
	/*
	input[0].type = input[1].type = input[2].type = input[3].type = INPUT_KEYBOARD;
	input[0].ki.wVk = input[3].ki.wVk = VK_LWIN;
	input[1].ki.wVk = input[2].ki.wVk = 0x44;
	input[2].ki.dwFlags = input[3].ki.dwFlags = KEYEVENTF_KEYUP;
	*/
	
	SendInput(str_num, input, sizeof(INPUT));	
	delete input;
}

void simulate_mouse_click(int type)
{
	switch(type)
	{
		case 0:	//left click
			if(flag_lm){
				INPUT input8;
				memset(&input8, 0, sizeof(input8));
				input8.type = INPUT_MOUSE;
				input8.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				SendInput(1, &input8, sizeof(INPUT));
				flag_lm = false;			
			}
			INPUT input0[2];
			memset(input0, 0, sizeof(input0));
			input0[0].type = input0[1].type = INPUT_MOUSE;
			input0[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			input0[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(2, input0, sizeof(INPUT));
			break;
		case 1:	//left press/release
			INPUT input1;
			memset(&input1, 0, sizeof(input1));
			input1.type = INPUT_MOUSE;
			if(flag_lm){
				input1.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				flag_lm = false;			
			}
			else{
				input1.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
				flag_lm = true;
			}
			SendInput(1, &input1, sizeof(INPUT));
			break;
		case 2:	//left double click
			if(flag_lm){
				INPUT input8;
				memset(&input8, 0, sizeof(input8));
				input8.type = INPUT_MOUSE;
				input8.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				SendInput(1, &input8, sizeof(INPUT));
				flag_lm = false;			
			}
			INPUT input2[4];
			memset(input2, 0, sizeof(input2));
			input2[0].type = input2[1].type = input2[2].type = input2[3].type = INPUT_MOUSE;
			input2[0].mi.dwFlags = input2[2].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			input2[1].mi.dwFlags = input2[3].mi.dwFlags =  MOUSEEVENTF_LEFTUP;
			SendInput(4, input2, sizeof(INPUT));
			break;
		case 3:	//right click
			if(flag_rm){
				INPUT input8;
				memset(&input8, 0, sizeof(input8));
				input8.type = INPUT_MOUSE;
				input8.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
				SendInput(1, &input8, sizeof(INPUT));
				flag_rm = false;			
			}
			INPUT input3[2];
			memset(input3, 0, sizeof(input3));
			input3[0].type = input3[1].type = INPUT_MOUSE;
			input3[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			input3[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			SendInput(2, input3, sizeof(INPUT));
			break;
		case 4:	//right press/release
			INPUT input4;
			memset(&input4, 0, sizeof(input4));
			input4.type = INPUT_MOUSE;
			if(flag_rm){
				input4.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
				flag_rm = false;			
			}
			else{
				input4.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
				flag_rm = true;
			}
			SendInput(1, &input4, sizeof(INPUT));		
			break;
		default:
			printf("Function \"simulate_mouse_click()\" doesn't support type = %d",type);
			break;
	}
}

void simulate_mouse_move(int x, int y)
{
	INPUT Input;
	memset(&Input, 0, sizeof(Input));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = get_dx(x);
	Input.mi.dy = get_dy(y);
	SendInput(1, &Input, sizeof(INPUT));
}

/*
	//C++中，全局阈只能声明、初始化变量； 不能用于赋值、运算、调用函数等！！！
	VK_num["VK_LBUTTON"]=1 ;	//鼠标左键
	VK_num["VK_RBUTTON"]=2 ;	//鼠标右键
	VK_num["VK_CANCEL"]=3 ;		//Cancel
	VK_num["VK_MBUTTON"]=4 ;	//鼠标中键
	VK_num["VK_XBUTTON1"]=5 ;
	VK_num["VK_XBUTTON2"]=6 ;
	VK_num["VK_BACK"]=8 ;		//Backspace
	VK_num["VK_TAB"]=9 ;		//Tab
	VK_num["VK_CLEAR"]=12 ;		//Clear
	VK_num["VK_RETURN"]=13 ;	//Enter
	VK_num["VK_SHIFT"]=16 ;		//Shift
	VK_num["VK_CONTROL"]=17 ;	//Ctrl
	VK_num["VK_MENU"]=18 ;		//Alt
	VK_num["VK_PAUSE"]=19 ;		//Pause
	VK_num["VK_CAPITAL"]=20 ;	//Caps Lock
	VK_num["VK_KANA"]=21 ;
	VK_num["VK_HANGUL"]=21 ;
	VK_num["VK_JUNJA"]=23 ;
	VK_num["VK_FINAL"]=24 ;
	VK_num["VK_HANJA"]=25 ;
	//VK_num[e "VK_KANJI"]=25* ;
	VK_num["VK_ESCAPE"]=27 ;	//Esc
	VK_num["VK_CONVERT"]=28 ;
	VK_num["VK_NONCONVERT"]=29 ;
	VK_num["VK_ACCEPT"]=30 ;
	VK_num["VK_MODECHANGE"]=31 ;
	VK_num["VK_SPACE"]=32 ;		//Space
	VK_num["VK_PRIOR"]=33 ;		//Page Up
	VK_num["VK_NEXT"]=34 ;		//Page Down
	VK_num["VK_END"]=35 ;		//End
	VK_num["VK_HOME"]=36 ;		//Home
	VK_num["VK_LEFT"]=37 ;		//Left Arrow
	VK_num["VK_UP"]=38 ;		//Up Arrow
	VK_num["VK_RIGHT"]=39 ;		//Right Arrow
	VK_num["VK_DOWN"]=40 ;		//Down Arrow
	VK_num["VK_SELECT"]=41 ;	//Select
	VK_num["VK_PRINT"]=42 ;		//Print
	VK_num["VK_EXECUTE"]=43 ;	//Execute
	VK_num["VK_SNAPSHOT"]=44 ;	//Snapshot
	VK_num["VK_INSERT"]=45 ;	//Insert
	VK_num["VK_DELETE"]=46 ;	//Delete
	VK_num["VK_HELP"]=47 ;		//Help

	VK_num["0"]=48 ;
	VK_num["1"]=49 ;
	VK_num["2"]=50 ;
	VK_num["3"]=51 ;
	VK_num["4"]=52 ;
	VK_num["5"]=53 ;
	VK_num["6"]=54 ;
	VK_num["7"]=55 ;
	VK_num["8"]=56 ;
	VK_num["9"]=57 ;
	VK_num["A"]=65 ;
	VK_num["B"]=66 ;
	VK_num["C"]=67 ;
	VK_num["D"]=68 ;
	VK_num["E"]=69 ;
	VK_num["F"]=70 ;
	VK_num["G"]=71 ;
	VK_num["H"]=72 ;
	VK_num["I"]=73 ;
	VK_num["J"]=74 ;
	VK_num["K"]=75 ;
	VK_num["L"]=76 ;
	VK_num["M"]=77 ;
	VK_num["N"]=78 ;
	VK_num["O"]=79 ;
	VK_num["P"]=80 ;
	VK_num["Q"]=81 ;
	VK_num["R"]=82 ;
	VK_num["S"]=83 ;
	VK_num["T"]=84 ;
	VK_num["U"]=85 ;
	VK_num["V"]=86 ;
	VK_num["W"]=87 ;
	VK_num["X"]=88 ;
	VK_num["Y"]=89 ;
	VK_num["Z"]=90 ;

	VK_num["VK_LWIN"]=91 ;		//左WIN键
	VK_num["VK_RWIN"]=92 ;		//右WIN键
	VK_num["VK_APPS"]=93 ;		//应用程序键
	VK_num["VK_SLEEP"]=95 ;		//睡眠键
	VK_num["VK_NUMPAD0"]=96 ;	//小键盘 0
	VK_num["VK_NUMPAD1"]=97 ;	//小键盘 1
	VK_num["VK_NUMPAD2"]=98 ;	//小键盘 2
	VK_num["VK_NUMPAD3"]=99 ;	//小键盘 3
	VK_num["VK_NUMPAD4"]=100 ;	//小键盘 4
	VK_num["VK_NUMPAD5"]=101 ;	//小键盘 5
	VK_num["VK_NUMPAD6"]=102 ;	//小键盘 6
	VK_num["VK_NUMPAD7"]=103 ;	//小键盘 7
	VK_num["VK_NUMPAD8"]=104 ;	//小键盘 8
	VK_num["VK_NUMPAD9"]=105 ;	//小键盘 9
	VK_num["VK_MULTIPLY"]=106 ;	//小键盘 *
	VK_num["VK_ADD"]=107 ;		//小键盘 +
	VK_num["VK_SEPARATOR"]=108 ;//小键盘 Enter
	VK_num["VK_SUBTRACT"]=109 ;	//小键盘 -
	VK_num["VK_DECIMAL"]=110 ;	//小键盘 .
	VK_num["VK_DIVIDE"]=111 ;	//小键盘 /
	VK_num["VK_F1"]=112 ;		//F1
	VK_num["VK_F2"]=113 ;		//F2
	VK_num["VK_F3"]=114 ;		//F3
	VK_num["VK_F4"]=115 ;		//F4
	VK_num["VK_F5"]=116 ;		//F5
	VK_num["VK_F6"]=117 ;		//F6
	VK_num["VK_F7"]=118 ;		//F7
	VK_num["VK_F8"]=119 ;		//F8
	VK_num["VK_F9"]=120 ;		//F9
	VK_num["VK_F10"]=121 ;		//F10
	VK_num["VK_F11"]=122 ;		//F11
	VK_num["VK_F12"]=123 ;		//F12

	VK_num["VK_NUMLOCK"]=144 ;	//Num Lock
	VK_num["VK_SCROLL"]=145 ;	//Scroll
	VK_num["VK_LSHIFT"]=160 ;	//左shift
	VK_num["VK_RSHIFT"]=161 ;	//右shift
	VK_num["VK_LCONTROL"]=162 ;
	VK_num["VK_RCONTROL"]=163 ;
	VK_num["VK_LMENU"]=164 ;
	VK_num["VK_RMENU"]=165 ;
*/

/*
int get_VK(char const* str)
{
	switch(str)	//not support string
	{
		case "VK_LBUTTON" : return 1;	//鼠标左键
		case "VK_RBUTTON" : return 2;	//鼠标右键
		case "VK_CANCEL" : return 3;		//Cancel
		case "VK_MBUTTON" : return 4;	//鼠标中键
		case "VK_XBUTTON1" : return 5;
		case "VK_XBUTTON2" : return 6;
		case "VK_BACK" : return 8;		//Backspace
		case "VK_TAB" : return 9;		//Tab
		case "VK_CLEAR" : return 12;		//Clear
		case "VK_RETURN" : return 13;	//Enter
		case "VK_SHIFT" : return 16;		//Shift
		case "VK_CONTROL" : return 17;	//Ctrl
		case "VK_MENU" : return 18;		//Alt
		case "VK_PAUSE" : return 19;		//Pause
		case "VK_CAPITAL" : return 20;	//Caps Lock
		case "VK_KANA" : return 21;
		//case "VK_HANGUL" : return 21;
		case "VK_JUNJA" : return 23;
		case "VK_FINAL" : return 24;
		case "VK_HANJA" : return 25;
		//case "VK_KANJI" : return 25*;
		case "VK_ESCAPE" : return 27;	//Esc
		case "VK_CONVERT" : return 28;
		case "VK_NONCONVERT" : return 29;
		case "VK_ACCEPT" : return 30;
		case "VK_MODECHANGE" : return 31;
		case "VK_SPACE" : return 32;		//Space
		case "VK_PRIOR" : return 33;		//Page Up
		case "VK_NEXT" : return 34;		//Page Down
		case "VK_END" : return 35;		//End
		case "VK_HOME" : return 36;		//Home
		case "VK_LEFT" : return 37;		//Left Arrow
		case "VK_UP" : return 38;		//Up Arrow
		case "VK_RIGHT" : return 39;		//Right Arrow
		case "VK_DOWN" : return 40;		//Down Arrow
		case "VK_SELECT" : return 41;	//Select
		case "VK_PRINT" : return 42;		//Print
		case "VK_EXECUTE" : return 43;	//Execute
		case "VK_SNAPSHOT" : return 44;	//Snapshot
		case "VK_INSERT" : return 45;	//Insert
		case "VK_DELETE" : return 46;	//Delete
		case "VK_HELP" : return 47;		//Help

		case "0" : return 48;
		case "1" : return 49;
		case "2" : return 50;
		case "3" : return 51;
		case "4" : return 52;
		case "5" : return 53;
		case "6" : return 54;
		case "7" : return 55;
		case "8" : return 56;
		case "9" : return 57;
		case "A" : return 65;
		case "B" : return 66;
		case "C" : return 67;
		case "D" : return 68;
		case "E" : return 69;
		case "F" : return 70;
		case "G" : return 71;
		case "H" : return 72;
		case "I" : return 73;
		case "J" : return 74;
		case "K" : return 75;
		case "L" : return 76;
		case "M" : return 77;
		case "N" : return 78;
		case "O" : return 79;
		case "P" : return 80;
		case "Q" : return 81;
		case "R" : return 82;
		case "S" : return 83;
		case "T" : return 84;
		case "U" : return 85;
		case "V" : return 86;
		case "W" : return 87;
		case "X" : return 88;
		case "Y" : return 89;
		case "Z" : return 90;

		case "VK_LWIN" : return 91;		//左WIN键
		case "VK_RWIN" : return 92;		//右WIN键
		case "VK_APPS" : return 93;		//应用程序键
		case "VK_SLEEP" : return 95;		//睡眠键
		case "VK_NUMPAD0" : return 96;	//小键盘 0
		case "VK_NUMPAD1" : return 97;	//小键盘 1
		case "VK_NUMPAD2" : return 98;	//小键盘 2
		case "VK_NUMPAD3" : return 99;	//小键盘 3
		case "VK_NUMPAD4" : return 100;	//小键盘 4
		case "VK_NUMPAD5" : return 101;	//小键盘 5
		case "VK_NUMPAD6" : return 102;	//小键盘 6
		case "VK_NUMPAD7" : return 103;	//小键盘 7
		case "VK_NUMPAD8" : return 104;	//小键盘 8
		case "VK_NUMPAD9" : return 105;	//小键盘 9
		case "VK_MULTIPLY" : return 106;	//小键盘 *
		case "VK_ADD" : return 107;		//小键盘 +
		case "VK_SEPARATOR" : return 108;//小键盘 Enter
		case "VK_SUBTRACT" : return 109;	//小键盘 -
		case "VK_DECIMAL" : return 110;	//小键盘 .
		case "VK_DIVIDE" : return 111;	//小键盘 /
		case "VK_F1" : return 112;		//F1
		case "VK_F2" : return 113;		//F2
		case "VK_F3" : return 114;		//F3
		case "VK_F4" : return 115;		//F4
		case "VK_F5" : return 116;		//F5
		case "VK_F6" : return 117;		//F6
		case "VK_F7" : return 118;		//F7
		case "VK_F8" : return 119;		//F8
		case "VK_F9" : return 120;		//F9
		case "VK_F10" : return 121;		//F10
		case "VK_F11" : return 122;		//F11
		case "VK_F12" : return 123;		//F12

		case "VK_NUMLOCK" : return 144;	//Num Lock
		case "VK_SCROLL" : return 145;	//Scroll
		case "VK_LSHIFT" : return 160;	//左shift
		case "VK_RSHIFT" : return 161;	//右shift
		case "VK_LCONTROL" : return 162;
		case "VK_RCONTROL" : return 163;
		case "VK_LMENU" : return 164;
		case "VK_RMENU" : return 165;
	}
};
*/


