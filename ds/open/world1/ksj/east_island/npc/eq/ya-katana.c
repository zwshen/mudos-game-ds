#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name("野太刀", ({ "ya katana","katana" }) );
  set_weight(4550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long",@long
野太刀是一種超長的刀，身材稍小的人甚至會抽不出來，由於太長不
適合在市街攜帶，大概都是修練武道者或浪人使用。
long);      
    set("material", "steel");
    set("value",4500);
    set("volume",5);
    set("limit_skill",40);
  }
  init_blade(40);
  setup();
}
