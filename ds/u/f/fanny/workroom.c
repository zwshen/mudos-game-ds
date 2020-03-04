// Room: /u/f/fanny/workroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
    set("short", WHT"笑紅塵的窩"NOR);
    set("long", 
    "這是笑紅塵工作的地方，這裡有一把紅塵劍，跟幾盅陳年老酒，\n"
"看來笑紅塵是個酒鬼吧，在笑紅塵的口裡還聲聲唸著他的「笑紅塵」\n"
"這首曲子，似乎還挺能自得其樂的。\n"
"\n"
+HIR "                    人生難有幾勁敵，\n" NOR
+HIR "                    但聞一二兩相齊；\n" NOR
+HIR "                    一一相破不得意，\n" NOR
+HIR "                    笑紅塵中無人匹。\n" NOR
"\n"
    );
	set("exits", ([ /* sizeof() == 4 */
  "town" : __DIR__"area/town/town1.c",
  "forest" : __DIR__"area/forest/forest1.c",
  "wiz" : "/d/wiz/hall1",
  "moon" : "/open/world1/acme/area/moon/room3",
]));
	set("world", "undefine");
    set("no_clean_up", 1);
    set("no_fight", 0);
    set("valid_startroom",1);

	setup();
call_other("/obj/board/fanny_b", "???");
set("objects",([
__DIR__"box.c" :1,
]));
	replace_program(ROOM);
}
