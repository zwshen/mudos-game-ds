// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
  set_name(HIB"電光劍"NOR, ({ "laser sword","sword"}) );
    set_weight(70);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是未來常用的武器。\n");
		set("value", 400);
		set("material", "platminum");
		set("wield_msg", "$N按下"HIB"電光劍"NOR"的鈕,突然射出一把劍。\n");
		set("unwield_msg", "$N將手上的"HIB"電光劍"NOR"收藏起來。\n");
	}
    init_sword(2500);
	setup();
}
