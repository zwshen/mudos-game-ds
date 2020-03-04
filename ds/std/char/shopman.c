//�зǰӤH�~����(���s�q��)	- by Luky -
//
//	�u�nNPC�~�Ӧ���, �Y�i�Q�ΥH�U�覡�ܦ��ӤH
//
// void init() 
// {
//   add_action("do_sell","sell");
//   add_action("do_list","list");
//   add_action("do_buy" ,"buy");
// }
// 
//  1. �o�̪� do_sell,do_list,do_buy�O�T�w��, ���O�᭱�����O�r��i�H�ۭq.
//  2. �H���ݭn�]�@�ӼȦs�f�����ж�, �� set("storeroom","���|�ɦW"); �]�w��.
//     �ɦW���Υ[".c".
//  3. ����Ȧs�f���ж����g�k�Ѧ� /u/l/luky/shop.c
//  4. list �i�H��< list wp > �C�X�Z��.< list eq >�C�X����.
//  5. �i�Ϋ��O�Ѽ�:
//		"  �ݦs�f�Х� <list>      <list wp>       <list eq>       "
//		"  �n�R�F��� <buy ���~>  <buy �ƶq ���~>                 "
//		"  �n��F��� <sell ���~> <sell all>      <sell �ƶq ���~>"
//
// �W�[�լ�\�� (�`�N�ק�)
#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
object stroom;
string args;
int sort_item(object ob1, object ob2);
void create()
{
	seteuid(getuid());
}

string item_list(object ob,int amount,object ppl,int rule)
{
	if(rule) 
	{
	   return sprintf("  %4d%-4s  %8d .......... %s\n",
	   amount,ob->query("unit"),ob->query("value"),ITEM_D->item_desc(ob,ppl));
	} else
	{
       return sprintf("  %4d      %8d .......... %s  [���p��%d%%] \n",
       amount,ob->query("value"),ITEM_D->item_desc(ob,ppl),ob->query_durable());
	}
}

int do_sell_all(object me)
{
	object *inv,*goods;
	int i,money,world,cost;
	money=0;
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{
	if( !inv[i] ) continue;
	 if( inv[i]->query("value")<20 ) continue;
	 if( inv[i]->query("secured") ) continue;
	 if( inv[i]->query("equipped") ) continue;
	 if( inv[i]->query("money_id") ) continue;
	 if( inv[i]->query("no_drop") ) continue;
	 if( inv[i]->query("no_sell") ) continue;
	 if( inv[i]->is_character() ) continue;

     cost = (inv[i]->query("value") * (70+random(10)) / 100) * inv[i]->query_durable() / 100;
	 message_vision("  $N�H"+cost+"�������N"+inv[i]->name()+"�浹�F$n�C\n",me,this_object());
	if( me->receive_money(cost) == cost ) 
	{
		inv[i]->move(stroom);
		money+=cost;
	}
	// �H�W��Y����bug fix��by alickyuen@ds
	}
	if(money<1)
	{
		tell_object(me,"  �A�S���F��i�H��F�C\n");
		return 1;
	}
	world = me->money_type();
	if(world!=3) tell_object(me,"\n  �A�@��o"+price_string(money,me->money_type())+"�C\n");
	else tell_object(me,"�A���s�ڱb���W�[�F"+money+"�ӳ��q�l���C\n");
	goods = all_inventory(stroom);
	if(sizeof(goods)>100)
	{
		for(i=100;i<sizeof(goods);i++)	destruct(goods[i]);
	}
	me->save();
	return 1;
}


