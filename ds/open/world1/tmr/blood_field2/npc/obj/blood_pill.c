#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name("行血丹", ({"blood pill","pill"}));
		set("long",@long
行血丹是極具療傷功效的藥丸，吞服之後，可以刺激人體體內造血的
的功能，達到迅復恢復傷勢的功能 
long
);
		if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("eff_msg", HIG "你覺得傷勢恢復不少了。" NOR );
        }
        set("value", 300);
        set("heal",([
			"hp": 300,
        ]));
        setup();
}




