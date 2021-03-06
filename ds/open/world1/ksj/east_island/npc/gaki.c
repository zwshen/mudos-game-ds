#include <ansi.h>
inherit NPC;

void create()
{
  set_name("餓鬼",({"gaki"}) );
  set("long",@LONG
由於前世造下的罪孽而淪落餓鬼道。它的嘴巴太小而無法進食，而大
大的肚子是因為營養失調而膨脹起來的。餓鬼依種類不同，有的是完
全無法進食，有的是吃進去又會吐出來的，也有專吃腐肉的。
LONG
);
  set("race", "野獸");    
  set("unit","隻");
  set("age",47);
  set("level",20+random(4));
  set("limbs", ({ "頭部","身體","手部","腳部"}) ); 
  set("verbs", ({ "bite","claw" }) );     
  set("chat_chance", 5);
  set("chat_msg", ({
      "餓鬼抓了把泥土，一口接著一口吃著。\n",
      "餓鬼緩緩地在地上爬動，一面吃食能拿到的所有東西。\n",
      "餓鬼往你身上打量，露出飢渴的表情。\n",
     }));                                
  setup();
  add_money("coin",100+random(200));
}
