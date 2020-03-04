inherit NPC;
void create()
{
set_name("[1;32m±Ð°ó¦u½Ã[0m",({"church guard","guard"}));
set("gender", "¨k©Ê");
set("title","[1;33m«i¤h[0m");
set("long", "¥L¬O±Ð®xªº¥¿¦¡¦u½Ã,²´¯«ºë¥ú°{Ã{,¤@¬Ý´Nª¾¹D¬O­Ó¤£¥i¤péßªº¾Ô¤h¡C\n");
set("age",36);
set("evil",-80);
set("level",52);
//set_skill("dragon_blade",30);
//map_skill("blade","dragon_blade");
set("combat_exp",26000+random(3000));
set_skill("rapid",180);
set_skill("strike",100);
set_skill("combat",240);
set("coin",random(1700));
set_temp("apply/armor",700);
set("chat_chance_combat",12);
set("chat_msg_combat",({
(:command,"angry":),
(:command,"rapid":),
(:command,"strike":),
}));   
setup();
//add_money("coin",random(1700));
//carry_object("/u/p/pudon/obj3/cloak")->wear();
//carry_object("/u/p/pudon/obj3/clothes")->wear();
carry_object(__DIR__"eq/redshield")->wear();
carry_object(__DIR__"wp/stonehammer")->wield();
}

/*
void die()
{
object ob;
if( !ob = query_temp("last_damage_from") )
{
 ob = this_player(1);
}
if( !ob ) return;
tell_room("[1;32m¦u½Ã³¬°_Âù²´¬èÃ«...¥D°Ú.. ½Ð³j§K§ÚªºÆF»î§a!![0m\n",ob);
::die();
    destruct(this_object());
}
*/