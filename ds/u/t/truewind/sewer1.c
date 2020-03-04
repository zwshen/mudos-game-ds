// Room: /u/t/truewind/sewer1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "下水道");
	set("long", @LONG
重重的摔落在一灘水上後，你注意到這裡是個地下水道。周圍非
常陰暗潮濕，還有一些小老鼠在地爬來爬去。遠方似乎有某種奇
怪的聲音傳來...。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"Minetown/area/machinefield5",
]));
	set("current_light", 0);
	setup();

}
