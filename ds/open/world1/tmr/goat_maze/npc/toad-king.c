#include <ansi.h>
inherit NPC;


mapping *combat_action = ({
        ([      "action":       "$N張大嘴巴朝著$n的$l一陣猛咬",
                "attact_type":  "bar", 
                "damage_type":  "咬傷",
        ]),
        ([      "action": "$N突然往$n的方向撞了過去",
                "attact_type":  "bar",
                "damage_type":  "瘀傷",
        ]),
        ([      "action": "$N一張嘴伸出條堅硬如鐵的舌頭，攻向$n的$l",
                "attact_type":  "bar",
                "damage_type":  "撞傷",
        ]),
        ([      "action": "$N對著$n的$l吐出一沱又黑又臭的劇毒口水",
                "attact_type":  "wit",
                "damage_type":  "內傷",
        ]),
});

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void create()
{
  set_name( HIR "蟾蜍王" NOR, ({"toad king", "toad", "king" }) );
  set("long",@LONG
這是一隻蟾蜍王，俗稱「癩蛤蟆」，大部分蟾蜍耳後有毒腺，分泌毒性分
泌物。這隻蟾蜍王重達三百公斤，大概要好幾個人才能圍的住他，牠渾身
佈滿鮮艷的紅色條紋，看起來是不好惹的怪物。
LONG
);
        set("age", 200 + random(50) );
        set("title", "贛林樹洞");
        set("limbs", ({
                "頭部", "頸部", "胸口", "背後","腰間","腹部","前腿","後腿","尾巴",
        }) );

        set("gender", "雄性" );
        set("race","beast");
        set("level", 50);
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        if( random(100) < 90 )
                carry_object(__DIR__"obj/toad-leggings")->wear();
        else
                carry_object(__DIR__"obj/toad-leggings2")->wear();
           carry_object(__DIR__"obj/toad-wart");
           carry_object(__DIR__"obj/pan_eye");
        set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
}

int special_attack(object me, object target, int hitchance)
{
  int dmg;
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if( random(9) ) return 0;

    dmg = query_damage()/2 + random(query_damage());
    dmg = COMBAT_D->Merits_damage(me, target, dmg, "wit");
    if(dmg < 1 ) dmg = 100 + random(50);
    message_vision( "$N背上毒腺「涮」地噴出一道奇毒無比的"HIR"紅色汁液"NOR"，直接打到$n臉上("+dmg+")！\n"NOR, me, target);
    target->receive_damage("hp", dmg, me );
    target->apply_condition("poison", 3 + random(5) );
    target->add_busy(1);
    return 1;
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
    message("world:world1:vision",
                HIR"\n\t為害贛林老木的百年毒物「蟾蜍王」終於被"+ob->name(1)+HIR"殺死了！！\n\n"+NOR
            ,users());
      ob->add("popularity", 3);   //聲望
        tell_object(ob, "你獲得3點聲望。\n");
    ::die();
    return;
}

