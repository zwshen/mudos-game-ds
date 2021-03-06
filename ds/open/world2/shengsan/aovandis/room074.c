// 奧凡迪斯

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"軍品店"NOR);
	set("long", @LONG
你看到牆上及專櫃裡擺著好多各式各樣的攻擊類武器，看到這些不經
讓你有搶購的衝動，如果需要可以跟老闆買你想要的武器。你注意到牆上
有個用木板釘成的告示牌(note)。
LONG
	);
	set("item_desc", (["note":@NOTE

佈告牌上寫著:

	看存貨請用 <list>      <list wp>       <list eq>
	要買東西用 <buy 物品>  <buy 數量 物品>
	要賣東西用 <sell 物品> <sell all>      <sell 數量 物品>

NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room062",
            ]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss.c" : 1,
	]));


	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("room_type","shop");
	setup();
	replace_program(ROOM);
}