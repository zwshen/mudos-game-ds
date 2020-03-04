#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�t���w��u��", ({ "dark side tower guard","guard" }) );
        set("level", 11);
        set("race","�H��");
        set("gender","�k��");
        set("age",18);
        set_skill("parry", 14);
        set_skill("unarmed", 24);
        set_skill("dodge", 15);
        set_skill("sword",22);
        set("chat_msg", ({
  (: command,"ponder" :),
  (: command,"sigh" :),
}));
        set("long","�@��믫���]�A������G���u�áC\n");
        set("chat_chance_combat",15);
        set("talk_reply","��..."+HIC+"�u�ê��u�@"+NOR+"�u���O�H�F��...\n"NOR);
        set("chat_msg_combat", ({
  (: command,"say �ܡI�I" :),
  (: command,"say �^���D���S�����E�Ԩ������O�A�������H���Z�t���w��w��I�I" :),
}));
        setup();

}
void init()
{
        object me;
        ::init();
        add_action("do_kill","kill");
        me=this_player();
        if(!this_object()->visible(this_player())) return;
        call_out("callhlvguard", 1, me);
}

void callhlvguard(object ob)
{
  object me,obj;
  me=this_player();
  obj=this_object();
  if(me->query_temp("DST/basicdie")>0)
  {
    command("say It's a good day to die�I�I");
    obj->kill_ob(me);
  }
  else {
    if(me->query_temp("DST/basicdie")>0)
    {
      command("say Interser will damn you�I�IGo hell�I�I");
      obj->kill_ob(me);
    }
  }
}
void do_kill(string arg)
{
        object ob,me,*obs;
        me=this_player();
        ob=this_object();
        if (!arg) return;
        if(!objectp(present(arg, environment(me)))) return;
        
        if( is_fighting(me) ) return;
        message_vision("$N���G���I�I�^�����O�N�P�^�P���I�I�o���h���a�I�I\n",this_object());
        obs = all_inventory(environment());
        for(int i=0;i<sizeof(ob);i++)
        {
                obs[i]->guard_assist(this_object(), me);
        }
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message_vision(
HIR"\n�t���w��u�æ��e�~�F�j�ۡGAlert�I�IDark Side Tower is under attack�I�I\n\n"NOR, users()
        );
        i=ob->query_temp("DST/basicdie");
        ob->set_temp("DST/basicdie",i+1);
        if(ob->query_temp("DST/basicdie")>2) 
        ::die();
        return;
}

void guard_assist(object alert, object me)
{
        if( alert==this_object()
        ||      !living(this_object())
        ||      is_fighting(me) )
                return;
        switch(random(4)) {
        case 0: command("say �j�����I�i�D�𤺨���...�k�v�̡I�İڡI"); break;
        case 1: command("say �ڭ̾D������F�I�I�����I�I"); break;
        case 2: command("say ���J�I�����a�I�I"); break;
        case 3: command("say �o�O�Ө������n��l�I"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}
