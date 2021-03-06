#include <ansi.h>
#include <path.h>
inherit NPC;
void flee();

void create()
{
        set_name( "顧知天", ({ "gou zhi tian","gou","tian" }) );
        set("level",15);
        set("long" ,"他就是滄縣的縣老爺了，眉宇之間散發著一股威嚴、正氣。\n");
        set("age",60);
        set("title",HIG"縣老爺"NOR);

        set("env/wimpy", 60);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
           (:command("help!"):),
           (:command("scream"):),
           (:command("say 人來啊！！快來救我啊！！"):),
         (: flee :),
         }) );
        set_skill("dodge",65);
        set_skill("parry",50);
        set_skill("unarmed",20);
        setup();

        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/hat")->wear();
        carry_object(__DIR__"eq/bangle")->wear();
        carry_object(__DIR__"item/key");
}

void init()
{
        ::init();
        add_action("do_kill","kill");
}


void do_kill(string arg)
{
        object ob,me,*obs;
        me=this_player();
        ob=this_object();

        if( !arg) return;
        if( !objectp(present(arg, environment(me)))) return;
        
        if( is_fighting(me) ) return;
        message_vision("$N說道﹕咦？造反啦？竟敢亂殺人！！去死吧 ...\n",this_object());
        obs = all_inventory(environment());
        for(int i=0;i<sizeof(ob);i++)
        {
                obs[i]->soldier_assist(this_object(), me);
        }
}

void soldier_assist(object alert, object me)
{
        if( alert==this_object()
        ||      !living(this_object())

        ||      is_fighting(me) )
                return;
        me->fight_ob(this_object());
}

void flee()
{
        object ob;
        ob=this_object();
        if (ob->is_busy() ) return;
        message_vision(HIW"你看見$N慌慌張張的逃的無影無蹤了。\n"NOR,ob);
        destruct(ob);
        return;
}

void die()
{
        int i;
           object ob,g,env,npc;
        object e,s,n,w;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->add_temp("SKYCITY/jail",i+1);

        env=environment();
       if(!objectp(npc=find_living("skycitywar") ) && env->query("Sky-City-War")==1 ) env->delete("Sky-City-War");
        if(env && env->query("Sky-City-War")!=1 )
        {
      
        message("world:world1:vision",
 HIG+"\n\t【急馬快報】" +HIW+""+ ob->name(1)+HIW"殺死了天城縣老爺！！\n\n" NOR
HIC"禁軍大元帥大喝：「反了反了！！竟然殺害朝廷命官，一群活老百姓！！」\n"NOR
HIY"\n\t 眾禁軍駐紮天城，封鎖了天城通外的四個城門！！\n" NOR
,users() );
          env->start_war(1);
             env->set("Sky-City-War",1);
        n=load_object(ACME_PAST+"area/ndoor");
        e=load_object(ACME_PAST+"area/edoor");
        w=load_object(ACME_PAST+"area/wdoor");
        s=load_object(ACME_PAST+"area/sdoor");
        n->lock_door("north");
        e->lock_door("east");
        w->lock_door("southwest");
        s->lock_door("southdown");
        }        
        ::die();
        return;
}

