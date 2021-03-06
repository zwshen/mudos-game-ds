/*
  Name: /cmds/std/wield.c
  Copyright: DS
  Author/Modify: Alickyuen
  Date: 04/08/05 01:24
  Description: 
*/

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
        object ob, *inv;
//		object old_wp;
//		string str,gender;
        int i, count;
        if(me->is_busy() || me->is_block())
                return notify_fail("你的上一個動作還沒完成。\n");
        if( !arg ) return notify_fail("你要裝備什麼武器﹖\n");

        if(arg=="all") {
                inv = all_inventory(me);
                for(count=0, i=0; i<sizeof(inv); i++) {
                        if( inv[i]->query("equipped") ) continue;
                        if(do_wield(me, inv[i]) ) count ++;
                }
                write("Wield all OK!!\n");
                return 1;
        }

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上沒有這樣東西。\n");

        if( ob->query("equipped") )
                return notify_fail("你已經裝備著"+ob->name()+"了。\n");
        
//		測試: 自動卸除原先的武器
//		拿掉放到/feature/equip.c 在這裡設定會不能裝副手武器
//		-Alickyuen@DS 2005 Aug 3
// 
//        if( old_wp = me->query_temp("weapon") )
//        {
//            if(old_wp->unequip() )
//            {
//                if( !stringp(str = old_wp->query("unwield_msg")) )
//                        str = "$N放下手中的$n。\n";
//                if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, old_wp);
//                else
//                {       
//                        if(me->query("gender")=="女性") gender="妳";
//                        else gender="你";
//                        str=replace_string( str, "$N", gender);
//                        str=replace_string( str, "$n", old_wp->name());
//                        tell_object(me,str);
//                }
//            }
//        }
        return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
        string str, gender;
        mapping class_c;
        int i, j=0;

        if( (arrayp(class_c = ob->query("class_only")) || stringp(class_c = ob->query("class_only"))) && me->query("class1") != "adventurer" )
        {
          if(arrayp(class_c))
            for(i=0; i<sizeof(class_c); i++)
            {
              if(me->query("class1") != class_c[i]) continue;
              j++;
            }

          if(stringp(class_c))
            if(me->query("class1") == class_c) j++;

          if(!j) return notify_fail("你試著裝備"+ob->name()+"，但此武器與你所學不合而無法裝備。\n");
        }


        if( ob->query("female_only")
        &&      (string)me->query("gender") != "女性" )
                return notify_fail(ob->name()+"是女人專用的武器。\n");
        if( ob->query("male_only")
        &&      (string)me->query("gender") != "男性" )
                return notify_fail(ob->name()+"是男人專用的武器。\n");
        if( ob->query("limit_lv") > me->query("level") )
                return notify_fail("你的等級太低，無法裝備"+ob->name()+"。\n");
        if( ob->query("limit_con") > me->query_con() )
                return notify_fail("你的體型不夠，無法裝備"+ob->name()+"。\n");
        if( ob->query("limit_str") > me->query_str() )
                return notify_fail("你的力量不夠，拿不動"+ob->name()+"。\n");
        if( ob->query("limit_int") > me->query_int() )
                return notify_fail("你不夠聰明，不懂得怎麼使用"+ob->name()+"。\n");
        if( ob->query("limit_dex") > me->query_dex() )
                return notify_fail("你試著裝備"+ob->name()+"，可是你反應太慢了不小心打到自己。\n");
	if( ob->query("limit_mks") > me->query("MKS") ) 
		return notify_fail("你的殺氣不夠應付這件東西。\n");
        if( ob->query("limit_skill") > me->query_skill((string)ob->query("skill_type"),1) )
                return notify_fail("你嘗試使用"+ob->name()+"，可是你的技巧不夠。\n");
                
        if( ob->wield() )
        {
                if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N裝備$n作武器。\n";
                if(me->query_temp("hide")+me->query_temp("invis")<1) message_vision(str, me, ob);
                else
                {       
                        if(me->query("gender")=="女性") gender="妳";
                        else gender="你";
                        str=replace_string( str, "$N", gender);
                        str=replace_string( str, "$n", ob->name());
                        tell_object(me,str);
                }
        if(me->is_fighting()) me->add_block(1);
                return 1;
        } else
                return 0;
}

int help(object me)
{
        write(@HELP
指令格式﹕wield <裝備名稱>
 
這個指令讓你裝備某件物品作武器, 你必需要擁有這樣物品.
 
HELP
    );
    return 1;
}

