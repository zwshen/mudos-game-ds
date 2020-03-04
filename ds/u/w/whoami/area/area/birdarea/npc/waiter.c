#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小弟" , ({ "waiter" }) );
        set("level",10);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set_skill("dagger",20);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        set("long","他是專門照顧信徒的小弟, 但是你看他腳步輕快, 知道他是個有練武的人。\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "小弟喝道：我要讓你知道小弟是不好惹的!!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger2.c")->wield();
}

