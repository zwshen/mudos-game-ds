/*
Title: �a�Ͻs�边 v1.0
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
	set_name("�a�Ͻs�边(v1.0)", ({ "map maker", "maker" }) );
	set_weight(100);
	set("unit", "��" );
	set("long", @MYLONG
�o�Ӥu��O�i�H��K�Ův�ֳt�إߧ��㪺�ϰ�ж��s�����c�C

1.�ϥΤ��e�������s��n�@��N*N������Φa����, �a�Ͻd�Ҧp�U:

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

PS: 0��ܨS���ж�,1~9���Ʀr���O�N��өж������ﰪ��. (�ثe���䴩�t��)
2. �M��ϥ� setpath <�ɮ׸��|> ���O�]�w�n�s��ж��ɮת����|.
   (���[�Ѽƫh�]���ثe�Ҧb�ؿ�)
3. �A�� readmap <map������|�ɦW> ���O�N�a����Ū�J.
   (���[�Ѽƫh�w�]���ثe�Ҧb�ؿ���map.txt)
4. �p�G�a���ɮ׳B�z�L�~, �������ӷ|�۰���ܦa�Ϩѹw��.
   (�]�i�H�� showmap ���O�Ӭ�.)
5. �T�w�L�~�h�i�H�ϥ� generate ���O�Ӧ۰ʲ��ͩж��ɮ�. 

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
	if(sizeof(maps)<1) return "�ثe�S���a�ϳQ���J�C\n";
	for(i=0;i<sizeof(maps);i++)
	{
		for(j=0;j<sizeof(maps[i]);j++)
		{
			str=sprintf("%s%d_",str,maps[i][j]);
			if(maps[i][j]>0) count++;
		}
		str+="\n";
	}
	str=replace_string(str,"0_","[34m�i[0m");
	str=replace_string(str,"1_","[1;30m�i[0m");
	str=replace_string(str,"2_","[32m�i[0m");
	str=replace_string(str,"3_","[33m�i[0m");
	str=replace_string(str,"4_","[37m�i[0m");
	str=replace_string(str,"5_","[1;32m�i[0m");
	str=replace_string(str,"6_","[1;33m�i[0m");
	str=replace_string(str,"7_","[37m�i[0m");
        str=replace_string(str,"8_","[1;37m�i[0m");
        str=replace_string(str,"9_","[1;36m��[0m");
        str+=sprintf("\n  �N���� %d �өж��ɮסC\n",count);
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
        set("short", "�Ŧa");
        set("long", @LONG
�o�̬O�@���|���}�o���Ŧa�C

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
		write("�ɮ� " + file_name + " �w�s�b�M�n�R�����ɶܡS[y/n]");
		input_to("save_room_file", file_name, file);
		return 1;
	}

	return save_room_file("y", file_name, file);
}


int save_room_file(string yn, string file_name, string file)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

	rm(file_name);
	write("�إ� " + file_name + "....");
	if( write_file(file_name, file,1) ) {
		write("OK!\n");
		return 1;
	} else
		return notify_fail("�A�S���g�J�o���ɮ�(" + file_name + ")���v�Q�C\n");
}

int do_setpath(string arg)
{
	string dir;
	if(!arg)
	{
		if(dir = this_player()->query("cwd"))
		{
			current_path=dir;
			write("�A�N��m�ɮץؿ��]�w��[ "+current_path+" ]\n");
			return 1;
		} else return notify_fail("�L�k�۰ʨ��o�ؿ��C\n");
	}
	else
	{
		if( strsrch(arg, "...") >= 0 ) return notify_fail("�S���o�ӥؿ��C\n");	//Add by Luky
		dir = resolve_path(this_player()->query("cwd"), arg);
		if(file_size(dir)!=-2) return notify_fail("�S���o�ӥؿ��C\n");
		if(dir[strlen(dir)-1]!='/') dir += "/";
		current_path=dir;
		write("�A�N��m�ɮץؿ��]�w��[ "+current_path+" ]\n");
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
			write("�a���ɸ��J����!!\n");
			this_player()->start_more(show_map());
			return 1;
		}
		else
		{
			return notify_fail("�a����"+file+"���J���ѡC\n");	
		}
	}
	else
	{
		file=resolve_path(this_player()->query("cwd"), arg);
		if(process_map(file))
		{
			write("�a���ɸ��J����!!\n");
			this_player()->start_more(show_map());
			return 1;
		}
		else
		{
			return notify_fail("�a����"+file+"���J���ѡC\n");	
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
	write("�ɮ׫إߧ���!!\n");
	return 1;
}

int query_autoload() { return 1; }
void owner_is_killed() { destruct(this_object()); }