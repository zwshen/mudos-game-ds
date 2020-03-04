#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG "¬Y¤H" NOR,({"somebody","somebody"}) );
        set("long",@LONG
 ¶Ç»¡·í¦Û¨­ªZ¥\½m¦Ü¬Y¤@¹Ò¬É«á¡A«K¥i¥H²`«p¤§¤º¤O±N¦×Åé©ÒÁôÂÃ ¦Û¥j¥H¨Ó±q¨S¤H½m¦Ü¹Ò¬É¡A¦ý¬Û¶Ç¾½(Demon)¥H¹F¦¹¹Ò¬É¡A[37m¡y[0m¨ÓµL¼v¥hµLÂÜ[37m¡I¡z¡C[0m
LONG    
        );
        set("race", "³¥Ã~");    
        set("unit","°¦");
        set("age",80);
        set("level",80);
        set("chat_chance",10);
        set("chat_msg",({
        "¬Y¤H¤@§¾ªÑ§¤¦b¦a¤W±æµÛ¤@®è³¥ªáµo°_§b¨Ó...\n",
        "¬Y¤H¤j²´¨L¨L¦a±æ¤F§A¤@²´¡C\n",
        "¬Y¤H¤f¤¤³ä³äªº°á¹D¡G¡u§A¬Ý¤£¨ì§Ú¡ã§A¬Ý¤£¨ì§Ú¡ã¡v\n",
        }) );

        set("attitude", "heroism");    
        set("limbs", ({ "ÀY³¡", "¸¡³¡","¯Ý³¡","¸}","§À¤Ú" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
//¼ÈÃö        carry_object(__DIR__"obj/paper");
}

