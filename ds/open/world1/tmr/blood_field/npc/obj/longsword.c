#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( "剔骨長劍" , ({ "barebone sword","sword" }) ); 
	set("long", "這是一把劍身歪歪扭扭的長劍，劍刃極其鋒銳。\n");
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
  	{
		set("unit", "把");
		set("material", "bone");
		set("value",3500);
	}
	set("weapon_prop/str",1);
	init_sword(40); 
	setup();
}



