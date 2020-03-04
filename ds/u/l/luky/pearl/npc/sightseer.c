//sightseer.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("Æ[¥ú«È",({"sightseer"}));
set("level",28);
set("age",32);
set("long","¤@­Ó¥~¦a¨ÓªºÆ[¥ú«È, ¥¿¦b¨ì³B¶R¬ö©À«~·Ç³Æ±a¦^®a°µ¬ö©À¡C\n");
set("gender", "¤k©Ê");
set("combat_exp",20000+random(3000));
set("coin",500+random(200));
set("chat_chance",35);
set("chat_msg",({
  (:command,"east":),
  (:command,"get all":),
  (:command,"west":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
setup();
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\nÆ[¥ú«È¤j¥s: ¡u·m§T°Ú¡ã¡T±Ï©R°Ú¡T¡v\n"NOR,
HIW"\nÆ[¥ú«È·Q°k¥i¬O³QÄd¦í¤F...¶]¤£±¼\n"NOR,
     }) );
//carry_object("/u/p/pudon/obj3/ring")->wear();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="sightseer")
 {
 message_vision("\n[1;37Æ[¥ú«È¹ï$N¯ºµÛ»¡: [1;37m§A¤]¬O¨ÓÆ[¥úªº¶Ü?[m\n",this_player());
 message_vision("\n[1;33mÆ[¥ú«È»¡:[1;32m ¨º´N©M§Ú¤@°_³}³}§a¡C*^_^*[m\n",this_player());
 return 0;
 }
return 0;
}