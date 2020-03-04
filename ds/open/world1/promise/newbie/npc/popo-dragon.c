#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"ªwªwÀs"NOR, ({ "popo dragon","popo","po","dragon" }));
        set("long","¥®Às¤§¤¤³Ì±j¶ÕªºÀsºØ¡C\n");

        set("race","³¥Ã~");
        set("level", 10);
        set("age", 333);

        set("limbs", ({ "ÀsÀY","§À¤Ú","Åì¥Ò","Ä²¨¤","«e¸}","«á¸}","­IÅ_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}

