
#include <ansi.h>

inherit NPC;

void do_super(object me);
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name(HIG "牧神潘恩" NOR,({"bariour pan","bariour","pan"}));
        set("gender", "男性");
        set("long",@LONG
一陣耀眼的月光刺痛你的眼睛，你無法看清楚牧神潘恩的長相，只能
聞到刺鼻的羊騷味。
LONG
        );
        set("level", 60);
        set("age", 800);
                set("race","celestial");
        set("title","羊男的迷宮");
        set_temp("fly",1);
        set_temp("apply/damage",200);
        set_temp("apply/armor", 400);
        set_temp("apply/shield",300);
                set("addition_hp", 30000);
                set("evil",-100);
                set("max_hp",50000);
        setup();
                set_temp("apply/wit", 3);
                set_temp("apply/bar", 3);
                set_temp("apply/bio", 3);
        set_living_name("bariour_pan");

                switch(random(4)) {
                        case 0:
                                carry_object(__DIR__"obj/pan_ankle1")->wear(); break;
                        case 1:
                                carry_object(__DIR__"obj/pan_ankle2")->wear(); break;
                        case 2:
                                carry_object(__DIR__"obj/pan_ankle3")->wear(); break;
                        case 3:
                                carry_object(__DIR__"obj/pan_ankle4")->wear(); break;
                }

        carry_object(__DIR__"obj/pan_necklace")->wear();
}

int special_attack(object me, object target, int hitchance)
{
        if(!me) return 0;
        if( query_temp("special_attack") ) return 0;
        if( random(100) < 30) return 0;

        if( target->is_busy() || random(100) < 20)
        {
            set_temp("special_attack", 1);
        set_name(HIY "牧神潘恩" NOR,({"bariour pan","bariour","pan"}));
                me->attack();
                me->attack();
        set_name(HIG "牧神潘恩" NOR,({"bariour pan","bariour","pan"}));
                delete_temp("special_attack");
                return 1;
        }

        if( random(100) < 80)
        {
                // 群體攻擊
                set_temp("special_attack", 1);
                message_vision("$N"HIW"的羊畸角激射出皎潔的白色光芒，轉眼間佈滿整座廣場！！\n"NOR, me);
                call_out("do_super", 1 + random(2) ,me);
                return 1;
        } else {
                // 補血

        }

        return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = me->query_enemy();
  delete_temp("special_attack");
  if(!inv) return;
  if(!me) return;

  message_vision( HIY"\n半空中形成無數長短不一的"HIW"白色羊畸角"HIY"，狂襲而來！！\n"NOR, me);
  for(i=0;i<sizeof(inv);i++)
  {
          if( !environment(me) ) continue;
          if( !inv[i] || !environment(inv[i]) ) continue;
          if(environment(me) != environment(inv[i]) ) continue;

          damage = query_damage() + random(query_damage());
          if( inv[i]->is_busy())
                damage -= random(inv[i]->query_shield());
          else
                damage -= random(inv[i]->query_shield()/2);

      damage += query_temp("horn") * 50;
      damage = COMBAT_D->Merits_damage(me, inv[i], damage, "wit" );
      if(damage < 100 ) damage = 100 + random(100);
      message_vision(HIR"$N"HIR"無所閃避，"HIW"白色羊畸角"HIR"直接穿越胸膛而過，帶出狂瀉而出的血流！！"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
      // 最多只會掉15根
      if( query_temp("horn") < 15  && userp(inv[i]) ) {
              add_temp("horn",1);
              new(__DIR__"obj/pan_horn.c")->move(environment(me)); // 掉一根角
      }
  }
  me->start_busy(2);
  return;
}

// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{
        object sw;

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");

        if( objectp(who) && type=="hp")
                set_temp("last_damage_from", who);
        sw=who->query_temp("weapon");

               if(random(100)<50)
               {
                        damage=1;
             if(  sw && objectp(sw) && sw->query("equipped") && random(100) < 70 ) 
                    {
                 sw->unequip();
                                                message_vision(HIY "\n一股刺鼻的羊騷味不知從何處傳來，$N"HIY"猛一聞到登時頭昏眼花，手臂酸軟無力。\n" NOR,who,sw);
                                                message_vision(CYN "($N脫落了手上的武器了。)\n" NOR,who,sw);
                     } if(random(100) < 40 ) {
                                                message_vision(HIY "\n一股刺鼻的羊騷味濔漫在整座廣場，$N"HIY"只覺得胸口煩悶難言，全身使不出力氣。\n" NOR,who);
                                                who->start_busy(2);
                                        } else {
                                                message_vision(HIM "\n$n"HIM"攻擊了老半天，才猛然發覺自已剛剛全都是往空氣發招。\n" NOR,this_object(),who);
                                        }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
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

          // 牧神之雨
         "/open/world1/tmr/goat_maze/stairway4.c"->open_rain();

                message("world:world1:vision",
HIG"\n\t" + ob->name(1) + HIG"終於擊敗了牧神潘恩，牧神又被放逐到曠野、廢墟、叢林、草澤之間！！\n\n"+NOR
        ,users());

        ob->add("popularity", 7);
        tell_object(ob,HIG "(你獲得 7 點聲望。)\n" NOR);

        ::die();
        return;
}


