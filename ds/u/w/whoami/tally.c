#include <ansi2.h>
inherit ITEM;

void create()
{
  set_name(WHT"神令符"NOR,({"god tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","這是一道謎般的符紙，符紙上寫了一堆奇怪文字，詭譎無比。\n使用方法: god <某生物的英文名>");
    set("value",3000);
    set("unit","張");
  }
  setup();
}
void init()
{
  add_action("god","god1");
}

int god(string str)
{
  object obj, me=this_player(), ob=this_object();
  if(ob->query("in_use")) return notify_fail("一張只能用一次。\n");
  if(!str) return notify_fail("請輸入對方的英文名。\n");
  if( !(obj = present(str, environment(me))) )
    return notify_fail("這裡沒有 " + str + "。\n");
  if(userp(obj) || !living(obj))
    return notify_fail("使用對象是不合法的。\n");
  obj->set("creater",me);
  set("value",0);
  message_vision(HIG"$N舉起手中的神令符喃喃念咒.....霎時間，"NOR"$n"HIG"的四週被一道綠光環繞...\n"NOR,me,obj);
  message_vision(HIG"只見"NOR"$n"HIG"雙眼迷茫，己經完全的被$N控制了。\n"NOR,me,obj);
  write(NOR""WHT"\n現在你只要輸入指令，對方就會照著你的意思行動。  指令格式﹕hest <手下> to <指令>\n"NOR);
  return 1;
}


