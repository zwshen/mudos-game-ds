#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "賣藝人" , ({ "acrobat" }) );
      set("level",2);
        set("race","人類");
         set("gender","男性");
        set("con",5);
        set("age",35);
        set("long",
                 "他是一位靠著賣藝雜耍混口飯吃的江湖藝人。\n");
        set("chat_chance", 5);
        set("chat_msg",({
               "賣藝人拿起手上的手把，往嘴裡塞去，表演吞火的絕藝。\n",
        }) );
        set("chat_msg_combat", ({
                "賣藝人大叫：殺人啊！！！救命啊！！！\n",
        }) );
        setup();
        carry_object(__DIR__"eq/cloth.c")->wear();
        carry_object("open/always/torch.c");
        carry_object("open/always/torch.c");
        carry_object("open/always/torch.c");
}
