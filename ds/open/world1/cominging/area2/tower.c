#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "守衛塔下");
	set("long", @LONG

你小心翼翼的進來了這個守衛塔的下方，這裡有許多的茶水和食物
，可以供給換下崗的士兵休息之用，還有些床舖，上面有一條大棉被，
可以給衛兵們歇息之用，這裡是一個圓環狀的小地方，四周都是用石頭
所做成的石壁，上面還掛著些油燈。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"tower_2.c",
  "out" : __DIR__"bwest5.c",
  "north" : __DIR__"lav.c",
]));
	set("objects",([
  __DIR__"npc/t_guard.c": 1,
]));
	set("item_desc",([
  "茶水" : "一些用瓷器裝起來的水，看起來很清徹，水質很好。\n",
  "食物" : "這些食物主要是乾饅頭組成的，放在木桌上，旁邊就是一壺壺的茶水。\n",
  "床舖" : "這是一個竹做的床舖，上面鋪一條大棉被，放的並不怎麼整齊，好像有人剛睡過的樣子。\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	set("level","tower_1");
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if( dir=="north" )
		tell_object(me,YEL"你似乎聞到了些怪怪的氣味傳到你鼻中。\n"NOR);

	return ::valid_leave(me, dir);
}