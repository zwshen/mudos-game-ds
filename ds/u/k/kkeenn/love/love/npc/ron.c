#include <ansi.h>
inherit NPC;
void create()
{
        set_name(MAG"妙法仙尊"NOR,({"mu fu ron","ron"}));
        set("long" ,
"情城池的初代使者，震城絕技[滅神鞭法]便是由她而創，實力絕不容小看\n"
"是位可畏的女鞭手。\n");
        set("nickname", RED"詭譎鞭"NOR );
        set("attitude", "friendly"); 
        set("age", 120);
        set("gender","女性");
        set("level", 60);
        create_family("情城池",15,"方外長老");
        set("adv_class",1);
        set("combat_exp", 150000);
	set("class1", "情城池");
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "whip" : ({ 110,3,80 }),
  "parry":({ 130,2,60 }),
 "masen_whip" : ({ 150,3,80 }),
  "force" : ({ 135,3,85 }),
  "unarmed" : ({ 100,3,80 }),
"run_cloud" : ({ 140,3,80 }),
]));

        set("title",HIW"情城池方外長老"NOR);
        set_temp("apply/armor",35);
        set_skill("run_cloud",100);
        set_skill("masen_whip",100);
        set_skill("seven-love",100);
        set_skill("force",100);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
  (:command("exert masen_whip"):),
  (:command("exert masen_whip"):),
}));
	set("chat_chance", 40);
	set("chat_msg", ({
		(: command,"wield whip" :),
	}));

        setup();
        carry_object(__DIR__"obj/ghost_whip")->wield();
        add_money("coin",5000);
        }
void init()
{
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
  if(me->query("combat_exp") > 150000) {
      ob->set("combat_exp",me->query("combat_exp") + 10000);
  return;
}
      ob->kill_ob(me);
                        return;
        }
        add_action("do_letter","say");
      if(me->query("class1") == "情城池" )
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
                        return;
        }
}
int do_letter(string arg)
{
        object me,ob,obj;
        me = this_player();
        ob = this_object();
 if(arg == "您最近好嗎?" && me->query_temp("ljoin"))
     {
tell_object(me,ob->name()+HIG"昂天嘆了一口氣，沒想到我這徒孫還滿孝順的..\n"NOR);
tell_object(me,ob->name()+HIG"嘴角泛起一絲微笑。\n"NOR);
tell_object(me,ob->name()+HIG"說道：被人關心的感覺真好....\n"NOR);
tell_object(me,ob->name()+HIG"說道：朋友，請幫我把這封信交給山雪，她會明白的。\n"NOR);     
       obj = new(__DIR__"obj/letter.c");
       obj->move(me);
      me->delete_temp("ljoin");
        return 1;

} else
{
tell_object(me,ob->name()+HIG"用疑惑的眼神看著你...@@\n"NOR);
}
return 1;
}

void die()
{
        object ob,me;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
                me=this_object();
                message_vision(
                HIG "\n$N小口一張，竟然使用邪教的【"HIR"天魔解體大法"HIG"】，再度提昇自己的精力！！\n\n"
           +HIC "$N提起手中鞭子，急速旋出九九八十一個圈子密密麻麻的包圍住$n\n，在$n被轉的眼花撩亂之際，$N昂天大叫一聲：『\n"HIR"毒霸江湖，詭譎血鞭，血氣一出，神形化無"HIC"』語畢那八十一個圈子中忽然漫出一股奇香無比的血氣，\n正當$n覺得奇怪之際，一股強烈的氣勁從$N身上急速衝出向$n直飛而來！！\n\n"NOR,me,ob);
                 if( random(10)>4) {
                        message_vision(HIR "在$N想要閃躲之際，被身旁的鞭圈纏住難以脫逃，終究被那股氣勁狠狠地被擊飛數丈之遠！！\n" NOR,ob );
 ob->apply_condition("poison", ob->query_condition("poison")+(ob->query("hp")+random(ob->query("con"))) );
                        ob->set("hp",ob->query("max_hp")/100);
                COMBAT_D->report_status(ob);
                        tell_room(ob,CYN +"(" + ob->query("name")+"口中鮮血狂噴往外直飛了過去...)\n" NOR,ob);
                        ob->move(__DIR__"../room25.c");                   tell_room(environment(ob),ob->query("name")+"渾身是血的平飛了過來，「碰」的一聲摔在你的腳旁邊顫抖中。\n",ob);
                        ob->start_busy(2);
                } else {
                        message_vision(HIW "$N勉強地躲避了這致命一擊，但也臉色嚇得蒼白...\n" NOR,ob );
                }

        message("world:world1:vision",
HIR"\n  《封天榜》:\n\n\t"HIC"天下十大高手 "MAG"詭譎鞭 "HIC"妙法仙尊竟被一名無名小卒"+ob->name()+HIC"擊敗了！\n\n"+NOR
        ,users());
        ob->add("popularity", 5); 
        ::die();
        return;
}
int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}
int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}
