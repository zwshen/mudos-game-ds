#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIC"冰心"HIW"鏡"NOR, ({ "ice mirror", "mirror" }));
    set_weight(1);
    set("long", "發出寒氣的大鏡子，可以反應自身的狀態。\n"
                "也能鑑定(ident)其他物品的狀態。\n");
    set("unit", "面");
    set("value", 0);
    setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_say", "say");
    add_action("do_ident", "ident");
}
int do_say(string arg)
{
    object me;

    me = this_player();
    me->set("dssystem/prompt/form","【"HIY"%L/"NOR", "HIR"HP"NOR":"HIC"%h"NOR"/"HIC"%H"NOR", "HIM"MP"NOR":"HIG"%m"NOR"/"HIG"%M"NOR", "HIW+BLK"SP"NOR":"HIW"%a"NOR"/"HIW"%A"NOR"】\n");
}

int do_ident(string arg)
{
    object ob, me;
    string target;
    mapping apply;

    me = this_player();

    if( me->is_busy() ) return notify_fail("動作還沒完成，不能鑑定。\n");

    if( !arg ) return notify_fail("你要鑑定什麼東西?\n");
    if( sscanf(arg, "%s", target) == 1 ) target = arg;

    ob = find_object(target);
    if( !ob ) ob = present(target, me);
    if( !ob ) ob = present(target, environment(me));
    if( !ob ) return notify_fail("這裡沒有你要鑑定的東西。\n");
    if( ob->id("past_money") ) return notify_fail("就已經是錢了還要鑑定什麼東東。\n");
    if( ob->is_character() || ob->is_corpse() ) return notify_fail("只能鑑定物品類的東西。\n");

    printf("\n鑑定名稱：%s、重量：%d\n物價：%d\n", ob->query("name"), ob->query_weight(), ob->query("value"));
    switch( ob->query_autoload() ) {
        case 0: printf("物品保存："HIR"否\n"NOR); break;
        case 1: printf("物品保存："HIY"可\n"NOR); break;
    }
    if( ob->query("heal") ) {
        string prop;
        mixed value;
        printf("類別：藥品\n"NOR);

        apply = ob->query("heal");
        write("特性：");
        foreach(prop, value in apply) {
            if( prop == "show_damage" ) continue;
            printf("%s+%O ", prop, value);
        }
        printf("\n\n");
    } else if( ob->query("skill_type") ) {
        string prop;
        mixed value;
        printf("武器威力：%d、武器類別：%s\n等級限制：%d\n"NOR, ob->query("weapon_prop/damage"), to_chinese(ob->query("skill_type")), ob->query("limit_level"));
        apply = ob->query("weapon_prop");
        write("特性：");
        foreach(prop, value in apply) {
            if( prop == "damage" ) continue;
            if( value == 0 ) continue;
            if( prop == "show_damage" ) continue;
            printf("%s:%O ", prop, value);
        }
        printf("\n\n");
    } else if( ob->query("armor_type") ) {
        string prop;
        mixed value;
        printf("防禦能力：%d、防具類別：%s\n等級限制：%d\n"NOR, ob->query("armor_prop/armor"), to_chinese(ob->query("armor_type")), ob->query("limit_lv"));
        apply = ob->query("armor_prop");
        write("特性：");
        foreach(prop, value in apply) {
            if( prop == "armor" ) continue;
            if( prop == "show_damage" ) continue;
            if( value == 0 ) continue;
            printf("%s:%O ", prop, value);
        }
        printf("\n\n");
    } else {
        printf("其他資訊暫時無法鑑定。\n\n"NOR);
    }
    if( !wizardp(me)) me->start_busy(3);
    return 1;
}
