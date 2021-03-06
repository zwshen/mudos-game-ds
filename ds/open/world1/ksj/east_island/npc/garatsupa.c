#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIG"河童"NOR, ({"garatsupa"}) );
  set("long",@LONG
身高大約是四或五歲兒童般的高度，具有將一匹馬給活生生地拖入水
中的力量。頭上頂著盤子，背後長著像龜殼般的東西，而且雙手可以
伸縮自如。它頭上的盤子裝滿著水，若是盤子內的水乾枯的話，就會
馬上喪失力量而變得虛弱。河童藏匿於河川附近，喜歡捉弄別人，最
愛跟路過的人玩相撲。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",60);
  set("gender", "雄性" );
  set("level",30);
  set_skill("unarmed",60);
  set_skill("dodge",40);
  set_skill("parry",30);
  set("limbs", ({ "頭部", "身體","左手","右手","左腳","右腳"}) );
  set("verbs", ({"bite","claw","crash"}) );
  setup();
  carry_object(__DIR__"eq/turtle-shell-armor")->wear();
  carry_object(__DIR__"eq/stone-shield")->wear();
}

void init()
{
        add_action("do_hit","hit");
 
}

int do_hit(string str)
{
        object me,ob;
        me=this_object();
        ob=this_player();
 
        if(!str || str!="garatsupa") return 0;
        if( me->is_fighting(ob) ) return notify_fail("你正在戰鬥中，沒空做這件事。");
        if( random(10)<2 && ob->query_temp("weapon"))
        {
         message_vision(
         HIC"\n$N出其不意，揮動手中兵器往河童頭上的盤子敲去！\n"NOR
         HIG"\n河童不小心被$N擊中，頓時頭昏眼花，癱在地上。\n"NOR,ob);
         me->start_busy(20);
        }
        else
        {
         message_vision(
         HIC"\n$N出其不意，揮動手中兵器往河童頭上的盤子敲去！\n"NOR
         HIR"\n河童慌慌張張地往一旁閃了開去！\n"NOR,me);
         me->fight_ob(ob);
         ob->add_busy(1);
        }
        return 1;
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
 
        switch( random(100) ) {
        case  0..2: new(__DIR__"eq/garatsupa-necklace")->move(this_object());
        break;}
        ::die();
        return;
 }
