#include <ansi.h>
inherit NPC;
void create()
{
    set_name("小肯尼",({"Kenny Roberts Jr.","kenny","roberts","jr"}));
    set("long",@LONG
Kenny Roberts Jr.看起來一點也不像是500cc grand-prix的騎士，
他是一個相當樸實又謙虛的一個人。

生　日：1973/ 8/ 25
出生地：Hickman, USA

LONG);
    set("level",45);
    set("title","飆車族");
    set("age",27+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;36m�[1m�[1m�[1m~[0m");
        setup();
carry_object(__DIR__"eq/arai_hands_6")->wear();
carry_object(__DIR__"eq/arai_head_14")->wear();
carry_object(__DIR__"eq/arai_legging_10")->wear();
}
