#include <armor.h>
inherit SURCOAT;
void create()
{
	set_name("繡布披風",({"surcoat"}));
	set_weight(980);            
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "這是一件很平常的披風。\n");
                set("value", 200);                                             
		set("armor_prop/armor", 2);  
	}
	setup();
}    
