// Room: /u/m/mulder/area/naboo/jungle/jungle12.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�˪L"NOR);
	set("long", @LONG
�o�̪������i��ѪŤ��A�𸭿@�K�A�B�\�F�j�����������C�O��o
�̳����˴ˡC�A�J�Ӥ@�ݡA�oı�a�W�G���j�p���P���}�L�C�A���_�Mı�o
�o�̦s�b�@�ǥͪ��D�D�D�D�D
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jungle10",
  "west" : __DIR__"jungle8",
  "north" : __DIR__"jungle11",
  "east" : __DIR__"jungle16",
]));
		 set("objects",([
  __DIR__"npc/ewoks":2,
__DIR__"npc/rancor":2,
 ]));

	set("world", "undefine");
	set("outdoors","forest");
	set("no_map",1);
	set("no_recall",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}