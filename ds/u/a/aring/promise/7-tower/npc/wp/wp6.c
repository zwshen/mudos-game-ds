#include <ansi.h>
#include <weapon.h>  
inherit SWORD; 
void create()
{
        set_name(NOR+MAG"陰陽"HIM"八卦傘"NOR, ({ "yin-yang eight umbrella" ,"umbrella" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",10);
                set("unit", "把"); 
                set("limit_str",60);
                set("limit_int",20);
                set("limit_dex",40);
                set("limit_con",40);
                set("limit_lv",40);
                set("armor_prop/int",3);
                set("armor_prop/wit",1);
                set("long", HIR"怪里怪氣的一把傘，上面貼滿了符咒，但此把卻是窯倪最得意的一把神兵。\n"NOR);
                set("value", 20000);
                set("wield_msg",HIR"$N拿起此把傘後，全身上下散發出一股濃濃的妖氣。\n"NOR);
                         
        }
        init_sword(70);
        setup();
}
void attack(object me,object victim)
{
        object ob;
        ob=this_object();
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(10) < 6 && !me->is_busy()) return;
        message_vision(HIW"從"NOR+MAG"陰陽"HIM"八卦傘"HIW"裡散發出一些許\的"HIY"黃光"HIW"，環繞在"NOR"$N"HIW"身上，令"NOR"$N"HIW" 恢復點元氣。\n"NOR,me,victim);
        tell_object(me,HIY "你恢復了點元氣。\n" NOR);
        me->receive_heal("hp",20);  
        victim->receive_damage("hp",20,me) ;
        return;
}

