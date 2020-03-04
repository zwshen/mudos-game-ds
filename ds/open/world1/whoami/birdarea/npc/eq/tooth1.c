#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
     set_name( HIW"九"HIY"尾"NOR"之牙《槍》"NOR,({"nine tail tooth","tooth","pike"}) );
     set_weight(12000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","九尾的牙齒，隱隱發出些許\的妖力，似乎可以轉變成別種武器•\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : pike sword blade dagger staff)\n");
            set("unit", "把");             
            set("value",6500);
            set("material","gold"); 
           }         
        set("limit_str",30);
        set("limit_level",40); 
        set("weapon_prop/str",3); 
        set("weapon_prop/bar",1);
        set("weapon_prop/tec",-1);
        init_fork(55);
        setup();
}
void init()
{
    add_action("do_change","change");
}
int do_change(string str)
{
   object ob = this_object();
   if( ob->query("equipped") )
   return notify_fail("請先解除裝備。\n"); 
   switch(str)
   {
     case "staff":
           set("skill_type", "staff");
set_name(HIW"九"HIY"尾"NOR"之牙《杖》"NOR,({"nine tail tooth","tooth","staff"}));
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化•••\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIY"杖形"NOR"了•\n");
           set("weapon_prop/str",0); 
           set("weapon_prop/con",0); 
           set("weapon_prop/int",3); 
           set("weapon_prop/dex",-2); 
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/wit",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);
           break;
     case "sword":
           set("skill_type", "sword");
set_name(HIW"九"HIY"尾"NOR"之牙《劍》"NOR,({"nine tail tooth","tooth","sword"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化•••\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIG"劍形"NOR"了•\n");
           set("weapon_prop/str",-1); 
           set("weapon_prop/con",2); 
           set("weapon_prop/int",3); 
           set("weapon_prop/dex",-2); 
           
           set("weapon_prop/bar",-1);
           set("weapon_prop/tec",0);
           set("weapon_prop/wit",1);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);
           break;
     case "blade":
           set("skill_type", "blade");
set_name(HIW"九"HIY"尾"NOR"之牙《刀》"NOR,({"nine tail tooth","tooth","blade"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化•••\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIC"刀形"NOR"了•\n");
           set("weapon_prop/str",1); 
           set("weapon_prop/con",-2); 
           set("weapon_prop/int",0); 
           set("weapon_prop/dex",0); 

           set("weapon_prop/bar",1);
           set("weapon_prop/tec",0);
           set("weapon_prop/wit",-1);
           set("weapon_prop/bio",1);
           set("weapon_prop/sou",-1);

           break;
     case "dagger":
           set("skill_type", "dagger");
set_name(HIW"九"HIY"尾"NOR"之牙《匕》"NOR,({"nine tail tooth","tooth","dagger"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化•••\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIW"匕形"NOR"了•\n");
           set("weapon_prop/str",3); 
           set("weapon_prop/con",0); 
           set("weapon_prop/int",0); 
           set("weapon_prop/dex",-2); 
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/wit",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);

           set("backstab_bonus",36);
           break;
     case "pike":
           set("skill_type", "fork");
set_name(HIW"九"HIY"尾"NOR"之牙《槍》"NOR,({"nine tail tooth","tooth","pike"}));  
write(HIW"九"HIY"尾"NOR"之牙的妖氣漸漸的發生了變化•••\n"
HIW"九"HIY"尾"NOR"之牙變化成"HIR"槍形"NOR"了•\n");
           set("weapon_prop/str",3); 
           set("weapon_prop/con",0); 
           set("weapon_prop/int",0); 
           set("weapon_prop/dex",0); 
           
           set("weapon_prop/bar",1);
           set("weapon_prop/tec",-1);
           set("weapon_prop/wit",0);
           set("weapon_prop/bio",0);
           set("weapon_prop/sou",0);

           break;
     default:      
           write("九尾之牙沒有這種形態！\n");
   }
     return 1;
}


int can_stab()
{
    if( query("skill_type")=="dagger" ) return 1;
    else return 0;
}
