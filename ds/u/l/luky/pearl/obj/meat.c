inherit COMBINED_ITEM;

void create()
{
set_name("肉乾",({"meat"}));
set_weight(830);
set("value",350);
if( clonep() )
 set_default_object(__FILE__);
else {
set("long","一片肉乾, 你可以吃(eat)它來恢復你的體力.\n");
set("amount",1);
}
set("unit","片");
set_amount(1);
}

void init()
{
 add_action("eat_meat","eat");
}

int eat_meat(string arg)
{
 int num;
 object ob;
 if(!this_player()) return 0;
 if(!arg) return 0;
 if(arg!="meat") return 0;
 if(!ob=present(arg,this_player()))
  return notify_fail("你想要吃什麼啊\n");
 else if(ob==this_object())
 {
  num = ob->query_amount();   
  if(this_player()->query("max_ap")==this_player()->query("ap"))
  {
   write("你的體力十分好\n"); 
   return 1;
  }
  if(this_player()->query("ap")+350>this_player()->query("max_ap"))
  {
   this_player()->set("ap",this_player()->query("max_ap"));
   write("你的體力全部恢負了\n");
   num--; 
   if(num==0) destruct(ob);
   else ob->set_amount(num);
   return 1;
  }
  this_player()->add("ap",350);
  write("你嚼了嚼肉乾, 然後吞了下去\n");
  num--;            
  if(num>0)
  { 
  set_weight(this_object()->query_weight()-830);
  //me->set_encumbrance(me->query_encumbrance()-1000);
  set_amount(num);
  } else destruct(this_object());
  return 1;
 }
}
