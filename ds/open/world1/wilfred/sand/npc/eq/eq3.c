#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit NECK;
void create()
{
  set_name(WHT"神木護符"NOR ,({ "divine-tree necklace","necklace" }) );
  set("long",HIW"這護符上刻著相當美麗的花紋，表面隱隱有白光流轉著，令人為之炫目。"NOR);
  set_weight(900);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",4);
    set("unit", "條");
    set("value",12000);
    set("replica_ob",__DIR__"eq14");
  }

  set("armor_prop/armor",5);
  set("armor_prop/shield",25);
  set("armor_prop/dodge",7);
  set("armor_prop/int",4);
  set("armor_prop/con",-2);
   set("armor_prop/wit",1);
  set("armor_prop/bar",-1);

  set("beast_armor_prop/armor",5);
  set("beast_armor_prop/shield",25);
  set("beast_armor_prop/dodge",7);
  set("beast_armor_prop/int",4);
  set("beast_armor_prop/con",-2);
  set("beast_armor_prop/wit",2);
  set("beast_armor_prop/bar",-1);

        set("limit_level",30);
        set("limit_int",50);

  setup();

  set("power",10);
  set("max_power",10);
}

void init()
{
  add_action("do_look","look");
  if(query("is_defined"))
  {
    add_action("do_defence","defence");
    add_action("do_recharge","recharge");
  }
}

int do_look(string str)
{
  if(str == "花紋")
  {
    if(query("is_defined"))
    {
      write("花紋上的意思是：\n"HIC"石甲 指令格式: defence\n神力回復 指令格式: recharge\n"NOR);
      return 1;
    }
    write("你仔細的看了看護符上的花紋。\n");
    write("美麗的花紋似乎交錯成一個個文字，但此文字並非中原一般所通用之正楷。\n");
    write("看來必需找人加以鑑定方能加以判斷此文字之意思。\n");
    return 1;
  }
  return 0;
}

int do_defence()
{
  object me = this_player(), ob = this_object();
  // 稍後再作
  return 1;
}

int do_recharge()
{
  object me = this_player(), ob = this_object();
  // 稍後再作
  return 1;
}
