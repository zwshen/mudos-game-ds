#include <ansi.h>
inherit NPC;
void create()
{
        set_name("艮山將" , ({ "kop general","general" }) );
        set("title",HIC"ξ神武教ξ 八神將"NOR );
        set("long",
                   "他是神武教護法八神將之一的艮山將，\n"
                   "他有如大山般的屹立不搖，百折不回，\n"
                   "不屈不撓，該靜則靜，應行就行，動靜\n"
                   "合宜，是個篤實之人。\n"
            );
        set("level",25);
        set("race","人類");
        set("gender","男性");
        set("age",40);
//        set_spell("god-benison",60);
        set_skill("mirage-steps",60);
        set_skill("godsword",60);
        set_skill("sword", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
        set("chat_chance", 6);
        set("chat_msg", ({
                "艮山將喃喃自語地說道：這個施迅不知把邪教一干人藏到哪去了。\n",
            (: random_move :),
        }));
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("exert mirage-steps"):),
        }) );
        setup();
  carry_object(__DIR__"wp/longsword.c")->wield();
     carry_object(__DIR__"eq/armor.c")->wear();
}
