// 解迷用 - 梅封之仇

#include <npc.h>

void create()
{
        set_name( "地獄獅" ,  ({ "hell lion","lion" }) );
        set("verbs", ({ "bite", "claw","crash"}) );
        set("age", 200 );
        set("long",@LONG
　　這是一隻長的異常巨大的獅子，正對著您張舞著鋒銳的爪子，血盆大口
中露出巨大的尖牙，喉嚨裡不時發出低吼聲，正目不轉瞬的直盯著你瞧。地
獄獅全身的毛髮盡做黑色，一雙眼睛綠油油的，顯得陰森恐怖。
LONG
        );
        set("attitude", "aggressive");
        set("title","死亡之森");
        set_skill("unarmed" , 150 );
        set_skill("dodge" , 100 );
        set_skill("parry" , 100 );
        set_attr( "cor" , 25 );
        set_attr( "strength" , 50 );
        set_stat_maximum("hp" , 800);
        set_stat_maximum("nina" , 500);
        set_race("beast");
        setup();
        set_level( 25 );
        carry_object(__DIR__"obj/lionhead.c")->wear();
}
