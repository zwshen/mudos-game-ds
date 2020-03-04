// Room: /d/gumu/anhe2.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"暗河"NOR);
	set("long", @LONG
原來這正是一條地下暗河，此處水聲已是轟轟，聲勢極為駭人。你
腳下一處踏空，便有水流直沖咽喉。此潛流不知來自何處，更不知通往
何方。慢慢你已感覺水勢漸緩，地勢漸高。
LONG	);

	set("exits", ([
          "northup"  : __DIR__"caodi",
		"westdown" : __DIR__"qianliu2",
	]));
	set("no_clean_up", 0);
	setup();
    replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
	if (dir == "northup")
	{
		write(HIW"\n你出得洞來，強光閃耀，一時之間竟然睜不開眼。\n"NOR);
	}
	return ::valid_leave(me, dir);
}
