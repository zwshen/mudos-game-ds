#include <ansi.h>
inherit NPC;

void create()
{
        set_name("¦Ì¦÷°Ç", ({"michel"}) );
   set("long", "§A²´«e´N¬O¥|¤j¿K¤Ñ¨Ï¤¤ªº¤j¤Ñ¨Ïªø¦Ì¦÷°Ç!¾Ö¦³¨â¤d¤Ñ¨Ï§L¹ÎªºÅv¤O,
´¿»P¼Z¸¨¤Ñ¨Ï§Ü¿Å¨Ã¤jÀò¥þ³Ó\n");
        set("race", "¤HÃþ");
        set("gender", "¤k©Ê"); 
        set("age", 3000);
        set("attitude", "heroism");
        set("level",70);
        set("evil", -999);
        set("combat_exp",5000);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("poken", 100);
        set_skill("cloudsteps", 100);
        set_skill("thundersword", 100);
        set_spell("god-benison", 100);
        set_skill("unarmed",100);
        set("title",HIW"¡i"HIR"¿K¤Ñ¨Ï"NOR" "HIG"¤õ"NOR" "HIC"¤j¤Ñ¨Ïªø"HIW"¡j"NOR);
        set_skill("parry", 100);  
        set("chat_chance", 3);  
        set("chat_msg", ({     
        "¦Ì¦÷°Ç­±µLªí±¡ªº»¡¹D:¤HÃþ¬O¥²»Ý·´·Àªº,¤HÃþ¬O¸o´cªº®Ú·½.\n"
}) ); 
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({ 
        (:command("[32mdefend [0muriel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert thundersword"):), 
        (:command("exert poken"):), 
        (:command("exert cloudsteps"):), 
        "¦Ì¦÷°Ç¤@Áy«ã¤õªº»¡¹D:¤HÃþ¬O¸o´cªº®Ú·½\n"
        }) );
        setup();  
        carry_object("u/z/zorg/obj/sword2.c")->wield();
}

