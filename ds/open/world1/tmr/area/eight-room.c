#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "牢獄");
        set("long", @LONG
一間土室，室廣八尺，深可四尋，上頭只有一扇短窄的小窗，地上盡
是溼腐的爛泥，室角堆積著一包包的腐爛米殼，還可看到數隻已發臭的死
鼠、死屍，整間牢室，還關著幾位犯人，更是擁擠難動。
LONG
        );
        set("light",1);
        set("world", "past");
   set("objects",([
    __DIR__"npc/man2":2,
       ]) );
        set("no_clean_up", 0);
        setup();
}

int room_effect(object me)
{
        switch(random(15))
        {
         case 0:
         write("外頭陡地下了陣陣大雨，室內登時淹起水來了...\n");
         tell_object(me, HIC "你覺得整隻腳浸在水裡，頗為難受。\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write("地上歷爛不堪的泥土發出陣陣味道..... \n");
         tell_object(me, HIY "你聞著這股味道，只覺得腦中一陣昏胘...\n" NOR ); 
         me->receive_damage("hp",20);
         me->receive_damage("mp",30);
         return 1;

         case 2:
         write("四周空氣因不流通又再度凝結起來了.....\n");
         tell_object(me, HIB "你只覺得胸中煩悶難受....\n" NOR ); 
         me->receive_damage("ap",40);
         return 1;

         case 3:
         write("室外似乎有人在炊煮，整間室內登時燥熱不堪.... \n");
         tell_object(me, HIR "你只覺得快熱昏頭了....\n" NOR ); 
         me->receive_damage("mp",40);
         return 1;

         case 4:
         write("室角腐爛的米殼發出陣陣的惡臭.... \n");
         tell_object(me, HIY "你不禁嘔吐起來....\n" NOR ); 
         me->receive_damage("hp",30);
         return 1;

         case 5:
         write("你看著四周的人淨是腥臊汙垢，大家擠來擠去...\n");
         tell_object(me, HIC "你覺得自已身體似乎也越來越惡臭了...\n" NOR ); 
         me->receive_damage("mp",30);   
         me->receive_damage("ap",30);
         return 1;

         case 6:
         write("室角的腐鼠、腐屍發出陣陣令人難聞的屍臭味...\n");
         tell_object(me, HIB "你聞著這股味道，只覺得四肢發軟，難以忍受...\n" NOR ); 
         me->receive_damage("hp",20);   
         me->receive_damage("ap",20);
         return 1;

     case 7:
         case 8:
   case 9:
         write(HIW "你想起諸聖先賢說過的話，登時心中激起一股正氣！！\n" NOR);
         me->receive_heal("mp",50);
         me->receive_heal("ap",50);
         me->receive_heal("hp",100);
         return 1;

         default:       return 1;
        }
}



void init()
{
          add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="破洞") return 0;
        if(me->is_busy()) return notify_fail("你正在忙。\n");
        message_vision("$N一縮身，從剛鑽進來的破洞擠了出去。\n",me);
        me->move(__DIR__"vroad4");
        tell_room(environment(me),me->query("name")+"忽然出現在你的面前。\n",({ me }) );
        return 1;
}



