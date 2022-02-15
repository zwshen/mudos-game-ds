//
// room_d.c
//
// Write By Luky (03/01/2000) : auto_complete
// #pragma save_binary
//≈„•‹§j§p¨∞1+2*MAP_LENGTH
#define MAP_LENGTH 8
//≈„•‹§j§p¨∞1+2*MAP_HEIGHT
#define MAP_HEIGHT 3
//¶aπœ√B•~∞TÆß∂}√ˆ
#define MAP_CONTENT 1
mapping search = ([]);
//¶aπœ
mapping maps=([]);
//√B•~∏Í∞T //º∆¶rΩs∏π
mapping contents=([]);

void create()
{
	seteuid(getuid());
}
string channel_id() {	return "ROOM_D"; }
mapping query_maps()
{
	return maps;
}

mapping query_contents()
{
	return contents;
}

mixed process_map(string input)
{
	string *line,*type,*icon;
	int i,j,k;
	mixed map;
	    line=explode(input,"\n");
	    icon=explode(line[0],",");
	    map=allocate(sizeof(line)-2);
	    for(i=2;i<sizeof(line);i++)
	    {
	    	type=explode(line[i],",");
		map[i-2]=allocate(sizeof(type));

	    	for(j=0;j<sizeof(type);j++)
	    	{
	    		sscanf(type[j],"%d",k);
	    		map[i-2][j]=icon[k];
	    	}
	    }
	    return map;
}

int set_content(string keyword,int x,int y,int setting)
{
	if(undefinedp(contents[keyword])) return 0;
	if(y>=sizeof(contents[keyword])) return 0;
	if(x>=sizeof(contents[keyword][y])) return 0;
	contents[keyword][y][x]=setting;
	return contents[keyword][y][x];
}
int add_content(string keyword,int x,int y,int setting)
{
	if(undefinedp(contents[keyword])) return 0;
	if(y>=sizeof(contents[keyword])) return 0;
	if(x>=sizeof(contents[keyword][y])) return 0;
	contents[keyword][y][x] += setting;
	return contents[keyword][y][x];
}
int sub_content(string keyword,int x,int y,int setting)
{
	if(undefinedp(contents[keyword])) return 0;
	if(y>=sizeof(contents[keyword])) return 0;
	if(x>=sizeof(contents[keyword][y])) return 0;
	contents[keyword][y][x] -= setting;
	if(contents[keyword][y][x]<0) contents[keyword][y][x]=0;
	return contents[keyword][y][x];
}

int moveout(object room_ob,object me)
{
	mapping record;
	if(!record=me->query_temp("map_record")) return 0;
	if(undefinedp(contents[record["area"]])) return 0;
	if(contents[record["area"]][record["y"]][record["x"]]>0) contents[record["area"]][record["y"]][record["x"]] -= record["value"];
	me->delete_temp("map_record");
	return contents[record["area"]][record["y"]][record["x"]];
}
int reload_map(string dir,string mapfile)
{
	string area,*temp,out;
	mixed map;
	temp = explode(dir, "/");
	if(sizeof(temp)<3) return notify_fail("ROOM_Dø˘ª~:∏ÙÆ|§£®¨•HøÎª{∞œ∞Ï¶W∫Ÿ!!\n");
	area = temp[sizeof(temp)-3]+temp[sizeof(temp)-2];
	if(!undefinedp(maps[area]))
	{
		if(file_size(mapfile)<=0) return notify_fail("ROOM_Dø˘ª~:®S¶≥¶aπœ≥]©w¿…["+mapfile+"]!!\n");
		out = read_file(mapfile);
		if(!map=process_map(out)) return notify_fail("ROOM_Dø˘ª~:¶aπœ≥]©w¿…["+mapfile+"]µLÆƒ!!\n");
		maps[area]=map;
		return 1;
	}
	return notify_fail("ROOM_Dø˘ª~:©|•º∏¸§J¶π¶aπœ•N∏π["+area+"]!!\n");
}

int movein(object room_ob,object me)
{
	string area,file,*temp;
	int x,y,value;
	mapping record;
	area = base_name(room_ob);
	temp = explode(area, "/");
	if(sizeof(temp)<3) return 0;
	file = temp[sizeof(temp)-1];
	area = temp[sizeof(temp)-3]+temp[sizeof(temp)-2];
	if(undefinedp(contents[area])) return 0;
	if(sscanf(file,"%*s_%d_%d",y,x)!=3) return 0;
	if(me->query_temp("invis") || me->query_temp("hide") || me->is_ghost()) return 0;
	if(userp(me)) value=100;
	else value=1;
	contents[area][y][x]+=value;
	record=([
		"area": area,
		"value": value,
		"x": x,
		"y": y,
	]);
	me->set_temp("map_record",record);
	return contents[area][y][x];
}

