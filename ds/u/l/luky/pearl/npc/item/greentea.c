inherit F_AUTOLOAD;
inherit F_CLEAN_UP;
inherit F_SAVE;
inherit COMBINED_ITEM;     
#define KIND "mp"
#define CKIND "ºë¯«"
void create()
{
set_name("[1;32m¯Â³ð¯ù[0m",({"green tea","tea"}));
set_weight(100);
set("value",300);
set_amount(1);
set("amount",1);
if(!restore())
{
set("unit","Åø");
set("long","¤@Åø¥ÑºñÄ¦´£·Ò¦Ó¦¨ªº¯ù, ¥i¥H¨³³t«ì´_§Aªººë¯«ª¬ºA.\n");
set("kind",KIND);
set("usage","«ì´_ª±®a700ÂIªºÅ]¤O");
set("cure",700);
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
if(arg=="tea" || arg=="green tea")
{
if(this_player()->query("birthday"))
this_player()->add_temp("cmds",1);
if(!ob=present(arg,this_player()))        
return notify_fail("§A­n³Ü¤°»ò??\n");
if(ob->query_amount()<1)
return notify_fail("§A¤w¸g³Ü§¹¤F\n");
if( me->query(KIND)>=me->query("max_"+KIND) )
{
write("§A"+CKIND+"¤w¸g«D±`¹¡º¡¤F!\n");
return 1;
}
if(this_player()->query(KIND)+700>this_player()->query("max_"+KIND))
this_player()->set(KIND,this_player()->query("max_"+KIND));
else this_player()->add(KIND,700);
message_vision("\n$N©BÂP©BÂPªº³Ü¤U¤F¤@Åø[1;32m¯Â³ð¯ù[m.\n",this_player());
write("§A·PÄ±"+CKIND+"ÅÜ¦n¤F¤@¨Ç!!\n");
num--;
if(num>0)
{ 
set_weight(this_object()->query_weight()-100);
//me->set_encumbrance(me->query_encumbrance()-100);
set_amount(num);
} else destruct(this_object());
return 1;
}
}

