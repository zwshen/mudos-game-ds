/*此檔案靈感源於 Wilfred 的sand obj*/
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIM"情焰爐"NOR,({"love fire furnace","furnace"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG  
    此為情城池創城祖師【蓮池仙尊】所留之物，是當年她老
人家取自南海之寒冰火種升起之烈焰，其溫度將近有攝氏一千
度高溫，其溫度原本該將整個情城池融化，可是經由妙法仙尊
的道化治煉之後，便可以烈焰中帶有一股寒氣，已取的溫度之
平衡，現下聽說【天山雪】將當年的江湖十大名器屬防具的《
烈情寒冰》經由此爐煉化成八顆神丹，可見此爐之利害。
( 使用方法: combine )
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
  int i,x,index = 0;

  obs = all_inventory(ob);
	if( !sizeof(obs) ) return notify_fail("沒有東西在內，怎樣combine???\n");
  message_vision("\n$N升起了爐火，開始冶煉 ...... \n\n",this_player());
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "jan ball") index += 1;
    if(obs[i]->query("id") == "lin ball") index += 10;
    if(obs[i]->query("id") == "she ball") index += 100;
    if(obs[i]->query("id") == "jin ball") index += 1000;
    if(obs[i]->query("id") == "jun ball") index += 10000;
    if(obs[i]->query("id") == "run ball") index += 100000;
    if(obs[i]->query("id") == "ju ball")  index += 1000000;
    if(obs[i]->query("id") == "win ball") index += 10000000; 
  }
  only_check = filter_array( children(__DIR__"armor"), (: clonep :) );
  if(index != 11111111 || sizeof(obs) > 8)
  {
    message_vision("\n結果什麼事都沒發生.... \n\n",this_player());
        new(__DIR__"ash")->move(ob);
  }
        else {
  if(sizeof(only_check) > 0 )
  {
    message_vision("\n結果一陣清香充滿了整個爐子.... \n\n",this_player());
      if(random(10) > 6)
{
        new(__DIR__"pill9")->move(ob); 
}
else {
        new(__DIR__"pill0")->move(ob); 
}
        for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);
   return 1;
}
  tell_room(environment(ob),HIW"丹爐裡爆射出一陣強光 ...... 你看到丹爐裡似乎冶煉出新的物事？\n"NOR);
  new(__DIR__"armor")->move(ob);
        }
        for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);


  return 1;
}
