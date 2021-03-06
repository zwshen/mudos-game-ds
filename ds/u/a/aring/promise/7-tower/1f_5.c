#include <ansi.h>
inherit ROOM;

string *temp_msg = ({
HIC"\n在一陣昏迷過後，你似乎回到了朝天樓。\n\n"NOR,});

void create()
{
  set ("short", YEL"百蝦閣"NOR);
  set ("long","眾海鮮將士奮不故身的守護的神聖境地，在旁有兩個石雕，分別
代表『忠誠』與『責任』，想必他們的將領也是遵循這兩種精神來維
持他將領的地位吧。\n"NOR);
  set("exits", ([
  "northwest" : __DIR__"1f_4", 
  ])); 
  set("no_clean_up", 0);
  
  setup();
 } 
void init()
{
  object me;
  ::init();

  if( interactive(me = this_player()) )

  {
    remove_call_out("action1");
    call_out("action1",1,me);
    me->start_busy(2);
  }
}

int action1(object me)
{
  if(!me) return 1;
  if(!random(3) || wizardp(me))
  {
     message("world:world1:vision",
HIW"\n\n\t英勇的"HIG+me->query("name")+HIW"闖過了"HIC"【水舞之陣】"HIW"繼續的持續接下來的挑戰！！\n\n"NOR,users());
    return 1;
  } 
  message("world:world3:vision",HIW"\n【江湖笑聞】 "HIR"英勇的"+me->query("name")+HIR"被幻術所迷，回歸到朝天樓了！！\n\n"NOR,users());
  message_vision(HIW"\n$N踏入了百蝦閣，但突然間頭極為暈眩！！\n"NOR,me);
  message_vision(HIW"似乎中了所謂的幻術！\n"NOR,me);
  message_vision(HIW"一煞那，$N整個被水陣震翻了出去，消失無蹤影！！\n"NOR,me);
  me->set_temp("block_msg/all",1);
  me->move("/open/world1/tmr/area/hotel");
  tell_room("/open/world1/tmr/area/hotel",HIY+me->query("name")+HIY"從天上飛了下來，狀況奇差！！\n"NOR);
  me->set_temp("define_look",HIC"(中了幻術的笨蛋)"NOR);
  me->set("hp",(me->query("max_hp") / 5) );
  me->start_busy(10);
  call_out("action2",7,0,me);
  return 1;
}

int action2(int index, object me)
{
  string msg = temp_msg[index];
  if(!me) return 1;
  me->delete_temp("block_msg/all");
  write(msg);
  me->set_temp("block_msg/all",1);
  if(++index < sizeof(temp_msg)) call_out("action2",4,index,me);
    else
    {
      me->delete_temp("block_msg/all");
      me->delete_temp("define_look");
    }
  return 1;
}

