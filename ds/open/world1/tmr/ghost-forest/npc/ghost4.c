#include <ansi.h>

inherit NPC;
inherit __DIR__"ghost-forest";

void create()
{
        set_name(CYN "年鬼" NOR ,({"year ghost","ghost"}) );
        set("long",@LONG
年鬼為鬼王「無妄」座下十二眾鬼將排行第四，生性兇殘惡暴，性嗜
人肉，尤好女色。年鬼喜用七七神兵之「七七嬰杖」，一手杖法舞得虎虎
生風，生人迴避。
LONG
);
        set("age",90);
        set("race","人類");
        set("title","鬼眾");
        set("level",30);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
                (: ghost_heal,this_object() :),
        }) );

        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("staff",110);
setup();
     carry_object(__DIR__"wp/staff")->wield();
       set_living_name("ghost-forest-war-ghost");
}


void init()
{
        ::init();

        if(this_player()->query("level") > 20 && userp(this_player() ) && this_object()->visible(this_player()))
        {
        message_vision("\n$N"+NOR+"狂喝一聲，開始攻擊$n！！\n" NOR,this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
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

        ob->add("ghost_forest_war",1);
          if(ob->query("ghost_forest_war") > 2 )
        {
                tell_object(ob,HIG"你得到一點聲望。\n" NOR);
                ob->add("popularity",1); //聲望
                ob->set("ghost_forest_war",0);
        }
        ::die();
        return;
}

