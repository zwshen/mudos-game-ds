// Room: /u/a/acme/area2/t5.c

inherit MOBROOM;

void create()
{
	set("short", "幽冥地窖[地下一層]");
	set("long", @LONG
這裡是幽冥地窖的地下一層，一樣昏暗不明，四周景緻並無二樣，但不時
的可聽見野獸的咆哮聲，令你不寒而慄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"t4",
  "south" : __DIR__"t6",
]));
	set("no_clean_up", 0);

set("chance",70);       
        set("mob_max",3);
        set("mob_amount",3);    //則最多出現三個怪物.
        set("mob_object",({     //設定怪物檔名.
            __DIR__"npc/chicken",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

