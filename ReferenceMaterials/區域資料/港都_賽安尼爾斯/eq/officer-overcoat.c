#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(HIY"����"CYN"�x�x�j��"NOR,({ "officer overcoat","overcoat" }) );
  set("long","���x�N�ŭx�x�t�ƪ��j��A���R�ӭ^���C\n");
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(2500);
    set("material", "leather");
    set("unit", "��" );
    set("value",12000);
    set("volume",2);
    set("wear_msg",
        "$N�N�@��^����$n�ܦb�ӤW�A��o��դ��Z�C\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 5);
  set("armor_prop/tec", -1);
  set("armor_prop/bar", 1);
  setup();
}