int do_sell(string arg)
{
	object ob,*inv,obj,ob1,ob2,me,*goods;
	string item,who;
	int valu,i,amount,world;
	me=this_player();
	load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	if(!arg) return notify_fail("�A�n�椰��F��H\n");
	if(sscanf(arg,"%s to %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
	}
	if(sscanf(arg,"%d %s",amount,item)==2) // AMOUNT
	{
	  if(amount<1) return notify_fail("�A�n��X�ӰڡH\n");
	  if(amount>10) return notify_fail("�@���̦h��Q�ӡC\n");
	  for(i=0;i<amount;i++)
	  {
	  	do_sell(item);
	  }
	 return 1;
	} //END of AMOUNT

	if(arg=="all")
 	{
		do_sell_all(me);
		return 1;
 	}
	 if(!ob=present(arg,me))
 	 return notify_fail("�A�S���o�˪F��C\n");
 	 valu=ob->query("value");
 	 if( ob->query("money_id") )
 		return notify_fail("��..���? �ڤ����H�~�����C\n");
 	 if( valu<20 )
		 return notify_fail("�o�F�褣�ȿ��C\n");
 	 if(ob->query("secured"))
 		return notify_fail("�Х��Ѱ��O�s���A�C\n");
 	 if( ob->query("no_drop") )
 		return notify_fail("�o�ӪF��ܯS�O, �A�٬O�ۤv�O�ަn�F�C\n");
 	 if( ob->query("no_sell"))
 		return notify_fail("�ڤ����ʳo�تF��C\n");
 	if( ob->is_character() ) return notify_fail("�ڤ����ʬ����F��C\n");
 	 if(ob->query("equipped"))
 		return notify_fail("�Х������U�Ӧn�ܡH\n");

	arg = ob->query("id");
    valu = (valu * (70+random(10)) / 100) * ob->query_durable() / 100;
	if( me->receive_money(valu) != valu ) return 1;
	world = me->money_type();
	if(world!=3) message_vision("$N��F�@"+ob->query("unit")+ob->query("name")+"��$n, $n���F$N"
		+price_string(valu,me->money_type())+"�C\n",me,this_object());
	else message_vision("$N��F�@"+ob->query("unit")+ob->query("name")+"��$n, $n�N"
		+valu+"�ӳ�쪺�q�l���s�J$N���b�������C\n",me,this_object());
	ob->move(stroom);
	goods = all_inventory(stroom);
	if(sizeof(goods)>100)
	{
		for(i=100;i<sizeof(goods);i++)	destruct(goods[i]);
	}
	me->save();
	return 1;
}

int do_list(string arg)
{
	object *goods,stroom,me;
	string list,who;
	int i,amount,k;
	me=this_player();
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	stroom->set("stroom",1);
	amount = 1;
	k=1;
	//stroom=find_object(this_object()->query("storeroom"));
    if(arg && sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
    } else if(arg && sscanf(arg,"from %s",who)==1)
	{
		if(!this_object()->id(who)) return 0;
		arg="";
	}
	goods = all_inventory(stroom);
	//goods = F_QUANTITY->sortinv(stroom);
	list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
	list +="�x  �s�q      ��  ��            ����  �ثe�i�H�ʶR���f�~�M��    �x\n";   
	list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
	if(stringp(arg))
	{
	  list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
	  list +="�x  �s��      ��  ��            ����  �ثe�i�H�ʶR���f�~�M��    �x\n";   
	  list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
		for(i=0; i<sizeof(goods); i++)
		{
			if(goods[i]->id(arg))
			{
				list += item_list(goods[i],k,me,0);
				k++;
			}
		}
			list +="\n";	
			if(i==0) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�f���槹�F�C\n");
			else me->start_more(list);
			return 1;
	}
	goods = sort_array(goods, "sort_item", this_object());
	for(i=0; i<sizeof(goods); i++)
	{
	 if( i+1 < sizeof(goods) )
	 {
	  if( base_name(goods[i])==base_name(goods[i+1]) )
	  	amount++;
	  else 
	  {
	    list+= item_list(goods[i],amount,me,1);
	    amount = 1;
	  }
	 } else
	 {
	    list+= item_list(goods[i],amount,me,1);
	 }
	}
	list +="\n";
	if(i==0) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�f���槹�F�C\n");
	else me->start_more(list);
	return 1;	
}

int do_buy(string arg)
{
	int amount,valus,i,world;
	object *goods,ob,me;
	string item,who;
	
	me=this_player();
	
	if(!arg) return notify_fail("�A�n�R����F��H\n");
	if(sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
	}
	load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	goods = all_inventory(stroom);
	if(sscanf(arg,"%d %s",amount,item)==2)
	{
	 if(amount < 1) return notify_fail("�ܤ֭n�R�@�ӧa�C\n");
	 if(amount >10) return notify_fail("�@���̦h�u��R�Q�ӡC\n"); //�קK�j��L��
	 for(i=0;i<amount;i++)
	 {
	  do_buy(item);
	 }
	 return 1;
	}
	
	if(ob=present(arg,stroom))
	{
	  if( (ob->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )   
 		return notify_fail("�A�����ʳo�ӪF��F�C\n");
 	  if( (int)me->query_capacity() + (int)ob->query("volume") > (int)me->query_max_capacity() )
 		return notify_fail("�A���W�񤣤U�o��h�F��C\n");
 	  if(!me->can_afford(ob->query("value")))
		return notify_fail("�A���W���������C\n");
	  valus=ob->query("value");
	  me->receive_money(-valus);
	  world = me->money_type();
	  if(world!=3) message_vision("$N�I�F$n"+price_string(valus,me->money_type())+", $n�ߨ讳�F�@"+ob->query("unit")+ob->name()+"��$N�C\n",me,this_object());
	  else message_vision("$N�ǰe�F"+valus+"�ӳ�쪺�q�l����$n, $n�ߨ讳�F�@"+ob->query("unit")+ob->name()+"��$N�C\n",me,this_object());
	  ob->move(me);
	  stroom->save();
	  me->save();
	  return 1;
	}
	else return notify_fail("�A�Q�n�R�����??\n");
}

int do_try(string arg)
{
	object goods,me;
	string who;
	me=this_player();
	if(!arg) return notify_fail("�A�n�դ���F��H\n");
	if(sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
	}
	load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	goods = present(arg,stroom);
	if(!goods) return notify_fail("�S����o�ӪF��C\n");
	if(goods->query("skill_type")) //weapon
	{
		if(me->query("race")!="human")
		{
			if(!goods->query(me->query("race")+"_weapon_prop"))
			{
				return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
			}
		} else
		if(!goods->query("weapon_prop"))
		{
			return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
		}
	if( goods->query("female_only")	&& (string)me->query("gender") != "�k��" )
		return notify_fail(goods->name()+"�O�k�H�M�Ϊ��Z���C\n");
	if( goods->query("male_only") && (string)me->query("gender") != "�k��" )
		return notify_fail(goods->name()+"�O�k�H�M�Ϊ��Z���C\n");
	if( goods->query("limit_lv") > me->query("level") )
		return notify_fail("�A�����ŤӧC�A�L�k�˳�"+goods->name()+"�C\n");
	if( goods->query("limit_con") > me->query_con() )
		return notify_fail("�A���髬�����A�L�k�˳�"+goods->name()+"�C\n");
	if( goods->query("limit_str") > me->query_str() )
		return notify_fail("�A���O�q�����A������"+goods->name()+"�C\n");
	if( goods->query("limit_int") > me->query_int() )
		return notify_fail("�A�����o���A�����o���ϥ�"+goods->name()+"�C\n");
	if( goods->query("limit_dex") > me->query_dex() )
		return notify_fail("�A�յ۸˳�"+goods->name()+"�A�i�O�A�����ӺC�F���p�ߥ���ۤv�C\n");
	if( goods->query("limit_skill") > me->query_skill((string)goods->query("skill_type"),1) )
		return notify_fail("�A���ըϥ�"+goods->name()+"�A�i�O�A���ޥ������C\n");
		
		write("�A�յۨϥ�"+goods->name()+"���Z���A�Pı�_���٤����C\n");
		return 1;
	}
	 else if(goods->query("armor_type"))
	{
		if(me->query("race")!="human")
		{
			if(!goods->query(me->query("race")+"_armor_prop"))
			{
				return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
			}
		} else
		if(!goods->query("armor_prop"))
		{
			return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
		}
		if( goods->query("female_only")
		&&	(string)me->query("gender") != "�k��" )
			return notify_fail(goods->name()+"�O�k�ʱM�Ϊ��˳ơC\n");
		if( goods->query("male_only")
		&&	(string)me->query("gender") != "�k��" )
			return notify_fail(goods->name()+"�O�k�ʪ��M�θ˳ơC\n");
		if( goods->query("limit_lv") > me->query("level") )
			return notify_fail("�A�����ŤӧC�A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_con") > me->query_con() )
			return notify_fail("�A���髬�����A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_str") > me->query_str() )
			return notify_fail("�A���O�q�����A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_int") > me->query_int() )
			return notify_fail("�A�����o���A�����o���˳�"+goods->name()+"�C\n");
		if( goods->query("limit_dex") > me->query_dex() )
			return notify_fail("�A�Q�n�˳�"+goods->name()+"�A�i�O�A�ʧ@�C�]�]���A�藍�W�h�C\n");
		if( goods->query("max_lv") < me->query("level") && goods->query("max_lv")>1)
			return notify_fail(goods->name()+"�O�C���űM�Ϊ��˳ơC\n");
		
		write("�A�յ۸˳�"+goods->name()+"�A�Pı�ܦX���C\n");
		return 1;
	}
	return notify_fail("�A�Q�ե�"+goods->name()+"�A�u��"+this_object()->name()+"�ܺôb���ݵۧA�C\n");
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int is_shopman()
{
	return 1;
}