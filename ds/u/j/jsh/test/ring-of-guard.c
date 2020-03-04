#include <armor.h>
#include <ansi.h> 
inherit FINGER;
void create()
{
        set_name(HIY"¦uÅ@ªÌ¤§§Ù"NOR,({"ring of guard","ring"}) );
        set("long","");
        set_weight(2500);
  if ( clonep() )
    set_default_object(__FILE__);
else
{
                set("volume",3);
                set("unit","¥u");
                set("value",6000);
               // set("limit_lv",50); 
               // set("armor_prop/str",-1);
                set("armor_prop/armor",4);
                //set("armor_prop/show_damage",1); 
                set("armor_prop/bio",1);
}
setup();
}

