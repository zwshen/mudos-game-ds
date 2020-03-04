inherit NPC;

void create()
{
        set_name("[0;1;37mÅ[1mÜ[1mº[1mØ[1m¥[1mÕ[1mÃ[1mÆ[0m", ({"radiated ant","radiated","ant"}) );
        set("long",@LONG
²´«e¬O¤@°¦¥¨¤jµL¤ñªº¥ÕÃÆ¡A§A¤£¸TÃhºÃ¨e¬O¤£¬O¦³¨ü¨ì¿ç®g½uªº¦Ã¬V¡C
LONG);
        set("unit","°¦");
        set("race", "beast");
        set("limbs", ({ "ÀY³¡", "¨­Åé", "Ä²¨¤","ÃE¾¦"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 10);
        set("level",50);
        set_temp("apply/hit",30);      
        set_temp("apply/dodge",-20);    
        set("str",90);
        set("dex",80);
        set("chat_chance",20);
        set("chat_msg",({
           (: command("walk") :),
        }));
        setup();
}
void init()
{
      ::init();
        add_action("do_guard", "go");
        add_action("do_guard", "sneak");
}
int do_guard(string arg)
{

    object me;
    me=this_player();
    if(!this_player()->visible(this_object()) ) return 0;
    if(!userp(me)) return 0;
    if(!arg) return notify_fail("§A­n¥h­þ¸Ì¡H\n");
        write( name() + "µo²{§Aªº°Ê¦V¡A§â§A¾×¦í¤F¡C\n");
        command("eh");
        return 1;
}
