// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("長劍", ({ "long sword", "testing" }));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把看起相當普通的長劍﹐份量大約有十來斤左右。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_sword(25);
	set("no_get", 1);
	set("no_drop", 1);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
	set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

// The setup() is required.

	setup();
}
void init()
{
        object room = environment(this_object());

        if( !room) return;
        if( !objectp(room) ) return;
        if( room->is_room() ) destruct(this_object());
}
