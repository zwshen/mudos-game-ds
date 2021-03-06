// 疾風門 - 指極心訣
// -tmr 2007/05/03

#include <ansi.h>
#define SWORD_FIELD  __DIR__"wind-obj/sword-field"
#define NAME "指極心訣"
#define SKILL_NAME "indicate-knack"

inherit SSERVER;
inherit SKILL;

int clone_field(object me, object target);

int exert(object me, object target, string arg)
{
     int sk,cost;

    sk = me->query_spell(SKILL_NAME);
    cost = 5 + sk/20;

    if( me->query("ap") < cost )
        return notify_fail("你的魔力不足，無法使用"NAME"。\n");
    if( !objectp(target) )
        return notify_fail("你想要用什麼東西佈指極劍陣？\n");

        if ( me->query_skill("star-sword") < 90
                 || me->query_skill("moon_force") < 90
                 || me->query_skill("indicate-knack") < 10
                 || me->query("level") < 40 )
        return notify_fail("你的能力不足，還無法使用指極心訣。\n");
        
    if( !target->is_weapon()
            || target->query("skill_type") != "sword"
            || target->query("equipped")
        || target->query_autoload()     // save wp 不能用
         || environment(target) != me     // 不在自已身上的，不能用
         )
        return notify_fail("這種東西無法佈指極劍陣。\n");

        if( objectp(present("_INDICATE_KNACK_FIELD_", environment(me))) ) {
        return notify_fail("這裡已經佈有一個指極劍陣了。\n");
        }

    message_vision(
        HIG "$N抽出一把$n"HIG"，捏劍訣吟道：「河行九曲龍蛇伏，地綴七星斗牛浮」\n" NOR,me, target);

    me->receive_damage("ap",cost );
    call_out("clone_field",3,me,target);
    me->start_busy(2);
    return 1;
}

void dest_field(object field) {
        if(!field) return;
        message_vision(HBK "噹啷地一聲響，$N"HBK"就像鏡子般地破碎成片片碎塊。\n"NOR, field);
        destruct(field);
}

int clone_field(object me, object target)
{
        int timeout;
          object field;
        string msg;
    if( !me ) return 0;

    field = new(SWORD_FIELD);
    if( !target 
                ||      objectp(present("_INDICATE_KNACK_FIELD_", environment(me)))
        ) {
                message_vision("但是什麼事也沒有發生。\n",me, target);
                me->improve_skill(SKILL_NAME, 2 + random(me->query_dex()/2) );
                destruct(field);
                return 1;
    }

        if( !field->move(environment(me)) ) {
                message_vision("但是什麼事也沒有發生。\n",me, target);
                me->improve_skill(SKILL_NAME, 2 + random(me->query_dex()/2) );
                destruct(field);
                return 1;
        }

        msg = HIW "$N已將$n"HIW"化成指極劍陣佔住北極星之位，穩如泰山，氣勢磅礡！\n" NOR;
    message_vision( msg,me, target);

        field->set("name", 
                sprintf(HIG"指極劍陣 "HBK"[%s(%s)所佈]"NOR, me->name(), me->query("id")) );
        field->set("power", me->query_skill(SKILL_NAME) );
        field->set("damage", target->query("weapon_prop/damage") );
        field->set("long", 
                field->query("long") + 
                HIW "此劍陣使用" + target->query("name") + "(" + target->query("id") + ")"+ HIW "所佈成，" NOR 
                + HIW "擁有" + field->query("power") + "%的" + field->query("damage") + "點攻擊力。" NOR );

      me->improve_skill(SKILL_NAME, me->query_dex() * (4+random(2)) );
    destruct(target);

        // 劍陣時效：基本 180 秒，每1點TEC可增加 180 秒。
        timeout = 180 + me->query_tec()*180;
        if(timeout < 180) timeout = 180;
        call_out( "dest_field", timeout, field);
        return 1;
}

int improve_limite(object ob)
{
        return  50 + ob->query_dex();
}


