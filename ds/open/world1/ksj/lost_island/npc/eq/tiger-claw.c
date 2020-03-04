#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIY"¼C¤úªê¤ö"HIR"(S)"NOR,({"tiger claw","claw"}));
  set("long",@LONG
¼C¤ú¥¨ªêªº«e¤ö¡A¾U§Qªº¦y¤ö¥Rº¡«Â¯Ù©Ê¡C
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "§â");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_fist(44);
  setup();
}

int query_autoload() { return 1; }
