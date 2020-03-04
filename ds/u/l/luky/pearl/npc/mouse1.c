inherit NPC;

void create()
{
set_name("老鼠",({"mouse"}));
        set("race", "野獸");
set("level",3);
set("age",5);
set("long","你看過一隻灰色的小老鼠十分可愛。\n");
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"}));
 set("verbs", ({ "bite"}));
set("chat_chance",30);
set("chat_msg",({
(:command("east"):),
(:command("west"):),
(:command("north"):),
(:command("south"):),
}));
        setup();
}
init() 
{
if (this_player()->query_temp("kill_king")==1)
{
write("[1;36m老鼠氣憤的說:我要替我偉大的鼠王報仇。[m\n");
kill_ob(this_player());
}
}
