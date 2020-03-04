// Room: /u/a/acme/area/pathway.c
inherit MOBROOM;
void create()
{
	set("short", "小路");
	set("long", @LONG
這裡是一條小路，路的兩旁荒蕪已久，雜草遍野，眼前更有一堆堆的
亂石，往西可以離開這裡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"pathway4",
  "west" : __DIR__"pathway1",
]));
        set("no_clean_up", 0);
        set("chance",65);
        set("mob_amount",2);    //則最多出現三個怪物.
        set("mob_object",({     //設定怪物檔名.
            __DIR__"npc/snake",
        }) );
      set("outdoors","land");
	setup();
}
