// 山貓(adx) by snow 2000-05-15

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "比武場貴賓席");
	set("long", @LONG
這裡是比武場的貴賓席，幾張紫檀太師椅排成一行，每張太師椅上面
都披著一張虎皮。只有夢幻七域的巫師才有資格坐在這裡。
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"biwutai",
	]));
	setup();
}

void init()
{
	if(!wizardp(this_player() ) ) {
	tell_object(this_player(),"一個大會人員對著你喝道：「這裡不是你該來的地方。」\n");
	this_player()->move(__DIR__"gate");
	message_vision("$N被大會人員請出比武場大門外面來了。",this_player() );
	}

	add_action ("do_urged","urged");
	add_action ("do_check","check");
	add_action ("do_next","next");
}

int do_urged()
{
	object where, ob, ob1, ob2;
	string id1, id2;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if(!ob->query("start"))
		return notify_fail("比武尚未開始啊！\n");

	id1=ob->query("start/biwu_fighter1");
	id2=ob->query("start/biwu_fighter2");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(!ob1) ob->keep_biwu(id2);
	if(!ob2) ob->keep_biwu(id1);

	message_vision(CYN"$N把"+ob1->query("name")+"和"+
		ob2->query("name")+"一腳踹上比武台！\n"NOR, this_player());
	if(environment(ob1)->query("short")!="比武台") {
		message_vision (CYN"公平子一腳把"+ob1->query("name")+
		"踹上比武台，嘴里嘟噥著：怎麼拖拖拉拉的！\n"NOR, ob1);
		ob1->move(__DIR__"biwutai");
	}
	if(environment(ob2)->query("short")!="比武台") {
		message_vision (CYN"公平子一腳把"+ob2->query("name")+
			"踹上比武台，嘴里嘟噥著：怎麼拖拖拉拉的！\n"NOR, ob2);
		ob2->move(__DIR__"biwutai");
	}
	return 1;
}

int do_start(string arg)
{
	object where, ob;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	if(!arg)
		return notify_fail("你要開始什麼？？！\n");
	ob->do_start(arg);
	return 1;
}

int do_check()
{
	object where, ob;
	object me=this_player();
	int i, j, k, a, b, c;
	string arg, id, msg, *str, *menpai;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	i=ob->query("biwudahui");
	j=ob->query("start/lunxu");
	k=(ob->query("start/huihe")-1);
	arg=ob->query("start/start");
	menpai=ob->query("fenzu");

	if(!arg)
		return notify_fail("目前還沒有開始比武！\n");

	if(arg=="xunhuan") {
		message_vision(WHT"第"+CHINESE_D->chinese_number(i)+"屆比武大會！\n"NOR, me);
	} else {
		message_vision(WHT"正在進行"MAG+arg+WHT"掌門大弟子選拔比武！\n"NOR, me);
	}

	message_vision (WHT"第"+CHINESE_D->chinese_number(j)+"輪！\n"NOR, me);

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=WHT"第"+CHINESE_D->chinese_number(a)+"組：";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			c=ob->query("jifen/"+id);
			msg+="("+id+") 積分=="+c+"\t";
		}
		message_vision (WHT""+msg+"\n"NOR, me);
	}
	message_vision (WHT"\n現在進行到第"+CHINESE_D->chinese_number(k)+"回合！\n"NOR, me);
	return 1;
}


int do_next(string arg)
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	if(!objectp(ob=present("da go ko", where))) return 1;;
	if( !ob->query("is_starting") ) return notify_fail("目前並沒有任何什麼比賽進行。\nsummo");

	message_vision (CYN"繼續進行下一輪比武！\n"NOR, me);
	ob->keep_biwu(arg);
	return 1;
}