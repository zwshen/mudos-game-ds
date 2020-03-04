#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{
set_name(HIC"縀方Ж"NOR,({"laster clip","laser","clip"}));
   if( clonep() )
      set_default_object(__FILE__);
   else {
   set("unit", "");
set("long","縀方Ж, –縀方Ж紅常杆Τ20縀杆恶:(reload clip)\n");
set("value", 2000);
set_weight(500);
set("amount",20);        
 set("bullet/damage",20);        
set("bullet/unit","");  
set("bullet/name","縀");     
set("type","energy");      
}
setup();
}
