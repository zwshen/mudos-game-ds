#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("����",({ "armor" }) );
 	set("long","�@��Q���p�����K���ҡA���L���m�O�ݨӭˤ]�����C\n");
      set_weight(8000);
	if (clonep() ) 
		set_default_object(__FILE__);
	else {
		set("value",1500);
		set("volume",4);
	set("material","iron");
	set("unit","��");
        set("armor_prop/armor",10);
	set("armor_prop/dex",-2);
	}		
	setup();
}
