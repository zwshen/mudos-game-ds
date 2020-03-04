#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name(HIC"陰"HIR"陽"NOR"劍",({"negative positive sword","sword"})); 
set("long","這是一把由獨臂老人所打造出來的最佳傑作，劍刃的地方有著絲\n"
           "絲的寒氣，寒氣的外圍卻又包圍了一層暖氣，入手之後，令人為\n"
           "之一震。\n");
set_weight(17000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("limit_str",45); 
        set("limit_int",30);
        set("limit_dex",40); 
        set("limit_level",45);
        set("value",10000);
        set("material","blacksteel");
        }
        set("wield_msg","$N從背後抽出一把$n，只見$N身旁圍繞著一股陰陽調和之氣。\n");
        set("unwield_msg","$N放下手中的$n，將$n插入背後的劍鞘中。\n");
        set("weapon_prop/sou",-2); 
        set("weapon_prop/bar",random(2));
        set("weapon_prop/tec",random(2));
        set("weapon_prop/wit",1);
        set("weapon_prop/int",2); 
        set("weapon_prop/hit",20);
        init_sword(40+random(30));
        setup();
}
void attack(object me,object victim)
{
  object ob = this_object(),
         ppl = this_player();      
        int aa,aa1,power,mysk,myint,hp,mp,ap;
        hp = random(ppl->query("max_hp")*11/40);
        mp = random(ppl->query("max_mp")*11/60);  
        ap = random(ppl->query("max_ap")*11/50);        
        
        ::attack();
        if(!me) return;
        if(!victim) return;
        if(me->is_busy()) return; 
        
    switch ( random(30) ) {
      case 1:        
        message_vision(HIG"\n$N手中的$n"HIG"發出一股溫暖的氣息…"
                      +"\n這股溫暖的氣息讓$N的精氣在惡鬥之中不降反升！\n\n"NOR,ppl,ob); 
        tell_object(ppl,HIC"生命點數(HP)："+HIY+"("+hp+")"+HIC+ 
                          "　魔法點數(MP)："+HIY+"("+mp+")"+HIC+ 
                          "　內勁點數(AP)："+HIY+"("+ap+")"+NOR+"\n");

        ppl->receive_heal("hp",hp);
        ppl->receive_heal("ap",ap);  
        ppl->receive_heal("mp",mp); 
      break;
      case 2..6:
        if(me->query("class1") != "疾風門" && me->query("class2") != "疾風門") return;
message_vision("\n$N"HIW"手中的"+ob->query("name")+HIW"出一陣耀眼的白光，光芒中發出一股強烈的陰陽之氣衝向$n！\n"NOR,me,victim);
        myint = me->query("int");
        mysk = me->query_skill("sword");
        aa1=me->query("MKS")/20000;
        if (aa1 < 1) aa1=1;
        if (aa1 > 4) aa1=4;
        power= (mysk+myint)/2;
        for (aa=0;aa<aa1;aa++)
        { 
         me->add_temp("apply/damage",power);
         COMBAT_D->do_attack(me, victim, this_object(), 1+random(4));
         COMBAT_D->report_statue(victim); 
         me->add_temp("apply/damage", -power);  
        }
      break;
     } 
  return; 
}

