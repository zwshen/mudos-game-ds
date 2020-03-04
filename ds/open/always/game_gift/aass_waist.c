//¥Ñ /std/item/game_gift.c ³Ð³y by -Acme-

#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
	set_name( "[1;36m¤ô[1;33m¥P[1;31mªá[1;37mÃ¤ºó[35m²Ó±a[0m", ({ "aass's flower waist" }) );
	set_weight(1874);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","¥Î¤@¦·¦·¤ô¥Pªá½sÂ´¦Ó¦¨ªº¸y±a");
		set("unit", "±ø");
		set("value",1209);
	}
	set("armor_prop/armor", 4);
	set("armor_prop/shield", 3);
	set("armor_prop/con", 1);
	setup();
}
int query_autoload() { return 1; }
