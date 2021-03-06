#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( HBK "巨魔之力" NOR , ({ "troll-force symbol", "symbol", "_TROLL_FORCE_"}));
        set("long", "這是一個由巨魔骨頭及血液做成的符石，具有再生能力，能治癒傷勢。\n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "個");
                set("value", 0);
                set("no_give", 1);
                set("no_put",1);
                set("no_sell", 1);
        }
        setup();
        call_out("receive_by_stone", 60);
}

void receive_by_stone()
{
        object me = environment(this_object());
          int p_hp;

        if( !this_object() || !me ) return;
        if( interactive(me) )
        {
                p_hp = me->query("max_hp");
                  if( me->query("hp") < p_hp *8/10 )
                {
                       me->receive_heal("hp", p_hp/27);
                        message_vision( YEL "$N"YEL"上的符文隱隱發亮，$n身上的傷勢開始恢復了。\n"NOR, this_object(), me);
                        add_temp("times",1);
                          if(query_temp("times") > 2500) {
                                message_vision( HBK "$N"HBK"的符文已經失去效用了，隨即也化作一堆粉未，消失了。"NOR, this_object(), me);
                                destruct(this_object());
                        }
                }
                else
                {
                        message_vision( "$N小小的震動一下，但是沒有發生什麼事。\n", this_object());
                }
        }
        call_out("receive_by_stone", 35);
}

int query_unique() { return 1; }  // 視為 daily eq
