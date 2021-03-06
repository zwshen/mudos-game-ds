inherit NPC;
#include <ansi.h>
void create()
{
        set_name("趙長孫", ({ "chiao", "master"}) );
        set("nickname", "賽華陀");
        set("gender", "男性");
        set("class","healer");
        set("age", 60);
        set("adv_class",1);
        set("class1","天梟教");

        set("guild_gifts",({10,7,0,3}));
        set("long",
"傳出趙長孫乃是身高五尺, 滿面白鬍, 誰知今日一見卻不然, 其實趙長孫乃。\n"
"是身高四尺有餘, 且沒有白鬍, 不管如何, 總之, 趙長孫的醫術相當高明, 也\n"
"為他贏得了賽華陀的稱號。\n"

        );
        set("attitude", "peaceful");
        set("level",41);
        set("guild_skills",([
                "dagger":({160,2,50}),
                "dodge" : ({130,2,50}),
                "parry" : ({130,2,50}),
        ])  );
        set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
	set_skill("sky-dagger", 80);
        set_temp("apply/armor",38);
        set("no_check_class",1);
        set("chat_chance",20);
        set("chat_msg",({
          "趙長孫幽幽說道：「不知十萬大山的盜患何時可除?....」\n" ,
                (:command("sigh"):),
          	(:command("think"):),
         }) );

                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("exert sky-dagger"):),
         }) );
        
        create_family("天梟冶藥", 6, "掌門人");
        setup();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/steel_dagger")->wield();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_speak","speak");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        message_vision("$N想加入「"+ arg + "」。\n",me); 

        switch(i)
        {
        case -1: return notify_fail("你已有門派了耶。....^_^\n");
        case -2: return notify_fail("你已有門派了耶。....^_^\n");
        case -8: return notify_fail("沒有這種門派耶....:P\n");
       }
        if(me->query_temp("eight_speak") )
                command("say 這位"+ RANK_D->query_respect(me) +"如不知那句話，就是在此跪了三天三夜，我也是不會收的。\n");
        else    
        {
                command("say 不敢當，如你能說出(speak)本門被江湖所盛傳的一句話，我就收了你吧");
                me->set_temp("eight_speak",1);                  
        }

        return 1;
}

int do_speak(string arg)
{
        object me;
        me=this_player();

        if(!me->query_temp("eight_speak") )return 0;

        if(arg != "劈掛參八極，英雄歎莫及")
        {
                message_vision("$N大聲說出：「"+ arg +"。」\n",me);
                command("shake");
              command("say 不是不是，再想想吧。");
        }
        else
        {
                message_vision("$N大聲說出：「"+ arg +"。」\n",me);
                command("say 好，就是這句話，我就收你入「天梟教」門下吧！。");
                me->set("adv_class",1);
                me->set("class1","天梟教");
                me->create_family("天梟教",7,"門徒");
                me->delete_temp("eight_speak");
        }       
        return 1;

}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("class1")=="天梟教" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("你不是天梟教的門徒。\n");
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
HIC"\n  武林傳出了一則驚人的消息:"HIW"\n\n\t救人無數的「賽華陀」趙長孫被"+ob->name(1)+"做掉了!。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
        ::die();
        //destruct(this_object());
        return;
}
string guild_rank(object me)
{
       string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // 將 rank 分為六個層次

        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "天梟實習藥師"; break;
                                // LV 10 ~ 19
                        case 1: rank = "天梟資淺藥師"; break;
                                // LV 20 ~ 29
                        case 2: rank = "天梟低階藥師"; break;
                                // LV 30 ~ 39
                        case 3: rank = "天梟冶藥師"; break;
                                // LV 40 ~ 49
                        case 4: rank = "天梟大冶藥師"; break;
                                // LV 50
                        default: rank = HIC "天梟冶藥長老" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "天梟實習妍藥"; break;
                                // LV 10 ~ 19
                        case 1: rank = "天梟資淺妍藥"; break;
                                // LV 20 ~ 29
                        case 2: rank = "天梟低階妍藥"; break;
                                // LV 30 ~ 39
                        case 3: rank = "天梟高等妍藥"; break;
                                // LV 40 ~ 49
                        case 4: rank = "天梟大研藥師"; break;
                                // LV 50
                        default: rank = HIC "天梟冶藥長老" NOR;
                }

        }
        return rank;
}

