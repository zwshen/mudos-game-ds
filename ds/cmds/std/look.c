// look.c
#include <room.h>
#include <ansi2.h>

inherit F_CLEAN_UP;

int can_look(object env); //new
varargs int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
int light_inventory(object me); //·|µo¥úªºªF¦è
varargs string room_describe(object me,object env);  //new
string show_item_status(object ob);
int sort_item(object ob1, object ob2);
string process_item(object me,object *inv);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string where,target;
        object obj,bag;
        int result;

	//¦pªG¥[°Ñ¼Æ..
	if(arg=="on")
	{
		me->delete("env/brief");
		write("±z±NÅã¥Ü¼Ò¦¡³]¬°"HIY"¥¿±`¼Ò¦¡\n"NOR);
		return 1;
	}
 
	if(arg=="off")
	{
		me->set("env/brief",1);
		write("±z±NÅã¥Ü¼Ò¦¡³]¬°"HIY"Â²²¤¼Ò¦¡\n"NOR);
		return 1;
	}

	//¥¼¥[°Ñ¼Æ,ªí¥Ü¬Ý¥Ø«e©Ð¶¡

        if( !arg ) return look_room(me, environment(me));

	if(!can_look(environment(me)))
		return notify_fail("§Aªº¥|©P¶Âº£º£ªº¤@¤ù..¤°»ò¤]¬Ý¤£¨£!\n");


	if(sscanf(arg,"%s in %s",target,where)!=2)
	{
	// §_«h
	// present(arg, me):§ä´M¦Û¤v¨­¤Wªº¤º§tª« (first)
	// present(arg,environment(me)):§ä´M¥Ø«e©Ð¶¡¤ºªºªF¦è (later)
		if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
		{
                        if( !obj->is_character() ) result = look_item(me, obj);        //¬Ýª«
                        else result = look_living(me, obj);                               //¬Ý¥Íª«
		}
		else result = look_room_item(me, arg);			//¬Ý©Ð¶¡ª«
	}
	else
	{
		if(where=="here")
		{
			result = look_room_item(me, target);			//¬Ý©Ð¶¡ª«
		}
		else if(where=="me")
		{
			if( obj = present(target, me) )
			{
				if( obj->is_character() ) result = look_living(me, obj);	//¬Ý¤H
				else result = look_item(me, obj);				//¬Ýª«
			}
			else return notify_fail("§A¨­¤W¨S¦³³o­ÓªF¦è¡C\n");
		} 
		else if( (bag = present(where, me)) || (bag = present(where, environment(me))))
		{
			if(bag->is_character() && bag!=me && !wizardp(me))
				return notify_fail("¥u¦³§Å®v¤~¥i¥H¬Ý¥L¤H¨­¤WªºªF¦è¡C\n");

			if( obj = present(target, bag) )
			{
				if( obj->is_character() ) result = look_living(me, obj);	//¬Ý¤H
				else result = look_item(me, obj);				//¬Ýª«
			} else return notify_fail("¨º¸Ì­±¨S¦³³o­ÓªF¦è¡C\n");
		}
		else return notify_fail("[look«ü¥O]:§ä¤£¨ì"+where+"¡C\n");
	}
	return result;
}


int can_look(object env) 
{
	object *inv;
	
        if(!env) return 0;
	if(env->light()) return 1;	//¦³³]·Ó©ú

	inv = all_inventory(env);

	// ¥H¤Uµ{¦¡¥Ñ shengsan Â²¤Æ¤F ..Luky ¦AÂ²¤Æ¤@¦¸..:P
	if( env->query("outdoors") && NATURE_D->query_light() > 1) return 1;	//¤á¥~¥Õ¤Ñ

  	return 0;
}

