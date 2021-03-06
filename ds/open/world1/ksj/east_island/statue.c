#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("地藏王菩薩像", ({"bodhisattva statue","statue"}));
  set("long",@LONG
一尊斑痕累累的石像，多年前村人設置用來鎮壓鬼魂，由於缺乏修繕
變得跟一般路邊的石頭沒兩樣，善心人士可以幫忙清理一下(clean)。
LONG);
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "個");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}

void init()
{
  add_action("do_clean", "clean");
}

int do_clean(string str)
{
  object me,b;
  me=this_player();
 
  if(!str || str!="statue") return 0;
  if(query_temp("be_clean") )
     return notify_fail("石像已經被推倒了，沒必要再清理了。\n");
  message_vision(HIW"\n$N仔細地擦去佛像上的泥塵，並且拔掉四周的雜草，\n"
                    "一不小心推倒了石像，從底座冒出一陣青煙！\n"NOR,me);
  set_temp("be_clean",1);
  b=new(__DIR__"npc/ghost" );
  b->move(environment(this_object()));
  b=new(__DIR__"npc/eq/protect-amulet" );
  b->move(environment(this_object()));
  set("long",@LONG
一尊斑痕累累的石像，不知道被誰給推倒了，石像的底下刻了一些咒文。
LONG);
  call_out("delay",1200,this_object());
  return 1;
}

void delay(object room)
{
  set("long",@LONG
一尊斑痕累累的石像，多年前村人設置用來鎮壓鬼魂，由於缺乏修繕
變得跟一般路邊的石頭沒兩樣，善心人士可以幫忙清理一下(clean)。
LONG);
  this_object()->delete_temp("be_clean");
}
