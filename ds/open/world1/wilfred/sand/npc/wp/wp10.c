#include <ansi.h>
#include <weapon.h>
#include <path.h>

inherit F_UNIQUE;
inherit DAGGER;

void create()
{
  set_name(HIW"龍牙"NOR,({"dragon tooth","tooth"}) );
  set("long",@LONG
相傳青眼龍之牙具有足以撼動天地的潛在能力，
此龍牙炙熱之極，卻不燙手，甚為奇特，要引發
其力量，可能需要某些物事，目前卻無法得知。
LONG
);
  set_weight(2500);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit","支");
    set("value",20000);
    set("wield_msg","$N裝備$n作武器，頓時被一股強勁的無形氣勁所環繞。\n");
    set("replica_ob",WD_PAST+"sand/npc/eq/eq23");
  }
  set("beast_weapon_prop/damage",30);
  init_dagger(45);
  setup();
}

void init()
{
  add_action("do_blooding","blooding");
}

int do_blooding(string arg)
{
        object me,ob,ghost,blood;
        me = this_player();
        ob = this_object();
        if(!arg || arg != this_object()->query("id")) return 0;
        if(!objectp(blood=present("dab-aqua blood",me) ) )
                return notify_fail("你身上沒有血塊之類的東西。\n");

        message_vision("$N將一片血塊塗沫在$n上。\n",me,this_object());
        call_out("power_up",1);
        destruct(blood);
        return 1;
}

void power_up()
{
  if( !query_temp("power_up") )
  {
    message_vision(HIW"血塊緩緩的滲入$N，只見四周頓時氣勁四射，狂風大作！\n"NOR,this_object());
    this_object()->unequip();
    init_dagger( query("weapon_prop/damage") + 10 );
    this_object()->wield();
    add("backstab_bonus",10);
    set_temp("power_up",1);
  }
  else message_vision(HIW"$N似乎透出一絲光芒。\n"NOR,this_object());

  if( query("weapon_prop/damage") < 70 )
  {
    this_object()->unequip();
    init_dagger( query("weapon_prop/damage") + (3+random(4)) );
    this_object()->wield();
    add("backstab_bonus",5);
  }

  remove_call_out("power_change");
  if( query_temp("power_up") )
  {
    if( query("weapon_prop/damage") < 60 ) call_out("power_change", 600 + random(600) );
      else call_out("power_change", 400 + random(200) );
  }
  else call_out("power_change", 1000 + random(800) );
}

void power_change()
{
  tell_room(environment(this_object()),"一陣龍吟之聲劃破天際，" +this_object()->name(1)+ "的光芒逐漸淡去。\n");
  this_object()->unequip();
  init_dagger(45);
  this_object()->wield();
  set("backstab_bonus",0);
  delete_temp("power_up");
}
