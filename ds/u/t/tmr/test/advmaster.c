//八極門 進階Master 
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("吳鐘",({"wu chung master","master","wu","chung"}));
        set("gender", "男性");
        set("long",@LONG
吳鐘為八極門拳術的始祖，年少時勇氣出眾，超拔出群，其武藝由一
名「癲」的道士所傳授，其大槍訣從癲的徒弟－癖，所習得，至此不分晝
夜，修習武藝，於五十歲時大成，次年創八極門，七十歲大徹大悟，退居
山林，悠遊自得。
LONG
        );
        set("level",60);
        set("age",80);
        set("adv_class",2);
        set("class1","八極門");
        set("class2","八極門");
        set("title","八極門開山祖師");
        set_temp("exert_mark/bagi-power",5000);
        set("apply/armor",30);
        set("apply/damage",30);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("fork",100);

        set_skill("da-fork",100);
        set_skill("bagi_fist",100);
        set_skill("horse-steps",100);

        set("chat_chance", 10);
        set("chat_msg",({
        }) );
                set("chat_chance_combat", 80);
                set("chat_msg_combat", ({
                         (:command("exert da-fork"):),
                         (:command("exert bagi_fist"):),
                }) );
        
        set("guild_skills",([           // 難度, 等級1可學, 上限
                "force":({300,3,100}),
                "bagi_force":({300,3,100}),
        ]) );

        set("guild_gifts",({10,7,0,3}));

        setup();
}

int accept_object(object who,object ob)
{
        if(!ob->id("quest-bagi-book") ) return 0;

        message_vision("$N給了吳鐘一本冊子。\n",who,ob);
        destruct(ob);
        if(who->query("adv_class")==2 
        && who->query("class2")=="八極門" 
        && !who->query_skill("bagi_force") )
        {
                command("say 瞧你也是本門中人，不如我傳你本門心法吧。");
                message_vision("吳鐘仔細地教了$N八極心法的口訣。\n",who);
                who->set_skill("bagi_force",5);
        }
        else 
                command("smile "+who->query("id") );
        return 1;
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_guild_join","join");
        add_action("do_advance","advance");
        add_action("do_say","say");
}

// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=(me->query_skill(argx)-1)*2;
        me->add("popularity",-cost);
        return;
}

// advance  成功後 GUILDMASTER會自動呼叫
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                return;
        }
     else {
         if( me->query("popularity") < 3 )
                 tell_object(me,"你的聲望不夠了!!\n");
         else {
              me->add("popularity",-3);
              return;
         }
        }
}

int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int j,lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(this_player()->query("class2") != "八極門")
                return notify_fail("你並不是八極門弟子。\n");
        
        if(arg=="force")
                lv=me->query_skill("force");
        if(arg=="bagi_force")
                lv=me->query_skill("bagi_force");

          if(arg=="force" || arg=="bagi_force")
        {
        if(lv < 5) //並未學到bagi_force
                return notify_fail("看來吳鐘並不想教你。\n");
        cost=lv*2;
        if(lv==100)
                return notify_fail("你已經到達登峰造極的境界了。\n");
        if( j < cost)
                return notify_fail("看來吳鐘並不想教你更深一層。\n");
        }
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        message_vision("$N想加入"+arg+"。\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("你已是其他們派的徒弟了\n");break;
               case -2: notify_fail("你已是其他們派的徒弟了\n");break;
               case -8: notify_fail("沒有這個門派吧");break;

        }
        if(me->query("class2")=="八極門")
                return notify_fail("你已是八極門的弟子了。\n");
        if(arg!="八極門" )
                return notify_fail("這裡沒有這個門派。\n");
        if( me->query("class1")=="八極門" && me->query("level")==25 
        && me->query("adv_class")==1 && me->query_temp("adv-bagi-quest")==0 )
                {
                command("say 你已是李書文的弟子，怎地還來找我這遭老頭。");
                me->set_temp("adv-bagi-quest",1);
                }
        else return notify_fail("看起來吳鐘並不想收你為徒。\n");

        return 1;
}


int do_advance(string arg)
{
          int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(me->query("class2") != "八極門")
                return notify_fail("你並不是八極門弟子。\n");
   //新修正，adv level 扣聲望 (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) 
                return notify_fail("你的聲望不夠。\n");
      if(j < 3 ) 
          return notify_fail("你的聲望不夠。\n");
        return GUILDMASTER->do_advance(ob,me,arg);
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
                        case 0: rank = "八極門之初出茅蘆"; break;
                                // LV 10 ~ 19
                        case 1: rank = "八極門之略有小名"; break;
                                // LV 20 ~ 29
                        case 2: rank = "八極門之仗義江湖"; break;
                                // LV 30 ~ 39
                        case 3: rank = "八極門之俠氣遠播"; break;
                                // LV 40 ~ 49
                        case 4: rank = "八極門之揚名天下"; break;
                                // LV 50
                        default: rank = HIC "八極門之一代宗師" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "八極門之初出閏房"; break;
                                // LV 10 ~ 19
                        case 1: rank = "八極門之略有英名"; break;
                                // LV 20 ~ 29
                        case 2: rank = "八極門之仗義四海"; break;
                                // LV 30 ~ 39
                        case 3: rank = "八極門之英氣遠播"; break;
                                // LV 40 ~ 49
                        case 4: rank = "八極門之揚名天下"; break;
                                // LV 50
                }

        }
        return rank;
}

int do_say(string arg)
{
        object me,ob;
        int i;
        me=this_player();
        ob=this_object();

        i=me->query_temp("adv-bagi-quest");
        if(arg!="癲")           return 0;
        if(i!=1)                return 0;

        message_vision("$N說道：癲\n",me);
        message_vision("$N神色之間顯得十分高興，上下地打望了你幾眼。\n",ob);
        message_vision("$N說道：「你就入我門下，讓我好好傳授你武藝，此外謹記「俠義」二字。」\n",ob);
        ob->command("pat "+me->query("id") );
        message("world:world1:vision",
        HIY "\n\t武林快報：一代宗師 吳鐘收了"+me->name(1)+HIY "為八極門第二代弟子。\n"NOR
        ,users() );

        me->command("kneel "+ob->query("id") );
        me->set("class2","八極門");
        me->create_family("八極門",2,"俠客");
        me->set("adv_class",2);
        me->delete_temp("adv-bagi-quest");

        return 1;
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
HIW"武林傳出了一則驚人的消息:"HIW"八極門開山祖師　吳鐘死在"+ob->name(1)+"手中。\n"+NOR
        ,users());
        ob->add("popularity",3);
        ::die();
        return;
}


