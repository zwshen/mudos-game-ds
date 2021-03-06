// 神武教進階師父        1999.10.17      by Acme
#include <ansi.h>
inherit NPC;
void heal();
void quick_cast_fire();
void create()
{
        set_name("蕭日山",({"sau zi san master","master","sau","san"}));
        set("gender", "男性");
        set("long",@LONG
他就是神武教教主的師兄「在水一方」蕭日山，他長得濃眉大眼
，長髮披肩，一身穿著天師道袍，顯得十分威嚴，他正在精研著
威力更為強勁的法術，只見他坐在石椅上，閉目唸著咒語。
LONG
        );
        set("level",60);
        set("race","celestial");
        set("age",65);
        set("adv_class",2);
        set("class1","神武教");
        set("class2","神武教");
        set("title","神武教掌教師兄");
        set("nickname","在水一方");
        set("addition_damage",60);
        set("addition_armor",140);
        set_temp("killbandit",1);
        set_spell("god-fire",100);
        set_spell("god-benison",100);
        set_skill("bloodsky-force", 100);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
         set_skill("constant-virtue",50);
        set("chat_chance", 1);
        set("chat_msg",({
                (:command("hmm"):),
        }) );
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                  (:command("cast god-fire"):),
                         (:quick_cast_fire:), 
                          (:quick_cast_fire:), 
        }) );
// ========================================================================
//      工會導師可以教授的法術列表
// ========================================================================
        set("guild_skills",([ 
            "force":({130,2,80}),
            "bloodsky-force":({140,2,90}),
        ]) );

// ========================================================================
//      工會導師可以教授的法術列表
// ========================================================================
        set("guild_spells",([ 
            "summon_ghost":({110,4,100}),
            "god-shield":({110,2,100}),
            "god-kill" : ({110,3,80}),
            "god-benison" : ({110,3,80}),
        ]) );

// ========================================================================
//      導師的屬性分配表(權數) 請 more /doc/wiz/屬性與素質.txt
//      設定屬性分配表, 每一項的值在負9至正10之間
//      而且四項的總和要剛好等於 20
//      ********************* 必須要和初級職業一樣 **********************
// ========================================================================
        set("guild_gifts",({2,4,9,5}));

        setup();
          carry_object(__DIR__"eq/zhu-rong_mask")->wear();
          carry_object(__DIR__"wp/sunsword")->wield();
        carry_object(__DIR__"eq/godneck.c")->wear();
        carry_object(__DIR__"eq/godarmor.c")->wear();
        carry_object(__DIR__"eq/godboots.c")->wear();
        carry_object(__DIR__"eq/godcloth.c")->wear();
        carry_object(__DIR__"eq/godhands.c")->wear();
        carry_object(__DIR__"eq/godhead.c")->wear();
        carry_object(__DIR__"eq/godlegging.c")->wear();
//        carry_object(__DIR__"eq/godmask.c")->wear();
        carry_object(__DIR__"eq/godpants.c")->wear();
        carry_object(__DIR__"eq/godring.c")->wear();
        carry_object(__DIR__"eq/godsurcoat.c")->wear();
        carry_object(__DIR__"eq/godwaist.c")->wear();
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_mp.c");
        carry_object(__DIR__"obj/pill_mp.c");
        carry_object(__DIR__"obj/pill_ap.c");

        add_money("coin",1000);
        map_skill("sword", "godsword");
        map_skill("dodge", "mirage-steps");
}

/* 超快速發火  -Tmr */
void quick_cast_fire()
{
        object me=this_object();
        object* target;
        int i;
        int SK=120,INN=150; // god-fire 等級 和 悟性(int)值
        if(me->is_busy() ) return;
        target=query_enemy();
        message_vision(
        HIG "$N低頭快速地唸了遍「神祝禱-火神篇」，霎時整個高台四週布起了一道火牆！！\n" NOR
	+ HIR "\n四周的火焰迅速而機動地聚成了一個似神似妖的形體，盤遊在$N頭上\n" NOR,
        me);



	for(i=0;i<sizeof(target);i++)
		SPELL_D("god-fire")->cast_fire(target[i],me,SK,INN);
        message_vision(
        HIG "$N全身一陣乏力，身上的火神也消失了。\n" NOR,me);
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
			message_vision(HIY "\n$N左手一引，帶著數道火勁消去了攻勢。\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}


void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
        if(this_player()->query_temp("canadd_senwu")==1) call_out("senwuquest",1);
}
// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
   me->add("popularity",-2);
   return;
}
// train spell  成功後 GUILDMASTER會自動呼叫
void train_spell_cost(object me,string argx)
{
  me->add("popularity",-2);
  return;
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

        return;
}

}

int do_spell_train(string arg)
{
        object me;
        me=this_player();
        if(this_player()->query("class2") != "神武教") 
           return notify_fail("你並沒有入神武進階門派哦。\n");
        if( this_player()->query("popularity") < 2 ) 
           return notify_fail("你的聲望不夠，看來蕭日山並不想教你。");
        GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
        return 1;
}