varargs string room_describe(object me,object env)
{
         int i,j,k;
	object *inv,*items;
	mapping exits,doors;
	string str, *dirs,and,vision_color,long_desc,short_desc,*door_dir;

	if( !env )
	{
		return"ªÅµê¤§¤¤¡A¥u¨£¤@¤ù¶Â·t¡C\n";
        }
/*
	//Åã¥Ülookµ²ªG 
	if(env->is_house())
	{
		long_desc=env->query_long(1);
		short_desc=env->query_short(1);
	}
	else
	{
		long_desc=env->query_long(1);
		if(!long_desc) long_desc=env->query_temp("long");
		if(!long_desc) long_desc=env->query("long");
		short_desc=env->query_short(1);
		if(!short_desc) short_desc=env->query("short");
	}

*/		long_desc=env->query_long(1);
		if(!long_desc) long_desc=env->query_temp("long");
		if(!long_desc) long_desc=env->query("long");
		short_desc=env->query_short(1);
		if(!short_desc) short_desc=env->query("short");
	if(!can_look(env) )
	{
				
		if(!env->query("outdoors")) 
		{
		  write(short_desc+"\n\n");
		  return "[1;30m  §Aªº¥|©P¶Âº£º£ªº¤@¤ù..¤°»ò¤]¬Ý¤£¨£![0m\n\n\n";
		}
		if(NATURE_D->query_light()==1) vision_color = CYN;
		else vision_color = HIB;
		
		//write(HIW+"§AÄ±±o¦³ÂI©ü·t\n"+NOR);
		str = sprintf(" %s - %s\n    %s%s%s",
				short_desc,
				(wizardp(me) && !me->query_temp("out_of_power"))? file_name(env): "",
				vision_color,	//add by Luky.
				long_desc+NOR,
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" 
			);
		if( me->query("level")<3 )
		{
			if(random(2)) str+=HIY+"[·s¤â´£¥Ü:] ¥ú½u¤£¨¬±N¬Ý¤£²M·¡³o¸ÌªºªF¦è©M¥X¤f¡A§ä¨Ç·|µo¥úªºªF¦è§a¡C\n"+NOR;
			else if(random(2)) str+=HIY+"[·s¤â´£¥Ü:] ¦h¨Ï¥Îmap«ü¥O¥i¥HÀ°§U§A¤F¸Ñ¦a§Î¡C\n"+NOR;
		}
                  str += NOR""; //«ì´_ÃC¦â
		if( mapp(exits = env->query("exits")) )
		{
			dirs = keys(exits);
			if( sizeof(dirs)==0 )
				str += "    ³o¸Ì¨S¦³¥ô¦ó©úÅãªº¥X¸ô¡C\n";
			else
				str += "    ³o¸ÌÁô¬ùªº¥X¤f¬O " +  dirs[0] + NOR + "¡C\n";
		} 
		else str += "    ³o¸Ì¨S¦³¥ô¦ó©úÅãªº¥X¸ô¡C\n";
		return str;
	}
	
	str = sprintf( "%s - %s\n    %s%s%s",
		short_desc, 			//Â²µu´y±Ô
		(wizardp(me) && !me->query_temp("out_of_power"))? file_name(env): "", 	//ÀÉ®×¦WºÙ
		long_desc,			//¸Ô²Ó´y±Ô
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "",
		env->query("outdoors")? NATURE_D->outdoor_room_weather_status(env) : ""  //¤Ñ®ð§Î®e
//		""
		);
	if( mapp(exits = env->query("exits")) )
	{
		dirs = keys(exits);
		if(doors=env->query_doors())
		{
			door_dir=keys(doors);
			for(i=0; i<sizeof(door_dir); i++)
			{
				if( (int)env->query_door(door_dir[i], "status") == DOOR_LOCKED )
				{
					str +="    " + to_chinese(door_dir[i])+"Ãäªº"+env->query_door(door_dir[i], "name")+"¬O"+HIR+"Âê"+NOR+"µÛªº¡C\n";
					dirs[i] = 0;
				}
				else if( (int)env->query_door(door_dir[i], "status") == DOOR_CLOSED )
				{
					str += "    " + to_chinese(door_dir[i])+"Ãäªº"+env->query_door(door_dir[i], "name")+"¬O"+HIW+"Ãö"+NOR+"µÛªº¡C\n";
					dirs[i] = 0;
				}
				else if( (int)env->query_door(door_dir[i], "status") == DOOR_OPENED )
				{
					str += "    " + to_chinese(door_dir[i])+"Ãäªº"+env->query_door(door_dir[i], "name")+"¬O¶}µÛªº¡C\n";
				}
			}
		}
		dirs -= ({ 0 });
                  str += NOR""; //«ì´_ÃC¦â
		if( sizeof(dirs)==0 )
			str += "    ³o¸Ì¨S¦³¥ô¦ó©úÅãªº¥X¸ô¡C\n";
		else if( sizeof(dirs)==1 )
			str += "    ³o¸Ì°ß¤@ªº¥X¤f¬O " +HIW+  dirs[0] + NOR + "¡C\n";
		else
		{
			str += sprintf("    ³o¸Ì©úÅãªº¥X¤f¬O ");
			k=sizeof(dirs);
			if(k>2) and="¡B";
				else and="";
			for(i=0;i<k-2;i++)
			{
				str +=HIW+dirs[i]+NOR+"¡B";
			}
			str +=HIW+dirs[k-2]+" ©M "+dirs[k-1]+NOR+"¡C\n";
		}
	} else str += "    ³o¸Ì¨S¦³¥ô¦ó©úÅãªº¥X¸ô¡C\n";
	if( mapp(exits = env->query("hide_exits")) &&  wizardp(me) )
	{
		dirs = keys(exits);
		if(sizeof(dirs)!=0)
		for(i=0; i<sizeof(dirs); i++)
		{
			if( (int)env->query_door(dirs[i], "status") == DOOR_LOCKED )
				dirs[i] = 0;
			else if( (int)env->query_door(dirs[i], "status") == DOOR_CLOSED )
				dirs[i] = 0;
		}
		dirs -= ({ 0 });
		k=sizeof(dirs);
		if( k==0 )
			str += "";
		else if( k==1 )
			str += "    [32m(§Å®v) ÁôÂÃªº¥X¤f¬O " +  dirs[0] + "¡C[0m\n";
		else
		{
			str += sprintf("    [32m(§Å®v) ³o¸ÌÁôÂÃªº¥X¤f¦³ ");
			for(i=0;i<k-2;i++)
				str +=dirs[i]+"¡B";
			str += dirs[k-2]+" ©M "+dirs[k-1]+"¡C[0m\n"+NOR;
		} 
	}
	j=1;	//add by luky
	items = all_inventory(env);
	if(sizeof(items)>110)
	{
		str+=HIC"\n  ³o¸ÌªF¦è¤Ó¦h¤F¡A§A³s¦Û¤v¦b­þ¸Ì³£¤£ª¾¹D¤F¡C\n\n"NOR;
		return str;
	}
	//inv = F_QUANTITY->sortinv(env);	// add by shengsan for sort env
	
	inv = sort_array(items, "sort_item", this_object());
	k=sizeof(inv);
	if(k>90)
	{
			for(i=0; i<k; i++)
			{
				if(inv[i]->is_character())
				{
				 if(me!=inv[i] && me->visible(inv[i]) ) str+="  "+show_item_status(inv[i]);
				}
			}
			str+=HIW"\n  ³o¸Ì¨ì³B³£¬OªF¦è¡A¤@®É¤§¶¡«ÜÃø¬Ý¥J²Ó¡C\n\n"NOR;
			return str;
	}
	else 
	{
		str+=process_item(me,inv);
		return str;
	}
}

