//¥Ñ /std/item/game_gift.c ³Ð³y by -Acme-

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
	set_name( "[1;35m©b¤ë[0m[0m", ({ "fly moon","fly" }) );
	set_weight(6801);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","©b¤ë¬Û¶Ç¬O¹ß®Z¦b­¸¦V¤ë®c®É±¼¤F¤@°¦¾vÂ¯©Ò°µ¦¨ªº,©b¤ë¨ã¦³¤@¨ÇµLªk»¡©úªºªk¤O,½è¦a«Ü»´¨¾¿m¤O«o«Ü°ª¡C");
		set("unit", "¥ó");
		set("value",6870);
	}
	set("armor_prop/shield", 28);
	set("armor_prop/str", 1);
	set("armor_prop/con", 1);
	set("armor_prop/armor", 49);
	setup();
}
int query_autoload() { return 1; }
