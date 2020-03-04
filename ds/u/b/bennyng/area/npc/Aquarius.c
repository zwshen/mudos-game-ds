#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"卡妙"NOR,({"aquarius"}));
        set("long",
                "    你眼前這個身穿寶瓶座黃金聖衣的人就是十二宮中唯一使用凍氣的\n"
                "黃金聖鬥士!他便是冰河的恩師，一招就能把你凍僵而死\n"
        );
        set("level",50);
        set("str",  65+random(10));
        set("combat_exp",50000);
        set("age",29);
        set("chat_chance",1);
        set("chat_msg",({
  (: command("say 要打倒我，必須有絕對零度！！") :),
}));
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
                                (:command("exert bagi_fist"):),
  HIW"卡妙說：你找死了，沒有絕對零度不能解決我\n"NOR,
}));
        set("class","fighter");
        set("class1","軍人");
        set("title",HIY"寶瓶座黃金聖鬥士"NOR);
        set_skill("unarmed",90);
        set_skill("dodge", 100);
        set_skill("parry", 80);
        set_skill("bagi_fist", 70);
        set_skill("combat",100);
        map_skill("unarmed","bagi_fist");
        setup();
        carry_object(__DIR__"eq/aquarius")->wear();
}
