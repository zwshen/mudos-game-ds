#include <ansi.h>
inherit NPC;
void create()
{
    set_name("¤pªÖ¥§",({"Kenny Roberts Jr.","kenny","roberts","jr"}));
    set("long",@LONG
Kenny Roberts Jr.¬Ý°_¨Ó¤@ÂI¤]¤£¹³¬O500cc grand-prixªºÃM¤h¡A
¥L¬O¤@­Ó¬Û·í¾ë¹ê¤SÁ¾µêªº¤@­Ó¤H¡C

¥Í¡@¤é¡G1973/ 8/ 25
¥X¥Í¦a¡GHickman, USA

LONG);
    set("level",45);
    set("title","öt¨®±Ú");
    set("age",27+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;36m¤[1mÑ[1m¤[1m~[0m");
        setup();
carry_object(__DIR__"eq/arai_hands_6")->wear();
carry_object(__DIR__"eq/arai_head_14")->wear();
carry_object(__DIR__"eq/arai_legging_10")->wear();
}
