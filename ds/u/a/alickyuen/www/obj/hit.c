#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"敲三小"NOR,({ "hit" }));
    if( clonep() )
    set_default_object(__FILE__);
    else
    {
       set("can_give",1);
    }
    setup();
}

void init()
{
    add_action("do_hit", "hit");
}

int do_hit(string arg)
{
    object obj,me;
    me = this_player();

    if(!arg) return notify_fail("<格式>:hit <Player ID>\n"); 
    if(!obj = present(arg, environment(me)))
       return notify_fail("這裡沒有這個人。\n");
    message_vision(HIY"\n\n\n\n\n$n用力往$N的頭敲下去。\n\n\n\n\n"NOR,obj,me);
    obj->start_busy(26);
    obj->set_temp("hit",1); 
    call_out("hit",1,obj);
    return 1;
}

int hit(object obj)
{
      int i;
      object me;
      me = this_player();
      i = obj->query_temp("hit");

//      if(!interactive(obj))
//         return notify_fail(HIR"什麼事也沒發生...\n");
      switch( i ) {
          case 1:
            tell_object(obj,HIR"你滿頭的星星，漸漸的失去意識....\n\n\n\n\n\n\n"NOR);
            obj->disable_player_cmds("你還在昏迷。\n");
            obj->set_temp("define_look",NOR" 正站在這裡 "HIR"[昏迷中]"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 2:
            tell_object(obj,HIW"模糊的意識中你夢到自己正在裸奔...\n\n\n\n\n\n\n"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 3:
            message_vision(HIR"$N陶醉在裸奔的愉悅中，好不快樂...\n\n"NOR,obj);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 4:
//            tell_object(users(),HIR+obj->query("name")+HIR+"使勁大喊﹕我愛裸奔∼∼\n"NOR);
            tell_object(obj,HIW"一個不小心太過興奮，腦充血你又昏了過去...XD\n\n\n\n\n\n\n"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 5:
            tell_object(obj,HIR"一段時間後你漸漸恢復意識...\n\n"NOR);
            obj->set_temp("hit",i+1);
            call_out("hit",10,obj);
            break;
          case 6:
            message_vision(YEL"$N"YEL"跪著東爬爬, 西爬爬, 爬完又捏捏屁屁大叫: 我屁屁好臭唷∼∼\n"NOR,obj);
            obj->delete_temp("hit"); 
            obj->delete_temp("define_look");
            obj->enable_player_cmds();
            break;
          }
}
