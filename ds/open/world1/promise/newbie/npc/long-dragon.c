#include <ansi.h>
inherit NPC;
void create()
{
        set_name(YEL"ªøÅ½Às"NOR, ({ "long dragon","dragon","long" }));
        set("long","¥®Às¤§¤¤·s¦u½Ã¡A¦ý¥\\¤Oµy·LÁ¡®z¡C\n");

        set("race","³¥Ã~");
        set("level", 5);
        set("age", 200);

        set("limbs", ({ "ÀsÀY","§À¤Ú","Åì¥Ò","Ä²¨¤","«e¸}","«á¸}","­IÅ_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}

