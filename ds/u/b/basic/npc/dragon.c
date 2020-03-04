#include <ansi.h>
inherit NPC;
void create()
{
        set_name(BLK"¶ÂÀs"NOR, ({ "black dragon","dragon","mob" }));
        set("long","basicªºÃdª«¤§¤@¡C\n");

        set("race","³¥Ã~");
        set("level", 31+random(5));
        set("age", 1);

        set("limbs", ({ "ÀsÀY","§À¤Ú","Åì¥Ò","Ä²¨¤","«e¸}","«á¸}","­IÅ_","ÀsÃ@" }) );
        set("verbs", ({ "bite", "claw","poke" }));

        set_temp("apply/attack", 3);
        set_temp("apply/damage", 20);
        set_temp("apply/dodge", 40);
        set_temp("apply/armor", 15);

        set("combat_exp", 10000000);
        setup();
        add_money("silver",2);
}
