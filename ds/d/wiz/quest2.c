// Room: /u/l/luky/workroom.c
#include <ansi.h>  //若要用有顏色的須加此行
#include <room.h> //要加門要這一行
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short","廢棄礦坑");  //短敘述
 set("long","\n"
	+"  這裡是一個廢棄礦坑的深處, 四週都是一些垃圾...還有一些小孩子的玩\n"
	+"具(toy)。由此可以確定某些孩子們真的把這個危險的地方當成了秘密基地了。\n"
 ); //長敘述
 set("exits", ([  //此房間連結之出口方向及檔案
 "south": __DIR__"quest1",
 ]));
 set("item_desc", ([
     "toy" : "一個孫悟空的模型玩具還有一些彈珠...全都亂七八糟的放在地上。\n",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 set("objects",([
 __DIR__"npc/boy":1,
 ]));
 create_door("south","黑色鐵門","north",DOOR_LOCKED,"redkey");
 setup();
}
