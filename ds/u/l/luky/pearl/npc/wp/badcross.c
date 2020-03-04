#include <ansi.h>.
#include <weapon.h>
inherit STAFF;
int do_wield(object me, object ob);
void create()
{
set_name("穕反琜",({"bad cross","cross","wand"}));
set_weight(21000);
  if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "р");
                set("long", "硂琌р穕反臸\n");
  set("value",1);
                set("material", "steel");
        }
init_staff(1);
        setup();
}
void init()
{
 add_action("do_invoke","invoke");
 add_action("do_recharge","recharge");
}

int do_invoke(string arg)
{                        
 object me;
 me=this_player();
 if(!me) return 0;
 if(this_object()==present(arg,me))
	return notify_fail("臸穕反礚猭ㄏノ\n");
 else return 0;
}

int do_recharge(string arg)                     
{                                           
 object me;                          
 int time;
 me = this_player();              
 if(!me) return 0;
 if(this_object()==present(arg,me))
	return notify_fail("臸穕反礚猭ㄏノ\n");
 else return 0;
}
