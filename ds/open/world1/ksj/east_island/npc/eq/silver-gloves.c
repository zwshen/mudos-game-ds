#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIW"白銀籠手"NOR,({"silver gloves","gloves"}) );
  set("long",@LONG
純銀製作的護手，不但華麗高貴，防禦力也很好。
LONG);
  set_weight(2100); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");       
    set("value",5000);          
    set("volume", 2);                       
    set("material", "silver");   
  }
  set("limit_con",30);
  set("armor_prop/armor",12);       
  setup();
}
