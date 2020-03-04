//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("ºÑ¹pº¸Âí¦u½Ã",({"pearl guard","guard"}));
set("level",32);
set("age",30);
set("long","¥L¬O¥»Âíªº¤jªù¦u½Ã, ¤@°Æ«ÜµL²áªº¼Ë¤l¡C\n");
set("gender", "¨k©Ê");
set_skill("tenken",20);
set("amount",1);
map_skill("unarmed","tenken");
set("chat_chance",5);
set("chat_msg",({
  (:command,"yawn":),
}) );
set("coin",300+random(80));
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n¦u½Ã¤j­ú: ¡u ÄÇ¤F§Ú§a!! §Ú¦­´N¤£·Q·íÄµ½Ã¤F.. ¡v\n"NOR,
HIW"\n¦u½Ã·Q°k¥i¬O³QÄd¦í¤F...¶]¤£±¼\n"NOR,
     }) );
carry_object(__DIR__"eq/scalescloth")->wear();
carry_object(__DIR__"wp/club")->wield();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="guard")
 {
 message_vision("\n[1;37m¦u½Ã¬ðµM¹ï$N[1;37m¤j¥s: §A¸òµÛ§Ú·Q·F³Â!!?¡C[m\n",this_player());
 message_vision("\n[1;33m¦u½Ã¥Î¤O±À¤F$N[1;33m¤@§â, Á×¶}¤F$Nªº¸òÂÜ¡C[m\n",this_player());
 return 1;
 }
return 0;
}