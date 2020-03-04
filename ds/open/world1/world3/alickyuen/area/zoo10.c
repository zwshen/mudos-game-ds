// 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Fish＠CyberZoo"NOR);
	set("long", @LONG
這房間內有很多像工藝品的物品，但你仔細一看，才發現那些原來是
一些古代的魚的化石。雖然經過多年，但形狀還沒有變。你不禁覺得大自
然是很厲害的，竟然可把很多年前存在在這世界的東西保存得那麼妥當。
往南可回到水族館展覽魚類的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoo9",
]));
	set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/traveller" : 2,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
