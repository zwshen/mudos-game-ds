#include <ansi.h>
void whip();
inherit NPC;
varargs int receive_damage(string type, int damage, object who);
void create()
{
        set_name(HIW"白靈"NOR,({"white lin","lin"}));
        set("long" ,
"情城池的第三代傳人，練有震城絕技[滅神鞭法]中一式，實力絕不容小看\n"
"是位可敬的女鞭手。\n");
        set("nickname", HIM"八仙子之一"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","女性");
        set("level", 25);
        set("class1","情城池");
        set("title",HIC"情城池第三代傳人"NOR);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                          (:whip:), 
                          (:whip:), 
        }) );
        set_temp("apply/armor",15);
        set_skill("run_cloud",75);
        map_skill("dodge","run_cloud");
        setup();
        carry_object(__DIR__"obj/whip6")->wield();
         carry_object(__DIR__"obj/pill3");
        add_money("coin",1500);
        }
void whip()
{
        object me=this_object();
        object* target; 
        int dam = random(me->query_skill("whip") + 200);        if(me->is_busy() ) return;
        target=query_enemy();
        message_vision(
"$N舞姿一起，滅神鞭法第五式『"HIW"七夕銀河聚"NOR"』，手中鞭子帶著一股渾厚的內勁向直直的向你鞭去，\n  狠狠地擊向你的小腹\n",me);
        target->receive_damage("hp",dam,me);
        message_vision(HIR"造成你" +dam+ "點的傷害"NOR"。\n",me);
    return;
}
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
}
varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);      
 if(query("hp")<query("max_hp")/4 && !is_busy() && !query_temp("eaten") && random(100) > 70 ) 
           {
           command("eat ball");
           this_object()->set_temp("eaten");
           command("grin");                             
           }
        return damage;
}
