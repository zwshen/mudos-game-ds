inherit NPC;
void create()
{
        set_name("X",({ "xcook" }));
        set("long",
                "他是一位辛苦做菜的廚師，不曉得為何叫X，看來他好像不是一般的廚師\n"
                "看他炒的菜色香味俱全就知道了。\n"
        ); 
        set("title","廚師");
        set("gender", "男性");
        set("race", "人類");        set("age",40);
        set("level",20);
        set_skill("hammer",30);  
        set("chat_chance",4);
        set("chat_msg",({
  "你聽見廚師吵菜的吵雜聲。\n",
  "廚師正努力的炒著菜。\n", 
}) );        setup();
        carry_object(__DIR__"wp/flap_pot.c")->wield();
}

