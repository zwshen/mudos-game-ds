#include <armor.h>
#include <ansi.h> 
inherit F_UNIQUE;   
inherit WAIST;

void create()
{
        set_name(HIR"血蛟軔帶"NOR,({ "blood-snake waist","waist" }) );
        set("long","這是一件「血蛟」的中段皮囊，傳聞有活血療傷的功\用，是一件不可多得的奇珍異寶。\n");

        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("material","steel");
                set("unit", "件" );
                set("value",4000); 
                set("replica_ob",__DIR__"snake-waist2");
         }
                set("armor_prop/con",2);
                set("armor_prop/str",2);
                set("armor_prop/armor", 11);  
                set("beast_armor_prop/armor", 11);  
        setup(); 
        call_out("receive_by_waist", 60);
}

void receive_by_waist()
{
        object me; 
        int effect;

        if( !this_object() ) return;

        me = environment(this_object());

        if( !me || !interactive(me) || me->query_temp("armor/waist") != this_object() ) {
                //沒有人使用中
                        call_out("receive_by_waist", 180); 
                        return ;
                }

        effect = me->query("max_hp");

        if( me->query("hp") < effect*3/4 )
        {
                me->receive_heal("hp", effect*1/15);
                message_vision("一陣溫和的"HIR"紅色光芒"NOR"從$N"NOR"眼中散發而出，$N"NOR"只覺得身上的傷口似乎癒合不少了。\n"NOR, me);
                call_out("receive_by_waist", 60);
        } else {
                message_vision(CYN"$N"CYN"隱隱發出微弱的光芒，但是並沒有發生什麼事。\n"NOR, this_object(), me);
                call_out("receive_by_waist", 90);
        }
}


