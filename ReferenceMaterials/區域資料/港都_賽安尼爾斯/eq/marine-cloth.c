#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW"���x�x�A"NOR ,({"marine cloth","cloth" }) );
  set("long",@LONG
�o�O�H�W�j�]�~�мC�����ꤧ�֩һs�����֦�A���׬O����٬O
�X�n�סA�i���O�֦礤�����~!
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",20000);
    set("material", "fur");
    set("limit_level",40);
    set("armor_prop/shield",10);
    set("armor_prop/str",2);
    set("armor_prop/con",2);
    set("armor_prop/dex",1);
    set("armor_prop/armor", 20);
  }
  setup();
}