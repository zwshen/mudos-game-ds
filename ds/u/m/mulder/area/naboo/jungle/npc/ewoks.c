#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIB "魯那斯" NOR , ({ "ewoks" }) );
        set("race","人類");
        set("gender","男性");
        set("age",25);
        set("level",13);
        set_skill("dodge",40);
        set("env/wimpy", 25);
        set("long",HIB "魯那斯是一種很低等的生物。" NOR);
        set("chat_chance",5);
        set("chat_msg",({
                (: "random_move" :),
        }) );

        setup();
}