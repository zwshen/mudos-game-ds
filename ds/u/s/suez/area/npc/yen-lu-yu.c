//月嵐客棧的漂亮妹妹喔！
#include <ansi.h>
inherit NPC;
void create()
{
   set_name("顏如玉",({"yen-lu-yu","yen"}));
   set("long","一位身材玲瓏，臉蛋漂亮的美女正站在這裡，她似乎心中\n"
                    "有著一些苦惱，正對著窗外嘆氣。\n");

   set("level",27);
   set("title",MAG"客棧老闆"NOR);
   set("gender","女性");
   set("age",23);
   set("adv_class",1);    
   set("class1","摘星門"); 
   create_family( MAG "摘星門" NOR ,21,"代理門主");

   set("guild_skills",([  
             "dodge":({110,2,100}),  
             "dagger":({120,2,70}),   
             "unarmed":({170,2,50}),
             "parry":({110,2,70}),  
        ]) );

   set("guild_gifts",({-2,-2,7,17}));

   set("dex", 77);
   set("evil",27);

   set("chat_chance",9);
   set("chat_msg",({(:command, "unwield dagger":),
                    (:command, "sigh":),
                    (:command, "say 他....現在不知道怎麼樣了...":),
                    
}));

   set("inquiry/name", "名字嗎？如果他還記得我的名字就好了.....唉......
            顏如玉不是我的本名，但是大家都這樣叫，客倌
            就這樣稱呼小女子吧。\n ");
  set("talk_reply","客倌你真好心，可是這是小女子的私事，還是不麻煩了。");

  set("chat_chance_combat", 17);
  set("chat_msg_combat", ({
      "顏如玉哭著大喊：「你們都欺負我！！」\n",
      command("wield dagger")
     }) );

        setup();
        add_money("coin", 700);
        carry_object(__DIR__"wp/stonedragon_d.c");
        carry_object(__DIR__"eq/sky-walk_b.c")->wear();
        carry_object(__DIR__"eq/soft_dress.c")->wear();
}
void init()
{
        ::init();
        add_action("do_kill","kill");
        add_action("do_say","say");
        add_action("do_inquiry","inquiry");
        add_action("do_skill_list","check");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
}
int do_kill(string arg)
{
  object obj;
  obj=this_object();
  if(arg != "yen" && arg !="yen-lu-yu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;

     command("slap "+this_player()->query("id"));
     say(HIG"顏如玉哀怨的說道：「我被人家欺負了，他也不來救我。」\n"NOR);
     command("angry");
     command("wield dagger");
     say(HIR"顏如玉眼眶紅腫的大叫：「好！你們都欺負我，我..我跟你們拼了！！」\n"NOR);

     obj->kill_ob(this_player());
}
int do_inquiry(string arg)
{
    if(arg != "摘星門" ) return notify_fail("你要打聽(inquiry)什麼？？\n");    
    else{
	if (this_player()->query("class1")=="摘星門") 
	{
        tell_object(this_player(),"顏如玉小小聲的對你說道：「在走廊的地下有密室，只要以我教的方法按壓(push)地板就可以進去了。」\n");
        return 1;
}
    
     else{
    say("顏如玉聽到這三個字好像吃了一驚！\n");
    command("whisper "+this_player()->query("id")+" 這位客倌你想知道摘星門的事？");
    command("hmm");
    command("whisper "+this_player()->query("id")+" 摘星門在數個月前慘遭滅門....");
    command("whisper "+this_player()->query("id")+" 我們是正好下山採買，才殘存下來的摘星門弟子。");   
    command("whisper "+this_player()->query("id")+" 從此我們就在這裡一邊籌措資金一邊招募人才。");
    command("whisper "+this_player()->query("id")+" 不知閣下是否願意助我們一臂之力。");      
    command("whisper "+this_player()->query("id")+" 加入(join)我們摘星門好嗎？");
    add_action("do_guild_join","join");
    return 1;
    }
}  
}
int do_say(string arg)
{
    if(arg != "風無影" && arg !="風哥哥" )  return 0;
    else{
    say("顏如玉聽到這個名字，突然整個臉都紅了。\n");
    command("say 這位客倌....你有見到風...風...風......嗎...?");
    add_action("do_nod","nod");
    return 1;
    }
  
}    
int do_nod(string arg)
{
       if(arg == "yen" && arg =="yen-lu-yu" )  
    {
     command("smile");
     command("say 風..風..哥哥...有說....什麼嗎....?"); 
     if(this_player()->query_temp("quest/eight")== 0) return 0;  
     message_vision("( $N把風無影的話全部告訴了顏如玉。 )\n",this_player());
     command("blush");
     command("say 原來風哥哥還念著我.....總算還沒忘了摘星門.....");
     say ("顏如玉一臉幸福的模樣，低頭不知道在唸些什麼...");
     
     return 1;
    }
      
}

int accept_object(object who,object ob)
{
       int gain;
        if(ob->name()!="古老的石雕")
                return 0;

          else {

           say("顏如玉看到這東西突然臉色一變。\n");
           command("say 這，這位客倌你是從哪裡拿來這東西的？\n");
           if(this_player()->query_temp("quest/story")== 0) return 0;
           message_vision("( $N把顏輿的事一五一十的告訴了顏如玉。 )\n",this_player());
           command("sigh");
           command("say 原來是父親....風哥哥一定早就知道了....所以才阻止我報師門之仇.....");
           destruct(ob);
         gain=this_player()->query("level")*1000+5000+random(1000);
           this_player()->add("exp", gain);
           tell_object(this_player(),HIR"你得到 "+gain+" 點經驗值。\n"NOR);
           say("顏如玉說完就看著遠方的天空，眼神十分悲哀。\n");
           this_player()->delete_temp("quest/story");

        message("world:world1:vision",
      HIC"\n  武林中懸宕以久的摘星門滅門之謎終於被"+this_player()->name(1)+"解開了﹗﹗\n\n"+NOR
        ,users());
           return 1;
           }

}
void relay_emote(object ob, string verb, object me)
{
        if( !userp(ob) ) return 0;
        switch(verb) {
        case "sex":
                command("slap "+ob->query("id") );
                command("say 客倌！你太過分了！");	
                break;
        case "kiss":
                command("slap "+ob->query("id") );
                command("say 客倌！你太過分了！");	
                break;
        default:
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
        me->delete("no_check_class");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);

}
int do_advance(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
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
                        case 0: rank = HIC"摘星門打雜小妹"NOR; break;
                        case 1: rank = HIY"可愛的摘星門女弟子"NOR; break;
                        default: rank = HIM"摘星門影落天河"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"摘星門打雜小弟"NOR; break;
                        case 1: rank = HIY"風趣的摘星門男弟子"NOR; break;
                        default: rank = HIM"摘星門神幻破空"NOR;
                }
        }
        return rank;
}
int do_guild_join(string arg)
{

        object ob, me;
        int i;

        ob = this_object();
        me = this_player();
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("whisper "+me->query("id")+"  原來，閣下已經是"+me->query("class1")+"的高徒了...真是可惜。");break;
                case -2: command("say 啊！你是"+me->query("name")+"大俠！小妹有眼不視泰山，真是失禮....");break;
                case -3: command("say 這....原來閣下並非同道中人...還是別淌這灘混水吧...");break;
                case -4: command("say 嗯....閣下等級不夠....怎麼辦?");break;
                case -5: command("say 玩家的 termstr 並沒有大於 termnum 值。");break;
                case -6: command("say 玩家的 termstr 並沒有等於 termnum 值。");break;
                case -7: command("say 玩家的 termstr 並沒有小於 termnum 值。");break;
                case -8: command("whisper "+me->query("id")+" 閣下...我們這裡是「摘星門」...請別開玩笑了..");break;
                default: command("whisper "+me->query("id")+" 太好了！如果要學東西儘管問我(check)，不用客氣。");
        }
        
        return 1;
}
