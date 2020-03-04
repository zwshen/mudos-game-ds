#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"Honey"NOR, ({ "honey","dog" }) );
        set("race", "野獸");
        set("age", 3); 
        set("title",HIY"迷你貴賓犬"NOR);        set("level",1);
        set("long", "Jangshow 的寵物。\n");
        set("str",1);
        set("max_hp",10);
        set("dex",-3);
        set("int",1);
        set("con",1); 
        set("no_kill",1);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                "Honey用鼻子聞了聞你的腳。\n",
                "Honey對著你搖了搖尾巴。\n",
                "Honey用後腿抓了抓身體。\n" }) );
                

        setup();
}


