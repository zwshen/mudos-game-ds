#include <armor.h>
#include <ansi2.h>

inherit HANDS;

void create()
{
        set_name(HIY"蜈蚣護手"NOR, ({ "scolopendra gloves", "gloves" }) );
        set("long", @long
這是黃金蜈蚣遺下的殘足。

[save eq]
long);
        set_weight(4000);
        set("unit", "雙");
        set("value", 100000);
        set("armor_prop/armor", 6);
        set("armor_prop/sou", 1);
        set("armor_type", "hands");
        set("beast_armor_prop/armor", 50);
        set("beast_armor_prop/shield", 50);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_sell", 1);
        setup();
        call_out("poisonheal", 60);
}

int wear()
{
        object me;
        int num;

        ::wear();

        me = this_player();
        num = me->query("saveeq/scolo_gloves");

        set("armor_prop/armor", 6-num);
        if( num >= 6 )
        {
                this_object()->set_durable(-1);
//                destruct(this_object());
                this_object()->delete("armor_prop");
                if( !this_object()->query_temp("used") )
                {
                  this_object()->set("name", this_object()->query("name")+NOR HIR"[已損毀]"NOR);
                  this_object()->set_temp("used",1);
                }
                write(HIW"請用destroy指令把沒用的gloves消毀。\n"NOR);
                return 1;
        } else {
        me->add("saveeq/scolo_gloves", 1);
        this_object()->add("armor_prop/armor", -1);
        }

        return 1;
}

int query_autoload() { return 1; }

void poisonheal()
{
        object me = environment(this_object());

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/hands") == this_object())
        {
                if( me->query_condition("scolopendra_poison") > 0 )
                {
                        me->apply_condition("scolopendra_poison", me->query_condition("scolopendra_poison")-1);
                        if( me->query_condition("scolopendra_poison") < 0 ) me->apply_condition("scolopendra_poison", 0);
                        tell_object(me, YEL"你感到體內的蜈蚣毒有所減緩。\n"NOR);
                }
                if( me->query("ap") < me->query("max_ap") )
                {
                        me->add("ap", 10+random(me->query("max_ap")/50));
                        if( me->query("ap") > me->query("max_ap") )
                        {
                                me->set("ap", me->query("max_ap"));
                        }
                        tell_object(me, HIM"你突然感到內勁有所恢復。\n"NOR);
                }
        }
        call_out("poisonheal", random(60));
}

void init()
{
        add_action("do_dest", "destroy");
}

int do_dest()
{
        message_vision(HIW"$N把"NOR+this_object()->name()+NOR HIW"弄成灰燼散落在地上。\n"NOR, this_player());
        this_player()->delete("saveeq/scolo_gloves");
        destruct(this_object());
        return 1;
}
