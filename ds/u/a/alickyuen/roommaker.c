#define RMK_VERSION "(v2.0.Lsr.FF Alpha)"

#include <ansi.h>
 
inherit ITEM;
inherit F_AUTOLOAD;
 
int show_table(string arg);
int get_main_choice(string choice);
int make_room(string arg);
int show_room_item();
int get_room_item(string arg);
int set_room_item(string arg,string item);
int show_room_flag();
int set_room_flag(string flag);
int show_room_all();
int get_delete_item(string item);
int save_room(); 
int save_room_file(string yn, string file, string str);
int do_read(string arg);
string *special_props = ({ "short" , "long" });
 
mapping tmp;
 
mapping room_flag =  ([
	"1" : (["cname": "禁止施法",  "name" : "no_magic", "set" : 0 ]),
	"2" : (["cname": "禁止戰鬥",  "name" : "no_fight", "set" : 0 ]),
        "3" : (["cname": "水源", "name" : "resource/water", "set" : 0 ]),
	"4" : (["cname": "室外", "name" : "outdoors", "set" : 0 ]),
	"5" : (["cname": "儲存點 (通常是開著的)", "name" : "valid_startroom", "set" : 1 ])
]);
 
mapping room_item = ([
	"short" : "房間名",
	"long"  : "長敘述",
	"outdoors" : "屬於哪區域(室外才需設)",
	"detail/" : "物品描述",
	"objects of file" : "物件",
	"exits/dir"	: "出口",
	"others" : "其他"
]);
 
void create()
{
	set_name("房間製造器" + RMK_VERSION, ({ "new_maker", "maker" }) );
	set_weight(100);
	set("unit", "個" );
	set("long", @LONG
    這是一個用來製造或修改房間的工具﹐幫助巫師能在線上修改或
創造房間。不過只能提供基本的設定。若想知道此製造器詳細用法﹐
請打 read maker。

建議使用前請先看一看注意事項, 看注意事項的方法: 請打 read note。

請注意 ! 請不要在已經寫好的而且有 set  以外函數的房間使用
saveroom  的功能. 否則會破壞您辛辛苦苦寫好的函數及特殊功能.
LONG
	);
}
 
