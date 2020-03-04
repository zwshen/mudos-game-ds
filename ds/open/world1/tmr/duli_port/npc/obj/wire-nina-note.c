#include <ansi.h>
#include <skill.h>

inherit ITEM;

void create()
{
        set_name("紙條",({ "note" }) );
        if(!clonep() ) {
        set("long",@LONG
    這是一張不過巴掌大的紙條，但上頭似乎密密碼碼地寫有幾行字，只
是字跡隱晦，根本看不清楚。

相關指令：blooding , check。
LONG
        );
                set("value",0);
                  set("no_give",1);
                set("unit","一張");
        }
        setup();
}

void init()
{
        set("no_get",1);
       add_action("do_blood","blooding");
        add_action("do_check","check");
}

int do_check(string arg)
{
        object me;
        me = this_player();
          tell_object( me , "這上面的東西，你估計大概懂了" + me->query_temp("wire-nina-exp")*100/20000 + "%\n");
        return 1;
}
int do_blood(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="note") return 0;
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒有空做這動作。\n");
        if( me->query_stat("gin") < 50)
                return notify_fail("你的精神不濟，無法做這種事情。\n");
        if( me->query_stat("hp") < 50)
                return notify_fail("你的生命垂危，無法做這種危險的動作。\n");
        message_vision(HIR "$N一咬手指，登時冒出一縷鮮血，$N慢慢將鮮血滴在紙條上...\n" NOR ,me);
        if( me->query_skill("literate") >= 10 ) {
                /* 變-線性念力 技能經驗*/
                tell_object(me, CYN "(你看到被鮮血塗抹到的部份顯示出幾個字，你似懂非懂地讀著...)\n" NOR );
                me->add_temp("wire-nina-exp" , 1 + random(me->query_attr("int")) );
                me->improve_skill("psychical",1+random(3) );
        } else {
                // 讀不懂
                tell_object(me, CYN "(你看到被鮮血塗抹到的部份顯示出幾個字，但你完全不識字，無法讀出意思。)\n" NOR );
        }
        // 精神少10
        me->consume_stat("gin",10);
        // 生命少10
        me->consume_stat("hp",10);
        me->start_busy(1);
          if( me->query_temp("wire-nina-exp") >= 20000 ) { // 二萬
        tell_object(me , CYN "你身上的紙條由於過於潮溼，已經破爛不堪，無法再繼續使用了..\n" NOR);
                me->delete_temp( "wire-nina-exp" );
                if( me->query_learn("wire nina") 
                ||  me->query("skills_point")+3 > SKILL_MAX_POINT ) {
                        tell_object(me , CYN "你覺得什麼事都沒有發生...\n" NOR);
                } else {
                        // ok ...學到 線性變化
                        me->add("skills_point",3);
                        tell_object(me , HIG"(你的技能學習點數花掉三點。)\n" NOR);
                        me->improve_skill("wire nina",201);
                }
                destruct( this_object() );
        }
        return 1;
}

