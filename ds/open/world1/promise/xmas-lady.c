#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIM"聖誕"HIW"小"HIR"紅"HIW"帽"NOR,({"christmas lady","christmas","lady"}));
set("gender","女性");
set("race","人類");
set("title",HIR"獎品美少女"NOR);
  set("long",
"要獎品請打(want)!!\n",
);
       set("age", 14);
       set("combat_exp", 0);
       set("attitude", "friendly");

setup();
}
void init()
{
add_action("do_want", "want");
}
int do_want(string arg)
{
       object me,gift;
       me = this_player();
       
if (me->query("age") <= 17 )
     return notify_fail(HIW"你沒資格拿到獎品。\n"NOR);


       if(me->query("xmas-gift"))
       return notify_fail(HIY"真是貪心的人，我討厭你>.<~\n"NOR);
       else
{
me->set("xmas-gift",1);
gift=new(__DIR__"xmas-gift");
message_vision(HIM"聖誕"HIW"小紅帽"NOR"給"+me->query("name")+"一份"HIR"聖誕禮物"NOR"，並且幫"+me->query("name")+"打打氣加加油！！\n"NOR,me);
gift->move(me);
}

       return 1;
}




