#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIY"鐵獅•玉玲瓏"NOR,({"iron-lion ue-lin-lon","lion"}) );
  set("long",@LONG
牠是守護玲瓏村有上千年已久的吉祥獅，身穿鑲金的鐵獅寶甲，
手持萬惡之爪─狂獅爪，無疑的是要保護牠所守護的村莊，免於
外患的欺辱，這樣的精神，深深的存在玲瓏村的上下，就是敬佩
這樣的精神，所以玲瓏村上下一到了祭拜日，便放下手邊的工作
，虔誠的祭拜。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",1032);
  set("level",42);
  set("attitude", "heroism");
  set("limbs", ({ "頭部", "腹部","胸部","獸爪","獸腳","背部" }) );
  set("verbs", ({ "bite","claw" }) );
  add("addition_armor",90);
  add("addition_damage",80);
  setup();
 /*
  carry_object(__DIR__"eq/lion_armor.c")->wear(); 
  carry_object(__DIR__"eq/lion_waist.c")->wear();
  carry_object(__DIR__"eq/lion_ring.c")->wear();
  carry_object(__DIR__"wp/lion_claw.c")->wield();
*/
}
void die()
{
   object ob;
   if( !ob = query_temp("last_damage_from") )   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }
message("world:world1:vision",
        HIY"\n\n    鐵獅•玉玲瓏說：\n\n"NOR
        HIR"            玲瓏村的老少，我無法守護你們，真是抱歉，永別了！\n\n"NOR, 
        HIW"            "+ob->name(1)+"真是厲害，將來一定是武林中的奇才∼∼\n\n"NOR,
        users());
        ob->add("popularity", 2); //聲望
        tell_object(ob,HIC"你擊敗了"HIY"鐵獅•玉玲瓏，你可得到2點聲望！！\n"NOR);
        ::die();
        return;

  }

