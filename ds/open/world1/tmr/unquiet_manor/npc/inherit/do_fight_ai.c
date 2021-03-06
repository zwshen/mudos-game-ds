#include <ansi.h>

void do_fight_issue();        
void do_fight_heal();                   // 補血
void do_fight_help();                   // 求援

string file_path = "/open/world1/tmr/unquiet_manor/npc/";         // 求援的npc位置
string *mob_file = ({ "skeleton.c",
                      "evil.c",
                      "evil2.c",
                      "demon.c",
                      "general.c",
                      "solider.c",
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
                        message_vision(HIR"$N"HIR"對著$n"HIR"吐出口穢氣，仗著氣勢欺上前來就是一陣亂打！！\n"NOR, me, target);
                        me->attack();
                        me->attack();
                        me->attack();
                } else {
                        message_vision(HIM"$N"HIM"從嘴裡吐射出數十條詭絲，轉瞬間就侵入$n"HIM"五臟六腑之內！！\n"NOR, me, target);
                        dmg = this_object()->query_damage() - target->query_shield();
                        if(dmg<1) dmg = 10;
                        dmg = COMBAT_D->Merits_damage(me, target, dmg, "wit");
                        target->receive_damage("hp", dmg, this_object());
               }
}

void do_fight_heal()
{
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
                if( target->query("ap") < target->query("max_ap")*70/100) {
                    message_vision(HIW"$N"HIW"放出暗言術，瞬間$n"HIW"身上全爬滿密密麻麻的屍蟲...\n"NOR, me, target);
                        target->receive_damage("ap", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
                if( target->query("mp") < target->query("max_mp")*70/100) {
                    message_vision(HIW"$N"HIW"放出暗影尖嘯，$n"HIW"的耳裡充塞著惱人的尖叫聲...\n"NOR, me, target);
                        target->receive_damage("mp", me->query_damage()/3 + random(me->query_damage()/3) ,me);
                        return;
                }
        do_fight_issue();                     // 如果血量還足夠則自已用特功
        return;
    }

    message_vision(HIW"$N"HIW"嘴裡唸唸有辭，瞬間$n"HIW"四周圍散出白色光芒...\n"NOR, me, hurter);
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
            if( sizeof(obs) < (target->query_bar() + 15) ) return; 

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
                message_vision(HIR"$N"HIR"對著不遠處的墳場呼救，引來$n前來幫忙。\n"NOR, me, mob_list[i]);
                return;
            }
            do_fight_issue();               // 救援者無法移過來則自已用特功
            return;
        }
    } else do_fight_issue();                     // 找不到人來幫，自已用特功
}

