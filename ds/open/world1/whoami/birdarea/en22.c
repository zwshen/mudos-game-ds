#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIW"東北"NOR"澤林");
     set("long",@LONG 
你現在來到東北澤林的沼澤部份, 這裡的沼氣臭氣沖天, 令
人難以忍受, 你覺得你頭昏眼花, 方向感全失, 在這泥濘這沼澤
裡, 你只能憑直覺走出了。
LONG
);
     set("outdoors","forest");
     setup();
}
void init()
{
     add_action("do_move","move");
}
int do_move(string arg)
{
          object me;
          me=this_player();
          if( me->over_encumbranced() )
                return notify_fail("你的負荷過重﹐動彈不得。\n");
          if( me->is_busy() )
                return notify_fail("你的動作還沒有完成﹐不能移動。\n");
          if( me->query("wound/left_leg") > 10 && me->query("wound/right_leg") > 10  )
                return notify_fail("你的腳傷勢過重，無法通過泥沼。\n");
          if(arg!="n" && arg!="w" && arg!="north" && arg!="west")
          {
            notify_fail("那裡的泥沼很深，不可能走的過去的。\n");
            return 0;
          }
          else {
            if(arg == "n" || arg == "north")
            {
              message_vision("$N用力的把腳從泥沼中拔出，緩緩的往北邊過去。\n",me);
              me->move(__DIR__"en23");
            }
            if(arg == "w" || arg == "west")
            {
              message_vision("$N用力的把腳從泥沼中拔出，緩緩的往西邊過去。\n",me);
              me->move(__DIR__"en21"); 
            }
            return 1;
          }
}
int room_effect(object me)
{
          switch(random(10))
        {
         case 0:
         case 1:
         case 2:

                message_vision("你的雙腳正慢慢陷入泥沼中．．．。\n",me);
                if(me->query_skill("dodge")< 35 && random(10)<3 )
                {
                        tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
                        me->add_busy(5);
                }

                else if(me->query_skill("dodge")< 70 && random(10)<3 )
                {
                        tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
                        me->add_busy(3);
                }

                else if(me->query_skill("dodge")> 69 && random(10)<3 )
                {
                        tell_object(me,YEL"等你發現時，已深陷於泥沼，一時動彈不得！！\n" NOR ); 
                        me->add_busy(1);
                }
                return 1;
        

         default:       return 1;
        }
}
