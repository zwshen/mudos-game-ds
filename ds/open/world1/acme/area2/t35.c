// Room: /u/a/acme/area2/t35.c

inherit MOBROOM;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你正走在這陰暗的地道，你慢慢發覺地上濕泠泠的，似乎越往裡
頭地面越濕，這裡的空氣也越來越難聞，五味雜陳，令人作嘔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t36",
  "south" : __DIR__"t34",
]));
	set("no_clean_up", 0);
        set("chance",60);
        set("mob_amount",1);    //最多出現一個怪物
        set("mob_object",({     //設定怪物檔名.
            __DIR__"npc/devil",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

