#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "無頭鬼", ({ "lesshead ghost","ghost","lesshead", "__GUARD__" }) );
        set("level",22);
          set("combat_exp",2200);
set("exp",2000);
        set("long","他是一隻沒有頭的鬼，看來體形相當壯碩。\n");
        set("age",30);
        set("evil",26);
set("title",CYN"鬼出神沒"NOR);
        set("gender","無性");
        set("attitude","killer");
           set_skill("unarmed",44);
           set_skill("dodge",44);
           set_skill("parry",44);
        setup();
}
