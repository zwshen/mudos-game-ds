#include <ansi2.h>
inherit NPC;
void create()
{
        set_name(HIW"·à¤l"NOR, ({ "lion" }) );
        set("long",@LONG
            ¢©¢¨¢©¢¨ø    
          ¢ª¢«    ¢ª¢««  
          ¢¨  ¡ä¡ä  ¢©   ³o°¦·à¤l¬O©]¯«£»ò]ªºÃdª«¡C
          ¢ª ¡Ö¡C¡Õ ¢« 
          ¢¨¢© ¡³ ¢¨¢©   ¥Í©Ê·Å¹¥¡A©~®a¥~¥X¨â¬Û©y¡C
       ¡´   ¢«¢ª¢«¢ª     
     ~ ¡`¡]¢¨¢©¢¨¢©¡^ 


LONG
);
        set("race", "³¥Ã~");
        set("gender","¶¯©Ê");
        set("level",25);
        set("age",2);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);

	set_temp("apply/armor",600);

	set("limbs", ({ "ÀY³¡", "¨­Åé", "«e¸}", "«á¸}", "§À¤Ú" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("dex", 100);
	set("con", 100);

        set("combat_exp", 30000);

        setup();

}
