// Room15.c

inherit ROOM;

void create()
{
	set("short","長老之間");
	set("long", @LONG
這房間是幫主和長老們休息之處，正中央擺放著一佈告板，長老
們報告幫中事務之用。而此處也有著一把碧綠色長劍插在地上。

LONG
	);
	set("objects",([
__DIR__"item/greensword2" :1,
__DIR__"item/heaven_box" :1,
]));
	set("exits", ([
	]));
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1);
	call_other( "/obj/board/sky_room05_b", "???" );
}
