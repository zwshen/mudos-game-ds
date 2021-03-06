#include <ansi.h>
#include <box.h>
//#define COVER_NONE 	   	2
//#define COVER_OPENED    	3
//#define COVER_CLOSED		4
//#define COVER_SMASHED		5
//#define LOCK_NONE		6
//#define LOCK_OPENED	    	7
//#define LOCK_CLOSED		8
//#define LOCK_SMASHED		9
//inherit F_CLEAN_UP;
inherit BOX;
void create()
{

	set_name("髒鐵箱",({"dirty box","box"}));
        set("unit", "個");
        set("long",@LONG

你看到一個骯髒的鐵箱子，大概盜賊們練習開鎖用的。

  這個鐵箱可以用萬能匕首開鎖或是上鎖，你可以
  將箱子鎖上(lock box with dagger)或是打開它
  (unlock box with dagger)。

  如果你想用它來練習開鎖，建議你可以先將箱子
  鎖上然後試著使用開鎖技巧來開啟它(pick box)。

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        
        set_max_encumbrance(300000);
        set_max_capacity(50);
	set("cover_name","鐵蓋\");	//蓋子名稱
	set_cover(COVER_CLOSED);	//初始蓋子狀態 == 關閉
	set_lock(LOCK_CLOSED);		//初始鎖狀態 == 鎖上
	set_keys( ({"/open/always/thief_mark"}) ); //使用鑰匙檔案
	set_lock_level(1); //設定鎖的等級 1~10
	setup();
}

