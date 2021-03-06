#include <room.h>
#include <ansi.h>
inherit ROOM;
//int do_cput(string arg);
int do_xput(object me, object obj, object dest, int func);
void create()
{
 set("short",HIR"絕世之窟"NOR);
 set("long", @LONG
你來到了一個比較陰涼的洞穴之中, 裡邊插了一把劍鞘, 可是你
卻看不到劍在何處. 你仔細的觀察了一陣子, 發現石壁上竟刻了首詩:

		殺   持   獨   惟
		聲   劍   在   憾
		轟   浴   江   餘
		傳   血   湖   我
		九   斬   步   稱
		千   荊   紅   無	絕
		里   棘   塵   敵       世
					間
		
					題

真是的狂傲自大的傢伙! 不知道他是否還活在這世上呢?
LONG
    ); 
 set("exits", (["wiz": "/d/wiz/hall1"]));
 set("objects", ([ "/open/world1/acme/area/sky/item/weapon_shelf" :1,
		   "/open/world1/acme/area/sky/item/equip_shelf" :1,
		   "/open/world1/acme/area/sky/item/item_shelf" :1, ]));
 set("light",1);
 set("valid_startroom",1);  
 setup();
 call_other("/obj/board/programming_b","???");
}                   
void init()
{
//    add_action("no_put","put");
    add_action("do_put","put");
}
int no_put(string arg)
{
  write("這邊不能用 put 喔, 要放東西請改用 cput..!\n");
  return 1;
}

int do_put(string arg)
{
        string target, item;

	object me,obj,dest,*inv,obj2;
        int i, amount,active=0;
	me=this_player();


	if(!arg) return notify_fail("你要將什麼東西放進哪裡?\n");
        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("你要放什麼東西﹖\n");
        if( target == "shelf" || target == "equip shelf" || target == "weapon shelf" || target == "item shelf")
		active = 1;
        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) ) return notify_fail("這裡沒有這樣東西。\n");
        if( dest->is_box() )
        {
                if(!dest->can_access_box()) return notify_fail("你必須先打開"+dest->name()+"才能放東西進去。\n");

        }
        if(sscanf(item, "%d %s", amount, item)==2)
        {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("你身上沒有這樣東西。\n");
                if( obj==dest ) return notify_fail("來源和目的不能是相同的東西!\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分開。\n");
                if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"並不是一個容器。\n");
                if( obj->query_max_encumbrance() && !obj->query("no_get"))
                        return notify_fail( "容器不能放到容器裡。\n");
                if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "不能被丟棄。\n");
                if( amount < 1 )
                        return notify_fail("東西的數量至少是一個。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_xput(me, obj, dest, active);
                else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if(!obj2->can_move(dest))
                        {
                                destruct(obj2);
                                return notify_fail("你沒有辦法把"+obj->query("name")+"放進"+dest->query("name")+"裡。\n");
                        }
                        obj->set_amount( (int)obj->query_amount() - amount );
                        return do_xput(me, obj2, dest, active);
                }
        }

        if(item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest ) do_xput(me, inv[i], dest, active);
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("你身上沒有這樣東西。\n");
        return do_xput(me, obj, dest, active);
}

int do_xput(object me, object obj, object dest, int func)
{
        mixed no_put;
        if( obj==dest ) return notify_fail("來源和目的不能是相同的東西!\n");
        if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"並不是一個�
e器。\n");
        if( obj->query_max_encumbrance()  && !obj->query("no_get"))
                        return notify_fail( "容器不能放到容器裡。\n");
        if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "不能被丟棄。\n");
        if( no_put = obj->query("no_drop"))
        {
                if(stringp(no_put)) return notify_fail( no_put+"\n");
                return notify_fail( "你無法把"+obj->name()+"放進那裡。\n");
        }
        if( obj->query_temp("riden") ) return notify_fail("你正在騎著耶!\n");
        if(!obj->can_move(dest)) return notify_fail("你沒有辦法把"+obj->query("name")+"放進"+dest->query("name")+"裡。\n");
	if( func ) {
		if( obj->query("skill_type") )
            dest = present("weapon shelf",environment(me));
		else if(obj->query("armor_type") )
            dest = present("equip shelf",environment(me));
        else dest = present("item shelf",environment(me));
	}
        if( obj->move(dest) )
        {
                message_vision( sprintf("$N將一%s%s放進%s。\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        me );
//                message_vision("\nFUNC: "+func+"\n",me);
                if(dest->query("access_log")) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                return 1;
        }
        else return 0;
}
