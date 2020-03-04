// 目前只先開放 "白色水晶跟劍" 的融合, 其餘的以後再寫   wilfred@DS

#include <path.h>
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("青龍紋丹爐",({"Dragon furnace","furnace"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG
一個青銅製的丹爐，上面刻著許\多龍形花紋，接近底部
的其中一圈花紋刻的似乎是漢字，上頭寫著：

                 冶 煉 之 法

        放入其欲冶煉之物，或為一，或為多也

  升爐火(combine)，待之有時，可得物也，其無可預之也

LONG
);

  }
  set("no_sac", 1);
  set("no_get", 1);
  set("no_clean_up",1);
  set_max_encumbrance(999999);
  setup();
}

void init()
{
  add_action("do_combine","combine");
}

int do_combine()
{
  object ob = this_object(), *obs, *only_check;
  int i, index = 0;

  obs = all_inventory(ob);
  if(sizeof(obs) < 1) return notify_fail("必需先放入你想要冶煉的東西。\n");
//  if(sizeof(obs) > 8) return notify_fail("你放入的東西太多了！！\n");
  message_vision("\n$N升起了爐火，開始冶煉 ...... \n\n",this_player());

  // 唉唉唉.... 想破頭也沒有擠出一個融合的好規則 (我卡在這裡約數小時 -.-+發亮)
  // 暫時限制只能放兩個好了而且判定用最笨的方法, 之後一定要改寫
  // 泛用性真夠差的     wilfred@DS

  if(sizeof(obs) > 2)
  {
    message_vision("\n結果什麼事都沒發生.... \n\n",this_player());
    return 1;
  }

  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "white crystal") index += 10;
    if(obs[i]->query("skill_type") == "sword") index += 100; 
  }

  only_check = filter_array( children(WD_PAST+"sand/npc/wp/wp12"), (: clonep :) );

  if(index != 110 || sizeof(only_check) > 0 )
  {
    message_vision("\n結果什麼事都沒發生.... \n\n",this_player());
    return 1;
  }

  for(i=0;i<sizeof(obs);i++)
    destruct(obs[i]);

  tell_room(environment(ob),HIW"丹爐裡爆射出一陣強光 ...... 你看到丹爐裡似乎冶煉出新的物事？\n"NOR);
  new(WD_PAST+"sand/npc/wp/wp12")->move(ob);
  return 1;
}
