#include <ansi.h>
inherit NPC;
void create()
{
        set_name("震雷將" , ({ "thunder general","general" }) );
        set("title","ξ神武教ξ 八神將" );
        set("level",30);
        set("race","人類");
        set("age",40);
        set_skill("sword", 100);
          set_skill("godsword",50);
         set_spell("god-fire",60);
        set_skill("parry", 100);
        set_skill("dodge", 130);
        set("long","他是神武教的八神將之一。\n");
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
           (:command("exert godsword"):),
         (:command("cast god-fire"):),
        }) );
        setup();
        carry_object(__DIR__"wp/longsword.c")->wield();
}
