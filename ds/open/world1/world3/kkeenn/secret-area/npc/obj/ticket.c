#include <ansi.h>
inherit ITEM;
void create() 
{
          set_name(HIC"ó布"NOR,({"ticket"}) );
           set("long","眎疊ㄨ帝[->]ó布(use ticket)\n");
               set("value",300);
               set_weight(2000);
            if(clonep() ) 
       set_default_object(__FILE__);
            else {
               set("unit","眎");
                  }
      setup();
}

void init()
{
        add_action("do_use","use");
}

int do_use(string arg)
{ 
        object me,ob;
        if( !this_object() ) return 0;        
        if( !this_object()->id(arg) ) 
   return notify_fail("稱璶硂柑ㄏノ裕 \n");
        ob=this_object();
        me=this_player(); 
                message_vision(HIY+me->query("name")+"もó布, 筿óミㄨ゜τㄓр"+me->query("name")+"更ǐ\n" NOR ,me);
   me->move("/open/world3/tmr/basic/train_station1.c");
                message_vision(HIY"筿ó礛瞷玡, "+me->query("name")+"眖ó絯˙ǐ\n" NOR ,me);
        destruct(ob);
  return 1;
}

