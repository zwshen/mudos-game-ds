#include <ansi.h>
inherit ITEM;
//int do_put(object me,string arg);
int do_xput(object me, object obj, object dest, int func);
void create()
{
    set_name(HIG"ªZ¾¹³¯¦C¬["NOR,({"weapon shelf","shelf"}));
        set("unit", "­Ó");
        set("long",@LONG

  ¤@­Ó¥Î¨Ó©ñ¸m«O¦s²³¦hªZ¾¹ªºÅK¬[¡C§A¥i¥H§â¬Ã¶QªºªZ¾¹©ñ¦b¬[
  ¤W«O¦s©Î¬O±q¬[¤l¤¤®³¥X§A©Ò³ß·RªºªZ¾¹¡C

  ©ñªF¦è: put [ªF¦è] in weapon shelf
  ®³ªF¦è: get [ªF¦è] from weapon shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(10000);
        setup();
}

void init()
{
        add_action("do_put", "put");
}

int do_put(string arg)
{
        string target, item;

        object me, obj, dest, *inv, obj2;
        int i, amount,active=0;
	me = this_player();

        if(!arg) return notify_fail("§A­n±N¤°»òªF¦è©ñ¶i­þ¸Ì¡S\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("§A­n©ñ¤°»òªF¦è¡S\n");
	if( target == "shelf" || target == "equip shelf" || target == "weapon shelf" || target ==
	    "item shelf" || target == "shelf 1" || target == "shelf 2" || target == "shelf 3" )
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
	if( obj->query("equipped") ) return notify_fail( obj->name() + "¥¿³Q§A¸Ë³ÆµÛ, ¤£¯à©ñ¨ì®e¾¹¸Ì¡C\n");
        if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"¨Ã¤£¬O¤@­Ó®
e¾¹¡C\n");
        if( obj->query_max_encumbrance()  && !obj->query("no_get"))
                        return notify_fail( "®e¾¹¤£¯à©ñ¨ì®e¾¹¸Ì¡C\n");
  if( obj->query("no_put")) return notify_fail("³oªF¦è¤£¯à©ñ¨ì®e¾¹¸Ì¡C\n");  // add by wilfred
        if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "¤£¯à³Q¥á±ó¡C\n");
        if( no_put = obj->query("no_drop"))
        {
                if(stringp(no_put)) return notify_fail( no_put+"\n");
                return notify_fail( "§AµLªk§â"+obj->name()+"©ñ¶i¨º¸Ì¡C\n");
        }
        if( obj->query_temp("riden") ) return notify_fail("§A¥¿¦bÃMµÛ­C!\n");
        if(!obj->can_move(dest)) return notify_fail("§A¨S¦³¿ìªk§â"+obj->query("name")+"©ñ¶i"+dest->query("name")+"¸Ì¡C\n");
	if( obj->query("secured") ) return notify_fail("§AµLªk±N³]©w¬°«O¦sª¬ºAªºª««~©ñ¶i®e¾¹¤¤.\n");
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
                if(dest->query("access_log")) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                return 1;
        }
        else return 0;
}
