// Room: /u/l/luky/room/pearl_16.c
#include <ansi.h>
inherit ROOM;
inherit MOBROOM;	//需放在 inherit ROOM; 之後
void create()
{
	set("short", HIG"龍蝦第一實驗場"NOR);
	set("long", @LONG

  你正位於碧雷爾鎮的珍珠北街。北方是本鎮主要的商店，如果你尚
有多餘的裝[1;33m │       ▃▄▅▆▆▆▅▄▃             │[m 備，不
妨來此中[1;33m   ▲▃▄▅[m│◢◣│◢◣│◢◣│[1;33m▅▄▄▃▃▂▲[m心與其
他冒險者 ▕ │ 田田│田田│田田│田田│ 田 田 │田 ▏▎ 交換
         ▕ │[33m＿▂▃▄▄▅▅▅▅▅▄▄▃▂＿[m  │   ▏▎
￣￣￣￣￣￣￣￣ :╲  ◢◣ ◢◣ ◢◣  ╱: ￣￣￣￣￣￣￣￣￣
:      -         :▕  ︵  ������  ︵  ▏:[1;35m【裝備交換中心】[m  :
= ."   -       - :▕  ♁[1;34m   ██[m   ♁  ▏:                  =
==-  " -       - :▕[34m       ██[m       ▏:  -       - .   -==
￣￣￣￣￣￣￣￣￣￣￣￣￣￣  ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lukylab2",
  "east" : __DIR__"workroom1",
]));
	set("no_clean_up", 0);
        set("light",1);
	set("chance",50);	//則有 50% 的機率會出現怪物.
	set("mob_amount",3);	//則最多出現三個怪物.
	set("mob_object",({	//設定怪物檔名.
	"/open/world2/anfernee/start/npc/bug",
	"/u/l/luky/npc/mosquito"
	}) );
	setup();
	
	//注意, 繼承MOBROOM後 絕不可以有 replace_program(ROOM);
}

void init()
{
        ::init();	//注意, 若是有繼承MOBROOM的room要用到init(),則需加這一行!!

        add_action("d_creat","creat");
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"怪物地雷已關閉!\n");
 return 1;
}

int d_creat(string arg)
{
 this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"怪物地雷已開啟!\n");
 return 1;
}