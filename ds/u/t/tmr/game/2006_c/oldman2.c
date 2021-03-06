#include <ansi.h>

inherit NPC;

/*

        $NOR$ - 正常顏色        1 分
        $HIR$ - 亮紅色          2 分
        $HIG$ - 亮綠色          4 分
        $HIY$ - 黃色            8 分
        $HIB$ - 藍色            16 分
        $HIM$ - 粉紅色          32 分
        $HIC$ - 天青色          64 分
        $HIW$ - 白色            128 分
*/

void initName() {
        int i = random(1000);
        if(i>=990) {
                set_name(HIW "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",128);
                return;
        }
        if(i>=950) {
                set_name(HIC "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",64);
                return;
        }
        if(i>=900) {
                set_name(HIM "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",32);
                return;
        }
        if(i>=850) {
                set_name(HIB "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",16);
                return;
        }
        if(i>=800) {
                set_name(HIY "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",8);
                return;
        }
        if(i>=600) {
                set_name(HIG "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",4);
                return;
        }
        if(i>=400) {
                set_name(HIR "不知名的大白鬍老人" NOR,({"unknow oldman","oldman","man"}) );
                set("score",2);
                return;
        }
        set_name( "不知名的大白鬍老人" ,({"unknow oldman","oldman","man"}) );
        set("score",1);
        return;
}

void create()
{
        initName();
        set("long",@LONG
一個不知其姓名的老先生，看不出多大年紀，留著一大把白鬍子，滿
臉紅通通的甚是溫和，身著大紅色的大衣，樣式奇特，不是這時代的衣著
，背上負著一個大紅色的袋子，看起來鼓鼓的，不知裝了啥玩意。他發現
你正看著他，就對著你呵呵的笑著。
LONG
);
        set("age",1200);
        set("level",1);
        set("attitude", "peaceful");
        set("race","人類");
        set("gender", "男性" );
        set("chat_chance",60);
        set("chat_msg",({
        (:command("sing 叮叮噹∼叮叮噹∼鈴聲多響亮∼∼"):),
        "老人呵呵的笑了起來，似乎非常高興。\n",
        "老人喃喃自語說道：「一年難得下來一次，這附近可變的真多啊。」\n",
        (:command("say 雪花紛紛何所似？"):),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        (: random_move() :),
        }) );
        setup();
        set("max_hp",1);
        set("hp",1);
        if( random(100) == 1 )
                add_money("gold", 1 + random(10));
        else if( random(100) < 10 )
                add_money("silver", 1 + random(100));
        else
                add_money("coin", 1 + random(1000));

        if(random(10)==1) carry_object(__DIR__"eq/hat")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/cloth")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/gloves")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/boots")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/beard")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/waist")->wear();
        if(random(10)==1) carry_object(__DIR__"eq/pants")->wear();
        if(random(99999)==1) carry_object(__DIR__"eq/ring")->wear();
          if(random(99999)==1) carry_object(__DIR__"eq/ankle")->wear();

        
}



void die()
{
        object ob;
        int sc = query("score");
        if( sc < 1 ) sc = 1;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }

        tell_object(ob,"你獵殺聖誕老人獲得" + sc  +"點積分。\n");
        "/u/t/tmr/game/2006_c/board.c"->addScore(ob, sc);
        ::die();
        return;
}
