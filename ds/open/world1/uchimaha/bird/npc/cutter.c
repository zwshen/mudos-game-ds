#include <ansi.h>
inherit NPC;
void create()
{
 set_name("决ひ",({"woodcutter","cutter"}));
 set("long","硂琌タワれ决ひ\n");
 set("attitude","peaceful"); 
 set("age",45);
 set("gender","╧┦");
 set("level",20);
 set("guild_gifts",({10,10,0,0}));
 set_skill("axe",60);
 set_skill("parry",50);
 set_skill("dodge",50);
 set("chat_chance",20);
 set("chat_msg", ({"决ひ癬もい繷, ┕攫.\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({                         
                         (:command,"say ぃ璶ぃ癬决ひ!!":),
 }));
 setup();
 carry_object(__DIR__"eq/axe")->wield();
 
}

