// Room: /u/l/luky/workroom.c
#include <ansi.h>  //若要用有顏色的須加此行
#include <room.h> //要加門要這一行
#include <path.h>
inherit ROOM;
inherit DOOR;
void entercheck(object ob);
void create()
{
 set("short",HIG"海底平原"NOR);  //短敘述
 set("long","\n"
 HIB"▊"NOR"                      這裡是海底峽谷的最深處••••••••••\n"
 HIB"▉"HIW"  o"NOR"°             幾條非常罕見的深海魚從你身邊游過，一隻"HIY"金黃色"NOR"的\n"
 HIB"▉"NOR"      °          "HIY"小龍蝦"NOR"突然在你身邊露出了牠的頭，還吐出一顆顆的\n"
 BLU"▊"NOR"  °    "HIG"ξ φ"NOR"     小氣泡，你注意到牠旁邊的岩壁上還刻了幾個大字。\n"
 BLU"▋"HIY"╮"NOR"°"HIB"  ◢█▇██◣"HIW"°"NOR+GRN"ξ      "NOR"°"HIG"    φ"NOR"\n"
 BLU"▊"HIY"％╮"HIB"◢█"HIC"請勿餵食"HIB"█"BLU"▇▆"HIB"▅▄▄▅▄▄▅▄▄▅▄▃▂▁"NOR"\n"
 BLU"█"HIB"█▇███████████████████████▇▆▅▄"BLU"▃▂▁"NOR"\n"
 ); //長敘述

 set("light",1);
 set("exits", ([  //此房間連結之出口方向及檔案
 "east": __DIR__"lukyroom1",
 "west": __DIR__"lukylab1",
 "fonsan": LUKY+"fonsan/eega1",
 "wiz": "/d/wiz/hall1",
 ]));
 set("hide_exits", ([
 "ship":__DIR__"workroom",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 set("objects",([
  __DIR__"npc/passenger":1,
  __DIR__"npc/pig":1,
  __DIR__"box":1,
  __DIR__"redkey":1,
 ]));
 create_door("east","紅色大門","west",DOOR_LOCKED,"redkey");
// set("never_clean",1); //一般房間絕不可加此行.
 setup();
// call_other( "/obj/board/luky_b", "???" );
}

void init()
{
 call_out("leave_message",3,this_player());
 call_out("entercheck",2,this_player());
}

void entercheck(object ob)
{
 if(userp(ob))
 {
   if(wiz_level(ob) < wiz_level("(immortal)"))
   {
     message_vision(HIR"對不起 "+ob->name()+" 你不能進來喔!!\n"NOR, ob);
     ob->move("/d/slake/start");
   } else 
   {
     message_vision(HIY"\n 小龍蝦說: 嗨!! "+ob->name()+"大大! 我好想你喔!!\n"NOR, ob);
   }
 }
 return;
}

void leave_message(object me)  //*****訪客動作*****
{
 object luky,ob1,ob2;
 if(luky=find_player("luky")) //本人在遊戲中
 {
  if(me->query("id")!="luky") //別人進入
  {
   ob1=find_object(__DIR__"workroom");
   ob2=present("luky",ob1);
   if(ob2) return; //本人在房間內即取消動作
   add("guest",me->query("id")+" - "); //紀錄訪客
   tell_object(luky,"[1;37m有訪客來囉!("+me->query("name")+")[m\n");
   tell_object(me,"[1;37m龍蝦(Luky)告訴你: 嗨!歡迎光臨!!我馬上回來招呼你![m\n");
  } else //of if(me->query("id")!="luky") 本人進入
  {
   if(query("guest")) //有訪客紀錄
   {
    tell_object(me,"[1;37m今天的訪客有:"+query("guest")+"[m\n");
    delete("guest");
   } else //of if(query("guest")) 沒有訪客紀錄
   {
          //tell_object(me,"[1;37m今天還沒有訪客來過[m\n");
   }
  }
 } else //of if(luky=find_player("luky")) 本人不在遊戲中
 {
  add("guest",me->query("id")+" - ");  //紀錄訪客
  tell_object(me,"[1;37m小龍蝦(Lobster)告訴你: Luky還沒來喔..[m\n");
 }
 
 if( file_size("/u/l/luky/note")>0 )
 {
  write(WHT"=======================龍蝦備忘錄=========================\n");
  me->start_more( read_file("/u/l/luky/note") ); //me->cat("/u/l/luky/note");
  write("\n"NOR);
 }
 
}

