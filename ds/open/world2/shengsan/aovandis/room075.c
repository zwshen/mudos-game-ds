// ¶ø¤Z­}´µ

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"±B«Ã¤¶²Ð©Ò"NOR);
	set("long", @LONG
§A¥¼±B¶Ü¡H§A¥¿¦b§ä²Ä¤G¬K¶Ü¡H³o¸Ì¬O«P¦¨¨}¦n«Ã½tªº¦n¦a¤è¡C®öº©
®ðª^ªº¸ËæC¡A¥[¤W¤¶²Ð¤Hªº±M·~»P°õµÛ¡A¨ü´fªº¨k¤k¥i¬O»¡¤]»¡¤£§¹¡CÅ¥
»¡¦b¥þ¥@¬É¦U¦a³£¦³¥L­Ìªº¤À¤½¥q¡CÀð¤W¦³­Ó§i¥ÜµP(note)¡C
LONG
	);
	set("item_desc", (["note":@NOTE

§G§iµP¤W¼gµÛ:
[1;36m
	±B«Ã¤D²×¨­¤j¨Æ¡A¤£¥i¥H¨àÀ¸µø¤§¡C
	§O¦bµS¿Ý¤F¡A¯S§O¬°±z¶q¨­©w°µªº¦ñ«Q¡A¤@©wÅý±zº¡·N¡C
	¦pªG¦³»Ý­n´N½Ð¥»¤½¥qªº¤¶²Ð¤H¬°§A¤¶²Ð§a¡C
[m
[1;33m					* ±B«Ã¤¶²Ð©Ò *
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room063",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/introducer.c" : 1,
	]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}