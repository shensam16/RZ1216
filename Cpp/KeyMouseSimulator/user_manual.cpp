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
  *					NOTE: While 1<=value<=9,use 0x1~0x9 or constant instead of 1~9
  *							e.g. key "backspace" ,which is VK_BACK or 0x8, DO NOT INPUT 8(which will be "8")
  *				- slp : sleep(microsecond)
  *					(1) type 0/1 : not necessary (default 1000ms, set by DEF_SLP_TIME in "win_simu.h")
  *					(2) type 9 : <=0 means pause until input a char, >0 means pause for specific microseconds
  *							tip: "1 9 0 slp" is recommended
  *		3. dev = 9 = pause
  *			- cmd : dev slp
  *				- dev : must be 9
  *				- slp : sleep(microsecond), <=0 means pause until input a char, >0 means pause for specific microseconds
  * tips:
  * 1. Use "keyboard_listener.exe" to get position data.
  *		How to: keep console window on top, click any keyboard to get current mouse position, click '.' to exit
  * 2. Edit "$input.txt" to realize your own simulate function.
  *	3. PC's screen resolution doesn't matter.
  *	4. How to use pause function:
  *		dev = 0 = mouse: x and y is not used but required, so "0 9 0 0 slp" is recommended, though x and y can be any strings
  *		dev = 1 = keyboard: "1 9 0 slp" is recommended, though "1 9 2 VK_LWIN D slp",for example, also works(won't click keyboard)
  *		dev = 9 = pause: it's easy,  u know it!
  *		ATTENTION PLS : microsecond!!!
  * 5. DO Not forget to release keyboard after using press keyboard!!!
  * 6. Although actually it's OK if u forget to release before using click mouse, it's a good habit to release.
  * 7. Use "#" to add comments, just like "//" in C/C++
  */