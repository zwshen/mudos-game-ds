#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","梅花椿");
        set("long", "你正站在梅花椿上，這是一道錯綜複雜，奇奧無比的陣勢。\n");
        set("item_desc", ([ /* sizeof() == 1 */
        "梅花椿" : HIM"\n          ●  ●  ●  ●  ●\n\n"
                   "          ●  ●  ●  ●  "HIY"●\n\n"
                   "          "HIM"●  ●  ●  ●  ●          "HIY"●"NOR"=所在位置\n\n"HIM
                   "          ●  ●  ●  ●  ●\n\n"
                   "          ●  ●  ●  ●  ●\n\n"NOR,
        "may" : HIM"\n          ●  ●  ●  ●  ●\n\n"
                   "          ●  ●  ●  ●  "HIY"●\n\n"
                   "          "HIM"●  ●  ●  ●  ●          "HIY"●"NOR"=所在位置\n\n"HIM
                   "          ●  ●  ●  ●  ●\n\n"
                   "          ●  ●  ●  ●  ●\n\n"NOR,
        ]));
        set("outdoors","land");
        setup();
}
void init()
{ 
  object me;
  me=this_player();      
  add_action("do_move","move");
  add_action("do_may","may");
  if(me->environment() ) return 0;
  me->start_busy(1);
  call_out("add_may",1,me);
}
int do_move(string arg)
{
          object me;
          me=this_player();
          if( me->over_encumbranced() )
                return notify_fail("你的負荷過重﹐動彈不得。\n");
          if( me->is_busy() )
                return notify_fail("你的動作還沒有完成﹐不能移動。\n");
          if( me->query("wound/foot") > 10 )
                return notify_fail("你的腳傷勢過重，無法走椿了。\n");
          if(arg!="n" && arg!="s"  && arg!="w" 
             && arg!="sw" && arg!="nw" && arg!="off")
          {
            notify_fail("沒有這個方向哦。\n");
            return 0;
          }
          else {
            if(arg == "off")
            {
              message_vision(HIB"\n$N因無法破這道梅花陣，往下一躍，跳出了陣勢。\n\n"NOR,me);
              me->move(__DIR__"start");
              me->delete_temp("MAY");
            }
            if(arg == "n")
            {
              message_vision("$N踏著梅花步伐，緩緩的往北邊過去。\n",me);
              me->move(__DIR__"may25");
            }
            if(arg == "s")
            {
              message_vision("$N踏著梅花步伐，緩緩的往南邊過去。\n",me);
              me->move(__DIR__"may15");
            }
            if(arg == "w")
            {
              message_vision("$N踏著梅花步伐，緩緩的往西邊過去。\n",me);
              me->move(__DIR__"may19");
            }
            if(arg == "sw")
            {
              message_vision("$N踏著梅花步伐，緩緩的往西南邊過去。\n",me);
              me->move(__DIR__"may14");
            }
            if(arg == "nw")
            {
              message_vision("$N踏著梅花步伐，緩緩的往西北邊過去。\n",me);
              me->move(__DIR__"may24");
            }
            return 1;
          }
}
void do_may(string arg)
{
       int may;
       object me;
       me=this_player();
       if( arg = "")
       may=me->query_temp("MAY/total");
       notify_fail("你目前梅花數為："+ may +"。\n");
}
void add_may()
{
       int i;
       object me;
       me=this_player();
       i=me->query_temp("MAY/total");
       me->set_temp("MAY/total",i+3);
       me->start_busy(1);
       call_out("move",1,me);
}
void move()
{
        object me;
        me=this_player();
        if(me->query_temp("MAY/total")>20)
        {
         message_vision(HIR"\n$N因走錯步伐，一個不慎，從梅花椿摔了下來。\n\n"NOR,me);
         me->delete_temp("MAY");
         me->start_busy(1);
         me->move(__DIR__"start");
        }
        else {
         if(me->query_temp("MAY/total")==20)
         {
          message_vision(HIC"\n$N成功\的破解了這道梅花椿。\n\n"NOR,me);
          me->delete_temp("MAY");
          me->start_busy(1);
          me->move(__DIR__"good");
         }
         else {
          message_vision("$N穩穩的站在這梅花椿上。\n",me);
          me->start_busy(1);
         }
        }
}