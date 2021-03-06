#include <ansi.h>

void do_fight_issue();        
void do_fight_heal();                   // 補血
void do_fight_help();                   // 求援

string file_path = "/open/world1/tmr/blood_field/npc/";         // 求援的npc位置
string *mob_file = ({ "fetish.c",
                      "cat.c",
                      "hulks.c",
                      "wendigo.c",
                      "fetish_wizard.c",
                      "wild_toast.c",
                   });

// 特攻
void do_fight_issue()
{
        int dmg;
        object me, target;
        me = this_object();
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;
        target = me->select_opponent();
        if( !target ) return;
                if( environment(target) != environment(me) ) return;
        if( random(100) < 50) {
                        // 連擊
                        message_vision(HIR"$N"HIR"對著$n"HIR"吼叫，瞪著紅眼跨前幾步！！\n"NOR, me, target);
                        me->attack();
                        me->attack();
                        me->attack();
                } else {
                        message_vision(HIG"$N"HIG"「喝」的一聲，張嘴吐出一道強勁的氣旋，狠狠撞上$n"HIG"的胸前要害！！\n"NOR, me, target);
                          dmg = this_object()->query_damage() - target->query_armor();
                        if(dmg<1) dmg = 10;
                        dmg = COMBAT_D->Merits_damage(me, target, dmg, "bio");
                        target->receive_damage("hp", dmg, this_object());
                }
}

void do_fight_heal()
{
        int dmg;
    object me, hurter, target;
        me = this_object();
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;

        target = me->select_opponent();
        if( !target ) return;

    // 敵人的敵人(應該是自已人)
        hurter = target->select_opponent();

    if( !hurter || !objectp(hurter) ) {        
        do_fight_issue();                     // 如果沒有找到要補血的人則自已用特功
        return;
    }

    if( hurter->query("hp") > hurter->query("max_hp")*80/100 ) {
        dmg = me->query_damage()/3 + random(me->query_damage()/3);
                if( target->query("ap") > target->query("max_ap")*3/10) {
                    message_vision(HIG"$N"HIG"放出纏根術，$n"HIG"的雙腳被地上冒出的粗大樹根緊緊纏住。\n"NOR, me, target);
                        target->receive_damage("ap",  dmg ,me);
                        target->start_busy();
                        return;
                }
                if( target->query("mp") > target->query("max_mp")*3/10) {
                    message_vision(HIM"$N"HIM"放出酸霧術，一股強烈的酸氣從$n"HIM"的表皮血管直鑽了進去...\n"NOR, me, target);
                                        target->receive_damage("mp", dmg ,me);
                                         return;
                }
        do_fight_issue();                     // 如果血量還足夠則自已用特功
        return;
    }

    message_vision(HIW"$N"HIW"施展回春術，在$n"HIW"的全身散出點點光芒...\n"NOR, me, hurter);
    hurter->receive_heal("hp", 500 );
}

void do_fight_help()
{
    int i;
    string file;
    object *mob_list,*obs;
    object me,target;

        me = this_object();
        obs = all_inventory(environment(me));
        target = me->select_opponent();
        if( !target ) return;
        
        if( !me || me->is_busy() ) return;
        if( !me->is_fighting() ) return;

        if( sizeof(obs) < target->query_bio() + 15 )  {
                do_fight_issue();
                return;
        }

    switch( random(100) ) {
        case 0..40: do_fight_issue(); return;
        case 41..60: break;
        default: return;
    }

    file = file_path + mob_file[random(sizeof(mob_file))];
    if( sizeof(mob_list = children(file)) ) {
        for(i=0; i<sizeof(mob_list); i++) {
            if( !environment(mob_list[i]) ) {
                destruct(mob_list[i]);
                continue;
            }
            if( mob_list[i]->is_busy() || mob_list[i]->is_fighting() ) continue;
            if( mob_list[i]->move(environment(me)) ) {
                message_vision(HIR"$N"HIR"發出刺耳的尖叫聲，引來$n"HIR"前來幫忙。\n"NOR, me, mob_list[i]);
                return;
            }
            do_fight_issue();               // 救援者無法移過來則自已用特功
            return;
        }
    } else do_fight_issue();                     // 找不到人來幫，自已用特功
}

