//u/c/chiaa/obj/eq/light blue_shield.c
#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(HIB"湛藍之盾"NOR,({"light blue shield ","shield"}) );
        set("long","以天然形成的藍色鑽石,稍微加工打造,非常堅硬\n");
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(5000);  
                set("limit_str",18);
                set("unit", "個");       
                set("value",6666);                                                     set("material", "diamond");   //鑽石
                set("armor_prop/armor",28);     
                set("armor_prop/shield",14);   
       }
      set("weapon_prop/parry",15);        //加 enable 技能15
          setup();
}
