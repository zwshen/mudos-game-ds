#include <ansi.h>
inherit NPC;

void create()
{
        set_name("看門狗", ({"watchdog","dog"}) );
        set("long", "一隻忠心耿耿的看門狗，誓死保護入口•\n");
        set("unit","隻");
        set("race", "野獸");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳" })); //受攻部位
        set("verbs", ({ "bite","poke","crash" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
        set("age", 5);
        set("level",20);
        set("dex",50);
        set("str",50);
        set("con",50);
        set_temp("apply/hit",20);      
        set_temp("apply/dodge",20);    
        set("max_hp",3000);
        set("evil",-10);
        setup();
}

void init()
{
    object me=this_player(),obj;
    add_action("do_throw","throw");

    if(objectp(obj=present("dump",me))){
    command("drool "+me->query("id"));
    tell_object(me,"眼前這隻看門狗眼巴巴的望著你手中的肉包，嘴邊還一直的流口水。\n"); 
    tell_object(me,HIW"(或許\把包子丟(throw)出去，能把這條狗給引開。)\n"NOR); 
    }
}

int do_throw()
{
    object me=this_player(),obj,ob=this_object();
    
    if(objectp(obj=present("dump",me))){
    message_vision(HIY"$N掏出懷中的$n遠遠的一丟，$n消失在遙遠的天空中。\n"NOR,me,obj);
    message_vision(CYN"$N汪的一聲，朝著$n跑去，也消失在遙遠的天空中。\n"NOR,ob,obj); 
    destruct(obj);
destruct(ob);
    }
    return 1;
}
    
    
