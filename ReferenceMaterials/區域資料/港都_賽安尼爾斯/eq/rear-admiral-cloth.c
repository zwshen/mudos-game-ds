#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIC"�ֱN�x�A"NOR ,({"rear admiral cloth","cloth" }) );
  set("long",@LONG
���x�ֱN���x�A�A�W�����ֱN�����żХܡA��A����Ƭ۷��n�C
LONG
);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",8000);
    set("material", "fur");
    set("limit_con",30);
    set("armor_prop/shield",3);
    set("armor_prop/con",1);
    set("armor_prop/armor", 15);
  }
  setup();
}