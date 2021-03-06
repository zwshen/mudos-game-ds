#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIY"通倍利王"NOR,({"tonbeli king", "tonbeli", "king"}) );
    set("long","手持菜刀的綠色生物，因此又被稱呼為「菜刀怪」\n"
               "牠們是聖特拉遺跡的原住民，從出生到死亡都為了守護此地。\n"
               "眼前這位全身金光閃閃，還頭戴皇冠，應該是牠們的國王了。\n");
    set("race", "ogre");
    set("unit", "隻");
    set("title", HBK"聖特拉遺跡"NOR);
    set("age", 1000 + random(5000));
    set("level", 70);
    set("limbs", ({ "頭部", "腹部","胸口","背部", "短腿", "短手"}) );
    set("chat_chance", 30);
    set("chat_msg", ({
        (: random_move :),
    }) );
    set("max_hp", 30000 + random(20000));
    set("max_ap", 10000 + random(10000));
    set("max_mp", 10000 + random(10000));
    setup();
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
    carry_object(__DIR__"obj/meat");
}

int filter(object inv)
{
    if( inv->id("quest_ob") ) return 0;    // notebook
    if( inv->id("mail_ob") ) return 0;     // mailbox
    if( inv->id("undead_item") ) return 0; // doll
    if( inv->id("past_money") ) return 0;  // money
    return 1;
}

int special_attack(object me, object target, int hitchance)
{
    object *inv;
    object item;
    int i, j, damage;

    string *msg = ({ "頭部", "背部", "腰部", "腿部", "手腕", "腳指" });

    inv = all_inventory(target);
    if( !sizeof(inv) ) return 0;

    inv = filter_array(inv, (:filter:) );
    i = random(8)+3;

    if( !me || !target ) return 0;
    if( target->is_busy() ) return 0;
    if( random(100) < 25 ) {
        message_vision("\n$N"HBK"隨手召喚出"+chinese_number(i)+"堆垃圾往"NOR"$n"HBK"頭上砸去...\n\n"NOR, me, target);
        for(j=i;j>0;j--) {
            if( !sizeof(inv) ) {
                message_vision("但是$N召喚失敗了，什麼事都沒發生。\n\n"NOR, me);
                return 0;
            }
            // 獲得 item
            item = new( base_name(inv[random(sizeof(inv))]) );
            if( !objectp(item) ) return 0;

            damage = item->query_weight();

            if( item->query("weapon_prop") ) {
                if( item->query("weapon_prop/bio") >= 1 &&  item->query("weapon_prop/wit") >= 1 ) damage = (COMBAT_D->Merits_damage(me, target, damage/2, "bio") + COMBAT_D->Merits_damage(me, target, damage/2, "wit"));
                else if( item->query("weapon_prop/bio") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
                else if( item->query("weapon_prop/wit") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "wit");
            }
            if( item->query("armor_prop") ) {
                if( item->query("armor_prop/bio") >= 1 &&  item->query("armor_prop/wit") >= 1 ) damage = (COMBAT_D->Merits_damage(me, target, damage/2, "bio") + COMBAT_D->Merits_damage(me, target, damage/2, "wit"));
                else if( item->query("armor_prop/bio") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
                else if( item->query("armor_prop/wit") >= 1 ) damage = COMBAT_D->Merits_damage(me, target, damage, "wit");
            }
            damage -= target->query_armor()/2 + random(target->query_armor()/2);

            if( damage < 1 ) {
                message_vision("$n"HIY"以雷霆之勢向$N電射而至！卻被$N以力使力道化解了攻擊。\n"NOR, target, item);
            COMBAT_D->report_status(target);
                continue;
            }
            if( damage > 600 ) damage = 600 + random(200);
            else damage -= random(50);

            target->receive_damage("hp", damage);
            message_vision(HIR"各種垃圾數之不盡地從高空墜落，$N不慎被"NOR"$n"HIR"擊中了"+msg[random(sizeof(msg))]+"！"HIY" ("+damage+")\n"NOR, target, item);
            COMBAT_D->report_status(target);
        }
        message_vision(NOR"\n"NOR, me);
        target->start_busy(1);
        me->start_busy(2);
    }
    return 0;
}
