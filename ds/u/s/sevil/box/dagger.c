#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
    set_name(HIY"邪念匕"NOR,({"evil dagger","dagger"}));
	set("long",@LONG
    這是邪仔為了他的護衛隊，使用強大的魔力所製造出來。由於其蘊有強大的
魔力，因此可施展強力的攻擊，是一件少有的武器。
LONG
);
	set_weight(6600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "根");
		set("material","iron");
		set("no_sac",1);
        }
        set("value",4380);
        set("volume",1);
    set("backstab_bonus",100);
    init_dagger(500);
        setup();
}

void attack(object me,object victim)
{
	if(!me) return;
	if(!victim) return;
	if(me->is_busy()) return;
	if(random(11)) return; // 1/20 的機率出現特攻
	if(me->query("evil")<800)
	{
		tell_object(me,"你突然有一股很想殺人的慾望，你的人格似乎越來越邪惡了。\n");
		me->add("evil",3+random(10));
	}
	return;
}


