#include <ansi.h>
inherit NPC;

void create()
{
        set_name("îî¸t¨¸ÆF", ({"dark ghost","dark","ghost","dg"}) );
        set("long", "îîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîîî¡I\n");
        set("race", "§¯Å]");
        set("gender", "¤k©Ê"); 
        set("age", 2500);
        set("attitude", "friendly");
        set("level", 50);
        set("evil", -999);
        set("combat_exp",2000);
        set("env/wimpy", 25);        
        set("chat_chance", 2 );   
        set("chat_msg", ({   
        (:command("say i am a test mob of hest"):),
        (:command(""):),
        (:command(""):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("halt"):),
        (:command("halt"):),
        }) );
        setup(); 
  
}
void init()
{
        object owner;
        owner=this_object()->query("creater");
        if(!this_object()->query("no_creater"))
        {
                if(!objectp(owner) || !owner->is_character())
                {
                        message_vision("$N­Ë¦b¦a¤W, º¥º¥¤Æ¬°¤@Åy¦Ã¤ô¤F..\n",this_object());
                        destruct(this_object());
                        return;
                }
        }
        ::init();
}


