inherit NPC;
#include <ansi.h>
void create()
{
           set_name("數位機器人",({"0101010 robot","robot"}) );
set("long","上面掛著一怪牌子寫著『本公司從揍敵客家族企業所購之殺手！』\n");
        set("race","human");
   set("age",0);
               set("level",45);
              set_skill("doubleshoot",100);
set("chat_chance",10);
        set("chat_msg",({
                         (:command,"reload clip":)}));
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (:command("exert doubleshoot"):),
                (:command("reload clip"):), 
 }) ); 
	setup();
carry_object(__DIR__"obj/light-clip.c");
carry_object(__DIR__"obj/light-clip.c");
       carry_object(__DIR__"obj/g_plate.c");
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
   command("no");
            say("數位機器人說："HIY"我的任務就是消滅冒險者！\n"NOR);
        return 1;
} 
void die()
{
         message_vision("$N死前說：對...不...起..., 主人，我..沒...法...完成..你的...任務...",this_object());
            ::die();
}
