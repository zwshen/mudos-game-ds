#include <ansi.h>
inherit NPC;
void do_jail();
void create()
{
        set_name("流無形" , ({ "invisible liu","liu" }) );
        set("long",@long
他是ξ神武教ξ的教主，是威震武林的武林天尊，但卻生得慈眉
善目的，毫無驕矜之態。你可以和他一起討論武術之事。
long
);
        create_family( HIC "ξ神武教ξ" NOR ,2,"教主");
        set("level",42);
        set("race","人類");
        set("age",65);
        set("nickname","孤獨一方");
        set("adv_class",1);
        set("class1","神武教");
        set("gender","男性");
        set("int",100);
        // 設定屬性分配表, 每一項的值在負9至正10之間
        // 而且四項的總和要剛好等於 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "sword" : ({160,2,60}),
               "godsword" : ({140,2,70}),
               "meditate" : ({160,2,20}),
               "mirage-steps" : ({150,2,50}),
        ])  );
        set("guild_spells",([
               "god-fire" : ({170,2,60}),
//               "god-benison":({170,2,50}),
               "summon_ghost" : ({170,2,50}),
        ]) );
        set_spell("god-fire",100);
        set_spell("god-benison",99);
        set_spell("summon_ghost",90);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
        set("no_check_class",1);

        set("talk_reply","哦？這倒不用，但你可以用train學習技能，用learn學習法術。");
        set("inquiry/武術","神武教的武功\可分為三類，第一是「氣」、第二是「猛」，第三則是「御」。\n");
        set("inquiry/氣","「氣」是指神武教的內功\「血蒼穹」，但以目前的你是無法習得的。\n");
        set("inquiry/猛","「猛」是指神武教的法術類的，只要你智慧高，使將起來，可是威猛無比。\n");
        set("inquiry/御","「御」是指神武教的控鬼之術，控制好的話，鬼可是無所不能的。\n");
        set("chat_chance", 10);
        set("chat_msg",({
		(:command("think"):),
        (:command("exert mirage-steps"):),
        (:command("exert godsword"):),
        (:command("cast god-fire"):),
        (:command("cast god-fire"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
//                 (:command("cast god-benison"):),
//                 (:command("cast god-benison"):),
                  (:command("cast god-fire"):),
                  (:command("cast god-fire"):),
                  (:command("cast god-fire"):),
        }) );
        setup();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="神武令牌")
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
message_vision("$N給了流無形一個"+ob->query("name")+"。\n",who);
             obj->start_busy(10);
             obj->set_temp("addsenwu",1);
             destruct(ob);
             call_out("addsenwu",1,obj);
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
        add_action("do_kill","kill");
}
void addsenwu()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("addsenwu");
      switch( i ) {
          case 1:
            command("say 咦！！這不是師父的令牌嗎！！");
            command("say 這位"+RANK_D->query_respect(me)+"是從何得此令牌的？");
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 2:
            message_vision(YEL"$N說：這是尊師托我交給您的，並說他老人家逍遙自在，您不用擔心了。\n"NOR,me);
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 3:
            command("say 原來師父安好，看來我是多擔心了。");
            command("smile");
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 
            {
              command("say 這位" +  RANK_D->query_respect(me) + "多謝幫忙。");
              command("bow "+me->query("id"));
              obj->delete_temp("giveplate");
            }
            else {
              command("say 我看你這"+ RANK_D->query_respect(me) + "蠻順眼的，這樣吧！老夫就收你為徒！");
              obj->set_temp("addsenwu",i+1);
              call_out("addsenwu",2,me);
            }
            break;
          case 5:
            command("say 入我教當行俠仗義，除強濟弱！");
            message_vision(YEL"$N跪下來說道：師父！弟子必定遵照師父的教誨！\n"NOR,me);
            message_vision(HIY"流無形輕輕地拍拍$N的頭，並說道：好！好！..\n"NOR,me);
            command("pat "+me->query("id"));
            me->set("adv_class",1);
            me->set("class1","神武教");
            me->create_family("神武教",3,"教徒");
            obj->delete_temp("addsenwu");
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

if(me->query("class1")=="神武教") return notify_fail("你已是神武教弟子了。\n");
         if(arg!="神武教") return notify_fail("你要拜入那一個門派?\n");
     say("流無形正自發愁，並沒有發現你要加入。\n");
     say("流無形喃喃自語的道：師父他老人家不知安好，已十年八戴未通消息。\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="神武教") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是神武教徒。\n");
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
CYN"\n  武林傳出了一則驚人的消息:\n\n\t武林泰斗「獨孤一方」流無形終於敗給了"+ob->name(1)+"。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
        ::die();
        //destruct(this_object());
        return;
}
int do_kill(string arg)
{
        object *ob,me;
        int i;
        me=this_player();
        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        if( is_fighting(me) ) return 0;
        command("say 說道﹕咦？敢在神武教地盤裡動粗，去死吧！！\n");
        command("cast god-fire on "+me->query("id"));
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
        kill_ob(me);
        me->fight_ob(this_object());
}
void do_jail()
{
    command("exert mirage-steps");
    command("exert godsword");
    command("cast god-fire");
   // command("hest ghost to defend liu");
}
