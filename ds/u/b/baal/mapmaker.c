/*
Title: 地圖編輯器 v1.0
Coder: Luky 03/11/2000
MUD: ds.muds.net 7000
*/
// #pragma save_binary
#define HAVE_OBLIQUE_LINK 0
inherit ITEM;
mixed *maps;
string file_head="room";
string current_path="/";
int save_room_file(string yn, string file_name, string file);


void create()
{
	set_name("地圖編輯器(v1.0)", ({ "map maker", "maker" }) );
	set_weight(100);
	set("unit", "個" );
	set("long", @MYLONG
這個工具是可以方便巫師快速建立完整的區域房間連結結構。

1.使用之前必須先編輯好一個N*N的正方形地圖檔, 地圖範例如下:

0,0,0,0,0,0,0,0,0,0
0,0,0,0,1,1,0,0,0,0
0,0,0,1,1,1,1,0,0,0
0,0,1,1,1,2,1,1,0,0
0,0,0,1,2,2,2,1,0,0
0,0,1,2,2,3,3,2,1,0
0,1,1,2,2,3,2,1,1,0
0,0,1,1,2,2,2,1,1,0
0,0,0,1,1,2,1,1,0,0
0,0,0,0,0,0,0,0,0,0

PS: 0表示沒有房間,1~9的數字分別代表該房間的絕對高度. (目前不支援負值)
2. 然後使用 setpath <檔案路徑> 指令設定要存放房間檔案的路徑.
   (不加參數則設為目前所在目錄)
3. 再用 readmap <map完整路徑檔名> 指令將地圖檔讀入.
   (不加參數則預設為目前所在目錄的map.txt)
4. 如果地圖檔案處理無誤, 此時應該會自動顯示地圖供預覽.
   (也可以用 showmap 指令來看.)
5. 確定無誤則可以使用 generate 指令來自動產生房間檔案. 

MYLONG
	);
}

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_setpath", "setpath");
		add_action("do_readmap", "readmap");
		add_action("do_showmap", "showmap");
		add_action("do_generate", "generate");
	}
}


int process_map(string file)
{
	string input,*line,*height;
	int i,j;
	mixed map;
	if(file_size(file)>0)
	{
	    input=read_file(file);
	    line=explode(input,"\n");
	    map=allocate(sizeof(line));
	    for(i=0;i<sizeof(line);i++)
	    {
	    	height=explode(line[i],",");
		map[i]=allocate(sizeof(height));
	    	for(j=0;j<sizeof(height);j++)
	    	{
	    		sscanf(height[j],"%d",map[i][j]);
	    	}
	    }
	    maps=map;
	    return 1;
	} else return 0;
}

mixed query_map()
{
	return maps;
}

string show_map()
{
	int i,j,count;
	string str="\n";
	if(sizeof(maps)<1) return "目前沒有地圖被載入。\n";
	for(i=0;i<sizeof(maps);i++)
	{
		for(j=0;j<sizeof(maps[i]);j++)
		{
			str=sprintf("%s%d_",str,maps[i][j]);
			if(maps[i][j]>0) count++;
		}
		str+="\n";
	}
	str=replace_string(str,"0_","[34m█[0m");
	str=replace_string(str,"1_","[1;30m█[0m");
	str=replace_string(str,"2_","[32m█[0m");
	str=replace_string(str,"3_","[33m█[0m");
	str=replace_string(str,"4_","[37m█[0m");
	str=replace_string(str,"5_","[1;32m█[0m");
	str=replace_string(str,"6_","[1;33m█[0m");
	str=replace_string(str,"7_","[37m█[0m");
        str=replace_string(str,"8_","[1;37m█[0m");
        str=replace_string(str,"9_","[1;36m▲[0m");
        str+=sprintf("\n  將產生 %d 個房間檔案。\n",count);
	return str;
}

