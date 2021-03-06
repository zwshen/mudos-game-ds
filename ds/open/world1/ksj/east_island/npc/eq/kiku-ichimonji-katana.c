#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIY"菊"HIW"一文字"NOR, ({ "kiku-ichimonji katana","katana" }) );
  set("long",@long
刀鐔雕刻十六辦菊花的花紋，是名匠精心鑄造的名刀，刀姿剽悍，曲
度優雅刀紋為驚濤駭浪水波刃紋，刀上附有極強的刀魂。
long);      
  set_weight(2750);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",4);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",40);
  set("weapon_prop/sou",-1);
  set("weapon_prop/wit",-1);
  set("weapon_prop/bar",1);
  set("weapon_prop/tec",1);
  set("weapon_prop/hit",10);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(64);
  set("wield_msg","$N拔出腰間的$n，森寒的刀光令人望之心怯。\n");
  set("unwield_msg","$N將手中的$n放回刀鞘，發出--鏗--一聲清響。\n");
  setup();
}
