// Npc: /u/s/suez/npc/3.c

inherit NPC;

void create()
{
 set_name("必可", ({"bi co bonze","bonze"}) );
	set("long", "他是凌雲寺裡負責盆栽與花草的僧人。\n");
	set("race", "人類");
	set("age", 25);
	set("level", 12);
   set("chat_chance",9);
   set("chat_msg",({(:command, "sweat":),
                    (:command, "smile":),
                    (:command, "say 萬物皆有生,怡然遊大荒....":),
                    (:command, "say 這些花草看來得多澆點水了...":),
}));
     set("chat_chance_combat",17);
     set("chat_msg_combat", ({
      (:command("fear"+this_player()->query("id")):),
     "必可害怕的說道:「這位施主別再為難小僧了........」\n"
     }) );



	setup();

          carry_object(__DIR__"wp/shovel.c")->wield();
}
