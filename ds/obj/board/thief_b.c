#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
	set_name("盜賊工會討論板",({"thief board","board"}));
	set("location","/open/world2/shengsan/aovandis/room087.c");
	set("board_id", "thief_b");
	set("long",@LONG
這個小黑板掛在工會的角落看起來並不顯眼，上面放了一個破舊
的板擦和幾隻斷掉的白色粉筆，上面寫的都是一些大盜們留下的一些
生存秘訣與各種新式的犯案手法。

LONG);
	setup();
  	set("capacity",100);
}
