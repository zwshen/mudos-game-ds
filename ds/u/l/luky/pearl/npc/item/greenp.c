inherit F_AUTOLOAD;
inherit F_CLEAN_UP;
inherit F_SAVE;
inherit COMBINED_ITEM;     
void create()
{
set_name("[1;32mºñÄ¦ÃÄ¤ô[0m",({"green potion","potion"}));
set_weight(1250);
 set("value",1400);
set_amount(1);
set("amount",1);
if(!restore())
{
set("unit","²~");
set("long","¥ÑºñÄ¦´£·Ò¦Ó¦¨ªºÃÄ¤ô, ¥i¥H¨³³t«ì´_¥Í©R¤O»PÅé¤O.\n");
set("kind","hp");
set("usage","«ì´_ª±®a1000ÂIªº¥Í©R¤O»P500ÂIªºÅé¤O");
set("cure",1000);
}
}


void init()
{
add_action("drink_potion","drink");
}

int drink_potion(string arg)
{
int num
;
object ob,me;
me=this_player();
num = query_amount();            
if(!this_player()) return 0;
if(!arg)
return 0;
if(this_player()->query("hp")<0)
return 0;
if(this_player()->query_temp("supply"))
return notify_fail("§A¥¿¦b¦£,¨SªÅ³ÜÃÄ¤ô\n");
if(arg=="potion")
{
if(this_player()->query("birthday"))
this_player()->add_temp("cmds",1);
if(!ob=present(arg,this_player()))        
return notify_fail("§A­n³Ü¤°»ò??\n");
if(ob->query_amount()<1)
return notify_fail("§A¤w¸g³Ü§¹¤F\n");
if(me->query("hp")>=me->query("max_hp") && me->query("ap")>=me->query("max_ap"))
{
write("§A¥Í©R¤O©MÅé¤O³£º¡¤F!\n");
return 1;
}
me->add("hp",1000);
me->add("ap",500);
if(me->query("hp")+1000>me->query("max_hp"))
me->set("hp",me->query("max_hp"));
if(me->query("ap")+500>me->query("max_ap"))
me->set("ap",me->query("max_ap"));
message_vision("\n$N³Ü¤F¤@²~[1;32mºñÄ¦ÃÄ¤ô[m.\n",me);
me->start_busy(1);
num--;
if(num>0)
{ 
set_weight(this_object()->query_weight()-1000);
//me->set_encumbrance(me->query_encumbrance()-1000);
set_amount(num);
} else destruct(this_object());
return 1;
}
}

