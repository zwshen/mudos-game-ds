#include <ansi.h>
inherit NPC; 
void create()
{
®       set_name(MAG"§ÔªÌ"NOR, ({ "ling jia","jia" }) );
        set("long","ªF¬v§Ô³Nªº°ª¤â¡C\n");
        set("level",40);
        set("age",45);

        set("combat_exp", 20000); 
        set("chat_chance",10);  
        set("combat_msg", ({
"$N¥Î¥XªF¬v§Ô³N¤¤ªº "HIC"¤g¹P"NOR" ,$N©¿µMÆp¨ì¦a¤U,$n°±¹y¤F´X¬í\n"
"$N®¨®¨ªº±q¦a©³ª¦¥X¨Ó,Ñ        set("chat_msg",({
            "¥¬¤B»¡:¦Ñ¤½¥X¥h°e³f«ç»òÁÙ¨S¦^¨Ó©O..^^....\n",
        }) );                               
        set_skill("combat", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
         
        setup();
        }



