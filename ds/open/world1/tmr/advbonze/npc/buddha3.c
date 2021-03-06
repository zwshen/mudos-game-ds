// 四金剛羅漢之一

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("大力金剛" ,({"da li jingang","da","li","jingang"}) );
        set("long",@LONG
大力金剛
LONG
);
        set("age",200);
        set("race","人類");
        set("title","護法尊者");
        set("level",40);
        set("attitude", "aggressive");
        set("gender", "男性" );
        set_skill("parry",100);
          set_skill("jingang-finger",100);
        map_skill("unarmed","jingang-finger");

        set_skill("dodge",100);
        set_skill("unarmed",100);
          set_skill("sword",100);
        set_skill("staff",100);
            set("str",90);
        setup();
        set_living_name("buddha-war-jingang");
                set("combat_exp",500000);
                carry_object(__DIR__"eq/armor")->wear();
                carry_object(__DIR__"eq/cloth")->wear();
                carry_object(__DIR__"eq/helmet")->wear();
                carry_object(__DIR__"eq/boots")->wear();
                carry_object(__DIR__"eq/hands")->wear();
                  carry_object(__DIR__"wp/sword")->wield();

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
 
        tell_object(ob,HIG"\t你得到一點聲望。\n"NOR);
        ob->add("popularity",1); //聲望

        ::die();
        return;
}
