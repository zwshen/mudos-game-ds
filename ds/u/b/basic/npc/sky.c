#include <ansi.h>
inherit NPC;
void create()
{
        set_name("甘天將" , ({ "sky general","general" }) );
        set("long",
                  "他是天地四將之一，\n"
                  "看起來身手矯健的是位血氣方剛的青少年\n"

            );
        set("title",HIR"天地四將之"HIC"甘天將"NOR );
        set("level",34);
        set("race","人類");
        set("gender","男性");
        set("age",20);
        set_skill("sword", 75);
        set_skill("parry", 75);
        set_skill("dodge", 80);
        set("chat_chance", 5);


        setup();
       carry_object("/u/b/basic/wp/sword")->wield();
}
