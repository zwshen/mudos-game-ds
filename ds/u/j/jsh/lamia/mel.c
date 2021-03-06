#include <ansi2.h>

#define PCLAW __DIR__"claw.c"

inherit NPC;
inherit F_UNIQUE;

mapping *combat_action = ({
        ([
                "action" :      "$N用身體猛烈的撞向$n的$l過去",
                "attack_type" : "bar",
                "damage_type" : "撞傷",
        ]),
});

mapping areas= ([
        "/open/world1/acme/bonze/" : "凌雲寺",
        "/open/world1/wilfred/meadow/" : "牯牛草原",
        "/open/world1/wu_sha_town/" : "無沙鎮",
        "/open/world1/kkeenn/love/" : "情城池",
]);

void create()
{
        set_name(HIY"黃金蜈蚣"NOR, ({ "gold scolopendra", "scolopendra" }) );
        set("level", 80);
        set("race", "beast");
        set("default_actions", (: call_other, __FILE__, "query_action" :) );
        set("actions", (: call_other, __FILE__, "query_action" :) );
        set("combat_exp", 200000);
        set("limbs", ({ "頭部", "腹部" }) );
//        set("attitude", "aggressive");
        set("chat_chance", 5);
        set("chat_msg", ({
//                (: random_move :),
        }) );
        setup();
        set_living_name("scolopendra");
        carry_object(__DIR__"gloves")->wear();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void drill()
{
        object obj, claw, room;
        string *exits;

        obj = this_object();
        room = environment(this_object());

        if( !room || sscanf(base_name(room),"%*s.ug") != 0 )
                return;

        exits = values(room->query("exits"));

        new(PCLAW)->move(room);
        new(PCLAW)->move(room);
        new(PCLAW)->move(room);

/*
        foreach(string str in exits)
        {
                if( claw = load_object(str) )
                {
                        new(PCLAW)->move(claw);
                }
        }
*/
        command("drill");

        return;
}

int receive_damage(string type, int damage, object who)
{
        if( !random(10) ) this_object()->drill();
        ::receive_damage(type, damage, who);
        return 1;
}

int heal_up()
{
        if( !sizeof(filter_array( children(__DIR__"claw"), (: clonep :) ) ) )
        {
                command("climb");
                if( !random(5) ) random_move();
        }

        ::heal_up();
        ::heal_up();
        ::heal_up();
        ::heal_up();
        ::heal_up();

        return 1;
}

void special_attack(object me, object victim, int hitrole)
// NPC之自訂特攻函數,special_attack(<obj>攻擊者,<obj>受攻者,<int>命中計算)
{
        int damage;
//        if( hitrole >= 135 )
        if( !random(10) )
        {
                if( victim->query_armor()*victim->query("level")/5 > victim->query("max_hp") )
                        damage = 10;
                else damage = (victim->query("max_hp") - (victim->query_armor()*victim->query("level")/5) - random(100));

                if( damage <= 0 ) damage = 10;
                if( damage >= victim->query("max_hp")*2/5 ) damage = victim->query("max_hp")*2/5 +random(50);

        } else damage = 0;

        message_vision(HIY"\n$N"NOR HIY"把身體捲成一團，然後猛烈撞向$n身上，造成 "+damage+" 點損傷。\n\n"NOR, me, victim);
        victim->receive_damage("hp", damage, me);
        me->kill_ob(victim);
        return;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        command("climb");
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
                HIY"\n\t古神獸"HIW"["HIY"黃金蜈蚣"HIW"]被"+ob->name()+"("+ob->query("id")+")打敗了！\n\n"NOR
        ,users());
        ob->add("popularity",10); //聲望
        new(__DIR__"gloves")->move(ob);
        tell_object(ob, BLINK"你得到了一件"HIY"蜈蚣護手"NOR"。\n");
        ::die();
        return;
}

int be_stolen(object me, object what)
{
        if( !me || !what )
                return notify_fail("[錯誤]:請用 report 指令回報。\n");

        tell_object(me, this_object()->name() + "不經意地一轉頭﹐你急忙將手縮了回去﹗\n"
                "還好﹐沒有被發現。\n");
        me->start_busy(2);
        return 1;
}

int start()
{
        string dir, *file, dest;

        dir = keys(areas)[random(sizeof(keys(areas)))];
        file = get_dir(dir);
        dest = dir+file[random(sizeof(file))];

        if( !objectp(load_object(dest)) 
        || !load_object(dest)->query("short")
        || !load_object(dest)->query("exits")
        || !load_object(dest)->is_room()
        ) {
                return start();
        }

        this_object()->move(dest);
        message("world:world1:vision",
                HIW"急報！\n\n"NOR HIY"\t古神獸 ["+this_object()->name()+"] "HIW"在 ["HIG+values(areas)[member_array(dir , keys(areas))]+HIW"] 出現。\n"NOR
        ,users());

        return 1;
}

void init()
{
        object me = this_player();

        if( me->is_corpse() ) return;

        if( (userp(me) && !wizardp(me) && me->query("level") > 30 && environment(me) == environment(this_object())) || ( !userp(me) && !me->query("no_kill") ) ) 
                this_object()->kill_ob(me);
}

