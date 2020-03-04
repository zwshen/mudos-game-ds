#include <ansi.h>

inherit NPC;
inherit SELLMAN; 
/*
string *list = ({
        "/open/world1/promise/lovegame/six-legging.c",
        "/open/world1/promise/lovegame/six-ring.c", 
     
});
*/

void create()
{
        set_name(HIM"織女妹妹"NOR, ({"zhi-lu sister", "sister"}));
        set("gender", "女性" );
        set("age", 17);
        set("long","永遠的１７歲，要跟我買巧克力的請打list 和 buy吧，查看獎品請打elist!!\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", HIC"１７歲少女"NOR);
        set("sell_list",([
                __DIR__"dove-chocolate" : 50,
                __DIR__"gin-chocolate" : 50,
        ]) );

        set("chat_chance",10);
        set("chat_msg", ({
                (:command,"say 別害羞喔，要買巧克力請打list 和 buy喔....":),
                (:command,"smile":),
        
}));
       
setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy"); 

        add_action("list_price","elist");        }

void greeting()

{
        command("say 快來買巧克力喔∼∼∼^^");
        return;
}


int list_price()
{
        string msg;

        msg = HIC"２００４七夕情人節抽獎之獎品如下：\n"NOR+
                HIY"＝＝＝＝＝＝＝＝＝"HIM"七夕情人抽獎活動"HIY"＝＝＝＝＝＝＝＝＝＝＝＝＝\n"NOR+
                HIW"\t大獎：訂做專屬娃娃裝飾品乙個。\n"NOR+
                HIW"\t二獎：隨機SAVE EQ乙件。\n"NOR+
                HIW"\t三獎：１００００００經驗值\n"+
                HIW"\t三獎：聲望１０點\n"+
                HIW"\t五獎：古幣３０００００元\n"+
                HIW"\t安慰獎：隨機巧克力一包。\n"NOR+
                HIY"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"NOR;
        this_player()->start_more(msg);

        return 1;
}

int accept_object(object me,object ob)
{
        object price;
        int lucky;

        lucky = random(80);

        if( ob->query("id") !="bliss ticket" )
                return notify_fail("織女妹妹: 給我這個東西要幹麻.....-_-。\n");

        if( this_object()->is_busy() ) 
                return notify_fail(this_object()->query("name")+"說道:等等..在兌獎啦!\n");

        this_object()->add_temp("waiting", 1);
        if( this_object()->query_temp("waiting") >= 10 )
        {
                this_object()->start_busy(3);

                this_object()->delete_temp("waiting", 1);
        }

        call_out( (:destruct($1):), 1, ob);
            switch(lucky)  
              //switch(random(5))
                {  
                case 1:
                        new(__DIR__"no1-ticket")->move(me);
                        command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了大獎，訂做專屬娃娃乙隻，請大家幫他恭喜一下吧！");
                        return 1;
                break; 
                case 20:
                        //price = new(list[random(sizeof(list))]);
                        //price->move(me); 
                        if(random(2))
{
                        price = new(__DIR__"six-leggings");
      return 1;
}
          else{price = new(__DIR__"six-ring"); 
          return 1;}
                        price->move(me);
                        command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了二獎，得到SAVE EQ乙件，請大家幫他恭喜一下吧！");
                                                        log_file( "static/gamea",sprintf("[%s] %s(%s) get %s[%s]\n",ctime(time()),me->name(1),getuid(me),price->name(1),base_name(price))); 
                break; 
             case 25:
                        me->add("exp", 100000);
                        command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了三獎，得到100000 exp，請大家幫他恭喜一下吧！");
                break;

                case 35:
                        me->add("popularity", 10);
                        command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了四獎，獲得10點聲望，請大家幫他恭喜一下吧！");

                break;
                 case 40..50:
                        me->add("bank/past", 30000);
                        command("tchat 恭喜玩家"+me->query("name")+"("+me->query("id")+") 中了五獎，獲得古幣30000，請大家幫他恭喜一下吧！");
                break;

                case 60..69:
                        new(__DIR__"dove-chocolate")->move(me);
                        command("say 恭喜，你有一個巧克力");
                break;
                case 70..80:
                        new(__DIR__"gin-chocolate")->move(me);
                        command("say 恭喜，你有一個巧克力。");
                break;
                default:
                        command("say 真遺憾，什麼都沒抽到。");
                break; 
        }

        return 1;
}
     


