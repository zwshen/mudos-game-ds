#include <ansi.h>
#include <weapon.h>
#include "/open/world1/wilfred/sand/npc/wp/std_fist.c"


void create()
{
  set_name(HIC"無上"HIW"奔雷"HIY"爪"NOR , ({ "top claw","claw" }) );
  set_weight(12000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("long", HIW"凡是曾給大自然之現象加持過的武器，威力會大於從前，此爪便是如此
。在爪的周圍便可看到些雷光環繞，極為華麗。\n"NOR);
    
    set("material", "sliver");
    set("value",7000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",3);
    set("weapon_prop/con",-2); 
    set("limit_lv",40);
    set("limit_dex",30);
    set("limit_con",70);
    set("limit_int",20);
    set("limit_str",70);  
  }
        set("wield_msg",HIB"$N裝上了"HIC"無上"HIW"奔雷"HIY"爪"NOR""HIB"後，便有道電流從百匯穴竄流至壇千穴，力量頓時大增！！\n"NOR);
        set("unwield_msg", BLU"$N放下此爪後，竄留在體內的電流便頓時消失。\n"NOR);
  init_fist(78);
  setup();

}
