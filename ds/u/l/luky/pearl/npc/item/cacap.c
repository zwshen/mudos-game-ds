#include <ansi.h>

inherit F_AUTOLOAD;
inherit F_CLEAN_UP;
inherit F_SAVE;
inherit COMBINED_ITEM;     
void create()
{
set_name("[1;35m�d�d�Ĥ�[0m",({"caca potion","potion"}));
set_weight(2000);
 set("value",530);
set_amount(1);
set("amount",1);
if(!restore())
{
        set("unit", "��");
        set("long",
"�o�Ĥ��ڻ��i�H���t�ͩR�O\n"
                );
set("usage","��_���a2000�I���ͩR�O");
set("kind","hp");
set("cure",2000);
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
if(!arg) return 0;
if(this_player()->query("hp")<0) return 0;
if(arg=="potion")
{
if(this_player()->query("birthday"))
this_player()->add_temp("cmds",1);
if(!ob=present(arg,this_player()))        
return notify_fail("�A�n�ܤ���??\n");
if(ob->query_amount()<1)
return notify_fail("�A�w�g�ܧ��F\n");
if( me->query("hp")>=me->query("max_hp") )
{
write("�A�ͩR�O�D�`����!\n");
return 1;
}
me->add("hp",2000);
if(me->query("hp")+2000>me->query("max_hp"))
me->set("hp",me->query("max_hp"));
message_vision("\n$N�ܤF�@�~[1;35m�d�d�Ĥ�[0m.\n",me);
me->start_busy(1);
num--;
if(num>0)
{ 
set_weight(this_object()->query_weight()-2000);
//me->set_encumbrance(me->query_encumbrance()-1000);
set_amount(num);
} else destruct(this_object());
return 1;
}
}

