#include <ansi2.h>
inherit ITEM;

void create()
{
  set_name(WHT"神速符"NOR,({"speed tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","這是一道謎般的符紙，符紙上寫了一堆奇怪文字，詭譎無比。\n使用方法: speed");
    set("value",4000);
    set("unit","張");
  }
  setup();
}
void init()
{
  add_action("speed","speed");
  add_action("do_action","",1);
}

int speed()
{
  object me=this_player(), ob=this_object();
  if(ob->query("in_use")) return notify_fail("一張只能用一次。\n");
  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  message_vision(HIY"$N運指成戟，將$n"HIY"輕輕夾住，朝著自己寫了個『疾』字...\n\n霎時間，$N的身影變得朦朧起來...\n"NOR,me,ob);
  call_out("out_contorl",30,ob);
  return 1;
}

int do_action()
{
  if(!query("in_use")) return 0;
  this_player()->add_busy(-5);
  return 0;
}

int out_contorl(object ob)
{
  write(HIR"神速符的效力己過，你的身影也漸漸變得清晰可見... \n"NOR);
  destruct(ob);
  return 1;
}

