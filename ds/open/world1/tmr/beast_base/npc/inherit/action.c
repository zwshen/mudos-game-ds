#include <ansi.h>

void do_random_move(object me)
{
    string direct, *exits;
    object env;

    if( !me ) return;
    if( !objectp(me) ) return;
    if( !objectp(env=environment(me)) ) return;

    if( sizeof(exits=keys(env->query("exits"))) == 0 ) return;

    if( env->query("move_direct") ) direct = env->query("move_direct");
    else direct = exits[random(sizeof(exits))];

    me->force_me("go " + direct);

    return;
}

void do_fight_issue(object me, string type)
{
    int damage, i;
    int def;
    object enemy, target, *enemys;

    if( !me ) return;
    if( !objectp(me) ) return;
    if( !objectp(enemy=me->query_opponent()) ) return;
    if( environment(me) != environment(enemy) ) return;

    def = enemy->query_ability("defense");
    switch( type ) {
        case "heal":
            if( (me->query_stat("nina") > me->query("level")) && objectp(target=enemy->query_opponent()) ) {
              if( target->query_stat("hp") >= target->query_stat_maximum("hp")-50 ) { do_fight_issue(me, "attack"); return; }
                message_vision(GRN"$N週身散出一陣紅光，$n恢復了許多精力。\n"NOR, me, target);
                me->consume_stat("nina", 5);
                target->set_stat("hp" , target->query_stat("hp") + me->query("level")*5 + random(me->query("level")) );
            }
            break;

        case "attack":
            if( me->query_stat("nina") > me->query("level") ) {
                damage = random(me->query("level")*2) + 1;
                message_vision(HIR"$N一口咬住$n"HIR"，並舉起頭來狠狠的左右搖晃了數下，造成 " + damage + " 點撕裂傷。\n"NOR, me, enemy);
                me->consume_stat("nina", 5 );
                enemy->consume_stat("hp", damage);
                COMBAT_D->report_status(enemy);
            }
            break;

        case "heavy_attack":
            if( me->query_stat("nina") > me->query("level") ) {
                damage = me->query("level") + random(me->query("level")*2);
                message_vision(HIR"$N好似發狂一般，咬住$n"HIR"並高舉頭來瘋狂的左右搖晃了數十下，造成 " + damage + " 點撕裂傷。\n"NOR, me, enemy);
                me->consume_stat("nina", 10 );
                enemy->consume_stat("hp", damage);
                COMBAT_D->report_status(enemy);
            }
            break;

        case "multi_attack":
            enemys = me->query_enemy();
            message_vision(HIR"$N"HIR"暴吼一聲，眼睛泛紅光，張牙利爪，身影如閃電般快速移動...\n"NOR, me);
            for(i=0;i<sizeof(enemys);i++) {
                if( i > 10 ) break;
                damage = me->query("level") + random(me->query("level")) + 1;
                message_vision(HIK"$N"HIK"被撕扯下一塊血肉，看似相當痛苦，造成 " + damage + " 點撕裂傷。\n"NOR , enemys[i] );
                enemys[i]->consume_stat("hp", damage);
                COMBAT_D->report_status(enemys[i]);
            }
            me->consume_stat("nina", 15 );
            break;
    }

    return;
}


