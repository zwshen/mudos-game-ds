#include <npc.h>

void create()
{
        set_name("巨魔獸", ({ "huge monster","monster" }) );
        set("long",@long
    這是一隻長得非常高大的魔戰，你可以清楚瞧見牠全身長滿黃色
短毛，細長如柳葉而散發紅光的眼睛正瞪視著你，牠兩隻手臂長可及膝，
正伸著五大根如黑色鐵塊般尖銳的指甲，似乎隨時都可以把你撕成兩半。
你站著牠面前，大概還不及牠的腰身。
long
);
        set("title","迷霧森林");
        set_race("human");
        set("age", 200);
        set_skill("twohanded axe",80);
        set_skill("parry",100);
        set_skill("dodge",100);
        // 殺死魔獸，能得到 20點聲望
        set("bounty",([
                  "reputation": 10,  
        ]) );
        set("attitude", "aggressive");
        setup();
        set_level(30);
        carry_money("gold", 1);
        /* 基本裝備 */
        carry_object(__DIR__"obj/evilmonster-armor")->wear();
        carry_object(__DIR__"obj/python-belt")->wear();
        carry_object(__DIR__"obj/evil-axe")->wield("twohanded axe");
}
void init()
{
    ::init();
    add_action("intercept", "go");
    add_action("intercept2", "north");
}

int intercept(string arg)
{
        
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "一伸爪把你擋了下來。\n");
    return 1;
}

int intercept2()
{
        
    if( !this_player()->visible(this_object()) ) return 0;
    write( name() + "一伸爪把你擋了下來。\n");
    return 1;
}

        
