#include <ansi2.h>
inherit ROOM;

int go_rebus();

void create()
{
	set("short", "空中纜車站");
	set("long", @LONG
你正站在這個山頭上的纜車等候處。因為這個山頭十分難以攀爬
，因此有心人就在此建立了一個纜車的接駁點，以方便後來的人過來
這裡。旁邊立了一個牌子。
LONG
	);
	set("item_desc",([
        	"牌子":"想要回去者，請用搭乘回程的空中纜車(take bus)。\n"
        ]));
        set("exits", ([
        	"north" : __DIR__"chris3",
	]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);
	set("outdoors", "land");

	setup();
}
void init()
{
	::init();
	add_action("do_take","take");
}
int do_take(string arg)
{
	object me;
	me=this_player();
	
	if(!me) return 0;
	if(!arg || arg!="bus") return notify_fail("你想搭什麼東西回去啊？\n");
	me->start_busy(4);
	call_out("go_rebus",2,0);
	return 1;
}
int go_rebus()
{
	object me;
	me=this_player();
	
	if(!me) return 0;
	tell_object(me,HIW"\n你站在這裡，看見纜車由遠方靠近。\n"NOR
		       HIW"\n當纜車停下來之後，你打開纜車的車門，走了進去。\n\n"NOR);
	me->move(__DIR__"airbus2");
	return 1;
}