/*
Title: ¦a¹Ï½s¿è¾¹ v2.0
Coder: Luky 05/06/2000
MUD: ds.muds.net 7000
*/
#define HAVE_OBLIQUE_LINK 0
#define MAP_BEGIN_LINE 2
inherit ITEM;
static string *outdoors_type = ({"off","land"});
mixed *maps;
string *icons;
string *room_short;
string file_head="map";
string current_path="/";
int block=0;
int busy;
int lock=1;
int save_room_file(string yn, string file_name, string file);
int light=0;
int can_save=0;
string outdoors="off";
void create()
{
	set_name("°Ï°ì²£¥Í¾¹(v2.0)", ({ "area maker", "maker" }) );
	set_weight(100);
	set("unit", "­Ó" );
	set("long", @MYLONG
³o­Ó¤u¨ã¬O¥i¥H¤è«K§Å®v§Ö³t«Ø¥ß§¹¾ãªº°Ï°ì©Ð¶¡³sµ²µ²ºc¡C¥»
²£¥Í¾¹¥i±N¤@­Ó¦a¹Ï½s½XÀÉ®×§Ö³tÂà´«¬°¾ã§å©Ð¶¡ÀÉ®×¡C<help maker>

«ü¥O:

¢zhelp 	<ÃöÁä¦r>		¬ÛÃö»¡©ú
¢usetpath <¸ô®|>		³]©w¤u§@¸ô®|
¢usetblock <½s¸¹>		³]©w»ÙÃªª«½s¸¹½d³ò
¢usetoutdoors <ºØÃþ|off>	³]©w²£¥ÍÀÉ®×¬O§_¬°¤á¥~(¹w³]¬°off:«Ç¤º)
¢usetlight <on|off>		³]©w²£¥Í°Ï°ì¬O§_­n¥[light(¹w³]¬°off)
¢usetsaveroom <on|off>		³]©w²£¥Í°Ï°ì¬O§_¥i©wÂIÀx¦s(¹w³]¬°off)
¢|readmap <§¹¾ãÀÉ®×¸ô®|>	Åª¨ú¦a¹ÏÀÉ
  ¢ushowmap			Åã¥Ü°Ï°ì¦a¹Ï
  ¢usavemap <ÀÉ¦W>		Àx¦s°Ï°ì¦a¹ÏÀÉ®×
  ¢|generate			²£¥Í°Ï°ìÀÉ®×

MYLONG
	);
}

void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("do_setpath", "setpath");
		add_action("do_setblock", "setblock");
		add_action("do_setoutdoors", "setoutdoors");
		add_action("do_setlight", "setlight");
		add_action("do_setsaveroom", "setsaveroom");
		add_action("do_readmap", "readmap");
		add_action("do_showmap", "showmap");
		add_action("do_generate", "generate");
		add_action("do_savemap", "savemap");
		add_action("do_help", "help");
	}
}

int do_help(string arg)
{
	if(arg=="maker")
	{
		write(@HELP_MAKER
°Ï°ì²£¥Í¾¹¨Ï¥Î¤èªk:
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

HELP_MAKER);
		return 1;
	}
	return 0;
}

int do_setoutdoors(string arg)
{
	if(!arg) return notify_fail("«Ç¥~(land): setoutdoors land  «Ç¤º: setoutdoors off¡C\n");
	if(member_array(arg,outdoors_type)==-1) return notify_fail("¨S¦³³oºØ«Ç¥~(¤º)«¬ºA¡C\n");
	outdoors=arg;
	write("³]©w¬°: "+arg+" ..OK.");
	return 1;
}

int do_setlight(string arg)
{
	if(!arg || (arg!="on" && arg!="off")) return notify_fail("setlight <on|off>¡C\n");
	if(arg=="on")
	{
		light=1;
		write("©Ð¶¡±N¦Û°Ê¥[¤J set(\"light\",1); \n");
		return 1;
	}
	if(arg=="off")
	{
		light=0;
		write("©Ð¶¡±N¤£·|²£¥Í set(\"light\",1); \n");
		return 1;
	}
}

