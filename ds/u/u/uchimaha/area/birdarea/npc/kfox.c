#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"九尾"NOR,({ "killer fox", "fox" }) );
        set("level",60);
        set("race", "野獸");
        set("age", 1000);
        set("title",HIR"殺人狐"NOR);
        set("long", "牠是這裡的頭頭，據說牠已經活了上千年了。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_skill("dodge",100);
        set("Merits/bar",10);
        set_skill("combat",100);
        set_skill("parry",90);
        add("addition_armor",90);
        add("addition_damage",80);
        set("evil",200);
        set("attitude", "aggressive");
        set("guild_gifts",({6,6,-2,10}));
        setup();
}
int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;

  if(!random(5))
  {
    message_vision("\n$N"HIW"的妖氣開始吸收附近周圍所有的精氣...\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}
void do_super(object me)
{
  // 這裡的 me 是指 this_object()
  object *inv;
  object ob;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]))
    {
      damage = random(150)+200;
      message_vision(HIW"$n的精氣被"HIR"$N"HIW"給吸食了... "MAG"("+damage+")\n"NOR,inv[i],me);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
      add("hp", damage);
    }
    else
    {
      message_vision(HIR"\n$N瞬間被吸成一具乾屍... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  return;
}
int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();

  // 反擊
  if(!random(10))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIW"\n【"HIR"九尾的反擊！"HIW"】\n"NOR,ob);
    if(me->query("level") > 40)
    {
      COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    else
      if(me->query("level") > 30) 
      {        COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+2);
         if(query("hp") < query("max_hp")) add("hp",15+random(15));
      }
      else
        if(me->query("level") > 24)
        {
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+2));
        }
        else
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+1));
  }

  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIC"\n  [小道消息]:"HIR"\n\n\t傳聞中的殺人狐  九尾如今竟慘死在"+ob->name(1)+"的手下!\n\n"+NOR,users());
        ob->add("popularity",10);
        tell_object(ob,HIW"(因為你殺死了九尾，所以得到了 10 點聲望。)"NOR);
        message_vision( "$N"+HIR "臨死前，因為妖氣用盡，身上毛皮脫落下來...." NOR ,this_object() );
        ob->move(environment(this_object() ) );
        ob=new(__DIR__"obj/pe");
        ob->move(environment(this_object() ) );
        ::die();
        return;
}
