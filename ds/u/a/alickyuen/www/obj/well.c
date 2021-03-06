#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
    set_name("古井",({"well"}));
    set("unit", "口");
    set("long",@LONG
    看起來非常老舊的水井，想必有相當的歷史。這口井深不見底，
貿然下去似乎不是明智之舉，看來得找個東西攀爬(climb)下去了。
LONG);
    set_weight(99999);
    set("value", 1);
    set("no_sac", 1);
    set("no_get", 1);
    set("no_clean_up",1);
    setup();
}

void init()
{       
    add_action("do_climb","climb");
}

int do_climb(string arg)
{
    int sk;
    object me,obj,item;
    me = this_player();

    if(me->is_busy())
       return notify_fail("你正在忙。\n");
    if(!arg || sscanf(arg, "into %s", arg) != 1)
       return notify_fail("你要攀爬進(climb into)哪裡？\n");
    if(arg != "well" && arg != "古井")
       return notify_fail("你要爬進哪裡？\n");
    if(!(item = present("rope",me)))
       return notify_fail("你沒有適合的工具攀爬。\n");

    message_vision(HIC"$N將麻繩固定後便抓著麻繩準備躍下古井\n"NOR,me);
    destruct(item);
    call_out("msg",4,me);
    return 1;
}
int msg(object me)
{
    int i;
    i = me->query("str");
    switch(i/10+(random(5)+1))
    {
       case 1..6:
            message_vision(HIR"$N突然間使不上力鬆開了手，墜入井內！\n"NOR,me);
            me->receive_damage("hp",me->query("max_hp")/2);
            me->receive_wound("random",random(10)+1,me);
            me->start_busy(2);
            me->move("/u/f/fedex/fantasyland/room1");
            call_out("damage",0,me);
            break;
       case 7..10:
            message_vision(HIR"$N突然間使不上力鬆開了手，所幸已經快到井底只受點輕傷。\n"NOR,me);
            me->receive_damage("hp",random(100)+1);
            me->start_busy(2);
            me->move("/u/f/fedex/fantasyland/room1");
            call_out("damage",0,me);
            break;
       default:
            me->move("/u/f/fedex/fantasyland/room1");
            message_vision(HIR"$N穩穩的著陸在井底。\n"NOR,me);
            break;
    }
    return 1;
}

int damage(object me)
{
  int dam;
  string msg;
  object *list;
  list = all_inventory(environment(me));
  dam = random(300+1);

  if(!list) return 1;
  foreach(object who in list)
  {
     if(who == me) continue;
     if(environment(who) && userp(who))  
     {
          tell_object(who,HIW+me->query("name")+"從井口掉下來壓在你身上...\n"NOR);
          tell_object(who,HIR"[你受到"+dam+"點的傷害]。\n"NOR);
          tell_object(me,HIW"你重重的壓在"+who->name()+"身上...\n"NOR);
          who->receive_damage("hp",dam);
          who->start_busy(2);
     }
  }
  return 1;
}
