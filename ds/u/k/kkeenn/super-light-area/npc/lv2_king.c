inherit NPC;
#include <ansi.h>
void create()
{
          set_name("修練者",({"practice robot","robot"}) );
set("long","由超•光子公司製作而成的生化人，擁有百年高人—李書文的DNA！！\n");
        set("race","human");
set("age",60);
              set("level",30);
set("chat_chance",10);
        set("chat_msg",({
                         (:command,"reload clip":)}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("shoot"):),
                (:command("reload clip"):), 
 }) ); 
	setup();
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-gun.c")->wield();  
}

void init()
{
       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{
        if( (arg!= "up") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "將你攔了下來。\n");
      command("sigh");
           say("修練者說道："HIW"不要去送死阿！\n"NOR);  
        return 1;
} 
void die()
{
         message_vision("$N消失前說: 我好心勸你不要在前進了！",this_object());
            ::die();
}
