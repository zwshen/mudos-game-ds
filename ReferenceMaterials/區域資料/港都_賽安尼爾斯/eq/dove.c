inherit NPC;

void create()
{
        set_name("海鷗", ({ "dove" }) );
        set("race", "野獸");
        set("age", 2);
     set("level",5);

        set("long", "一隻海鷗，在海邊隨處可見。\n");
        
   set("str",1);
      set("max_hp",100);
    set("dex",-3);
     set("int",1);
       set("con",5);

        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "海鷗啄了啄地上的小石子。\n" }) );
                

        setup();
}
