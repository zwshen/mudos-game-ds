//u/c/chiaa/obj/eq/leading_cloak.c
#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
   set_name(RED"霸"HIB"王"MAG"披風"NOR,({"leading cloak","cloak"}) );
   set("long","霸王橫千秋隨身的披風,這是相當難得的一件寶物.\n");
  
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(9500);
                set("material", "fell");  //獸皮
                set("unit", "件");
                set("limit_con",15);                    
                set("armor_prop/dodge", 20);
                set("armor_prop/armor", 30);
                set("armor_prop/shield",15);
                set("value",12215);
        }
      set("weapon_prop/parry",30);        //加 enable 技能30
        setup();
}

