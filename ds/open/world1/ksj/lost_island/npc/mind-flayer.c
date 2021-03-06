#include <ansi.h>
inherit NPC;

varargs int do_remove(object me, object ob,int silent);
mapping *combat_action = ({
        ([  "action":       "$N雙眼緊緊盯住$n的眼睛，就在$n恍神之際，$N的觸手已伸向$n頭部。",
                "attact_type":  "sou",
                "damage_type":  "心靈傷害",
        ]),
        ([  "action":       "$N右手凌空一揮，一隻青綠色的鬼爪憑空抓向$n的$l。",
                "attact_type":  "wit",
                "damage_type":  "創傷",
        ]),
});

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW""BLK"奪心魔"NOR, ({"mind flayer","flayer"}) );
  set("long",@LONG
奪心魔是個奇異的生物，它的身體如橡皮般有彈性而呈淡紫色，並附
有會反光的冰涼黏液，奪心魔的頭看起來像是一個有四隻觸手的章魚
，那一對臃腫白色眼睛會所有人感到毛骨悚然，當它停止吸取獵物的
腦汁後，有如八目鰻的嘴巴會不停滴落油膩的黏液。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",250);
  set("gender", "雄性" );
  set("level",46);
  set("attitude", "aggressive");
  set("evil",20);
  set("title",GRN"  妖獸 "NOR);
  set("limbs", ({ "頭部", "身體","頭上的觸手","手部","腳部" }) );
  set("verbs", ({ "bite" }) );
  set("Merits/sou",6);
  set("Merits/wit",5);
  set("chat_chance", 15);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/black-magic-robe")->wear();
}

void init()
{        
  ::init();
  if( random(this_player()->query_int()) < 10 && userp(this_player()) )
  {
    message_vision(HIM"$N朝$n發出強烈腦波，$n一時間頭暈目眩無法行動！\n"NOR,this_object(),this_player() );
    this_player()->add_busy(random(2)+2);
  }
} 

int special_attack(object me, object target, int hitchance)
{
  object *inv;
  int damage,i;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if( random(target->query_int()) < 5 )
  {
    damage=300-(target->query_shield())+random(50);
    if(damage<1) damage = 1;
    message_vision("$N"HIW"的頭部一陣劇烈扭動之後，對著$n使出"HIM"【心靈爆破】"NOR"，\n"
                  +HIW"$n覺得無數強烈的思緒在腦中翻滾，痛苦難當！("+damage+")\n"NOR, me, target);
    target->receive_damage("hp",damage,me);
    target->receive_damage("mp",damage/10,me);
    return 1;
  }
  else if( random(target->query_dex()) < 5 )
  {
    damage=200-(target->query_shield())+random(30);
    if(damage<1) damage = 1;
    if(damage < 0) damage=0;
    message_vision("$N"HIR"的身形突然化為一道黑影，瞬即來到$n的身後，等到$n發覺時已被觸手\n"
                  +"纏住脖子，$n感覺到血液正快速地被吸走！("+damage+")\n"NOR, me, target);
    target->receive_damage("hp",damage,me);
    if( me->query("hp")+200 < me->query("max_hp") )
      me->receive_heal("hp", damage);
    return 1;
  }
  else if( random(target->query_sou()) < 1 && !random(2) ) 
  {
    message_vision("$N"HIM"的雙眼如同深陷的漩渦，$n不由得被催眠了心智！\n"NOR, me, target);
    switch( random(6) )
    {
      case  0: 
            message_vision(YEL"$N可愛的說：『我是月光仙子！』\n"NOR,target);
            break;
      case  1:
            message_vision(YEL"$N覺得世界真是美好，每樣東西都值得你擁抱。\n"NOR,target);
            break;
      case  2:      
            message_vision(YEL"$N露出像白痴般的笑容... :D~\n"NOR,target);  
            break;
      case  3: 
            message_vision(YEL"$N高興的跳起了台中恰恰。\n"NOR,target); 
            break;
      case  4: 
            message_vision(YEL"$N像條魚一樣快樂的游來游去。\n"NOR,target); 
            break;
      case  5:
            message_vision(YEL"$N眼前浮現一張柔軟舒適的大床，嗯∼該脫衣就寢了。\n"NOR,target); 
            inv = all_inventory(target);
            for(i=0; i<sizeof(inv); i++)
              do_remove(target, inv[i]);
            write("Ok.\n");
            break;
    }
    return 1;
  }
  return 0;
}

// copy 自/cmds/std/remove.c
varargs int do_remove(object me, object ob,int silent)
{
  string str,gender;

  if( (string)ob->query("equipped")!="worn" )
    return notify_fail("你並沒有裝備"+ob->name()+"當作防具。\n");

  if( ob->unequip() )
  {
    if(!silent)
    {
      if( !stringp(str = ob->query("unequip_msg")) )
        switch(ob->query("armor_type"))
        {
          case "cloth":
          case "armor":
          case "surcoat":
          case "boots":
          case "pants":
          case "legging":
          case "mask":
          case "hands":
          case "neck":
          case "finger":
            str = YEL "$N脫下一"+ob->query("unit")+"$n。\n" NOR;
            break;
          case "bandage":
            str = YEL "$N將$n從傷口處拆了下來。\n" NOR;
            break;
          default:
            str = YEL "$N卸下一"+ob->query("unit")+"$n。\n" NOR;
        }
      if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
      else
      {       
        if(me->query("gender")=="女性") gender="妳";
        else gender="你";
        str=replace_string( str, "$N", gender);
        str=replace_string( str, "$n", ob->name());
        tell_object(me,str);
      }
    }
    if(me->is_fighting()) me->add_block(1);
    return 1;
  }
  else
    return 0;
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
  ob->add("popularity",1);
  tell_object(ob,HIG"你得到 1 點聲望。"NOR);      
  switch( random(100) )
  {
    case  0..5: new(__DIR__"eq/brambly-crown")->move(this_object());
          break;
  }
  ::die();
  return;
}
