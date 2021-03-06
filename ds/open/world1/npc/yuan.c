#include <ansi.h>

inherit NPC;

void create()
{
        set_name("黿", ({ "yuan","yuan" }) );
        set("race","human");
        set("gender", "男性");
        set("level",33);
        set("age",35);
        set("evil",-20);
        set("attitude", "peaceful");
        set("title",HIR"聖炎佛使"NOR);
        set("long",@LONG
人如其名，整個身體就像是個球一樣，圓滾滾的，其心地亦
很慈悲，是個虔誠的佛教徒，不喜鬥爭，因此他的能力大都
是防禦性的力量。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/bs_hands")->wear();
        carry_object(__DIR__"../eq/bt_neck")->wear();
}

int special_attack(object me,object target,int hitchance)
{
	if(!me || !target) return 0;
        if(random(4)) return 0;
        if(me->query("mp")<16) return 0;
        message_vision(HIM"$N念咒恢復了一部份的體力\n"NOR,me,target);
        me->receive_heal("hp",100+random(100) );
        me->receive_damage("mp",16);
        me->add_busy(1);
        return 1;
}
