#include <ansi.h>
inherit F_MASTER;

inherit NPC;

void create() {

    set_name("邢幽風",({"shin-you-fon master","fon", "master"}));

    set("long",@LONG
邢幽風身長六尺，顏面莊重，頭髮至肩，腿部肌肉結實，眼睛散發出
耀眼的光輝，就像老鷹一樣，一看就知道此人輕功絕佳，為天梟三聖中的
大哥，與邢獨風及邢殘風是三胞胎兄弟，人稱天梟三聖。邢幽風目前是天
梟派的掌門，一手炙穴針灸之技冠絕古今。
LONG
);

    create_family( "天梟派", 8, "針灸師");
    set("attitude","peaceful");
    set("age", 50);
    set("gender","男性");
    set("level", 40+random(10));
    set("title", HIC"天梟三聖"NOR);
    set("class1","天梟派");
    set("dex", 120+random(50));
    set("ap", 50000);
    set("adv_class",1);

    set_skill("needle",100);
    set_skill("dodge",100);
    set_skill("wing-eight",100);
    set_skill("parry",100);
    set_skill("moxibustion",100);
    set_skill("acupuncture-cognition",100);
    set_skill("unarmed",100);
    set_skill("skyowl-needle",70);

    map_skill("needle","skyowl-needle");
    map_skill("parry","skyowl-needle");
    map_skill("dodge","wing-eight");
    set
        ("guild_gifts",( {
                             2,7,8,3
                         }
                       ));
    set
        ("guild_skills",([
                     "needle" : ( {
                                              140,3,80
                                          }
                                        ),
                     "skyowl-needle" : ({ 140,3,80 }),
                     "dodge" : ({ 140,3,80 }),
                     "wing-eight" : ({ 140,3,80 }),
                     "moxibustion" : ({ 140, 3, 60 }),
                     "acupuncture-cognition" : ({ 140,3, 60 }),
                     "parry" : ({ 140,3,50 }),
                     "unarmed" : ({ 140,3,50 }),
                         ]));
    set
        ("chat_chance_combat",80);
    set
        ("chat_msg_combat",
                ( {
              (:command,"say 小子！！你不要命了！！去死吧！！ ":),
                  }
                ));
    setup();
    carry_object(__DIR__"eq/dagger3")->wield();
    carry_object(__DIR__"eq/cloth2")->wear();
    carry_object(__DIR__"eq/boots2")->wear();
    carry_object(__DIR__"eq/surcoat")->wear();
}

void init() {

    ::init();
    add_action("do_skill_list","list");
    add_action("do_skill_train","train");
    add_action("do_join","join");
    add_action("do_advance","advance");
}

void die() {
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if( ob )
        message("world:world1:vision", HIW"\n
                武林傳出了一則驚人的消息:"HIC"\n\n\t天梟三聖之一的 邢幽風竟然敗給了"NOR+ob->name(1)+"。\n\n"+NOR,users());
    ob->add("popularity",2);
    tell_object(ob,HIW"(你得到了 2 點聲望。)"NOR);
    ::die();
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

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") == "天梟派") return notify_fail("你已是天梟派弟子了。\n");
        if( me->query("adv_class") ) return notify_fail("你已是其它門派的弟子了。\n");
         if(arg != "skyowl") return notify_fail("你要拜入那一個門派?\n");
           if( me->query_int() < 8) { 
                command("shake");
            command("say 我看你長的一臉呆樣，不適合走天梟派這條路。");
                        return 0;
                }
        command("say 好好好！！我瞧你天資聰穎，你就加入我們天梟派，好好研讀醫術及毒術吧。");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","天梟派");
        me->create_family("天梟派",9,"針師");
        me->set("guild_rank","天梟派第九代針師");
    me->set("guild_gifts", query("guild_gifts") );
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="天梟派") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是天梟派弟子。\n");
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
                        case 0: rank = "天梟派之新手針師"; break;
                        case 1: rank = "天梟派之認穴好手"; break;
                        case 2: rank = "天梟派之炙穴神醫"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "天梟派之新手針師"; break;
                        case 1: rank = "天梟派之認穴好手"; break;
                        case 2: rank = "天梟派之炙穴神醫"; break;
                }
        }
        return rank;
}