varargs int look_room(object me, object env)
{
	string str;
	if(!stringp(str=room_describe(me,env))) write("³o¸Ì¤@¤ù¶ÂÀÛÀÛªº¡A§A¤°»ò³£¬Ý¤£¨ì¡C\n");
	else write(str);
	return 1;
}


string show_item_status(object ob)
{
	object me,ride_ob;
	string str="",ride_type,desc;

	me = this_player();
	if(!ob) return "";
	if(ob->is_character())
	{
        if( !userp(ob) && NEWQUEST_D->hasQuest(me, ob) ) str += BLINK+HIY"¡I"NOR;
		if(ob->query_temp("killer")) str +=HIR+ "[±þ¤H¥Ç]"+NOR;
		if(ob->is_ghost() ) str += HIB+"(°­»î)"+NOR;
		if(wizardp(me) && ob->query_temp("invis")) str += "[1;33m(Áô¨­)[0m";
		else {
			if( me->visible(ob) && ob->query_temp("invis") ) str += "[1;32m(Áô¨­)[0m";
	     	     }
	     	     
		if(ob->query_temp("hide") ) str +=HIB+ "(ÂÃ°Î)"+NOR;
		if(ob->query_temp("stone") ) str +=HIW+ "(¥Û¤Æ)"+NOR;
		if(ob->query_temp("freeze") ) str +=HIW+ "(¦B­á)"+NOR;
		str += "" + ob->short();

		if( ob->query_temp("sleeping") ) str +=" ¥¿¦b³o¸ÌºÎÄ±";
		else if( ob->query_temp("float") ) str +=" ¥¿º}¯B¦bªÅ¤¤";
		else if( ob->query_temp("fly") ) str +=" ¥¿¦bªÅ¤¤­¸µÛ";
		else if(objectp(ride_ob=ob->query_temp("ride"))) //¦Û­qÃM­¼Åã¥Ü
		{
			if(ride_type=ride_ob->query("ride_type")) str +=ride_type;
			else str +=" ¥¿ÃM¦b"+ride_ob->name()+"¤W";
		} else if(living(ob))
			{
            if(ob->query_temp("define_look")) str += ob->query_temp("define_look");
            else {                   
            		if( ob->query("race")=="beast") str +="";
                   else if( ob->query("race")=="human") str+=" ¥¿¯¸¦b³o¸Ì";
                   else str+=" ¥¿¦b³o¸Ì";
                 }
			}

		if( ob->query_temp("netdead") ) str += HIG " <Â_½u¤¤>" NOR;
		if( in_input(ob) ) str += HIC " <¿é¤J¼Ò¦¡>" NOR;
		if( in_edit(ob) ) str += HIY " <½s¿èÀÉ®×>" NOR;
		if( interactive(ob) && query_idle( ob ) > 120 ) str += HIM " <µo§b¤¤>" NOR;
        if( ob->is_inactive() ) str += HIW " [¶¢¸m¼Ò¦¡]" NOR;

	}
	else if(ob->is_vehicle())	// by Shengsan
	{
		str += ob->name()+"("+capitalize(ob->query("id"))+")";
	}
	else
 	{
 		str += "" + ob->short();
 		
 	}
	
       if(desc=ob->query("status_desc")) str+=" "+desc; // ¥û¤â©Îª¬ºA

	str +="\n";

	return str;
}
// ¦pªG¦³·|µo¥úªºªFªF return 1
// else 0

