#include <ansi.h>
inherit NPC;
void create()
{
 set_name("守衛",({"guard"}));
 set("long",@LONG
這是一個四處巡邏的天壇守衛
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("nickname",HIC"天壇"NOR);
 set("evil",-10);
 set("gender","男性");
set("level",27);
 set_skill("sword", 30);
 set("chat_chance",10);
 set("chat_msg", ({"守衛四處的巡邏....\n", }));
 setup();
 carry_object(__DIR__"eq/steel_sword")->wield();
 carry_object(__DIR__"eq/sky_cloth")->wear();
}
