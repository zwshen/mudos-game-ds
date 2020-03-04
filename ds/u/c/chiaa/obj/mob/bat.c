//u/c/chiaa/obj/mob/bat.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("蝙蝠", ({ "bat" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age",2 );//年紀
set("long", "攀附在牆上的蝙蝠\n");//人物敘述
set("str",1 );//膂力
set("cor",0 );//膽識
set("int",0 );//悟性
set("spi",1 );//靈性  
set("cps",2 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",1 );//根骨
set("limbs", ({ "頭部", "身體", "前腳", "後腳", "翅膀" }) );//身體部位
set("verbs", ({ "bite", "claw", "crash" }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 360);//人物經驗
set("potential", 10);//潛能
set_temp("apply/attack", 14);//攻擊力
set_temp("apply/armor", 10);//防禦力

add_money("coin",400);//得到的金錢coin silver gold
set("max_gin", 20);//精最大值
set("max_kee", 200);//氣最大值
set("max_sen", 20);//神最大值  

setup();
  
}

