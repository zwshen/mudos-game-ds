#include <ansi.h>
inherit NPC;
void create()
{
  set_name("華霜", ({ "hua sun","sun","hua" }) );
  set("gender", "女性" );
  set("long",@LONG
她是申子平的朋友，特地陪他來喝酒解悶的。她身穿一襲水藍長袍，
腰際配了一把短劍，白淨瓜子臉帶著淡淡的笑容，十分可人憐愛。
LONG
);      
  set("age",20);
  set("level",25);
  set("race","human"); 
  setup();
  carry_object(__DIR__"armor/03")->wear();
}
