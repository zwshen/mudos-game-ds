#include <armor.h>
#include <ansi2.h> 
inherit WRISTS; 
string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
        set_name(HIR"鳳凰"HIY"陽炎"NOR"臂環",({ "phoenix-sun arms","arms" }) );
        set("long","一個蘊藏有火鳳凰力量的手環•雖然不能提供完好的防備，但是\n"
                   "它的法力可說是無人能及•\n");
        set_weight(4000);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("volume",3);
           set("material","steel");
           set("unit", "個" );
           set("value",700); 
         }
        set("armor_prop/int",2);
        set("armor_prop/wit",1);
        set("armor_prop/armor", 3); 
        set("armor_prop/shield", 25);
        set("times",3);  
        setup();  
        call_out("receive_by_arms", 5);
}

void receive_by_arms()
{

        object me = environment(this_object());
        int x, i;

        if( !this_object() || !me ) return;
        if( interactive(me)
         && me->query_temp("armor/wrists") == this_object()
         && me->is_fighting()
         && this_object()->query("times") > 0 )
        {
                x = me->query("max_hp"); 
                if( me->query("hp") < (x/20) )
                {
                message_vision(HIW"忽然間，一頭全身環繞著"HIR"烈焰的鳳凰"HIW"從$N"HIW"內飛竄而出！！\n"NOR
                               HIR"牠用牠自身的力量救助了瀕臨死亡邊緣的$n………\n"NOR, this_object(), me);                tell_object(me,CYN"(你身上所有的傷口都在瞬間痊癒了•)\n"NOR);
                        for(i=0;i<sizeof(wounds);i++)
                        me->receive_curing(wounds[i], 100);
                        me->receive_heal("hp", x); 
                        me->receive_heal("mp", me->query("max_mp"));
                        me->receive_heal("ap", me->query("max_ap"));
                        this_object()->add("times",-1);
                }  
        } else if ( this_object()->query("times") < 1 ) 
        {
          message_vision
          (HIY"忽然間，一頭全身環繞著"HIR"烈焰的鳳凰"HIY"從$N"HIY"內飛竄而出，接著便消失在遠方的天空！！\n"NOR,this_object(),me);
          destruct(this_object());
        }
        call_out("receive_by_arms", 2);
}