int light_inventory(object me)
{
	object *inv;
	int i,p;

	inv=all_inventory(me);
	p=sizeof(inv);
	if(!p) return 0;    //¨S¦³ªFªF
	for(i=0;i<p;i++)
	{
		if(inv[i]->query("is_light")) return 1;
	}
	return 0;
}


int look_item(object me, object obj)
{
	string str;
	object *inv;

	tell_room(environment(me),me->name()+"¥¿­Y¦³©Ò«äªº¬ÝµÛ"+obj->name()+"¡C\n",({me}));
	if(obj->outside_vision(me)) return 1;
//	if( obj->is_vehicle() && stringp(obj->query("vlong")) )		// by Shengsan
//		str = obj->query("vlong");
//	else
	str=obj->long();
	if(obj->is_box()) str+=obj->show_cover_status();
	me->start_more(str);
	inv = all_inventory(obj);
	//¥H¤W·s¼Wby Luky
	if( sizeof(inv) && !obj->is_house())
	{
//		inv = map_array(inv, "inventory_look", this_object() );
//		message("vision", sprintf("¸Ì­±¦³¡R\n  %s\n",
//		implode(inv, "\n  ") ), me);
		if(obj->is_box())
		{
			if(obj->can_access_box())  message("vision", sprintf("¸Ì­±¦³¡R\n%s\n",process_item(me,inv)), me);
		}
		else message("vision", sprintf("¸Ì­±¦³¡R\n%s\n",process_item(me,inv)), me);
	}
	return 1;
}


