#include <npc.h>

inherit F_SOLDIER;

void create()
{
        set_name("銀行警衛", ({ "bank guard","guard" }) );
        set_race("human");
        set("age", 25);
        set_stat_maximum("gin",100);
        set_stat_maximum("hp",100);        
        set("long", "一個壯碩的大漢，正全副武裝，戰戰兢兢著守衛著銀行的安全。\n");
        setup();
        carry_object(__DIR__"obj/longsword")->wield();
          carry_object(__DIR__"obj/guard-armor")->wear();
          carry_object(__DIR__"obj/guard-cloth")->wear();
}

