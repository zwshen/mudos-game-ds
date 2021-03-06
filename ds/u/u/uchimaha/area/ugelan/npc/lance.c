inherit NPC;
#include <ansi.h>
void create()
{
        set_name("藍斯比爾", ({ "master lance bill", "master", "bill", "lance" }) );
        set("nickname", HIY"神聖使者"NOR);
        set("gender", "男性");
        set("class","knight");
        set("age", 38);
        set("adv_class",1);
        set("class1","聖騎士");
        set("guild_gifts",({7,8,0,5}));
        set("long",@LONG
蘭斯比爾看起來不高不矮，身材十分均勻，面貌祥和，你站在他的身旁就
有一種莫名的安全感。他是【索蘭尼亞禁衛軍】的大將軍，幽遮蘭城國王
的左右手，身負守護全幽遮蘭城居民的安全，因此沒有人敢對他不敬•
LONG
        );
        set("max_ap",2000);
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
        "sword":({110,4,80}),
        "blade":({110,4,80}),
        "dodge" : ({120,3,80}),
        "parry" : ({120,4,80}),
        "unarmed":({110,4,80}),
        "fork":({120,4,80}),
        "axe":({110,4,80}),
        "staff":({110,4,80}),
        ])  );
        set_skill("unarmed",100);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("fork",90);
        set_skill("sword",100);
        set_skill("blade",100);
        set_skill("axe",100);

        set_temp("apply/armor",40);
        set("no_check_class",1);
        set("chat_chance",20);
        set("chat_msg",({
          "藍斯比爾對你說到：「這位小兄弟要不要加入我們阿？」\n" ,
          "藍斯比爾對你說到：「請打﹝join 聖騎士﹞加入我們吧•」\n" ,
          (:command(":D"):),
          (:command("smile"):),
        }) );
        create_family("索蘭尼亞", 12,"禁衛軍");
        setup();
        carry_object(__DIR__"eq/holyhelmet.c")->wear();
        carry_object(__DIR__"eq/holyarmor.c")->wear();
        carry_object(__DIR__"eq/honorboots.c")->wear();
        carry_object(__DIR__"wp/lightaxe.c")->wield();
}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_swear","swear");
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
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("level") > 24 && me->query("class2")=="聖騎士" )
        return notify_fail("你不是索蘭尼亞的禁衛軍。\n");
        if(me->query("class1")=="聖騎士" )
        return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("你不是索蘭尼亞的禁衛軍。\n");
}
int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        message_vision("$N想加入「"+ arg+ "」。\n",me); 

        switch(i)
        {
        case -1: return notify_fail("你已有門派了。\n");
        case -2: return notify_fail("你已有門派了。\n");
        case -8: return notify_fail("沒有這種門派。\n");
        }
        if(me->query_temp("knight") )
                command("say 這位"+ RANK_D->query_respect(me) +"如果不肯發誓，那就證明你與我們無緣了•\n");
        else    
        {
                command("say 如果你能發誓(swear)，你會永遠信奉光明之神費斯坦但提勒斯，那你就可以加入我們了•");
                me->set_temp("knight",1);                  
        }

        return 1;
}

int do_swear(string arg)
{
        object me;
        me=this_player();

        if(!me->query_temp("knight") )return 0;

        if(arg != "我會永遠信奉光明之神費斯坦但提勒斯")
        {
                message_vision("$N大聲說著：「"+ arg +"。」\n",me);
                command("shake");
                command("say 你發這種誓我是不會相信你的•");
        }
        else
        {
                message_vision("$N對著光明之神發誓：「"+ arg +"。」\n",me);
                command("say 太好了！讓我們一起消滅這世上的邪念吧！");
                message_vision("$N加入了索蘭尼亞的聖騎士團•\n",this_player());;
                me->set("adv_class",1);
                me->set("class1","聖騎士");
                me->create_family("索蘭尼亞", 12,"禁衛軍");
                me->create_rank("光明之神的新護衛");
                me->delete_temp("knight");
        }       
        return 1;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     

        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                                
                        case 0: rank = "光明之神的新護衛"; break;
                                
                        case 1: rank = "信仰堅貞的新武士"; break;
                                
                        case 2: rank = "技巧熟練的聖武士"; break;
                                
                        case 3: rank = "僅守教條的聖戰士"; break;
                                
                        case 4: rank = "堅守正義的聖騎士"; break;
                                
                        default: rank = HIW "索蘭尼亞神之眷使" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                
                        case 0: rank = "正義天使的侍奉者"; break;
                                
                        case 1: rank = "意志堅定的女武士"; break;
                                
                        case 2: rank = "技術純熟的女戰士"; break;
                               
                        case 3: rank = "僅守教條的女戰士"; break;
                               
                        case 4: rank = "和平之神的女聖者"; break;
                               
                        default: rank = HIW "索蘭尼亞神之眷女" NOR;
                }

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
        HIG"\n幽遮蘭城的"+HIY"索蘭尼亞神聖使者藍斯比爾"+HIG"不幸死在"+ob->name(1)+"的手裡！\n\n幽遮蘭城陷入一陣悲傷的情緒！\n\n"+NOR,users());
        ob->add("popularity",2); 
        ::die();
        //destruct(this_object());
        return;
}