string showmap(object room_ob)
{
	string out,area,*temp,*temp2,path="/",file,map_file;
	mixed map,content;
	int i,j,x,y,start_x,start_y;
	//´ÿ•ﬂ¶aπœ∞}¶C
	if(!room_ob) return 0;
	area = base_name(room_ob);
	temp = explode(area, "/");
	if(sizeof(temp)<3) return "ROOM_Dø˘ª~:∏ÙÆ|§£®¨•HøÎª{∞œ∞Ï¶W∫Ÿ!!\n";
	file = temp[sizeof(temp)-1];
	area = temp[sizeof(temp)-3]+temp[sizeof(temp)-2];
	if(undefinedp(maps[area])) {
		temp[sizeof(temp)-1]="";
		temp -= ({""});
		path+=implode(temp,"/");
		map_file=path+"/map.txt";
		if(file_size(map_file)<=0) return "ROOM_Dø˘ª~:®S¶≥¶aπœ≥]©w¿…["+map_file+"]!!\n";
		out = read_file(map_file);
		if(!map=process_map(out)) return "ROOM_Dø˘ª~:¶aπœ≥]©w¿…["+map_file+"]µLÆƒ!!\n";
		maps[area]=map;
		content=allocate(sizeof(map));
		for(i=0;i<sizeof(map);i++) content[i]=allocate(sizeof(map[0]));
		contents[area]=content;
	}
	 else 
	{
		map = maps[area];
		content = contents[area];
	}
	if(sizeof(map)<1) return "•ÿ´e®S¶≥¶aπœ≥Q∏¸§J°C\n";
	
	//∏g•—¿…¶Wß‰•XÆyº–.
	if(sscanf(file,"%*s_%d_%d",y,x)!=3) return "ROOM_Dø˘ª~:¿…¶WÆyº–µLÆƒ!!\n";
//	out="\n("+x+","+y+")\n";
	out="";
	//®M©wy∂b≈„•‹∞_©l¬I
	if(y<=MAP_HEIGHT || sizeof(map) <= 1+MAP_HEIGHT*2) start_y=0;
	else if(y>=sizeof(map)-1-MAP_HEIGHT) start_y=sizeof(map)-1-MAP_HEIGHT*2;
	else start_y=y-MAP_HEIGHT;
	
	//®M©wx∂b≈„•‹∞_©l¬I
	if(x<=MAP_LENGTH || sizeof(map[0])<=1+MAP_LENGTH*2) start_x=0;
	else if(x>=sizeof(map[0])-1-MAP_LENGTH) start_x=sizeof(map[0])-1-MAP_LENGTH*2;
	else start_x=x-MAP_LENGTH;
//	out+="[s[10A";
	for(i=start_y;i<sizeof(map) && i<start_y+1+(2*MAP_HEIGHT);i++)
	{
		out+="\t[0m¢y";
		for(j=start_x;j<sizeof(map[i]) && j<start_x+1+(2*MAP_LENGTH);j++)
		{
			//•ÿ´e∞œ∞Ï
			if(j==x && i==y) out+="[1;33m°Ú[0m";
			else if(MAP_CONTENT) 
			{
				if(!content[i][j]) out+=map[i][j];
				else if(content[i][j]/10000) out+="[1;31m§ı[0m";
				else if((content[i][j]%10000)/100) out+="°";
				else if(content[i][j]%100) out+="°C";
				else out+=map[i][j];
			}
			else out+=map[i][j];
		}
		out+="[0m¢k\n";
	}
//	out+="[u";
	return out;
}

void clean_up_map(object room_ob)
{
	string area,*temp,file;
	int x,y;
	//´ÿ•ﬂ¶aπœ∞}¶C
	if(!room_ob) return 0;
	area = base_name(room_ob);
	temp = explode(area, "/");
	if(sizeof(temp)<3) return;
	file = temp[sizeof(temp)-1];
	area = temp[sizeof(temp)-3]+temp[sizeof(temp)-2];
	if(undefinedp(maps[area])) return;
	if(sscanf(file,"%*s_%d_%d",y,x)!=3) return;
	set_content(area,x,y,0);
	return;
}
// •H§Uµ{¶°•—/std/room.c∑h®Ï≥o∏Ã∏`¨Ÿ∞Oæ–≈È
object make_inventory(object room,string file)
{
	object ob;
	if( !objectp(ob = new_ob(file)) ) return 0;
	// §‰¥©∞ﬂ§@™´´~(ßtNPC) by Luky.
	if( ob->violate_unique() ) ob = ob->create_replica();
	if( !ob ) return load_object(VOID_OB);

	ob->move(room);
	ob->set("startroom", base_name(room));
	return ob;
}

