#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("寇仲" , ({ "kou-zhong master", "kou", "zhong", "master" }) );
        set("long",@long
寇仲，黃易《大唐雙龍傳》小說裡的兩位男主角之一，
個性開朗豪邁、不拘小節。與另一男主角徐子陵一開始同是
揚州的小混混，因緣際會偷到武功秘籍《長生訣》，後來又
誤打誤撞竟然練城絕世神功，創立雙龍幫。立志爭天下。胸
懷大志，對目前政權不滿，招攬人材，一步一步建自己的少
帥軍，少帥國，是戰場不敗猛將，與李世民形成南北對峙之
局。但當有一定成就之後，歸附大唐李淵及李世民一方。
long
);
        create_family( "少帥軍", 1, "大元帥");
                set("title",HIC"天刀身意"NOR);
        set("level", 70);
        set("race","ogre");
        set("age", 28);
        set("class1","少帥軍");
        set("class2","少帥軍");
        set("gender","男性");
        set("adv_class", 2);
        set("guild_gifts",({8,8,0,4}));
        set_skill("unarmed",100);
        set_skill("combat",100);
        set_skill("dodge",100);
        set_skill("blade",100);
        set_skill("wellmoon-blade",100);
        set_skill("force",100);
         set_skill("constant-virtue",50);

        set_skill("flybird-steps",100);
        set_skill("bloodwar-blade",100);
        set_skill("nine-mystery",100);
          set_skill("longevity-force", 100);
        map_skill("dodge","flybird-steps");
        map_skill("blade","wellmoon-blade");

        set("guild_skills",([
                        "force" : ({130,3, 80}),
                        "wellmoon-blade" : ({130,3, 50}),
                          "longevity-force" : ({130,3, 50}),
        ])  );
        
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil", -250);
        setup();
        set_temp("apply/bar", 3);
        set_temp("apply/bio", 3);
        set_temp("apply/armor", 300);
         set_temp("apply/armor", 150);
                carry_object(__DIR__"wp/wellmoon-blade")->wield();
}

void init()
{
    ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
         add_action("do_join","join");
        add_action("do_advance","advance");
}

void combat_ai()
{
        object target;

        /* 武器被打掉，則裝回去 */
        if( query_temp("weapon") ) 
                command("wield blade");
        target = query_enemy()[0];

            if( !target ) return;
           if( target->is_busy() || random(100) < 70 ) {
                command("exert wellmoon-blade");
        } else {
                command("exert longevity-force on " + target->query("id") );
        }
        return;
}




int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        return 1;
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") != "少帥軍") return notify_fail("這兒不是你該來的地方。\n");
        if( me->query("class2") == "少帥軍") return notify_fail("你已是少帥軍的子弟兵了。\n");
        if( me->query("adv_class") == 2 ) return notify_fail("你已是其它門派的弟子了。\n");
        if(arg != "army") return notify_fail("你要拜入那一個門派?\n");

        if( me->query("level") < 25 
                || me->query_skill("flybird-steps") < 50
                || me->query_skill("nine-mystery") < 50
                || me->query_skill("blade") < 50
                || me->query_skill("bloodwar-blade") < 50
                || me->query("gender") == "女性"
        ) {
                command("shake");
                command("say 你再多去練練吧");
        return 0;
        }

        command("say 我看你身強體壯，非常適合軍旅生涯，你就加入少帥軍，好好發揮吧。");
        command("smile "+me->query("id"));
        me->set("adv_class",2);
        me->set("class2","少帥軍");
        me->create_family("少帥軍", 2,"將軍");
        me->set("guild_rank","少帥軍之天刀身意");
        return 1;   
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();

        if( me->query("class2") != "少帥軍") return notify_fail("這裡不是你該來的地方。\n");
       //新修正，adv level 扣聲望 (lv-20)^2
        j = me->query("popularity");
        if(j < 3 ) return notify_fail("你的聲望不夠。\n");
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("你的聲望不夠。\n");

        return GUILDMASTER->do_advance(ob,me,arg);
}

// advance  成功後 GUILDMASTER會自動呼叫
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "少帥軍")
               return notify_fail("你並不是少帥軍的士兵。\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("看來寇仲並不想教你更深一層。(除非你有"+cost+"點聲望)\n");

        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}

// train skill  成功後 GUILDMASTER會自動呼叫
void train_spell_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // 將 rank 分為六個層次
        switch( lv )
        {
                case 0: rank = "少帥軍之用刀新手"; break;
                case 1: rank = "少帥軍之刀法高手"; break;
                case 2: rank = "少帥軍之血戰沙場"; break;
                case 3: rank = "少帥軍之以戰養戰"; break;
                case 4: rank = "少帥軍之遁去的一"; break;
                case 5: rank = "少帥軍之天刀身意"; break;
        }
        return rank;
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
                 HIR"\n【奧特蘭克】"HIY"已達天刀身意的少帥軍大元帥「寇仲」竟然飲恨在" +ob->name(1)+HIY"手裡了！！！\n\n"+NOR,users());
        ob->add("popularity", 6); //聲望
        tell_object(ob,HIW"(你得到了六點聲望。)"NOR);
          // 自然奇觀：磐龍險灘
         "/open/world1/tmr/dragoncity/hotel3f"->open_star();

        ::die();
        return;
}


