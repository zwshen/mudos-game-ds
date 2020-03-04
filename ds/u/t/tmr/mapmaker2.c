/*
Title: ¦a¹Ï½s¿è¾¹ v2.0
Coder: Luky 05/06/2000
MUD: ds.muds.net 7000
*/
#define HAVE_OBLIQUE_LINK 0
inherit ITEM;
mixed *maps;
string *icons;
string *room_short;
string file_head="map";
string current_path="/";
int block=0;
int save_room_file(string yn, string file_name, string file);


void create()
{
	set_name("¦a¹Ï½s¿è¾¹(v2.0)", ({ "map maker", "maker" }) );
	set_weight(100);
	set("unit", "­Ó" );
	set("long", @MYLONG
³o­Ó¤u¨ã¬O¥i¥H¤è«K§Å®v§Ö³t«Ø¥ß§¹¾ãªº°Ï°ì©Ð¶¡³sµ²µ²ºc¡C

1.¨Ï¥Î¤§«e¥²¶·¥ý½s¿è¦n¤@­ÓN*Nªº¥¿¤è§Î¦a¹ÏÀÉ, ¦a¹Ï½d¨Ò¦p¤U:
[44;30m~~[0m,[33m¡¶[0m,¢i,Âí,[1;36;46mùá[0m,[44;36m::[0m,[1;30m¡¼[0m,  ,[32mªL[0m,[46m¡k[0m
¤j®ü,°ª¤s,¥Û¾À,«°Âí,©¥¼ß,¸®«Í¦¿,¥ÛªO¸ô,¯ó­ì,º_¾ðªL,«ý¾ô
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
00,00,00,00,07,07,00,00,00,07,07,00,00,00,07,07,00,00,00
00,03,06,06,07,08,07,07,07,07,07,07,07,07,06,06,07,00,00
00,00,07,06,08,08,01,01,07,07,07,06,06,06,06,03,07,07,00
00,00,00,06,08,08,08,01,05,05,05,06,07,07,06,07,07,07,00
00,00,07,06,01,01,01,08,07,07,05,09,05,05,06,07,07,07,00
00,07,07,06,01,01,08,07,07,07,07,06,07,05,06,07,07,07,00
00,00,07,06,01,07,07,07,07,03,07,06,07,05,09,05,05,00,00
00,00,07,06,07,07,07,07,07,06,06,06,06,06,06,08,00,00,00
00,00,07,06,06,06,06,06,06,06,07,07,08,08,08,08,00,00,00
00,07,07,07,07,07,07,07,07,07,07,07,07,07,08,08,08,07,00
00,07,03,07,07,00,07,07,07,07,07,07,07,07,07,08,07,07,00
00,07,07,07,00,00,00,07,07,07,07,07,00,00,07,07,07,00,00
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00

PS: 
²Ä¤@¦æ¬°¹Ï¥Ü°}¦C¥H³r¸¹¹j¶}, ¤À§O¥Nªí¨C­ÓÃä¸¹ªº¹Ï¥Ü. ¬°¤@­Ó¥þ§Î©Î¬O¨â­Ó¥b§Î²Å¸¹.
²Ä¤G¦æ¬°¤å¦r, ¼Æ¶q­n»P²Ä¤@¦æ¬Û¦P, ¤À§O¥Nªí¦UºØÃþªºµu¦WºÙ.
²Ä¤T¦æ¥H«á¬°¯x§Î¼Æ¦r°}¦C, ¼Æ¦r¤À§O¥Nªí¸Ó©Ð¶¡ªººØÃþ. (¥Ø«e¤£¤ä´©­t­È)
ª`·N: 0-3 ºØÃþ¬°»ÙÃªª«, ±N¤£·|²£¥Í©Ð¶¡.
2. ¨Ï¥Î setblock <¼Æ¦r> ³]©w§Aªº»ÙÃªª«½d³ò([0~¼Æ¦r]ªº©Ð¶¡ºØÃþ±N¤£·|²£¥Í).
3. ¦pªG»Ý­n¦s©ó¨ä¥L¸ô®|«h¨Ï¥Î setpath <ÀÉ®×¸ô®|> 
   «ü¥O³]©w­n¦s©ñ©Ð¶¡ÀÉ®×ªº¸ô®|. (¹w³]: ¥Ø«e©Ò¦b¥Ø¿ý)
4. ¦A¥Î readmap <map§¹¾ã¸ô®|ÀÉ¦W> «ü¥O±N¦a¹ÏÀÉÅª¤J.
   (¹w³]: ¥Ø«e©Ò¦b¥Ø¿ýªº map.txt)
5. ¦pªG¦a¹ÏÀÉ®×³B²zµL»~, ¦¹®ÉÀ³¸Ó·|¦Û°ÊÅã¥Ü¦a¹Ï¨Ñ¹wÄý.
   (¤]¥i¥H¥Î showmap «ü¥O¨Ó¬Ý.)
6. ½T©wµL»~«h¥i¥H¨Ï¥Î generate «ü¥O¨Ó¦Û°Ê²£¥Í©Ð¶¡ÀÉ®×. 

MYLONG
	);
}

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_setpath", "setpath");
		add_action("do_setblock", "setblock");
		add_action("do_readmap", "readmap");
		add_action("do_showmap", "showmap");
		add_action("do_generate", "generate");
	}
}


int process_map(string file)
{
	string input,*line,*type;
	int i,j;
	mixed map;
	if(file_size(file)>0)
	{
	    input=read_file(file);
	    line=explode(input,"\n");
	    icons=explode(line[0],",");
	    if(sizeof(icons)<1) return 0;
	    room_short=explode(line[1],",");
	    if(sizeof(icons)!=10) return 0;
	    map=allocate(sizeof(line)-2);
	    for(i=2;i<sizeof(line);i++)
	    {
	    	type=explode(line[i],",");
		map[i-2]=allocate(sizeof(type));
	    	for(j=0;j<sizeof(type);j++)
	    	{
	    		sscanf(type[j],"%d",map[i-2][j]);
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
	if(sizeof(maps)<1) return "¥Ø«e¨S¦³¦a¹Ï³Q¸ü¤J¡C\n";
	for(i=0;i<sizeof(maps);i++)
	{
		for(j=0;j<sizeof(maps[i]);j++)
		{
			str=sprintf("%s%d_",str,maps[i][j]);
			if(maps[i][j]>block) count++;
		}
		str+="\n";
	}
	for(i=0;i<sizeof(icons);i++)
	{
		str=replace_string(str,sprintf("%d_",i),icons[i]);
	}
	str+=sprintf("\n  ±N²£¥Í %d ­Ó©Ð¶¡ÀÉ®×¡C\n",count);
	return str;
}

private int generate_room_file(int x, int y)
{
	int i,type,tmp_h;
	string file_name,file,*exit_key,*exit_file;
	mapping exit=([]);
	type=maps[y][x];
	if(type<=block || type>=sizeof(icons)) return 0;
	//Scan north
	if(y>=1) {
		tmp_h=maps[y-1][x];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["north"]=file_head+sprintf("_%d_%d",y-1,x);
		}
	}

	//Scan east
	if(x<sizeof(maps[y])-1) {
		tmp_h=maps[y][x+1];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["east"]=file_head+sprintf("_%d_%d",y,x+1);
		}
	}

	//Scan south
	if( y<sizeof(maps)-1) {
		tmp_h=maps[y+1][x];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["south"]=file_head+sprintf("_%d_%d",y+1,x);
		}
	}

	//Scan west
	if(x>=1) {
		tmp_h=maps[y][x-1];
		if(tmp_h>block && tmp_h<sizeof(icons)) {
				exit["west"]=file_head+sprintf("_%d_%d",y,x-1);
		}
	}

	//generate file
	file_name=current_path+file_head+sprintf("_%d_%d.c",y,x);
	file=@FILE_1
inherit ROOM;
void create()
{
FILE_1;
        file+=sprintf("\tset(\"short\", \"%s\");\n",room_short[type]);
file+=@FILE_LONG
        set("long", @LONG

LONG
);
	set("exits",([
FILE_LONG;
	exit_key=keys(exit);
	for(i=0;i<sizeof(exit_key);i++) {
		file=sprintf("%s\t\"%s\" : __DIR__\"%s\",\n",file,exit_key[i],exit[exit_key[i]]);
	}
	file+=@FILE_2
	]));
        set("out_doors","land");
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

FILE_2
;
	if( file_size(file_name)!=-1 ) {
		write("ÀÉ®× " + file_name + " ¤w¦s¦b¡M­n§R°£ÂÂÀÉ¶Ü¡S[y/n]");
		input_to("save_room_file", file_name, file);
		return 1;
	}

	return save_room_file("y", file_name, file);
}


int save_room_file(string yn, string file_name, string file)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;

	rm(file_name);
	write("«Ø¥ß " + file_name + "....");
	if( write_file(file_name, file,1) ) {
		write("OK!\n");
		return 1;
	} else
		return notify_fail("§A¨S¦³¼g¤J³o­ÓÀÉ®×(" + file_name + ")ªºÅv§Q¡C\n");
}

int do_setpath(string arg)
{
	string dir;
	if(!arg)
	{
		if(dir = this_player()->query("cwd"))
		{
			current_path=dir;
			write("§A±N©ñ¸mÀÉ®×¥Ø¿ý³]©w¬°[ "+current_path+" ]\n");
			return 1;
		} else return notify_fail("µLªk¦Û°Ê¨ú±o¥Ø¿ý¡C\n");
	}
	else
	{
		if( strsrch(arg, "...") >= 0 ) return notify_fail("¨S¦³³o­Ó¥Ø¿ý¡C\n");	//Add by Luky
		dir = resolve_path(this_player()->query("cwd"), arg);
		if(file_size(dir)!=-2) return notify_fail("¨S¦³³o­Ó¥Ø¿ý¡C\n");
		if(dir[strlen(dir)-1]!='/') dir += "/";
		current_path=dir;
		write("§A±N©ñ¸mÀÉ®×¥Ø¿ý³]©w¬°[ "+current_path+" ]\n");
		return 1;
	}
}
int do_setblock(string arg)
{
	int temp;
	if(!arg) write("¥Ø«e¦a¹Ï³]©w¬°ºØÃþ½s¸¹[ "+block+" ]¥H¤Uªº¬°»ÙÃªª«¡C\n");
	else
	{
		if(sscanf(arg,"%d",temp)!=1) return notify_fail("³]©w°Ï°ìªº»ÙÃªª«ºØÃþ½d³ò: setblock [¼Æ¦r]¡C\n");
		if(temp<0) return notify_fail("³]©w°Ï°ìªº»ÙÃªª«ºØÃþ½d³ò: setblock [¼Æ¦r] <»Ý¤j©ó0>¡C\n");
		block=temp;
		write("§A±N½s¸¹"+block+"¥H¤Uªº©Ð¶¡ºØÃþ³]©w¬°»ÙÃªª«¡C\n");
	}
	return 1;
}
int do_readmap(string arg)
{
	string file;
	if(!arg)
	{
		current_path=this_player()->query("cwd");
		file=resolve_path(this_player()->query("cwd"),"map.txt");
		if(process_map(file))
		{
			write("¦a¹ÏÀÉ¸ü¤J§¹¦¨!!\n");
			this_player()->start_more(show_map());
			return 1;
		}
		else
		{
			return notify_fail("¦a¹ÏÀÉ"+file+"¸ü¤J¥¢±Ñ¡C\n");	
		}
	}
	else
	{
		file=resolve_path(this_player()->query("cwd"), arg);
		if(process_map(file))
		{
			write("¦a¹ÏÀÉ¸ü¤J§¹¦¨!!\n");
			this_player()->start_more(show_map());
			return 1;
		}
		else
		{
			return notify_fail("¦a¹ÏÀÉ"+file+"¸ü¤J¥¢±Ñ¡C\n");	
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
	if(current_path=="/") current_path=this_player()->query("cwd");
	if(!current_path) return notify_fail("½Ð¥ý³]©w¥Ø¿ý(setpath)¡C\n");
	for(y=0;y<sizeof(maps);y++)
	{
		for(x=0;x<sizeof(maps[y]);x++)
		{
			generate_room_file(x,y);
		}
	}
	write("ÀÉ®×«Ø¥ß§¹¦¨!!\n");
	return 1;
}

int query_autoload() { return 1; }
void owner_is_killed() { destruct(this_object()); }