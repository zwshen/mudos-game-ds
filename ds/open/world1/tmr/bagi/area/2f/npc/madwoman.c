#include <path.h>
inherit NPC;

void create()
{
        set_name("瘋婆子",({"madwoman","woman"}));
        set("long" ,@long
    一個汙頭垢面的瘋婆子，身上的衣服破爛不堪，還有腐臭的酸味傳出
，不知多久沒洗澡，虧她還能忍受下去。你細瞧她的臉，更是瘡疤偏偏，
還有化膿的傷口，已經無法清楚辨識她原本的面目了。
long
);
        set("attitude", "friendly"); 
        set("age", 35);
        set("gender","女性");
          set("level", 35);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                  (:command("exert masen_whip"):), 
        }) );
        set_skill("whip",90);
        set_skill("masen_whip",90);
          set_skill("force",50);
        set_skill("run_cloud",75);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        setup();
        carry_object(__DIR__"wp/whip3")->wield();
          carry_object(TMR_PAST"bagi/npc/obj/left-arm");
}
