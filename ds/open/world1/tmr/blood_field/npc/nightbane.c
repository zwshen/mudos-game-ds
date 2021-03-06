#include <ansi2.h>

inherit NPC;

void do_super(object me);

void create()
{
     set_name(HBK "骨龍 "HIR"夜禍" NOR, ({ "nightbane dragon", "nightbane", "dragon", "_BLOOD_FIELD_NPC_", "_NIGHTBANE_" }) );
    set("long", @LONG
夜禍是一條巨大的骨龍，渾身散發著黑色的死亡氣息，你半步也不敢靠近
牠，你只稍微望進夜禍空洞的雙眼，更在你腦海中浮現數百幅鮮活的殺戮場面
，只嚇著你膽顫心驚，腳底發軟，只想要快點離開這裡。夜禍是血腥荒野的領
主，統領著荒野上的各式生物，對任何侵入這個戰場的敵人，一律是殺無赦。
LONG
        );

    set("title", HIM"血腥領主"NOR);
      set("race", "dragon");
      set("gender","男性");
    set("age", 1200);
    set("level", 60 );
    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("attitude", "aggressive");
    set("max_hp", 40000);
    set("addition/bar", 15);
    set("addition/bio", 5);
    set("addition/wit", 15);
    set("addition_armor", 300);
    set("addition_hit", 250);
    set("addition_damage", 300);
    set("addition_shield", 300);
    setup();
    set_living_name("_NIGHTBANE_");
    if(random(100)<5)
        carry_object(__DIR__"obj/mask")->wear();
    else
        carry_object(__DIR__"obj/mask2")->wear();
}

void die()
{
       object ob;

        if( this_object()->query("pill") < 2 ) {
            message_vision(HIR"一道刺眼的光芒暴散開來，$N"HIR"的形體又恢復成原本的駭人模樣了。\n"NOR, this_object());
            set("hp", this_object()->query("max_hp"));
            add("pill", 1);
            return;
        }


        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        message("world:world1:vision",
           HIR"\n【奧特蘭克】"+name()+HIG"在臨死之際發出怒吼，已被"+HIG"戰場英雄《"+ob->name(1)+"(" + ob->query("id") + ")》摧毀到灰飛煙滅，形體不再！！\n\n" NOR
        ,users() );
        ob->add("popularity", 4);
        tell_object(ob,HIG"你獲得４點聲望。\n"NOR);

        ::die();

        return;
}


int special_attack(object me, object target, int hitchance)
{
        int dmg;
        if(!me) return 0;
        if( query_temp("special_attack") ) return 0;
        if( random(100) < 30) return 0;

        if( random(100) < 40)
        {

                message_vision(HIG"$N"HIG"張嘴吐出一道強勁的"HBK"黑色氣旋"HIG"，狠狠撞上$n"HIG"！！\n"NOR, me, target);
                dmg = this_object()->query_damage() - target->query_armor();
                if(dmg<1) dmg = 10;
                dmg = COMBAT_D->Merits_damage(me, target, dmg, "bio");
                target->receive_damage("hp", dmg, this_object());
            return 1;
        }

        // 群體攻擊
        set_temp("special_attack", 1);
        message_vision("$N"HBK"身上濃厚的黑氣宛如水銀瀉地，在四週的地上瀰散開來！！\n"NOR, me);
        call_out("do_super", 1 + random(2) ,me);
       return 1;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = me->query_enemy();
  delete_temp("special_attack");
  if(!inv) return;
  if(!me) return;

  message_vision( HIC"\n四週一陣騷動，"HBK"夜禍黑氣"HIC"就如海潚般漫天蓋\地的襲來！！\n"NOR, me);
  for(i=0;i<sizeof(inv);i++)
  {
          if( !environment(me) ) continue;
          if( !inv[i] || !environment(inv[i]) ) continue;
          if(environment(me) != environment(inv[i]) ) continue;

          damage = query_damage() + random(query_damage());
          if( inv[i]->is_busy())
                damage -= random(inv[i]->query_armor());
          else
                damage -= inv[i]->query_armor()/2 + random(inv[i]->query_armor()/2);

      damage = COMBAT_D->Merits_damage(me, inv[i], damage, "bio" );
      if(damage < 10 ) damage = 1 + random(9);
      message_vision(HIR"$N"HIR"無所閃避，轉眼間被"HBK"夜禍黑氣"HIR"撲上，只能無力地發出數聲慘叫！！"HIR"("+damage+")\n"NOR,inv[i]);
      damage = inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
  }
  me->start_busy(2);
  return;
}

