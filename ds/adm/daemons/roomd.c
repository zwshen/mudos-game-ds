//
// room_d.c
//
// Write By Luky (03/01/2000) : auto_complete
// 加入249行 -alick@ds 8/1/2003
// #pragma save_binary
//顯示大小為1+2*MAP_LENGTH
#define MAP_LENGTH 8
//顯示大小為1+2*MAP_HEIGHT
#define MAP_HEIGHT 3
//地圖額外訊息開關
#define MAP_CONTENT 1
mapping search = ([]);
//地圖
mapping maps=([]);
//額外資訊 //數字編號
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
	if(sizeof(temp)<3) return notify_fail("ROOM_D錯誤:路徑不足以辨認區域名稱!!\n");
	area = temp[sizeof(temp)-3]+temp[sizeof(temp)-2];
	if(!undefinedp(maps[area]))
	{
		if(file_size(mapfile)<=0) return notify_fail("ROOM_D錯誤:沒有地圖設定檔["+mapfile+"]!!\n");
		out = read_file(mapfile);
		if(!map=process_map(out)) return notify_fail("ROOM_D錯誤:地圖設定檔["+mapfile+"]無效!!\n");
		maps[area]=map;
		return 1;
	}
	return notify_fail("ROOM_D錯誤:尚未載入此地圖代號["+area+"]!!\n");
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
          string out,area,*temp,path="/",file,map_file;
	mixed map,content;
	int i,j,x,y,start_x,start_y;
	//建立地圖陣列
	if(!room_ob) return 0;
	area = base_name(room_ob);
	temp = explode(area, "/");
	if(sizeof(temp)<3) return "ROOM_D錯誤:路徑不足以辨認區域名稱!!\n";
	file = temp[sizeof(temp)-1];
	area = temp[sizeof(temp)-3]+temp[sizeof(temp)-2];
	if(undefinedp(maps[area])) {
		temp[sizeof(temp)-1]="";
		temp -= ({""});
		path+=implode(temp,"/");
		map_file=path+"/map.txt";
		if(file_size(map_file)<=0) return "ROOM_D錯誤:沒有地圖設定檔["+map_file+"]!!\n";
		out = read_file(map_file);
		if(!map=process_map(out)) return "ROOM_D錯誤:地圖設定檔["+map_file+"]無效!!\n";
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
	if(sizeof(map)<1) return "目前沒有地圖被載入。\n";
	
	//經由檔名找出座標.
	if(sscanf(file,"%*s_%d_%d",y,x)!=3) return "ROOM_D錯誤:檔名座標無效!!\n";
//	out="\n("+x+","+y+")\n";
	out="";
	//決定y軸顯示起始點
	if(y<=MAP_HEIGHT || sizeof(map) <= 1+MAP_HEIGHT*2) start_y=0;
	else if(y>=sizeof(map)-1-MAP_HEIGHT) start_y=sizeof(map)-1-MAP_HEIGHT*2;
	else start_y=y-MAP_HEIGHT;
	
	//決定x軸顯示起始點
	if(x<=MAP_LENGTH || sizeof(map[0])<=1+MAP_LENGTH*2) start_x=0;
	else if(x>=sizeof(map[0])-1-MAP_LENGTH) start_x=sizeof(map[0])-1-MAP_LENGTH*2;
	else start_x=x-MAP_LENGTH;
//	out+="[s[10A";
	for(i=start_y;i<sizeof(map) && i<start_y+1+(2*MAP_HEIGHT);i++)
	{
		out+="\t[0m▕";
		for(j=start_x;j<sizeof(map[i]) && j<start_x+1+(2*MAP_LENGTH);j++)
		{
			//目前區域
			if(j==x && i==y) out+="[1;33m♁[0m";
			else if(MAP_CONTENT) 
			{
				if(!content[i][j]) out+=map[i][j];
				else if(content[i][j]/10000) out+="[1;31m火[0m";
				else if((content[i][j]%10000)/100) out+="♀";
//                                else if(content[i][j]%100) out+="。";
				else out+=map[i][j];
			}
			else out+=map[i][j];
		}
		out+="[0m▎\n";
	}
//	out+="[u";
	return out;
}

void clean_up_map(object room_ob)
{
	string area,*temp,file;
	int x,y;
	//建立地圖陣列
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
// 以下程式由/std/room.c搬到這裡節省記憶體
object make_inventory(object room,string file)
{
	object ob;
	if( !objectp(ob = new_ob(file)) ) return 0;
	// 支援唯一物品(含NPC) by Luky.
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
          string *list;
	int i,j;

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is 
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//
	if(!room->have_door()) room->set("no_clean_up", 0);
	if(room->query_temp("mob_count")) room->set_temp("mob_count",0); //配合mobroom.c
	if(room->query_temp("out_mob")) room->set_temp("out_mob", 0); // for mobroom.c -alick
	if(room->query_temp("long")) room->delete_temp("long"); //配合look.c

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
			tell_room(room,"[超級電腦-愛瑪]: 此地東西太多, 啟動自動清除系統!!\n");
		}
		room->set("no_clean_up",1);
		return ;
	}
	
	if(sizeof(objs)>90) //限制物品量
	{
        /*     
        switch(area_domain(base_name(room)))
        {
            case "world1":  monster=new_ob("/open/world1/mob/sacer");
                    monster->move(room);
                    message("world:world1:vision",
                    "\n  你感覺地面稍微搖晃了一下, 似乎有小地震。\n\n"
                    ,users());
                    break;
            case "world2":  monster=new_ob("/open/world2/mob/sacer");
                    monster->move(room);
                    message("world:world2:vision",
                    "\n  你感覺地面稍微搖晃了一下, 似乎有小地震。\n\n"
                    ,users());
                    break;
            case "world3":  monster=new_ob("/open/world3/mob/sacer");
                    monster->move(room);
                    message("world:world3:vision",
                    "\n  你感覺地面稍微搖晃了一下, 似乎有小地震。\n\n"
                    ,users());
                    break;
            default :   
                                        monster=new_ob("/open/world1/mob/sacer");
                    monster->move(room);
                    break;
        }
        */

        switch( random(2) )
        {
            case 0:  
                        // 野槌
                                        monster=new_ob("/open/world1/mob/sacer");
                    monster->move(room);
                    message("world:world1:vision",
                            "\n  你感覺地面稍微搖晃了一下，似乎有小地震。\n\n"
                    ,users());
                    break;
            case 1:  
                        // 鼠神
                        monster=new_ob("/open/world2/mob/sacer");
                    monster->move(room);
                    message("world:world1:vision",
                           "\n  你感覺地面稍微搖晃了一下，似乎有小地震。\n\n"
                    ,users());
                    break;
                        default :   
                                        monster=new_ob("/open/world1/mob/sacer");
                    monster->move(room);
                    break;
        }


	  if(monster)
	  {
	  	message_vision("\n  突然間. 雜物堆附近一陣騷動, $N緩緩從地底爬了出來!!\n",monster);
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
	 tell_room(room,me->name()+"想往"+to_chinese(dir)+"離開卻突然被"+wall->name()+"彈了回來。\n",me);
	 return notify_fail("你想往"+to_chinese(dir)+"離開卻突然被"+wall->name()+"彈了回來。\n");
	}
	if(stop=room->valid_leave_door(me,dir)) return notify_fail(stop);
	else return 1;
}
