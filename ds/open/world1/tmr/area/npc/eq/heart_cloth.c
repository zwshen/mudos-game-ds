#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("觀意裳",({"heart cloth","cloth"}) );
	set("long",@long
  一件雪白色的衣裳，摸來絲質軟滑，令人愛不釋手。
long
);
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("volume",3);
		set("unit", "件");
		set("value",1000);
		set("max_lv",25);
		set("limit_lv",8);
          set("armor_prop/int",2);
            set("armor_prop/dex",2);
		set("armor_prop/armor",5);
                set("armor_prop/show_damage",1);
	}
	setup();
}


