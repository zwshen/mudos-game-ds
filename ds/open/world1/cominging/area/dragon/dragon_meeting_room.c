#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"狂龍幫"HIM"－"HIC"會議室"NOR);
	set("long", @LONG
    這�堿O幫主們展開會議的會議室，你看到兩旁都是木製的桌椅。
而正中有兩張太師椅，你心想，這應該是幫主和副幫主的坐位了。 
LONG
	);
	set("exits",([
  "south" : __DIR__"dragon.c",
]));
	set("item_desc",([
  "太師椅" : "一張用木頭所做成的一張椅子，上面鋪著一張不知是何種獸皮。\n",
]));
	set("light",1);
set("no_goto",1);
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	setup();
}