private int generate_room_file(int x, int y)
{
	int i,height,tmp_h;
	string file_name,file,*exit_key,*exit_file;
	mapping exit=([]);
	height=maps[y][x];
	if(height==0) return 0;
	//Scan north
	if(y>=1) {
		tmp_h=maps[y-1][x];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["north"]=file_head+sprintf("_%d_%d_%d",x,y-1,tmp_h);
			}
			else if(height-1==tmp_h) {
				exit["northdown"]=file_head+sprintf("_%d_%d_%d",x,y-1,tmp_h);
			}
			else if(height+1==tmp_h){
				exit["northup"]=file_head+sprintf("_%d_%d_%d",x,y-1,tmp_h);
			}
		}
	}
	//Scan northeast
	if(y>=1 && x<sizeof(maps[y-1])-1) {
		tmp_h=maps[y-1][x+1];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["northeast"]=file_head+sprintf("_%d_%d_%d",x+1,y-1,tmp_h);
			}
			if(HAVE_OBLIQUE_LINK) {
				if(height-1==tmp_h) {
					exit["northeastdown"]=file_head+sprintf("_%d_%d_%d",x+1,y-1,tmp_h);
				}
				else if(height+1==tmp_h){
					exit["northeastup"]=file_head+sprintf("_%d_%d_%d",x+1,y-1,tmp_h);
				}
			}
		}
	}
	//Scan east
	if(x<sizeof(maps[y])-1) {
		tmp_h=maps[y][x+1];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["east"]=file_head+sprintf("_%d_%d_%d",x+1,y,tmp_h);
			}
			else if(height-1==tmp_h) {
				exit["eastdown"]=file_head+sprintf("_%d_%d_%d",x+1,y,tmp_h);
			}
			else if(height+1==tmp_h){
				exit["eastup"]=file_head+sprintf("_%d_%d_%d",x+1,y,tmp_h);
			}
		}
	}
	//Scan southeast
	if( y<sizeof(maps)-1 && x<sizeof(maps[y+1])-1) {
		tmp_h=maps[y+1][x+1];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["southeast"]=file_head+sprintf("_%d_%d_%d",x+1,y+1,tmp_h);
			}
			if(HAVE_OBLIQUE_LINK) {
				if(height-1==tmp_h) {
					exit["southeastdown"]=file_head+sprintf("_%d_%d_%d",x+1,y+1,tmp_h);
				}
				else if(height+1==tmp_h){
					exit["southeastup"]=file_head+sprintf("_%d_%d_%d",x+1,y+1,tmp_h);
				}
			}
		}
	}
	//Scan south
	if( y<sizeof(maps)-1) {
		tmp_h=maps[y+1][x];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["south"]=file_head+sprintf("_%d_%d_%d",x,y+1,tmp_h);
			}
			else if(height-1==tmp_h) {
				exit["southdown"]=file_head+sprintf("_%d_%d_%d",x,y+1,tmp_h);
			}
			else if(height+1==tmp_h){
				exit["southup"]=file_head+sprintf("_%d_%d_%d",x,y+1,tmp_h);
			}
		}
	}
	//Scan southwest
	if( y<sizeof(maps)-1 && x>=1) {
		tmp_h=maps[y+1][x-1];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["southwest"]=file_head+sprintf("_%d_%d_%d",x-1,y+1,tmp_h);
			}
			if(HAVE_OBLIQUE_LINK) {
				if(height-1==tmp_h) {
					exit["southwestdown"]=file_head+sprintf("_%d_%d_%d",x-1,y+1,tmp_h);
				}
				else if(height+1==tmp_h){
					exit["southwestup"]=file_head+sprintf("_%d_%d_%d",x-1,y+1,tmp_h);
				}
			}
		}
	}
	//Scan west
	if(x>=1) {
		tmp_h=maps[y][x-1];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["west"]=file_head+sprintf("_%d_%d_%d",x-1,y,tmp_h);
			}
			else if(height-1==tmp_h) {
				exit["westdown"]=file_head+sprintf("_%d_%d_%d",x-1,y,tmp_h);
			}
			else if(height+1==tmp_h){
				exit["westup"]=file_head+sprintf("_%d_%d_%d",x-1,y,tmp_h);
			}
		}
	}
	//Scan northwest
	if(x>=1 && y>=1) {
		tmp_h=maps[y-1][x-1];
		if(tmp_h!=0) {
			if(height==tmp_h) {
				exit["northwest"]=file_head+sprintf("_%d_%d_%d",x-1,y-1,tmp_h);
			}
			if(HAVE_OBLIQUE_LINK) {
				if(height-1==tmp_h) {
					exit["northwestdown"]=file_head+sprintf("_%d_%d_%d",x-1,y-1,tmp_h);
				}
				else if(height+1==tmp_h){
					exit["northwestup"]=file_head+sprintf("_%d_%d_%d",x-1,y-1,tmp_h);
				}
			}
		}
	}
	
	//generate file
	file_name=current_path+file_head+sprintf("_%d_%d_%d.c",x,y,height);
	file=@FILE_1
inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
這裡是一塊尚未開發的空地。

LONG
);
	set("exits",([
FILE_1
;
	exit_key=keys(exit);
	for(i=0;i<sizeof(exit_key);i++) {
		file=sprintf("%s\t\"%s\" : __DIR__\"%s\",\n",file,exit_key[i],exit[exit_key[i]]);
	}
	file+=@FILE_2
	]));
        set("out_doors","land");
        setup();
}
FILE_2
;
	if( file_size(file_name)!=-1 ) {
		write("檔案 " + file_name + " 已存在﹐要刪除舊檔嗎﹖[y/n]");
		input_to("save_room_file", file_name, file);
		return 1;
	}

	return save_room_file("y", file_name, file);
}


int save_room_file(string yn, string file_name, string file)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

	rm(file_name);
	write("建立 " + file_name + "....");
	if( write_file(file_name, file,1) ) {
		write("OK!\n");
		return 1;
	} else
		return notify_fail("你沒有寫入這個檔案(" + file_name + ")的權利。\n");
}

int do_setpath(string arg)
{
	string dir;
	if(!arg)
	{
		if(dir = this_player()->query("cwd"))
		{
			current_path=dir;
			write("你將放置檔案目錄設定為[ "+current_path+" ]\n");
			return 1;
		} else return notify_fail("無法自動取得目錄。\n");
	}
	else
	{
		if( strsrch(arg, "...") >= 0 ) return notify_fail("沒有這個目錄。\n");	//Add by Luky
		dir = resolve_path(this_player()->query("cwd"), arg);
		if(file_size(dir)!=-2) return notify_fail("沒有這個目錄。\n");
		if(dir[strlen(dir)-1]!='/') dir += "/";
		current_path=dir;
		write("你將放置檔案目錄設定為[ "+current_path+" ]\n");
		return 1;
	}
}

int do_readmap(string arg)
{
	string file;
	if(!arg)
	{
		file=resolve_path(this_player()->query("cwd"),"map.txt");
		if(process_map(file))
		{
			write("地圖檔載入完成!!\n");
			this_player()->start_more(show_map());
			return 1;
		}
		else
		{
			return notify_fail("地圖檔"+file+"載入失敗。\n");	
		}
	}
	else
	{
		file=resolve_path(this_player()->query("cwd"), arg);
		if(process_map(file))
		{
			write("地圖檔載入完成!!\n");
			this_player()->start_more(show_map());
			return 1;
		}
		else
		{
			return notify_fail("地圖檔"+file+"載入失敗。\n");	
		}
	}
}

int do_showmap(string arg)
{
	this_player()->start_more(show_map());
	return 1;
}

int do_generate(string arg)
{
	int x,y;
	for(y=0;y<sizeof(maps);y++)
	{
		for(x=0;x<sizeof(maps[y]);x++)
		{
			generate_room_file(x,y);
		}
	}
	write("檔案建立完成!!\n");
	return 1;
}

int query_autoload() { return 1; }
void owner_is_killed() { destruct(this_object()); }