int look_living(object me, object obj)
{
          string str, pro, gender,*spell,name,ob_name;
        mixed *inv;
          mapping spells;
        if(!wizardp(me))
        {
	  if( !me->visible(obj))
		return notify_fail("§A­n¬Ý¤°»ò?\n");
        }
        name = me->name();
        ob_name=obj->name();
	if(me->query_temp("hide")+me->query_temp("invis") < 1 )
	{
		if( me!=obj )
		{
		 	message("vision", name + "¬nµÛÀY, ¤W¤U¥´¶q¤F§A¤@²´¡C\n", obj);
		        tell_room(environment(me),name +"¥¿¤W¤U¥´¶qµÛ"+ ob_name +"¡M¤£ª¾¹D¦b¥´¤°»ò¥D·N¡C\n",({me,obj}));
		}
		else
		{
			switch(me->query("race"))
			{
				case "robot":
						gender="¥¦";
						break;
				case "zerg":
				case "beast":
				case "monster":
						gender= "¨e";
						break;
				case "human":
				case "evil":
                case "tiger":
                case "titan":
				case "ogre":
				case "protoss":
				case "meda":
	  					if(me->query("gender")=="¤k©Ê") gender = "¦o";
	  					else gender = "¥L";
	  					break;
	  			default:
	  				gender = "¥L";
	  		}
			tell_room(environment(me),name +"¥¿¦bÀË¬d"+gender+"¨­¤Wªº¸Ë³Æ¡C\n",({me}));
		}
	}
	//=====¥H¤W·s¼Wby Luky======
	str = obj->short()+"¡C\n";
	if(stringp(obj->query("long"))) str += obj->long();
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	
    str += sprintf("%s¬Ý°_¨Ó¬ù%s·³¥ª¥k¡A¬°"HIY"%s¯Å"NOR"ªº"HIG"%sºØ±Ú"NOR"¡A§ðÀ»¯À½è¬°"HIY"%s"NOR"¡C\n", 
    	pro, 
		chinese_number(obj->query("age")) ,
		chinese_number(obj->query("level")) ,
		to_chinese(obj->query("race")),
		to_chinese(COMBAT_D->query_attack_merits(obj))
    );

	if( obj->query("hp") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("hp") * 100 / (int)obj->query("max_hp")) + "\n";

	if(obj->query_condition("blooding"))
		str += HIM+pro+"¨­¤WÁÙ¦³³\\¦h¶Ë¤f¡A¥¿¦b¬yµÛ¦å¡C\n"NOR;

        inv = all_inventory(obj);
        if( sizeof(inv) )
	{
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%sªº¿òª«¦³¡R\n%s\n" : "\n  %s¨­¤W±aµÛ¡R\n\n%s\n\n",
                                pro, implode(inv, "\n") );
        }
 
 	if( mapp(spells=obj->query_temp("spell")) )	//luky ·s¼W for magic
 	{
          spell = keys(spells);
 	  if(sizeof(spell)) str += "\n\n  "+pro+"¨­¤Wªº¯S®í®ÄªG¦³: \n\n";
 	  if(obj->query_temp("spell/bless")) str +="    [1;32m(¯¬ºÖªº¥ú¨~)[0m\n";
 	  if(obj->query_temp("spell/shield")) str +="    [1;33m(¸t  ¥ú  ¬Þ)[0m\n";
	  if(obj->query_temp("spell/armor")) str +="    [1;32m(Å] ªk Å@ ¥Ò)[0m\n";
 	} 
 	
        message("vision", str, me);

        if( obj!=me && living(obj) && !userp(obj)
        &&  random((int)obj->query("evil")) > 100 ) //¤Óevilªº°Êª«·|¦]¬°§A¬Ý¥L¦Ó§ðÀ»
	{
		write( obj->name() + "¬ðµMÂà¹LÀY¨ÓÀü§A¤@²´¡C\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}


string inventory_look(object obj, int flag)
{
        string str;

        if( obj->query("equipped") )
                str = obj->item_describe(1);
        else if( !flag )
                str = "            " + obj->short();
        else
                return 0;

        return str;
}


int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;
	string name;

        if( !objectp(env = environment(me)) )
		return notify_fail("³o¸Ì¥u¦³¦ÇÀÛÀÛ¦a¤@¤ù¡M¤°»ò¤]¨S¦³¡C\n");

        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) )
        {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                name=me->name();
		if(me->query_temp("hide")+me->query_temp("invis") < 1 ) tell_room(environment(me),name +"¬Ý¤F¬Ý³o¸Ìªº"+ arg +"¡C\n",({me}));
                return 1;
        }
        else
        if( mapp(item = env->query("hide_item_desc")) && !undefinedp(item[arg]) )
        {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                name=me->name();
		if(me->query_temp("hide")+me->query_temp("invis") < 1 ) tell_room(environment(me),name +"¬Ý¤F¬Ý³o¸Ìªº"+ arg +"¡C\n",({me}));
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("§A­n¬Ý¤°»ò¡S\n");
}

