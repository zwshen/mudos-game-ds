#include <npc.h>
#include <ansi.h>

inherit F_BANDIT;

void create()
{
        set_name("宋玉", ({ "song yu" ,"song","yu" }) );
        set("long",@long
　　宋玉是硬幫幫中唯一的女性，但是本領高強，左右手宋家刀法已
達出類拔萃，加上生性兇悍，雖然長的高挑，容貌頗美，但是幫中成
員莫不對她保持敬重之意。
long
);
        set_race("operation");

        set("age", 35);
        set("force_ratio",10);
        set_attr("operation" , 60);
        set("gender","female");
        set_skill("parry" , 80);
        set_skill("psychical" , 100);
        set_skill("blade" , 100);
        set_skill("secondhand blade" , 100);
        set_skill("song blade" , 120);
        map_skill("blade","song blade");
        map_skill("secondhand blade","song blade");
        set_skill("dodge" , 80);
        set("attitude", "aggressive");
        set("title","硬幫幫二首領");
        setup();
        set_level(30);
        set_attr("int",18);
        set_attr("cps",18);
        carry_object(__DIR__"obj/cyan-hairpin")->wear();
        carry_object(__DIR__"obj/song-blade-book");
        carry_object(__DIR__"obj/right-lao-blade")->wield();
        carry_object(__DIR__"obj/left-sui-blade")->wield();
}

