// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("轉生之珠",({"undeath ball","ball","undead_item"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value",0);
		set("no_drop",1);
		set("can_give",1);
		set("needaward",5);
		set("unit","顆");
		set("long",@LONG
  一顆青藍色的玻璃珠。裡面蘊含了古代的智慧與無上的魔力，
珠子裡面鑲了個人形小木偶，並環繞著神聖的靈氣。
[SAVE]
LONG
		);
	}
		set("undead_msg",HIG"\n\t就在千鈞一髮之際，$N身上的$n突然爆裂了!!\n\n"NOR);

setup();
}

int query_autoload() { return 1; }
