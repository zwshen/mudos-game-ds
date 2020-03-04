inherit NPC;

void create()
{
set_name("¦Ñ¹«",({"mouse"}));
        set("race", "³¥Ã~");
set("level",3);
set("age",5);
set("long","§A¬Ý¹L¤@°¦¦Ç¦âªº¤p¦Ñ¹«¤Q¤À¥i·R¡C\n");
set("limbs", ({ "ÀY³¡", "¨­Åé", "«e¸}", "«á¸}","¸¡³¡"}));
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
write("[1;36m¦Ñ¹«®ð¼«ªº»¡:§Ú­n´À§Ú°¶¤jªº¹«¤ý³ø¤³¡C[m\n");
kill_ob(this_player());
}
}
