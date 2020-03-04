#include <ansi.h>
inherit NPC;
void create()
{
    set_name("§ùº~",({"Michael Doohan","michael","doohan"}));
    set("long",@LONG
¡m¨®¯«¡n§ùº~¡A¤@­ÓÅTÅLÅLªº¦W¦r¡A¦P¹D¤¤¤HÅ¥¨ì¥Lªº¦W¦r¨S¦³¤£°_
¥ß·qÂ§ªº¡C¥L¬OWGP 500 '94~'98 ¥@¬É«a­x¡C

¥Í¤é¡G1965¦~6¤ë4¤é

LONG);
    set("level",45);
    set("title","öt¨®±Ú");
        set("age",35+random(2));
    set("combat_exp",50000);
    set("nickname","[0;1;31m¨[1m®[1m¯[1m«[0m");
        setup();
carry_object(__DIR__"eq/arai_pants_17")->wear();
carry_object(__DIR__"eq/arai_shield_14")->wear();
carry_object(__DIR__"eq/arai_surcoat_10")->wear();
}
