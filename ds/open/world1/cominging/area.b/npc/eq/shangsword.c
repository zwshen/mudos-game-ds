#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
	set_name(HIG"商隱劍"NOR, ({ "shang in sword","sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這把劍已經有十分久遠的歷史, 傳說是疾風門開山祖師留下的寶劍。\n");
		set("value", 30000);
		set("material", "crimsonsteel");
		set("limit_skill",50);
		set("limit_int",25);
		set("limit_dex",25);
		set("weapon_prop/dex",2);
		set("weapon_prop/con",2);
		set("weapon_prop/parry",10);
		set("weapon_prop/hit",5);
		set("replica_ob",__DIR__"fakesword");
	}
    init_sword(65);
    setup();
}
