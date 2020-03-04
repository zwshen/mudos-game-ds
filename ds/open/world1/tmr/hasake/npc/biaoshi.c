#include <ansi.h>
inherit NPC;
void create()
{
       set_name("神秘鏢師", ({ "escort guard", "guard" }) );
       set("title", "虎遠鏢局");
       set("gender", "男性" );
       set("age", 45);
       set("level",15);
       set("long", "他是個來自中原的鏢師，但他十年來從沒回去過，好像是在找什麼東西。\n" );
       set("attitude", "heroism");
       set("chat_chance", 30);
       set("chat_msg", ({
            "神秘鏢師好像在自言自語：在哪呢？在哪呢？ \n",
       }) );          
       set_skill("force", 30); 
       set_skill("unarmed", 30);
       set_skill("sword", 30);
       set_skill("dodge", 30);
       set_skill("parry", 30);       
       setup();       
       add_money("silver", 5);
}