int do_setsaveroom(string arg)
{
	if(!arg || (arg!="on" && arg!="off")) return notify_fail("setlight <on|off>¡C\n");
	if(arg=="on")
	{
		can_save=1;
		write("©Ð¶¡±N¦Û°Ê¥[¤J set(\"valid_startroom\",1); \n");
		return 1;
	}
	if(arg=="off")
	{
		can_save=0;
		write("©Ð¶¡±N¤£·|²£¥Í set(\"valid_startroom\",1); \n");
		return 1;
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
	    map=allocate(sizeof(line)-MAP_BEGIN_LINE);
	    for(i=MAP_BEGIN_LINE;i<sizeof(line);i++)
	    {
	    	type=explode(line[i],",");
		map[i-MAP_BEGIN_LINE]=allocate(sizeof(type));
	    	for(j=0;j<sizeof(type);j++)
	    	{
	    		sscanf(type[j],"%d",map[i-MAP_BEGIN_LINE][j]);
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

string show_map(int raw)
{
	int i,j,count=0;
	string str="\n";
	if(sizeof(maps)<1) return "¥Ø«e¨S¦³¦a¹Ï³Q¸ü¤J¡C\n";
	for(i=0;i<sizeof(maps);i++)
	{
		for(j=0;j<sizeof(maps[i]);j++)
		{
			str=sprintf("%s<%d>",str,maps[i][j]);
			if(maps[i][j]>block) count++;
		}
		str+="\n";
	}
	for(i=0;i<sizeof(icons);i++)
	{
		str=replace_string(str,sprintf("<%d>",i),icons[i]);
	}
	if(!raw) str+=sprintf("\n  ±N²£¥Í %d ­Ó©Ð¶¡ÀÉ®×¡C\n",count);
	else str+="\n";
	return str;
}

private int generate_room_file(int x, int y)
{
	int i,type,tmp_h;
	string file_name,file,*exit_key,*exit_file;
	mapping exit=([]);
	type=maps[y][x];
	if(type<=block || type>=sizeof(icons)) return 0;
	//¬°¨DÂ²¼ä, ¨ú®ø±×¦V³sµ²
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
	file+="\t]));\n";
	//
	//¨ä¥L©Ð¶¡³]©w
	//
	if(type==23)
	{
		file+=@TREES
	set("outdoors","land");

TREES;
	}
	else
	{
		if(outdoors!="off") file+="\tset(\"outdoors\",\""+outdoors+"\");\n";
		if(light ) file+="\tset(\"light\",1);\n";
		if(can_save) file+="\tset(\"valid_startroom\",1);\n";
	}
	file+=@FILE_2
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //¥[¨ä¥L¨ç¦¡xxx()®É½Ð®³±¼¦¹¦æ
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

	if( file_size(file_name)!=-1 ) rm(file_name);
	write("«Ø¥ß " + file_name + "...");
	if( write_file(file_name, file,1) ) {
		write("OK!\n");
		return 1;
	} else 
	{
		write("¥¢±Ñ!!\n");
		return notify_fail("§A¨S¦³¼g¤J³o­ÓÀÉ®×(" + file_name + ")ªºÅv§Q¡C\n");
	}
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
			this_player()->start_more(show_map(0));
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
			this_player()->start_more(show_map(0));
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
	this_player()->start_more(show_map(0));
	return 1;
}

void delay_generate(int y)
{
	int x;
	for(x=0;x<sizeof(maps[y]);x++)
	{
		generate_room_file(x,y);
	}
	return;
}
void generate_done()
{
	busy=0;
	write("ÀÉ®×«Ø¥ß§¹¦¨!!\n");
	return;
}

int do_generate(string arg)
{
	int x,y,time=0;
	if(current_path=="/") current_path=this_player()->query("cwd");
	if(!current_path) return notify_fail("½Ð¥ý³]©w¥Ø¿ý(setpath)¡C\n");
	if(block<10 && lock)
	{
		lock=0;
		return notify_fail("ºò§i: §A¥Ø«eªº»ÙÃªª«³]©w¬°:"+block+", ­Y¦³¿ù»~½Ð¥Î setblock ­«³]¡C\n[¦A¦¸¨Ï¥Îgenerate«h·|±j­¢°õ¦æ¡C]\n");
	}
	lock=1;
	if(busy) return notify_fail("¥¿¦b²£¥ÍÀÉ®×¤¤, ½Ðµy«Ý¡C\n");
	busy = 1;
	for(y=0;y<sizeof(maps);y++)
	{
		call_out("delay_generate",time,y);
		time+=3;
		//for(x=0;x<sizeof(maps[y]);x++)
		//{
		//	generate_room_file(x,y);
		//}
	}
	call_out("generate_done",time);
	write("·Ç³Æ¶}©l«Ø¥ßÀÉ®×...³o¥i¯à·|ªá¤@¬q®É¶¡, ½Ðµy«Ý¡C\n");
	return 1;
}

int do_savemap(string arg)
{
	string output;
	if(sizeof(maps)<1) return notify_fail("¥Ø«e¨S¦³¦a¹Ï³Q¸ü¤J¡C\n");
	if(!arg) arg = "area";
	arg = current_path+arg;
	output=show_map(1);
	if( file_size(arg)!=-1 ) {
		write("ÀÉ®× " + arg + " ¤w¦s¦b¡M­nÂÐ»\\ÂÂÀÉ¡S[y/n]");
		input_to("save_room_file", arg, output);
		return 1;
	}
	return save_room_file("y", arg, output);
}

int query_autoload() { return 1; }
void owner_is_killed() { destruct(this_object()); }