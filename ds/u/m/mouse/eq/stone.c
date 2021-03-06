#include <ansi2.h>
#include <armor.h>
inherit CLOTH;

void create()
{
    set_name(HIM"不明"HIY"礦石"NOR, ({ "unknown stone", "stone" }));
    set_weight(1000);
    set("long", "以下為目前所發現的能量使用方法：\n"
                "╭────┬────────┬──────────────╮\n"
                "│"HIR"紅色殺謬"NOR"│fk <A> with <B> │讓非人為控制的生物互相攻擊。│\n"
                "│"HIM"紫色吞食"NOR"│ate <A>         │將非玩家的東西吞食。        │\n"
                "│"HIW+BLK"黑色死鐮"NOR"│hack <A>        │使用死神鐮刀瞬殺生物。      │\n"
                "│"HIW"白色治癒"NOR"│heal <A>        │快速回復目標人物的生命。    │\n"
                "╰────────────────────────────╯\n\n");
    if( clonep() ) set_default_object(__FILE__);
    else {
        set("unit", "塊");
        set("value", 0);
    }
    set("limit_lv",80);
    set("armor_prop/armor", 300);
    set("armor_prop/shield", 300);

    set("armor_prop/bar", 10);
    set("armor_prop/sou", 10);
    set("armor_prop/tec", 10);
    set("armor_prop/bio", 10);
    set("armor_prop/wit", 10);
    set("armor_prop/show_damage", 1);
    setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_fk", "fk");
    add_action("do_eat", "ate");
    add_action("do_hack", "hack");
    add_action("do_heal", "heal");
}
int do_fk(string arg)
{
    string str, npc;
    object ob, me, obj;

    me = this_player();

    seteuid(getuid());
    if( !arg || sscanf(arg, "%s with %s", str, npc) != 2 )
        return notify_fail("指令格式﹕fk <Mob> with <Mob>\n");

    if( !(ob = present(str, environment(me))) )
        return notify_fail(HIR"這裡沒有 "NOR+str+HIR" 這號人物。\n"NOR);

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(HIR"這裡沒有"NOR+npc+HIR"這號人物。\n"NOR);

    if( !ob->is_character() || !obj->is_character() )
        return notify_fail(HIY"兩個物件中有其中之一無法執行命令。\n"NOR);

    if( userp(ob) || userp(obj) )
        return notify_fail(HIY"被命令的雙方不可是玩家。\n"NOR);

    message_vision(HIR"$N發出神力讓"NOR+ob->name()+HIR"主動攻擊"NOR+obj->name()+HIR"！\n"NOR, me);
    ob->kill_ob(obj);
    obj->kill_ob(ob);
    return 1;
}

int do_eat(string arg)
{
    string target;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));
    if( !arg ) return notify_fail("指令格式 : ate <物件之名稱或檔名>\n" );

    if( sscanf(arg, "%s", target) == 1 ) target = arg;

    obj = find_object(target);
    if( !obj ) obj = present(target, me);
    if( !obj ) obj = present(target, environment(me));
    if( !obj ) obj = find_object( resolve_path(me->query("cwd"), target) );
    if( !obj ) return notify_fail("好像太餓了...沒看到這樣物品。\n");

    if( (userp(obj) && !wizardp(obj)) || obj->query("userp") > 0 )
        return notify_fail(HIB"玩家不能隨便被你給吃掉。\n"NOR);

    message_vision(HIW"$N"HIM"使出"HIY"『"HIC"吞吞工廠"HIY"』"HIM"一口當兩口的把"NOR"$n"HIM"給吃掉了。\n"NOR, me, obj);
    destruct(obj);

    RACE_D( me->query("race") )->reset_attribute( me );
    if( obj ) write("這樣東西似乎吞吞工廠也吃不掉。\n");
    else write("Ok.\n");
    return 1;
}
int do_hack(string arg)
{
    string npc;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));
    if( !arg || sscanf(arg, "%s", npc) != 1 )
        return notify_fail("指令格式 : hack <Mob Name>\n");

    if( !(obj = present(npc, environment(me))) )
        return notify_fail(" "NOR+npc+HIR" 又不在這裡，砍空氣嗎？\n"NOR);

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail(HIB"這樣東西沒生命，砍它也沒用。\n"NOR);

    if( (userp(obj) && wizardp(obj)) || obj->query("userp") > 0 )

        return notify_fail(HIB"怎麼能亂砍人的頭勒！\n"NOR);

    if( environment(me)==environment(obj) ) {
        obj->set_temp("last_damage_from", me);
        message_vision(HIR"$N"HIR"陰森的揮起"HIW+BLK"死神鐮刀"HIR"...順手就砍下了"NOR"$n"HIR"的腦袋...\n"NOR, me, obj);
        message_vision(HIR"只見"NOR"$n"HIR"的身子仍然不停抽動噴出剩餘的血液...\n"NOR, me, obj);
        obj->die();
    }
    if(obj) write("死神鐮刀居然失靈了？我的天阿！\n");
    else write("Ok.\n");
    return 1;
}
int do_heal(string arg)
{
    string npc;
    object obj, me;

    me = this_player();

    seteuid(geteuid(this_player(1)));

    // 指定人物不在就判定是使用者
    if( !arg || sscanf(arg, "%s", npc) != 1 ) npc = me->query("id");
    if( !( obj = present(npc, environment(me)) ) ) obj = me;

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail(HIG"這樣東西沒生命，就算幫他治療也不會變成生物。\n"NOR);

    if( obj == me ) {
        message_vision(HIW"$N慈祥地唸起了古老的咒語，一陣溫暖的白光快速籠罩著你自己的全身...\n"NOR, me);
        tell_object(obj,HIY"你的身體受到白光加持，已經回復到最佳狀態了。\n"NOR);
    } else {
        message_vision(HIW"$N慈祥地唸起了古老的咒語，一陣溫暖的白光快速籠罩著$n的全身...\n"NOR, me, obj);
        tell_object(obj,HIY"你的身體受到白光加持，已經回復到最佳狀態了。\n"NOR);
    }
    // 所有身體傷害解除
    obj->receive_curing("left_arm", 100);
    obj->receive_curing("left_leg", 100);
    obj->receive_curing("right_arm", 100);
    obj->receive_curing("right_leg", 100);
    obj->receive_curing("body", 100);
    obj->receive_curing("head", 100);

    // 體力回到最佳狀態
    obj->receive_heal("hp", obj->query("max_hp"));
    obj->receive_heal("ap", obj->query("max_ap"));
    obj->receive_heal("mp", obj->query("max_mp"));

    return 1;
}
