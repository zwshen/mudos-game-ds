inherit NPC;

void create()
{
        set_name("兵蟻", ({"army ant","army","ant"}) );
        set("long",@LONG
強壯的顎齒，碩大的身軀，眼前是一隻巨大的兵蟻。
LONG);
        set("unit","隻");
        set("race", "beast");
        set("limbs", ({ "頭部", "身體", "觸角"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 1);
        set("level",34);
        set_temp("apply/hit",10);      
        set_temp("apply/dodge",-30);    
        set("str",60);
        set("dex",40);
        set("chat_chance",5);
        set("chat_msg",({
                "兵蟻不停地摩擦牠的顎齒。\n",
    (: random_move :),
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
    if(!arg) return notify_fail("你要去哪裡？\n");
        write( name() + "發現你的動向，把你擋住了。\n");
        command("eh");
        return 1;
}