void init()
{
	if( wizardp(environment()) ) {
		seteuid(getuid(environment()));
		add_action("show_table", "run");
		add_action("do_read", "read");
		
	// modify by Lsr 以下這些是來自v1.1 版的
		add_action("xdo_make_room", "mkroom");
		add_action("xdo_rset", "rset");
		add_action("xdo_connect", "connect");
		add_action("save_room", "saveroom");
	}
}
 
 
int show_table(string arg)
{
	write("
 
");
	write("1. 創造新房間(create room)		\n");
	write("2. 設定房間元素(set room item)		\n");
	write("3. 設定房間基本屬性(set default flag)	\n");
	write("4. 清除房間元素(delete room item)	\n");
	write("5. 儲存房間資料(save room)		\n");
	write("＊ 注意：若無儲存則修改無效哦。 ＊	\n");
 	write("請輸入數字選擇(1-5)﹐或輸入 quit 離開。	\n");
	write("=>");
	input_to("get_main_choice");
	return 1;
}
 
int get_main_choice(string choice)
{
	switch(choice)
	{
		case "1":
			write("
 
請輸入房間檔名:");
			input_to("make_room");
			return 1; break;
			
		case "2":
			return show_room_item();
			break;
 
		case "3":
			return show_room_flag();
			break;
 
		case "4":
			return show_room_all();
			break;
 
		case "5":
			return save_room();			
			break;
 
		case "quit":	
			tmp = ([]);
			return 1; break;
		default:
			write("無此選項。\n");
			call_out("show_table",1);			
	}
	return 1;
}

int xdo_make_room(string arg)
{
        string file, dir, code;

        if( !arg ) return notify_fail("指令格式﹕mkroom <房間檔名> \n");
        if( sscanf(arg, "%s %s", file, dir)!=2 )
                file = arg; 
	make_room(arg);   
	return 1;
}
 
int make_room(string arg)
{
	string file, room;
 
	seteuid(geteuid(this_player()));
// Modified by Spock...:D
	if( sscanf( arg, "%s.c", room) == 1)
		file = resolve_path(this_player()->query("cwd"), room) + ".c";
	else file = resolve_path(this_player()->query("cwd"), arg) + ".c";

	if( file_size(file)!=-1 )
	{	
		write("檔案 " + file + " 已經存在了.\n");
		call_out("show_table",1);
		return 1;
	}
 
	if( !write_file(file, @ROOM_CODE
// room by Lsr@FSS

#include <ansi.h>
#include <room.h>

inherit ROOM;

//02____05________10________15________20________25________30________35________40__(中文字)

void create()
{
	set("short", "short");
	set("long",@LONG
這是一間什麼也沒有的空房間。
LONG
	);
	setup();
}
ROOM_CODE
	) ) return notify_fail("你沒有寫入檔案(" + file +")的權利。\n");
	message_vision(CYN"只聽到$N"NOR+CYN"的房間編輯器"HIW"「嗶」"NOR+CYN"的一聲﹐你覺得這個世界又變大了一點。\n"NOR, this_player());
 
	call_out("show_table",1);	
	return 1;
}

int xdo_connect(string arg)
{
        mapping exits;
        string dir, file;

        if( !arg || sscanf(arg, "%s %s", dir, file)!=2 )
                return notify_fail("指令格式﹕connect <方向> <房間檔名>\n");
        file = resolve_path(this_player()->query("cwd"), file);
        exits = environment(this_player())->query("exits");
        if( mapp(exits) )
                exits[dir] = file;
        else
                environment(this_player())->set("exits", ([ dir: file ]) );
        write(HIW"Ok.\n"NOR);
        return 1;
}

int xdo_rset(string arg)
{
        string prop, str;
        mixed data;

        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
                return notify_fail("指令格式﹕rset <房間屬性> <屬性內容>\n");

        if( sscanf(str, "%d", data)!=1 )
                data = str;

        environment(this_player())->set(prop, str);
        write(HIW"Ok.\n"NOR);
        return 1;
} 

 
int show_room_item()
{
	int i;
	string *items;
	
	write("
 
== 請選擇要設定的房間元素 ==\n");
	items = keys(room_item);
	for(i = 0; i< sizeof(items); i++)
		write(room_item[items[i]]+"("+items[i]+")\n");	
		
	write(HIW"=>"NOR);
	input_to("get_room_item");
	return 1;
}
 
int get_room_item(string arg)
{
	string dir;
 
	write("
 
== 設定 "+ arg +" 中( 用 . 表結束 ) ==：\n");
 
	if( strsrch(arg,"objects") != -1 )
	{
		sscanf(arg,"objects of %s",dir);
		if( !find_object(dir) )
		{
			write("無此物件﹐請檢查路徑有無設錯。\n");
			call_out("show_table",2);
			return 1;
		}	
	}
 
	input_to("set_room_item",arg);
	return 1;
}
 
int set_room_item(string arg,string item)
{
	string dir;
	int num;
	if(arg == ".") {
		write(HIW" OK!!\n"NOR);
		if( strsrch(item,"objects") != -1 )
		{
			sscanf(item,"objects of %s",dir);
			sscanf(tmp[item],"%d",num);
			environment(this_player())->set("objects", ([ dir:num ]));				
 
		} else if( !undefinedp(tmp[item]) ){
			environment(this_player())->delete(item);
			environment(this_player())->set(item,tmp[item]);
		}
		call_out("show_table",1);
		return 1;
	}
	if(!mapp(tmp))
		tmp = ([ item : arg ]);
	else
	{		
		if( !undefinedp(tmp[item]) )
			tmp[item] += arg + "\n";
		else if(item == "long")	
			tmp[item] = arg + "\n";	
		else 	tmp[item] = arg;
	}
	
	input_to("set_room_item",item);
	return 1;
}
 
int show_room_flag()
{
	string str,j,*flags;
	int i;
	str = "
 
";
	
	if(sizeof(room_flag) )
	{
		for(i=1;i<=sizeof(room_flag);i++)
		{
			
			j = sprintf("%d",i);
			if(environment(this_player())->query(room_flag[j]["name"]) )
				room_flag[j]["set"] = 1;
			else	room_flag[j]["set"] = 0;	
 
			str += sprintf("%s. [%s]  %s(%s)\n",j,
			(room_flag[j]["set"])? "◎":"  ",
			room_flag[j]["cname"],room_flag[j]["name"]);
		}	
		str += "請選擇想設定的屬性(1 - 5 ,直接 enter 跳到主選單)：";
		write(str);
		input_to("set_room_flag");
		return 1;
	}		
}
 
int set_room_flag(string flag)
{
	object me = this_player();
	object env = environment(this_player());
 
	if(!room_flag[flag])
	{
		call_out("show_table",1);
		return 1;	
	}
	else
	{
		if(env->query(room_flag[flag]["name"]) )
			env->delete(room_flag[flag]["name"]);				
		else	env->set(room_flag[flag]["name"],1);
 
		call_out("show_room_flag",1);
		return 1;	
	}
	
}
 
int show_room_all()
{
	string str,*item;	
	int i;
	mapping room;
	
	str = "
 
下面是此房間所有的元素﹐請選擇要刪除的。\n";
	
	room = environment(this_player())->query_entire_dbase();
	if(sizeof(room) )
	{
		item = keys(room);	
		for(i=0 ;i<sizeof(item); i++)
			str += sprintf(" %s\t\t︰ %O\n",item[i],room[item[i]]);			
		this_player()->start_more(str);
		write(HIW"=>"NOR);	
		input_to("get_delete_item");
		return 1;
	} else {
		write("此房間無任何資料。\n");
		call_out("show_table",1);
		return 1;
	}
}
 
int get_delete_item(string item)
{
	if( environment(this_player())->delete(item) )
		write(HIW"OK!!\n"NOR);
	else	write("無此資料可刪除。\n");
	
	call_out("show_table",1);
	return 1;
}
 
int save_room()
{
	object env;
	string str, *name, file;
	mapping prop;
	int i;
 
	env = environment(this_player());
	file = file_name(env) + ".c";
	str = "// " + file + @ROOM_CODE
 
// by Lsr@FSS
#include <ansi.h>

inherit ROOM;

//02____05________10________15________20________25________30________35________40__
 
void create()
{
ROOM_CODE
	;
	str += sprintf("\tset(\"short\", %O);\n", env->query("short") );
	str += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", env->query("long") );
	prop = env->query_entire_dbase();
	name = keys(prop);
	for(i=0; i<sizeof(name); i++) {
		if( member_array(name[i], special_props)!=-1 ) continue;
		str += sprintf("\tset(\"%s\", %O);\n", name[i], prop[name[i]] );
	}
	str += "\n\tsetup();\n\t}\n";
 
	// Replace current directory with __DIR__ macro to make relocatable code.
	i = strlen(file)-1;
	while( (i > 0) && (file[i]!='/')) i--;
	if( i>0 ) {
		write("目前目錄﹕" + file[0..i] + " 以 __ROOM_DIR__ 取代。\n");
		str = replace_string(str, "\"" + file[0..i], "__ROOM_DIR__\"");
	}
 
	if( file_size(file)!=-1 ) {
		write("檔案 " + file + " 已存在﹐要刪除舊檔嗎﹖[y/n]");
		input_to("save_room_file", file, str);
		return 1;
	}
 
	return save_room_file("y", file, str);
}
 
int save_room_file(string yn, string file, string str)
{
	if( strlen(yn)<1 || yn[0]!='y' ) return 1;
 
	rm(file);
	tmp = ([]);
	write("存檔 " + file + "....");
	if( write_file(file, str) ) {
		write(HIW"Ok.\n"NOR);
		return 1;
	} else
		return notify_fail("你沒有寫入這個檔案(" + file + ")的權利。\n");
}
 
void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }
 
int do_read(string arg)
{
	string str,note;
	object ob;
	ob = this_player();
	
	str = @HELP
== Roommaker 1.9 版 ==   作者: Smallpp

 A. 功能的第一部分.
 
啟動 roommaker  =>  run
 
會出現一個選單
1. 創造新房間(create room)
2. 設定房間元素(set room item)
3. 設定房間基本屬性(set default flag)
4. 清除房間元素(delete room item)
5. 儲存房間資料(save room)
＊ 注意：若無儲存則修改無效哦。 ＊
請輸入數字選擇(1-5)﹐或輸入 quit 離開。
=>
再照選單說明執行即可.


 B. 功能的第二部份. [來自roommaker v1.1]

mkroom <房間檔名>

    造出一個「空」房間﹐之後你可以 goto 到這個房間用 rset 設定房間的
    敘述或屬性。
    
rset <房間屬性> <屬性內容>

    設定你目前所在房間的屬性﹐如 short﹐long 等。

connect <方向> <房間檔名>

    將你目前所在的房間連接一個出口到另一個房間。

saveroom

    將你目前所在的房間存檔。           


PS. 其實第二部份的功能第一部份裡面已經都有了, 只是為了習慣使用v1.1版的巫師. 
 
HELP;
	note = @NOTE

 			++++ 注 意 事 項 ++++
 
 A. 創造出來的新房間會位於你所在的目錄下(即ls 時看到的目錄)

 B. 設定房間元素有幾個元素要注意 格式
     1.其他(others)          這個不是叫你鍵入 others, 而是任何字串皆可
     2.出口(exits/dir)            例如  exits/north    exits/enter
     3.物件(objects of file)      例如: objects of /d/locity/npc/cat
     4.物品描述(item_desc/item)   例如: item_desc/table  item_desc/ball

 C. 設定房間基本屬性,前有 ◎ 表此房間有設定此屬性, 再選一次可以取消
     1. [  ]  禁止施法(no_magic)
     2. [  ]  禁止戰鬥(no_fight)
     3. [  ]  禁止天神傳送(no_recall)
     4. [  ]  燈光(室內才有效)(light_up)
     5. [◎]  儲存點(valid_startroom)

 D. 如果有設定錯誤, 只要再重設定一次就可, 或者先不要 save ,
    update here即可恢復舊觀

 F. 發現 bug 請通知我..     
 
 G. 建議save之後再使用edit 存一次這個房間,如:
    edit here  <--編輯這個房間.
    :x          <-然後押x 存檔出來.
    
    這樣子做的用意是..
    假設我們寫了一個:
    set("item_desc", ([ /* sizeof() == 1 */
    "test" : "第一行\n 第二行\n",
    ])); 
    然後押look test時出現的是:
    第一行\n第二行\n 
    
    可是如果使用過edit 存檔的話, 再押look test就變成:
    第一行
    第二行
            
    就變成您想要的敘述了...:)    
 
 G. 這是一個用來「快速」製造房間的工具﹐幫助時間不多或有嚴重  lag 的巫師  
    利用線上輸入製造簡單的房間﹐不過如果您想提高自己區域房間的品質﹐最好
    不要太依賴這個東西.
   
 H. 這個 roommaker已經被 Lsr修改過一小部分了 ...
    把v1.1版的指令也加進來, 方便習慣於v1.1版的人.
    修改了一些字, 並依小佩的需要而添加了一些地方. 
    也就是說, 您再使用以前, 請先依您的需要做些修改後再使用.

NOTE; 
	if(arg == "roommaker" || arg == "maker" ){
		ob->start_more(str);
		return 1;
		}
	else
	if(arg == "note"){
		ob->start_more(note);
		return 1;
		}
	else 	return notify_fail("你想閱\讀什麼？\n");
	return 1;
}