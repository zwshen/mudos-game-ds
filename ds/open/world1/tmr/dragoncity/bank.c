// Room: /open/world1/tmr/dragoncity/bank.c

inherit ROOM;

void create()
{
	set("short", "磐龍錢莊");
	set("long", @LONG
這是磐龍城中最大的一家錢莊，由於老闆雷九指是少帥
冠仲的好兄弟，大家都很捧這家錢莊面子。加上雷九指生性
豪爽，愛結交朋友，所以磐龍錢莊的生意更是蒸蒸日上，不
少商旅都還只認這錢莊蓋印的錢票。
LONG
	);
	set("no_kill", 1);
	set("light", 1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"northroad1",
]));
         set("objects",([        
                  __DIR__"npc/banker" : 1,
          ])      );

	set("room_type", "bank");
	set("item_desc", ([ /* sizeof() == 1 */
  "木匾" : "   歲寒錢莊提供的服務有:

deposit      : 存錢
withdraw     : 提錢     

",
]));

	setup();
	replace_program(ROOM);
}
