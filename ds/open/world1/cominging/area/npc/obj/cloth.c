#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(WHT"烏蠶絲布"NOR,({ "gray silkworm thread drapery", "drapery","cloth" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一塊塊從布商那購買而來的烏蠶絲布，上面還有一些些灰灰的灰塵。\n");
		set("unit","大塊");
		set("value",290);
		set("cloth",1);
	}
	setup();
}