#include <weapon.h>
#include <ansi.h>
inherit GUN;

void create()
{
  set_name("��j",({"hand gun","gun"}));
  set("long","�@��H�̱`�Ϊ���C\n");
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",2000);
    set("rigidity",500);    
    set("material","iron");
  }
  set("wield_msg","$N�q�y���ǥX�@��$n���b�k��C\n");
  set("unwield_msg", "$N�N��W��$n���^�y���C\n");
  set("bullet_type","clip"); 
  set("max_load",25);
  init_gun(10);  
  setup();
}