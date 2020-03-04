//u/c/chiaa/obj/mob/eye brute.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("獨眼獸", ({ "eye brute" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age",20 );//年紀
set("long", "一隻只有一個眼睛的異獸\n");//人物敘述
set("str",10 );//膂力
set("cor",5 );//膽識
set("int",0 );//悟性
set("spi",0 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",8 );//根骨
set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );//身體部位
set("verbs", ({ "hoof", "crash" }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 600);//人物經驗
set("potential", 20);//潛能
set_temp("apply/attack", 30);//攻擊力
set_temp("apply/armor", 30);//防禦力
add_money("silver",2);//得到的金錢coin silver gold
set("max_gin", 35);//精最大值
set("max_kee", 360);//氣最大值
set("max_sen", 35);//神最大值  

setup();
  
}

