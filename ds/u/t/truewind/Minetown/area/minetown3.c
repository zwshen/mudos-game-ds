// Room: /u/t/truewind/Minetown/area/minetown3.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
此地豎立著一張大招牌，上頭用英文寫著"Crazy Bill Parking 
Lot"。三四輛輕型漂浮車停靠在這，還有一輛運輸型漂浮車正在卸貨
，看來是許多的食物。東邊的酒館傳出一陣陣的叫罵聲，而南邊傳來
誘人食慾的香味，讓你想馬上奔馳過去。
LONG
	);
	set("no_clean_up", 0);
	        set("objects", ([ 
        __DIR__"obj/parkingboard.c" :1 ,
]));
        set("current_light", 0);
	set("outdoors","land");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"minetown1",
  "west" : __DIR__"minetown4",
  "south" : __DIR__"foodshop",
  "east" : __DIR__"minetown_bill",
]));
	setup();
}
