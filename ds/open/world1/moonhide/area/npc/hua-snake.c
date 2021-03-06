#include <ansi.h> 
inherit NPC;
void create()
{
    set_name(HIR"迴天"NOR, ({"hua-tan snake","tan","hua", "snake"}) );
  set("long","長年躲在地底下的神獸，已活得百年歲，尖銳的牙齒，必會帶來重大的傷亡。\n");
  set("race", "beast");
  set("unit","隻");
  set("age",106);
  set("title","霧洞");
  set("level",45); 
  set("max_hp",26000);
  set_skill("dodge",200);
  set_skill("unarmed",100);
  set("limbs", ({ "頭部", "腹部","胸部","尾巴" }) );
  set("verbs", ({ "bite" }) ); 
        set("chat_chance_combat",13);
        set("chat_msg_combat",({ 
    (: random_move :), 
}));  
  setup(); 
  set_temp("apply/armor", 200);
  set_temp("apply/damage",100);
  set_temp("apply/shield", 150);
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(6)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIR"\n\n$N"+HIW"張開血盆大口！\n"
                    +HIW"一股"+HIR"紅色"+HIW"的能量漸漸凝聚••••\n"
                    +HIR"噴向$n，$n被巨大的能量淹沒，肢體漸漸麻痺！\n\n"+NOR,me,target);  
     target->receive_damage("hp",350+random(350), this_object()); 
     target->start_busy(2);
     return 1; 
    }
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision", 
                HIR"\n\t 霧洞百年大蛇 迴天 竟被"+ob->name(1)+ HIR "收服了！！\n\n"+NOR,users());
        ob->add("popularity", 2);
        if( random(100) < 15)
                new(__DIR__"snake-surcoat")->move(this_object());
        else
                new(__DIR__"snake-surcoat2")->move(this_object());
        ::die();
        return;
}

