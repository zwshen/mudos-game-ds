#include <ansi.h>
inherit NPC;
void create()
{
        set_name("護院武師" , ({ "guard" }) );
        set("level",10);
        set("race","人類");
        set("gender","男性");
        set("age",25);
        set_skill("staff", 20);
        set_skill("unarmed",15);
        set_skill("parry", 10);
        set_skill("dodge", 20);
        set("long","他是保衛金莊安全的武師，看來武功\並不弱。\n");
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
                (:command("wield stick"):),
                YEL"護院武師喝道：兄弟們！把這傢伙給宰了！\n"NOR,
        }) );        
        setup();
        carry_object(__DIR__"wp/stick.c");
}
void init()
{
        ::init();
        add_action("do_kill","kill");
}
int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;

        if( is_fighting(me) ) return 0;
        command("say 說道﹕咦？造反啦？竟敢亂殺人！！去死吧 ...\n");

        ob=all_inventory(environment());
        for(i=0;i<sizeof(ob);i++)
        {
                ob[i]->soldier_assist(this_object(), me);
        }
        return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
            ||      is_fighting(me) )
                return;

          switch(random(4)) {
        case 0: command("say 說道﹕大膽刁民﹗竟敢公然逞兇﹗\n"); break;
        case 1: command("say 喝道﹕反了反了﹗兄弟們﹐拿下這個匪徒﹗\n"); break;
        case 2: command("say 喂﹗你想幹什麼﹖"); break;
        case 3: command("say 來人哪﹗拿下那個可疑的傢伙﹗"); break;
        }
         me->fight_ob(alert);
         kill_ob(me);
}
