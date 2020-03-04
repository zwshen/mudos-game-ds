#include <ansi2.h>
inherit NPC;
void create()
{
 set_name(HIW+BLK"¶Â¤ò½Þ"NOR,({"black pig","pig"}));
 set("long","¥¿©v¶Â¤ò½Þ¡C\n");
 set("age",2+random(10));
 set("race", "³¥Ã~");
 set("level",3+random(10));
 set("limbs", ({ "ÀY³¡", "¨­Åé", "«e¸}", "«á¸}", "§À¤Ú" }) );
 set("verbs", ({ "bite", "claw" ,"crash"}) );
 set("max_hp",350+random(350));
 set("addition/damage",random(30)); 
 setup();
}
void die()
{
        object ob;
        ob=new(__DIR__"obj/item20"); 
        ob->move(this_object());
        ::die();
        return;
}

