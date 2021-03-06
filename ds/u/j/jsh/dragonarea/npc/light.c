#include <ansi.h>

inherit NPC;

void create()
{
        set_name("光之子", ({ "son of light","son","light" }) );
        set("long",@LONG
磐龍城的頭號打手，可以拿到通往元素之門的謎底。 
LONG
);  
        set("gender", "男性");  
        set("race", "人類");
        set("level",45);
        set("age",50+random(2));
        set("title",HIY"龍" HIG"的傳人"NOR); 
        set_skill("unarmed",100);
        set_skill("dodge",200); 
        set_skill("parry",100);       
        set_skill("combat",200);
        set("combat_exp",1000000);
        set("max_exp",50000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/dragonblade")->wield(); 
     carry_object(__DIR__"obj/pants")->wear();
     carry_object(__DIR__"obj/ring")->wear();
     carry_object(__DIR__"obj/cloth")->wear();   
     carry_object(__DIR__"obj/hands")->wear();  
     carry_object(__DIR__"obj/armor")->wear();
     carry_object(__DIR__"obj/boots")->wear(); }

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision("\n"
                    +HIW"$N使出幻龍法之百步龍\n" NOR    
                +HIW"無數的腳陣踢向$n........！！\n"NOR
                    +HIW"造成嚴重的踢傷..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",200+random(200), this_object());
    }
    else
    {
      message_vision("\n"
                    +HIR"$N使出幻龍法之日炎龍\n" NOR       
             +HIR"一波波的的焱掌攻向$n！！\n" 
NOR               
      +HIR"造成嚴重的掌傷......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    } 
     if(random(hitchance*10) > tdex+tcon)

    {
      message_vision("\n"
                    +WHT"$N使出幻龍法之塵空龍\n" NOR       
             +WHT"$N身體像是飛起來般的襲向$n！！\n" NOR    
                +WHT"造成嚴重的瘀傷\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    }
else
    {
      message_vision("\n"
                    +HIB"$N使出幻龍法之月影龍\n" NOR       
             +HIB"雙手畫圓，在胸口凝成一月符，[喝]的一聲，打向$n！！\n" NOR              
      +HIB"造成嚴重的內傷\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    }
if(random(hitchance*10) > tdex+tcon)

    {
      message_vision("\n"
                    +HIC"$N使出幻龍法之雲傲龍\n" NOR       
             +HIC"大量水氣漸漸凝聚，像萬針般的射向$n！\n" NOR                
    +HIC"造成嚴重的穿刺傷\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
    }
 else    {
      message_vision("\n"
                    +HIG"$N使出幻龍法之盛風龍\n" NOR       
             +HIG"$N以快打慢，攻的$n不之怎麼辦，終於不敵而中招！！\n" NOR   
                 +HIG"造成嚴重的擊傷\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(200), this_object());
      return 1;
    }
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIR"\n【 磐 龍 城 】"+HIW "光之子死在"+ob->name(1)+"的手裡。\n\n"+NOR     
       ,users());
        ob->add("popularity",4); 
     message_vision( "$N"+HIB"小聲的說 : 在藥鋪的後面 . . . . . . "NOR ,this_object() ); 
        ::die();
        return;
}

