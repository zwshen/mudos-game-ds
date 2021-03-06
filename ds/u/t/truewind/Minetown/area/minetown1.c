// Room: /u/t/truewind/Minetown/area/minetown1.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
你忐忑的進入礦村，發現路上有來自各星球的礦工正在到處閒晃
，每一個似乎都若有所思的模樣。而四處都搭滿的電子帳棚(Camp)吸
引了你的注意。這些都是給礦工休息的帳棚，當然你也可以休息，不
過休息可是要付費的。
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 1);
        set("map","hotel");
	set("outdoors","land");
	set("objects", ([
        __DIR__"npc/robotwaiter" : 1,
]));

	set("item_desc", ([ /* sizeof() == 1 */
  "camp" : "礦工們用來快速恢復體力的電子帳棚，其能量來自空氣中的微弱電離子。\n",
]));
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"minetown2",
  "north" : __DIR__"minetown",
  "south" : __DIR__"minetown3",
  "enter" : __DIR__"minetownhotel",
]));
 	setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="enter" )return ::valid_leave(me, dir);

        if( dir=="enter" && me->query_temp("mine/tent") <=0 || !me->query_temp("mine/tent") )
                return notify_fail("你還沒有付錢給維達！\n");

        return ::valid_leave(me, dir);
}
