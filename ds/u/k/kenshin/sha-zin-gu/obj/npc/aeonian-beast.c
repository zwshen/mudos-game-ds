#include <ansi.h>
inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);
 void create() {
  set_name(HIR"千"NOR"古守"HIM"鶴"NOR, ({"the aeonian of year beast","beast"}) );
  set("long",@LONG
封印於封魔台已經有數千年的野獸，在千年之前，據說數位法力高超的法師
使用渾身解數封印才把守鶴封印在此封魔台中。此野獸身性兇猛，最好少惹
他為妙。
LONG
);   set("gender", "雄性");  
  set("race", "beast");
  set("unit","隻");
  set("age",2312+random(10));
  set("level",51+random(10));
  set("attitude", "aggressive");
  set("title",HIC"<瞬>"NOR); 
  set("limbs", ({ "頭部", "腹部","胸部","尾巴","前爪","後爪",}) );
  set("verbs", ({ "bite","crash","claw" }) ); 
  set("chat_msg_combat", ({
                        (:do_heal:), 
                        (:do_heal:), 
                }) );        
  set("Merits/bar",12);
  set("Merits/bio",10);
  add("addition_armor",99+random(12));
  set("chat_chance", 15);
  setup();
  }

void init()
{
    ::init();
    if( environment(this_player())->query("no_kill") ) return;
    if( environment(this_player())->query("no_fight") ) return;
    if(!this_object()->visible(this_player())) return;
    if(userp(this_player()) )
      this_object()->kill_ob(this_player());
    if(!random(3) )
    {
      message_vision(NOR"守"HIM"鶴"HIG"一動牠的尾巴掃了一大陣風，使$N無法使力!!\n"NOR,this_player() );
      this_player()->add_busy(random(1)+1);
    }
} 

// 戰鬥中療傷
void do_heal()
{
        object me=this_object();
        if(me->query("hp") < me->query("max_hp")/2)
        {
                message_vision("$N"HIY"使出「古生物態換」瞬間回復了不少的體力。\n" NOR,me);
                me->heal("hp",110);
                me->add_busy(1);
        } else {
                if(me->is_busy() ) return;
                if(me->query_temp("do_attack") ) return;
                message_vision("$N"HIG"瞬間躍動，之後其力量便暴增數倍!!\n" NOR,me);
                me->set_temp("do_attack",1);    // mark 避免多次攻擊
                me->add_temp("apply/damage",45);
                me->add_temp("apply/hit",250);
                        me->attack();
                        me->attack();
                me->add_temp("apply/hit",-250);
                me->add_temp("apply/damage",-45);
                me->set_temp("do_attack",0);
        }

}  
// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
                        message_vision("$N"HIR"凶狠的暴擊削弱了你原有的攻擊！！\n" NOR,this_object());

                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}
 int special_attack(object me,object target,int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(7))

    {
      message_vision(NOR"守"HIM"鶴"HIR"突然遁了地，飛快的速度從你背後使出兇猛的利爪，用力一抓！！\n"NOR,target);
                      if(random(target->query_dex()) >35){
                      damage=400-target->query_armor()+random(100);
                      target->receive_damage("hp",damage,target); 
message_vision("\n"HIR"此番襲擊共造成$N"NOR""+damage+"點的傷害。\n",target);
} 
else
    {
    message_vision(HIG"\n$N靈敏度超乎常人，硬是活生生避開了此番攻擊！！\n"NOR,target);
    return 1;
    }
        return 1;
  }
  return 0;
}

void die()
{
   object ob,eqp;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
        HIC"\n\t<來自東方的消息> ："+HIC"<瞬> "HIR"千年"HIG"守"HIM"鶴"HIW"終於在千年之後被神勇的"+ob->name(1)+"殺害了!!\n\n"+NOR
        ,users());
        ob->add("popularity",10);      
        tell_object(ob,HIG"你獲得[10]點聲望作為鼓勵。"NOR);
        if( random(100) )
                eqp=new(__DIR__"eq/god-neck");
        else
                eqp=new(__DIR__"eq/aeonian-ring");
        eqp->move(this_object());
        ::die();
        return;
}