int do_skill_list(string arg)
{
        if(this_player()->query("class2") != "神武教") 
           return notify_fail("你並沒有入神武進階門派哦。\n");
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // 避免列出檢查職業的訊息
        write("\n");
        GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
        this_player()->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(this_player()->query("class2") != "神武教") return notify_fail("你並沒有入神武進階門派哦。\n");
        if( this_player()->query("popularity") < 2 ) return notify_fail("你的聲望不夠，看來蕭日山並不想教你。");
        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

// ========================================================================
// join 加入職業, 必須要使用 do_guild_join(),
// 如果巫師要使用自己的回應方式, 請用 do_guild_join_with_no_message()
// 傳回數值, 再使用這些數值作您想做的回應方式.
// ========================================================================
        //if(me->query("race") != "human" ) return 0;
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
               case -1: notify_fail("你已是其他們派的徒弟了\n");break;
               case -2: notify_fail("你已是其他們派的徒弟了\n");break;
                case -8: notify_fail("沒有這個門派吧");break;

        }

if(me->query_temp("canadd_senwu") > 1 && me->query("class1")=="神武教" && me->query("level")==25)
         {       
            command("say 很好！很好！你是我師弟的徒弟，算來也是我的徒姪兒。");
            command("say 以後有什麼武術不懂的，就來找我，我給你指點指點。");
            command("pat " + me->query("id") );
message("world:world1:vision",HIY "\n\t《武林快報》：一代宗師 蕭日山收了"+me->name(1)+HIY "為神武教弟子。\n"NOR,users() );
            me->set("class2","神武教");
            me->create_family("神武教",3,"教徒");
            me->set("adv_class",2);
            me->delete_temp("canadd_senwu");
          }
          else    
          {
            command("say 這位"+ RANK_D->query_respect(me) +"我並不想收你為徒。\n");
          }
        return 1;
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(me->query("class2") != "神武教") 
            return notify_fail("你並沒有入進階神武教。\n");


        if(me->query("popularity") < 3 ) 
            return notify_fail("你的聲望不夠，無法再升上去哦。\n");
        //新修正，adv level 扣聲望 (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("你的聲望不夠。\n");
        else return GUILDMASTER->do_advance(ob,me,arg);

}

// ========================================================================
// 使用 advance 升級時會參考到 guild_rank() 這個函數, 這個函數可以改變
// 玩家的職業rank.
// ========================================================================
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
                                // LV 1 ~ 9
                        case 0: rank = "神武教第三代教徒"; break;
                                // LV 10 ~ 19
                        case 1: rank = "神武教第三代教徒"; break;
                                // LV 20 ~ 29
                        case 2: rank = "神武教之烈焰破空"; break;
                                // LV 30 ~ 39
                        case 3: rank = "神武教之火劍雙絕"; break;
                                // LV 40 ~ 49
                        case 4: rank = "神武教火雲女劍俠"; break;
                                // LV 50
                        default: rank = HIR"神武教之毀天滅地"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "神武教第三代教徒"; break;
                        case 1: rank = "神武教第三代教徒"; break;
                        case 2: rank = "神武教之烈焰破空"; break;
                        case 3: rank = "神武教之火劍雙絕"; break;
                        case 4: rank = "神武教之火雲劍俠"; break;
                        default: rank = HIR"神武教之毀天滅地"NOR;
                }
        }
        return rank;
}
int accept_object(object who,object ob)
{
        object me,obj,newmob;
        me=this_player();
        obj=this_object();
        newmob=new(__DIR__"advmaster");
        if(ob->name()!="紙條") return notify_fail("蕭日山告訴你：我不需要這種東西。\n");
        else {
        message_vision("$N給了$n一個"+ob->name()+"。\n",me,obj);
          say("蕭日山仔細的看了看這張紙，突然驚恐的大叫。\n");
          say("你只見蕭日山慌慌張張的離開了。\n"); 
        newmob->move("/open/world1/acme/area/f5");
        me->set_temp("canadd_senwu",1);
        destruct(ob);
        destruct(obj);
        return 1;
        }
}
void senwuquest()
{
      destruct(this_object());
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
message("world:world1:vision",HIW"\n  武林傳出了一則驚人的消息:"HIW"\n\n\t神武教掌教師兄　蕭日山死在"+ob->name(1)+"手中。\n\n"+NOR,users());
        ob->add("popularity",3); //聲望
        tell_object(ob,HIW"(因為你殺死了蕭日山，所以得到了 3 點聲望。)"NOR);
    "/open/world1/acme/area/senwu4.c"->open_skypool();
        ::die();
        return;
}
void heal()
{
     object obj;
     obj=this_object();
     if( obj->query("hp") < obj->query("max_hp")/4 )
     {
         command("exert bloodsky-force heal");
     }
     if(obj->query("mp") < obj->query("max_mp")/2 )
     {
         obj->receive_heal("mp",100+random(50));
         message_vision("$N站起身來，舒展了筋骨，神情煥然一新。\n",obj);
     }
}
