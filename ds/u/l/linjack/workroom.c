#include <room.h>
#include <ansi.h>
inherit ROOM;
//int do_cput(string arg);
int do_xput(object me, object obj, object dest, int func);
void create()
{
 set("short",HIR"µ´¥@¤§¸]"NOR);
 set("long", @LONG
§A¨Ó¨ì¤F¤@­Ó¤ñ¸û³±²Dªº¬}¥Þ¤§¤¤, ¸ÌÃä´¡¤F¤@§â¼CÀT, ¥i¬O§A
«o¬Ý¤£¨ì¼C¦b¦ó³B. §A¥J²ÓªºÆ[¹î¤F¤@°}¤l, µo²{¥Û¾À¤W³º¨è¤F­º¸Ö:

		±þ   «ù   ¿W   ±©
		Án   ¼C   ¦b   ¾Ñ
		ÅF   ¯D   ¦¿   ¾l
		¶Ç   ¦å   ´ò   §Ú
		¤E   ±Ù   ¨B   ºÙ
		¤d   ¯ð   ¬õ   µL	µ´
		¨½   ´Æ   ¹Ð   ¼Ä       ¥@
					¶¡
		
					ÃD

¯u¬Oªº¨g¶Æ¦Û¤jªº³Ã¥ë! ¤£ª¾¹D¥L¬O§_ÁÙ¬¡¦b³o¥@¤W©O?
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
  write("³oÃä¤£¯à¥Î put ³á, ­n©ñªF¦è½Ð§ï¥Î cput..!\n");
  return 1;
}

int do_put(string arg)
{
        string target, item;

	object me,obj,dest,*inv,obj2;
        int i, amount,active=0;
	me=this_player();


	if(!arg) return notify_fail("§A­n±N¤°»òªF¦è©ñ¶i­þ¸Ì?\n");
        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("§A­n©ñ¤°»òªF¦è¡S\n");
        if( target == "shelf" || target == "equip shelf" || target == "weapon shelf" || target == "item shelf")
		active = 1;
        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) ) return notify_fail("³o¸Ì¨S¦³³o¼ËªF¦è¡C\n");
        if( dest->is_box() )
        {
                if(!dest->can_access_box()) return notify_fail("§A¥²¶·¥ý¥´¶}"+dest->name()+"¤~¯à©ñªF¦è¶i¥h¡C\n");

        }
        if(sscanf(item, "%d %s", amount, item)==2)
        {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("§A¨­¤W¨S¦³³o¼ËªF¦è¡C\n");
                if( obj==dest ) return notify_fail("¨Ó·½©M¥Øªº¤£¯à¬O¬Û¦PªºªF¦è!\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "¤£¯à³Q¤À¶}¡C\n");
                if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"¨Ã¤£¬O¤@­Ó®e¾¹¡C\n");
                if( obj->query_max_encumbrance() && !obj->query("no_get"))
                        return notify_fail( "®e¾¹¤£¯à©ñ¨ì®e¾¹¸Ì¡C\n");
                if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "¤£¯à³Q¥á±ó¡C\n");
                if( amount < 1 )
                        return notify_fail("ªF¦èªº¼Æ¶q¦Ü¤Ö¬O¤@­Ó¡C\n");
                if( amount > obj->query_amount() )
                        return notify_fail("§A¨S¦³¨º»ò¦hªº" + obj->name() + "¡C\n");
                else if( amount == (int)obj->query_amount() )
                        return do_xput(me, obj, dest, active);
                else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if(!obj2->can_move(dest))
                        {
                                destruct(obj2);
                                return notify_fail("§A¨S¦³¿ìªk§â"+obj->query("name")+"©ñ¶i"+dest->query("name")+"¸Ì¡C\n");
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
                return notify_fail("§A¨­¤W¨S¦³³o¼ËªF¦è¡C\n");
        return do_xput(me, obj, dest, active);
}

int do_xput(object me, object obj, object dest, int func)
{
        mixed no_put;
        if( obj==dest ) return notify_fail("¨Ó·½©M¥Øªº¤£¯à¬O¬Û¦PªºªF¦è!\n");
        if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"¨Ã¤£¬O¤@­Ó®
e¾¹¡C\n");
        if( obj->query_max_encumbrance()  && !obj->query("no_get"))
                        return notify_fail( "®e¾¹¤£¯à©ñ¨ì®e¾¹¸Ì¡C\n");
        if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "¤£¯à³Q¥á±ó¡C\n");
        if( no_put = obj->query("no_drop"))
        {
                if(stringp(no_put)) return notify_fail( no_put+"\n");
                return notify_fail( "§AµLªk§â"+obj->name()+"©ñ¶i¨º¸Ì¡C\n");
        }
        if( obj->query_temp("riden") ) return notify_fail("§A¥¿¦bÃMµÛ­C!\n");
        if(!obj->can_move(dest)) return notify_fail("§A¨S¦³¿ìªk§â"+obj->query("name")+"©ñ¶i"+dest->query("name")+"¸Ì¡C\n");
	if( func ) {
		if( obj->query("skill_type") )
            dest = present("weapon shelf",environment(me));
		else if(obj->query("armor_type") )
            dest = present("equip shelf",environment(me));
        else dest = present("item shelf",environment(me));
	}
        if( obj->move(dest) )
        {
                message_vision( sprintf("$N±N¤@%s%s©ñ¶i%s¡C\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        me );
//                message_vision("\nFUNC: "+func+"\n",me);
                if(dest->query("access_log")) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                return 1;
        }
        else return 0;
}
