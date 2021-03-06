#include <npc.h>

void create()
{
        set_name("石室守護者", ({ "guard monster","monster" }) );
        set("long",@long
    石室守護者為硬幫幫中極為強大的怪獸，對於組織非常的忠心，您可
以抬頭望見牠駭人的獠牙，上頭正滴著惡臭的流涎，深綠色的眼球好像正
瞪視著您。
long
);
        set("title","硬幫幫");
        set_race("strength");
        set("age", 80);
        set_skill("parry",120);
        set_skill("dodge",120);
        set_skill("unarmed",150);
        set_skill("psychical",100);
        set_skill("twohanded blunt",120);
        set("attitude", "aggressive");
        set("froce_ratio",10);        
        set("bounty",([
                 "reputation": 5, 
        ]) );
        
	set_temp("apply/armor" , 40 );
        setup();
        set_level(25);
        set_attr("strength",100);
        carry_money("gold", 1);
        carry_object(__DIR__"obj/boots")->wear();
        carry_object(__DIR__"obj/armor")->wear();
        carry_object(__DIR__"obj/ring")->wear();
        carry_object("/d/obj/big-blunt.c")->wield();
}