void reset_room(object room)
{
	mapping ob_list, ob;
	object *objs, monster;
	string *list, env_dir, buffer1, buffer2;
	int i,j;

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is 
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//
	room->set("no_clean_up", 0);
	if(room->query_temp("mob_count")) room->set_temp("mob_count",0); //∞t¶Xmobroom.c
	if(room->query_temp("long")) room->delete_temp("long"); //∞t¶Xlook.c

	objs = all_inventory(room);
	if(room->query("stroom"))
	{
		if(sizeof(objs)>130)
		{
	  		i=sizeof(objs);
	  		while(i>100)
	  		{
	    			if(!objs[i-1]->is_character() && !objs[i-1]->query("no_get")) destruct(objs[i-1]);
	    			i--;
			}
			tell_room(room,"[∂WØ≈πq∏£-∑R∫ø]: ¶π¶a™F¶Ë§”¶h, ±“∞ ¶€∞ ≤M∞£®t≤Œ!!\n");
		}
		room->set("no_clean_up",1);
		return ;
	}
	
	if(sizeof(objs)>90) //≠≠®Ó™´´~∂q
	{
		switch(area_domain(base_name(room)))
		{
			case "world1":	monster=new_ob("/open/world1/mob/sacer");
					monster->move(room);
					message("world:world1:vision",
					"\n  ßA∑Pƒ±¶a≠±µy∑L∑nÆÃ§F§@§U, ¶¸•G¶≥§p¶aæ_°C\n\n"
					,users());
					break;
			case "world2":	monster=new_ob("/open/world2/mob/sacer");
					monster->move(room);
					message("world:world2:vision",
					"\n  ßA∑Pƒ±¶a≠±µy∑L∑nÆÃ§F§@§U, ¶¸•G¶≥§p¶aæ_°C\n\n"
					,users());
					break;
			case "world3":	monster=new_ob("/open/world3/mob/sacer");
					monster->move(room);
					message("world:world3:vision",
					"\n  ßA∑Pƒ±¶a≠±µy∑L∑nÆÃ§F§@§U, ¶¸•G¶≥§p¶aæ_°C\n\n"
					,users());
					break;
			default :	monster=new_ob("/open/world1/mob/sacer");
					monster->move(room);
					break;
		}
	  if(monster)
	  {
	  	message_vision("\n  ¨µM∂°. ¬¯™´∞Ô™˛™Ò§@∞}ƒÃ∞ , $NΩwΩw±q¶a©≥™¶§F•X®”!!\n",monster);
	  }
	  return;
	}
	ob_list = room->query("objects");
	if( !mapp(ob_list) ) return;
	
	if( !mapp(ob = room->query_temp("objects")) )
		ob = allocate_mapping(sizeof(ob_list));
	list = keys(ob_list);
	for(i=0; i<sizeof(list); i++)
	{
		// Allocate an array if we have multiple same object specified.
		if(	undefinedp(ob[list[i]])
		&&	intp(ob_list[list[i]])
		&&	ob_list[list[i]] > 1 )
			ob[list[i]] = allocate(ob_list[list[i]]);

		switch(ob_list[list[i]])
		{
		  case 1:
			if( !ob[list[i]] ) ob[list[i]] = make_inventory(room,list[i]);
			if( !ob[list[i]] ) error("/std/room.c can't load object : "+list[i]);
			else if( environment(ob[list[i]]) != room
			&&	ob[list[i]]->is_character() )
			{
				if( !ob[list[i]]->return_home(room) )
					room->add("no_clean_up", 1);
			}
			break;
		  default:
			for(j=0; j<ob_list[list[i]]; j++)
			{
				// If the object is gone, make another one.
				if( !objectp(ob[list[i]][j]) )
				{
					ob[list[i]][j] = make_inventory(room,list[i]);
					continue;
				}
				// Try to call the wandering npc come back here.
				if( environment(ob[list[i]][j]) != room
				&&	ob[list[i]][j]->is_character() )
				{
					if( !ob[list[i]][j]->return_home(room) )
						room->add("no_clean_up", 1);
				}
			}
		}
	}
	room->set_temp("objects", ob);
	return;
}

int valid_leave_room(object room,object me,string dir)
{
	object wall;
	string stop;

	if(!room) return 1;
	if(wall=room->query_temp("wall/"+dir))
	{
	 tell_room(room,me->name()+"∑Q©π"+to_chinese(dir)+"¬˜∂}´o¨µM≥Q"+wall->name()+"ºu§F¶^®”°C\n",me);
	 return notify_fail("ßA∑Q©π"+to_chinese(dir)+"¬˜∂}´o¨µM≥Q"+wall->name()+"ºu§F¶^®”°C\n");
	}
	if(stop=room->valid_leave_door(me,dir)) return notify_fail(stop);
	else return 1;
}
