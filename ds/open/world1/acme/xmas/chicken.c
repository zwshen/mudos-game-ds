#include <ansi.h>
inherit NPC;
mapping exit=([ ]);
void create()
{
        set_name(HIR"火雞"NOR, ({ "fire chicken","chicken"}) );
        set("long","一隻長的十分強壯的大火雞，身上的毛相當稀鬆。\n");
        set("title",HIC"聖誕快樂"NOR);
        set("level",3);
        set("race","野獸");
        set("age",2);
        set("Merry_Xmas",1);
        set("chat_chance", 6);
        set("chat_msg", ({
                "火雞朝著藍藍的天空叫道：「咕∼咕∼咕∼∼」\n", }) 
        );
        setup();
             set_living_name("Merry_Xmas_chicken");
}
void init()
{
	object me,obj;
	::init();
	me=this_player();
        if(objectp(obj=present("net",me) ) )
	{
          call_out("flee",2);
	}
}
int flee()
{
        int i;
        object me,obj,env;
        string to_dir,to_dir_name,*dir,*dir_name;
        obj=this_object();
        me=this_player();

        env = environment(me);
        exit = env->query("exits");
        dir_name = keys(exit);
        dir = values(exit);

        i = random(sizeof(dir));
        to_dir = dir[i];
        to_dir_name = dir_name[i];

        obj->move(to_dir);
        message_vision("$n查覺$N身上有個竹網，發出「咕咕咕∼∼」的叫聲。\n",me,obj);
        write( obj->query("name")+"振趐往"+to_dir_name+"跑過去了。\n");
        return 1;
}
