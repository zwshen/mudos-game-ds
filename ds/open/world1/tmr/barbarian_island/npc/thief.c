#include <npc.h>
#include "barbarian_base.c"

void create()
{
        set_name("不知名的盜賊", ({ "thief" }) );
        set("long",@long
在你眼前是一個穿著黑衣、賊頭賊腦的男子，瞧起來就是當盜賊的樣
子。他正睜大眼睛四處張望，似乎在擔心什麼一樣。
long
);
        set_race("human");
        set("age", 30);
        set_skill("blade",80);
        set_skill("secondhand dagger",80);
        set_skill("parry",50);
        set_skill("dodge",50);
        setup();
        set_level(15);
        carry_object("/d/obj/blade")->wield();
        carry_object("/d/obj/dagger")->wield("secondhand dagger");
        carry_object("/d/obj/armor")->wear();
        carry_object(__DIR__"obj/battle-axe");
}


