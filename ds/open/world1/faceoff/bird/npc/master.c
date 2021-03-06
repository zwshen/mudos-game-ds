#include <ansi.h>
inherit NPC;
void heal();
void create()
{
        set_name("趙長孫" , ({ "master chao","master","chao" }) );
        set("long",@long
傳出趙長孫乃是身高五尺, 滿面白鬍, 誰知今日一見卻不然, 其實趙長孫乃。
是身高四尺有餘, 且沒有白鬍, 不管如何, 總之, 趙長孫的醫術相當高明, 也
為他贏得了賽華陀的稱號。
long
);
        create_family( HIC "天梟冶藥" NOR ,17,"掌門");
        set("level",42);
        set("race","人類");
        set("age",65);
        set("nickname","白鬍華陀");
        set("adv_class",1);
        set("class1","天梟教");
        set("gender","男性");
        set("int",100);
        // 設定屬性分配表, 每一項的值在負9至正10之間
        // 而且四項的總和要剛好等於 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "dagger" : ({160,2,60}),
        ])  );
	set("guild_spells",([
	       "moxibustion" : ({160,2,60}),
	])  );
        set_skill("dagger", 90);
	set_skill("sky-dagger", 90);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set("no_check_class",1);
        set("chat_chance", 10);
        set("chat_msg",({
                (:command("think"):),
        (:command("exert sky-dagger"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert sky-dagger"):),
        }) );
        setup();
          carry_object(__DIR__"eq/steel_dagger.c")->wield();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="令旗")
        {
           command("? "+who->query("id"));
           command("say 在下並不需要這個東西。");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。");
             return 0;
          }
	message_vision("$N給了趙長孫一個"+ob->query("name")+"。\n",who);
             obj->start_busy(10);
             obj->set_temp("kill_bandit",1);
             destruct(ob);
             call_out("kill_bandit",1,obj);
             return 1;
        }

}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
}
void kill_bandit()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("kill_bandit");
      switch( i ) {
          case 1:
            command("say 咦！！這不是十萬群盜的令旗嗎！！");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此令旗的？");
            obj->set_temp("kill_bandit",i+1);
            call_out("kill_bandit",3,me);
            break;
          case 2:
            message_vision(YEL"$N將得到令旗的過程告訴趙長孫。\n"NOR,me);
            obj->set_temp("kill_bandit",i+1);
            call_out("kill_bandit",3,me);
            break;
          case 3:
	    command("nod");
            command("say 這樣啊...閣下真是行俠仗義, 令人欽佩啊。");
            command("smile");
            obj->set_temp("kill_bandit",i+1);
            call_out("kill_bandit",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 

            {
              command("say 這位" +  RANK_D->query_respect(me) + ", 請受在下一拜。");
              command("bow "+me->query("id"));
              obj->delete_temp("kill_bandit");
            }
            else {
              command("say 天梟列祖, 弟子不才, 就再為天梟加一位高徒吧!!");
              obj->set_temp("kill_bandit",i+1);
              call_out("kill_bandit",2,me);
            }
            break;
          case 5:
            command("say 入我教當行俠仗義，除強濟弱！");
            message_vision(YEL"$N跪下來說道：師父！弟子必定遵照師父的教誨！\n"NOR,me);
            message_vision(HIY"趙長孫輕輕地拍拍$N的頭，並說道：好！好！..\n"NOR,me);
	    message_vision(HIY"趙長孫說道：這是我派針灸用的銀針, 如今就給你一根吧!\n"NOR,me);
            p=new(__DIR__"obj/needle.c");
            p->move(this_player());
            command("pat "+me->query("id"));
	    command("smile");
            me->set("adv_class",1);
            me->set("class1","天梟教");
            me->create_family("天梟教",18,"教眾");
        me->set("guild_rank","天梟教第十八代教眾");
            obj->delete_temp("kill_bandit");
            break;
      }
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //暫時
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//      GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")=="天梟教") return notify_fail("你已是天梟教教眾了。\n");
     if(arg!="天梟教") 
		return notify_fail("你要拜入那一個門派?\n");
     say("趙長孫正為盜患發愁，無心收你為徒。\n");
     say("趙長孫喃喃自語的道：不知盜患何時可除....。\n");
     say("趙長孫喃喃自語的道：如果能將各旗主的令旗....。\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="天梟教") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是天梟教眾。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
CYN"\n  武林傳出了一則驚人的消息:\n\n\t救人無數的「白鬍華陀」趙長孫被"+ob->name(1)+"給做掉了。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
       tell_object(ob,HIW"(因為你殺死了趙長孫，所以得到了 1 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
            ||      is_fighting(me) )
                return;
        kill_ob(me);
        me->fight_ob(this_object());
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        if( me->query("gender") == "女性" )
        {
                switch( lv )
                {
        // LV 10 ~ 19
                        case 1: rank = "初入醫道的江湖術士"; break;
                        case 2: rank = "小有名氣的藥術師"; break;
                        case 3: rank = "懸壺濟世的天梟弟子"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 1: rank = "初入醫道的江湖術士"; break;
                        case 2: rank = "小有名氣的藥術師"; break;
                        case 3: rank = "懸壺濟世的天梟弟子"; break;
                }
        }
        return rank;
}
void heal()
{
     object obj;
     obj=this_object();
if(obj->query("hp") < obj->query("max_hp")/2)
{
      command("exert bloodsky-force heal");
}
if(obj->query("mp") < obj->query("max_mp") /2)
{
     obj->add("mp",100+random(50));
     message_vision("$N站起身來，舒展了筋骨，神情煥然一新。\n",obj);
}
}



