#include <ansi.h>
inherit NPC;
void create()
{
  set_name("公孫華", ({ "Gon-sun Hua","hua","Hua" }) );
  set("gender", "女性" );
  set("long",@LONG
公孫華是公孫輩中的老么，最受嬤嬤疼愛，由於從小體弱多病的關係
，極少踏出春風樓一步，平常都是由湘兒跟菀兒輪流照顧。與嬤嬤更
是寸步不離。
LONG
);      
  set("age",21);
  set("level",15);
  set("race","human");
  setup();
}