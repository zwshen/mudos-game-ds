#include <ansi.h>
inherit NPC;
void create()
{
        set_name( GRN"滄縣官兵"NOR , ({ "guard" }) );
        set("level",18);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set("long","滄縣維持秩序的官兵，一副剛正不阿的樣子自然的令人生畏。\n");
        setup();
        carry_object("/u/f/fanny/wp/gsword.c")->wield();
add_money("coin", 300);
}
