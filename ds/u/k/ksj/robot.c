#include <ansi.h>
inherit NPC;
void normal_ai();

void create()
{
  set_name("機器人",({"robot"}) );
  set("long",@long
一個拼湊而成的機器人，利用它四個大小不一的輪子在緩緩移動著。
long);      
  set("age",10);
  set("level",23+random(2));
  set("attitude", "peaceful");
  set("unarmed",20);
  set("no_fight",1);
  set("chat_chance",2);
  set("chat_msg",({
     (: normal_ai() :),
     }) );
  setup();                
}

void normal_ai()
{
  object me,target;
  me = this_object();

  switch( random(10) )
  {
    case  0: message_vision("機器人撥出了一段錄音："HIG"泫染繽紛知為誰？\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIG"輕風搖曳望蝶飛，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIG"曾經一段尋香路，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIG"幾番秋冬思桂美。\n"NOR,me);
          break;
    case  1: message_vision("機器人撥出了一段錄音："HIW"閒看浮雲何時歇？\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIW"忽來幽香滿山野，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIW"卻看小徑曲折處，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIW"一樹桃花嬌豔雪。\n"NOR,me);
          break;
    case  2: message_vision("機器人撥出了一段錄音："HIR"牆裡朱紅佔春久，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIR"爭展豔容舞琴聲，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIR"不見岸柳空垂首，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIR"相依殘月怨秋冷。\n"NOR,me);
          break;
    case  3: message_vision("機器人撥出了一段錄音："HIC"風催綠芽萌，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIC"花顏笑春情，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIC"雪衣冬梅枝，\n"NOR,me);
             message_vision("機器人撥出了一段錄音："HIC"月下人共影。\n"NOR,me);
          break;
    case  4: message_vision("機器人伸出一條管子，發出吵雜的聲音，開始吸走牆角的灰塵。\n"NOR,me);
          break;
    case  5: message_vision("突然一陣不順暢的運轉聲，從機器人的身上彈出了一顆螺絲。\n"NOR,me);
          break;
    case  6: message_vision("機器人用四個大小不一的輪子慢慢地行走。\n"NOR,me);
          break;
    case  7: message_vision("從機器人身上突然冒出一團濃煙，但立刻被吸到機器人的背後。\n"NOR,me);
          break;
    case  8: message_vision("機器人直直地撞向牆壁，在牆上刮出數道刮痕後才調轉回頭。\n"NOR,me);
          break;
  }
  return;
}
