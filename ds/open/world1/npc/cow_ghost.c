inherit NPC;

void create()
{
        set_name("牛頭鬼", ({ "cow head ghost","ghost" }) );
        set("race","human");
        set("level",32);
        set("age",300);
        set("evil",-20);
        set("long",@LONG
陰曹地府的鬼差，專門管理及緝拿孤魂野鬼，與馬面鬼並稱
「牛頭馬面」。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/ghost_plate")->wear();
        carry_object(__DIR__"../wp/purple_hammer")->wield();
}