string process_item(object me,object *inv)
{
	int i,k,j;
	string str="";
	k=sizeof(inv);
	if(k<1) return "  ¨º¸Ì¤°»ò¤]¨S¦³¡C\n";
	if(k>140) return "ªF¦è¹ê¦b¤Ó¦h¤F¡A§A²´ªá¼º¶ÃµLªk¬Ý²M·¡¡C\n";
	inv = sort_array(inv, "sort_item", this_object());
	j=1;
		for(i=0; i<k; i++)
        	{
        		if(inv[i]==me) continue;
        		if(!me->visible(inv[i])) continue;
			if( i+1 < k )
			{
				if( inv[i]->query("name") == inv[i+1]->query("name") 
				    && !userp(inv[i])
				    && !userp(inv[i+1])
				    && !inv[i]->query_temp("no_combine")
				    && !inv[i+1]->query_temp("no_combine")
				    && me->visible(inv[i+1])
				    ) j++;
				else
				{
					str+="  ";
					if(!inv[i]->query_amount())
					{
				 		if(j>1)		//luky ¨â­Ó¥H¤W¦AÅã¥Ü¼Æ¶q
				 		{		//luky
				 			str += chinese_number(j);
				 			str += inv[i]->query("unit")  ? inv[i]->query("unit"):"­Ó";
				 		}		//luky
					}
					str += show_item_status(inv[i]);
					j = 1;
				}
			}
			else
			{
				str+="  ";
				if(j>1)		//luky ¨â­Ó¥H¤W¦AÅã¥Ü¼Æ¶q
				{		//luky
					str += chinese_number(j);
					str += inv[i]->query("unit")  ? inv[i]->query("unit"):"­Ó";
				}		//luky
				str += show_item_status(inv[i]);
			}
		}
		return str;
}

int sort_item(object ob1, object ob2)
{
	string file1,file2;
	if(userp(ob1) && !userp(ob2)) return 1;
	if(!userp(ob1) && userp(ob2)) return -1;
		
	file1=base_name(ob1);
	file2=base_name(ob2);
	if(file1==file2)
	{
		return getoid(ob2)-getoid(ob1);
	}
	return strcmp(file1,file2);
}

int help (object me)
{
        write(@HELP
«ü¥O®æ¦¡: look [on|off|<ª««~>|<¥Íª«>|<¤è¦V>] < in «ü©w¦ì¸m>

»¡©ú: ³o­Ó«ü¥OÅý§A¬d¬Ý§A©Ò¦bªºÀô¹Ò¡B¬Y¥óª««~¡B¥Íª«¡B©Î¬O¤è¦V¡C

ªþµù: 
(1) look on ¬O§¹¾ã¼Ò¦¡. look off¬OÂ²²¤¼Ò¦¡.
(2) «ü©w¦ì¸m¥i¥H¬O <in box> <in here> <in me> µ¥µ¥.

HELP
	);
        return 1;
}
