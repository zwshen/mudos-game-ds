// Room: /u/t/tmr/area/woodhouse.c

#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "草房");
	set("long", @LONG
雖只用草覆蓋著，卻高爽寬敞，窗格明亮。堂中掛一幅無名小畫，設
一張白木臥榻。桌凳之顏色潔淨青白，堂後精舍數間，臥室在內。向陽設
兩扇柴門，門外一條竹徑，兩邊都結柏展遮護。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"lake-road3",
]));
	set("item_desc", ([ /* sizeof() == 1 */
//  "out" : (: look_door,     "out" :),
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chiou" : 1,
]));
	set("light",1);
	set("no_clean_up", 0);

	setup();
      create_door("out", "柴門", "enter", DOOR_CLOSED);
}
