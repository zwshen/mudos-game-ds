// Room: /u/s/suez/tsing-yu/map_8_7.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
    這裡的石板路上沾滿了泥土，幾個穿著簡陋的小孩正在一旁的牆邊嬉
戲，一株綠蔭蓋天的老榕樹靜靜的伸出了粗壯的枝枒，穿過了古老的磚牆
延伸到大街上來，溫柔的將人們擁抱，讓身心的疲憊都隨著樹下的微風吹
散，幾個老人帶著一壺茶，就在這裡擺了個棋桌，一子一子的下著不知何
時才會下完的棋，棋盤上的此起彼衰，在棋局散去以後，剩下的只有飲茶
時閒聊的話題和飄落在棋桌上的榕樹葉而已。


LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "north" : __DIR__"map_7_7",
  "northwest" : __DIR__"map_7_6",
  "southeast" : __DIR__"map_9_8",
  "west" : __DIR__"map_8_6",
]));

	setup();
	replace_program(ROOM);
}
